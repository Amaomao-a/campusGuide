#include "campusguide.h"
#include "ui_campusguide.h"
#include "ui_manage.h"

campusGuide::campusGuide(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::campusGuide)
{
    ui->setupUi(this);

    uiSetLoad();

    objcetAndSignalsInit();

    buttonStateChange(0);  // 初始化按钮状态

    updatePeople();
}

campusGuide::~campusGuide()
{
    delete ui;
}

void campusGuide::objcetAndSignalsInit()
{
    // 系统时间计时器初始化
    datetime = QDateTime::fromString(QDateTime::currentDateTime().toString(tr("yyyy-MM-dd hh:mm:ss ddd")), "yyyy-MM-dd hh:mm:ss ddd");
    sysTimer = new QTimer(this);
    connect(sysTimer, SIGNAL(timeout()), this, SLOT(updateTime()));
    sysTimer->start(1000 / timeFlag);

    userTimer = new QTimer(this);       // 区段定时器，以用户的区段时间为计量
    userTimer->setSingleShot(true);
    moveTimer = new QTimer(this);     // 心跳定时器，每秒触发一次同时更新用户标签状态
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(userMove()));

    randTimer = new QTimer(this);     //  随机数更新定时器，每分钟更新一次建筑物内的人数
    connect(randTimer, SIGNAL(timeout()), this, SLOT(updatePeople()));
    randTimer->start(1000 * 60);

    //语音模块测试
    tts = new QTextToSpeech(this);
    tts->setLocale(QLocale::Chinese);
    tts->say(tr("这是一段语音测试"));

    // 禁止编辑
    ui->siteView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->searchList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->preferredView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void campusGuide::uiSetLoad()
{
    load = new Dialog(this);
    load->hide();

    ui->userLabel->hide();   // 在开始移动前将用户标签隐藏
    this->setWindowTitle("校园导览系统");
    uuser.location = graph_nodes[4]->COI;

    // 创建标签，设置标签样式并显示信息，然后将其以永久部件的形式添加到状态栏
    permanent = new QLabel(this);
    permanent->setFrameStyle(QFrame::Box | QFrame::Sunken);
    permanent->setText("系统时间: " + datetime.toString(tr("yyyy-MM-dd dddd hh:mm:ss")));
    ui->statusBar->addPermanentWidget(permanent);

    // 当编辑栏中文本改变时自动调用命令分析槽，检索出图中包含该关键字的节点
    connect(ui->lineEdit_src, SIGNAL(textChanged(QString)), this, SLOT(commandParse()));
    connect(ui->lineEdit_dst, SIGNAL(textChanged(QString)), this, SLOT(commandParse()));
    connect(ui->lineEdit_trans, SIGNAL(textChanged(QString)), this, SLOT(commandParse()));

    connect(ui->mapChange, SIGNAL(clicked()), this, SLOT(mapChange()));
    connect(this, SIGNAL(signal_travelPause()), this, SLOT(slot_travelPause()));
    connect(this, SIGNAL(signal_travelContinue()), this, SLOT(slot_travelContinue()));

    ui->groupBox_src->setEnabled(false);
    ui->groupBox_dst->setEnabled(false);
    ui->groupBox_trans->setEnabled(false);

    ui->search->setEnabled(false);
}

void campusGuide::preferredPathShow()
{
    commonPath.clear();
    database::getPreferredPath(uuser.userName, commonPath);

    pathModel.setStringList(commonPath);
    ui->preferredView->setModel(&pathModel);
    ui->preferredView->setAlternatingRowColors(true);
}

void campusGuide::accurateIsOk(unsigned seq, unsigned lineEdit)
{
    if(!accurateFlag)   return;
    switch (lineEdit) {
    case 0: // src
            if(graph_nodes[seq]->symbol == "教学楼")
            {
                ui->groupBox_src->setEnabled(true);
                ui->srcAccurate_academic->show();
                ui->srcAccurate_dormitory->hide();
                ui->srcAccurate_academic->setEnabled(true);
                ui->srcAccurate_dormitory->setEnabled(false);
            }
            else if(graph_nodes[seq]->symbol == "公寓")
            {
                ui->groupBox_src->setEnabled(true);
                ui->srcAccurate_dormitory->show();
                ui->srcAccurate_academic->hide();
                ui->srcAccurate_dormitory->setEnabled(true);
                ui->srcAccurate_academic->setEnabled(false);
            }
            else
            {
                ui->groupBox_src->setEnabled(false);
                ui->srcAccurate_academic->setEnabled(false);
                ui->srcAccurate_dormitory->setEnabled(false);
            }
        break;

    case 1: // trans
        if(graph_nodes[seq]->symbol == "教学楼")
        {
            ui->groupBox_trans->setEnabled(true);
            ui->transAccurate_academic->show();
            ui->transAccurate_dormitory->hide();
            ui->transAccurate_academic->setEnabled(true);
            ui->transAccurate_dormitory->setEnabled(false);
        }
        else if(graph_nodes[seq]->symbol == "公寓")
        {
            ui->groupBox_trans->setEnabled(true);
            ui->transAccurate_academic->hide();
            ui->transAccurate_dormitory->show();
            ui->transAccurate_academic->setEnabled(false);
            ui->transAccurate_dormitory->setEnabled(true);
        }
        else
        {
            ui->groupBox_trans->setEnabled(false);
            ui->transAccurate_academic->setEnabled(false);
            ui->transAccurate_dormitory->setEnabled(false);
        }
        break;

    case 2: // dst
        if(graph_nodes[seq]->symbol == "教学楼")
        {
            ui->groupBox_dst->setEnabled(true);
            ui->dstAccurate_academic->show();
            ui->dstAccurate_dormitory->hide();
            ui->dstAccurate_academic->setEnabled(true);
            ui->dstAccurate_dormitory->setEnabled(false);
        }
        else if(graph_nodes[seq]->symbol == "公寓")
        {
            ui->groupBox_dst->setEnabled(true);
            ui->dstAccurate_academic->hide();
            ui->dstAccurate_dormitory->show();
            ui->dstAccurate_academic->setEnabled(false);
            ui->dstAccurate_dormitory->setEnabled(true);
        }
        else
        {
            ui->groupBox_dst->setEnabled(false);
            ui->dstAccurate_academic->setEnabled(false);
            ui->dstAccurate_dormitory->setEnabled(false);
        }
        break;
    }
}

// 命令分析，返回所有包含该关键字的建筑物
void campusGuide::commandParse()
{
    QLineEdit *lineEdit = qobject_cast<QLineEdit*>(sender());//取得触发该槽的指针
    QString keyword = lineEdit->text();

    bool seqFlag;
    unsigned seq = keyword.toUInt(&seqFlag);
    _matchModel = new QStandardItemModel(this);

    if(seqFlag)   // 当前输入为节点编号则直接在容器中查询该节点后返回
    {
        if(seq<1 || seq>100)
        {
            lineEdit->clear();
            QMessageBox::information(nullptr, "输入错误", "超出节点编号范围，普通节点(1~100)", QMessageBox::Ok);
            return;
        }
        QString str = QString("[%1] %2").arg(graph_nodes[seq]->campus).arg(graph_nodes[seq]->name);
        Guide::addListItem(_matchModel, str, graph_nodes[seq]->people);
    }
    else
    {
        // 优先在映射关系表中查询，找到则唯一输出
        if(mappingRelation.find(keyword) != mappingRelation.end())
        {
            Guide::addListItem(_matchModel, mappingRelation[keyword], 0);
        }
        else
        {
            for(auto it=graph_nodes.begin(); it!=graph_nodes.end(); it++)
            {
                if(!(*it)->campus.contains("校区", Qt::CaseSensitive))    continue;   // 室内节点对室外不可见
                if(keyword.contains((*it)->name, Qt::CaseSensitive)     // 查询关键字command的子集与超集
                        || (*it)->name.contains(keyword, Qt::CaseSensitive))
                {
                    QString str = QString("[%1] %2").arg((*it)->campus).arg((*it)->name);
                    Guide::addListItem(_matchModel, str, (*it)->people);  // 将当前建筑物加入匹配得到的视图
                }
            }// end of for
        }// end of else
    }// end of else

    ui->siteView->setModel(_matchModel);
    ui->textBrowser_msg->hide();
    ui->siteView->show();

    if(lineEdit==ui->lineEdit_src)                ui->label->setText("起点");
    else if(lineEdit==ui->lineEdit_dst)           ui->label->setText("终点");
    else if(lineEdit==ui->lineEdit_trans)         ui->label->setText("中转点");

    ui->siteView->setAlternatingRowColors(true);
}

void campusGuide::editFinished()
{
    ui->label->setText("信息");
    ui->siteView->hide();
    ui->textBrowser_msg->show();

}

void campusGuide::buttonStateChange(int arg)
{
    switch(arg) {
        case 0:  // 程序待机状态
            ui->make->setEnabled(true);
            ui->start->setEnabled(false);
            ui->pause->setEnabled(false);
            ui->dstChange->setEnabled(false);
            ui->strategyChange->setEnabled(false);
            break;

        case 1:  // 制定导航路线后
            ui->start->setEnabled(true);
            break;

        case 2: // 开始移动后
            ui->make->setEnabled(false);
            ui->start->setEnabled(false);
            ui->pause->setEnabled(true);
            ui->search->setEnabled(true);
            ui->dstChange->setEnabled(true);
            ui->strategyChange->setEnabled(true);
            break;
    }
}

void campusGuide::updatePeople()
{
    for(auto it=graph_nodes.begin(); it!=graph_nodes.end(); it++)
    {
        (*it)->people = qrand()%300;
        if((*it)->name.contains("节点", Qt::CaseSensitive) || (*it)->name.contains("路口", Qt::CaseSensitive)
                || (*it)->campus == "教学楼"  || (*it)->campus == "公寓")
            (*it)->people %= 100;
    }
}

void campusGuide::updateTime()
{
    datetime = datetime.addSecs(timeFlag);
    permanent->setText("系统时间: " + datetime.toString(tr("yyyy-MM-dd ddd hh:mm:ss")));
}

bool campusGuide::userDataRead()
{
    uuser.srcAccurate.seq=0;    uuser.srcAccurate.name.clear();
    uuser.dstAccurate.seq=0;    uuser.dstAccurate.name.clear();
    uuser.transAccurate.seq=0; uuser.transAccurate.name.clear();

    // 读取用户的起点
    uuser.src.name = ui->lineEdit_src->text();
    uuser.src.campus = ui->comboBox_src->currentText();
    uuser.src.seq = getIndexOfGraph(uuser.src.name, uuser.src.campus);
    uuser.src.COI = graph_nodes[uuser.src.seq]->COI;

    // 读取用户的终点
    uuser.dst.name = ui->lineEdit_dst->text();
    uuser.dst.campus = ui->comboBox_dst->currentText();
    uuser.dst.seq = getIndexOfGraph(uuser.dst.name, uuser.dst.campus);
    uuser.dst.COI = graph_nodes[uuser.dst.seq]->COI;

    if(uuser.src.seq == uuser.dst.seq)  return false;

    // 读取用户的行进策略
    uuser.strategy = ui->comboBox_strategy->currentText();

    if(uuser.strategy == "最短距离(途径某地)") // 如果为途径中转点的最短距离策略
    {
        // 读取用户的中转点
        uuser.transPoint.name = ui->lineEdit_trans->text();
        if(!uuser.transPoint.name.isEmpty())
        {
            uuser.transPoint.campus = ui->comboBox_trans->currentText();
            uuser.transPoint.seq = getIndexOfGraph(uuser.transPoint.name, uuser.transPoint.campus);
            uuser.transPoint.COI = graph_nodes[uuser.transPoint.seq]->COI;
        }

        if(uuser.src.seq==uuser.transPoint.seq || uuser.dst.seq==uuser.transPoint.seq)
            return false;
    }

    if(accurateFlag)    // 读取房间制导
    {
        if(ui->srcAccurate_academic->isEnabled())   uuser.srcAccurate.name = ui->srcAccurate_academic->currentText();
        else if (ui->srcAccurate_dormitory->isEnabled()) uuser.srcAccurate.name = ui->srcAccurate_dormitory->currentText();
        if(!uuser.srcAccurate.name.isEmpty())
        {
            uuser.srcAccurate.seq = getIndexOfGraph(uuser.srcAccurate.name);
            uuser.srcAccurate.campus = graph_nodes[uuser.srcAccurate.seq]->campus;
            uuser.srcAccurate.COI = graph_nodes[uuser.srcAccurate.seq]->COI;
        }

        if(ui->dstAccurate_academic->isEnabled())   uuser.dstAccurate.name = ui->dstAccurate_academic->currentText();
        else if (ui->dstAccurate_dormitory->isEnabled()) uuser.dstAccurate.name = ui->dstAccurate_dormitory->currentText();
        if(!uuser.dstAccurate.name.isEmpty())
        {
            uuser.dstAccurate.seq = getIndexOfGraph(uuser.dstAccurate.name);
            uuser.dstAccurate.campus = graph_nodes[uuser.dstAccurate.seq]->campus;
            uuser.dstAccurate.COI = graph_nodes[uuser.dstAccurate.seq]->COI;
        }

        if(uuser.strategy == "最短距离(途径某地)")
        {
            if(ui->transAccurate_academic->isEnabled())   uuser.transAccurate.name = ui->transAccurate_academic->currentText();
            else if (ui->transAccurate_dormitory->isEnabled()) uuser.transAccurate.name = ui->transAccurate_dormitory->currentText();
            if(!uuser.transAccurate.name.isEmpty())
            {
                uuser.transAccurate.seq = getIndexOfGraph(uuser.transAccurate.name);
                uuser.transAccurate.campus = graph_nodes[uuser.transAccurate.seq]->campus;
                uuser.transAccurate.COI = graph_nodes[uuser.transAccurate.seq]->COI;
            }
        }
    }// end of accurateFlag

    if(Guide::isEnterIndoor(uuser.srcAccurate.seq)) whichMap = uuser.srcAccurate.campus;
    else  whichMap = uuser.src.campus;
    ui->mapChange->click();

    return true;
}

void campusGuide::on_make_clicked()
{  
    this->setWindowTitle(QString("校园导览系统 [%1] ").arg(uuser.userName));
    editFinished();
    if(!userDataRead())
    {
        QMessageBox::information(nullptr, "导航信息读取", "重复的目的地", QMessageBox::Ok);
        return;
    }
    if(pauseFlag)
    {
        removeStagnation();
        pauseFlag = false;
    }

    Guide::pathSchedule();

    ui->textBrowser_msg->setText(Guide::pathOutput());
    buttonStateChange(1);

    ui->userLabel->setPixmap(QPixmap(":/image/man_right.png"));
    if(Guide::isEnterIndoor(uuser.srcAccurate.seq)) ui->userLabel->move(uuser.srcAccurate.COI);
    else  ui->userLabel->move(uuser.src.COI);
    ui->userLabel->repaint();
    ui->userLabel->show();

    Guide::msgLogInsert("确认制定行进路线");
}

void campusGuide::on_start_clicked()
{
    buttonStateChange(2);

    travelStart();

    if(!movePause)
    {
        buttonStateChange(0);
        travelFinished();
    }
}

void campusGuide::travelStart()
{
    timeFlag = TIME_FLAG_CAMPUS;   // 校区内行进，时间加速推进
    uuser.userState = "行进中";
    uuser.walked = 0;
    uuser.campus = graph_nodes[uuser.Path.first()->from]->campus;
    uuser.start_time = datetime.toString(tr("yyyy-MM-dd hh:mm:ss"));
    ui->userLabel->move(graph_nodes[uuser.Path.first()->from]->COI);
    uuser.location = ui->userLabel->pos();
    whichMap = uuser.campus;
    ui->mapChange->click();

    // 跟随制定的路线的模拟行进
    while(!uuser.Path.isEmpty())
    {
        auto it=uuser.Path.begin();
        if(movePause)       return; //暂停槽被触发 直接返回
        if(!(*it)->remainingDistance) continue; // 当前区段已经走过，直接跳过

        uuser.curNode  = (*it);

        // 描述导航路线并更改图标显示
        QString msg;
        Guide::travelMsgConcat(msg);
        if(ui->siteView->isVisible())   ui->siteView->hide();
        userLabelChange();  // 根据行进的朝向、交通方式、行进策略改变标签图片

        // 开启定时器,模拟行进过程及时间推进
        auto flag = Guide::isCampusMoving();
        if(flag)
        {
            int waitTime = INF;
            int busSeq = Guide::findSuitableBus(datetime.time(), QDate::currentDate(), uuser.curNode->from, uuser.curNode->to, uuser.curNode->from, waitTime);
            uuser.userState = "等车中";    qDebug() << QTime::currentTime() << uuser.userState << Guide::timeTransfer(static_cast<unsigned>(waitTime));
            if(busSeq!=INF)
                msg = QString("[**等待校车中**]预计等待[%1]，于[%2]出发。\n").arg(Guide::timeTransfer(static_cast<unsigned>(waitTime))).arg(busTable[busSeq]->start_time) + msg;
            else if(busSeq!=-1)
                msg = QString("[**等待班车中**]预计等待[%1]，于[%2:00:00]出发。\n").arg(Guide::timeTransfer(static_cast<unsigned>(waitTime))).arg(datetime.time().hour()+1) + msg;

            msgCache = msgCache + msg + '\n';
            ui->textBrowser_msg->setText(msgCache);
            ui->textBrowser_msg->repaint();
            if(ttsFlag)     tts->say(tr("%1").arg(msg));   // 语音播报

            timeFlag = TIME_FLAG_WAITBUS;
            sysTimer->start(1000);
            moveTimer->stop();

            QMessageBox::information(nullptr, "等车", QString("当前正在等车，预计[%1]后出发").arg(Guide::timeTransfer(static_cast<unsigned>(waitTime))), QMessageBox::Ok);
            QEventLoop eventLoop;   // 使用局部事件循环让主线程等待，但仍保持响应。
            QTimer::singleShot(1000/timeFlag * waitTime + 4*timeFlag, &eventLoop, SLOT(quit()));  // 额外加4倍休整时间以弥补执行其他语句的时间消耗
            eventLoop.exec();

            timeFlag = TIME_FLAG_CITY;
            uuser.timecost += static_cast<unsigned>(waitTime);
            uuser.userState = "乘车移动中";  qDebug() << uuser.userState;
            load->show();
            uuser.timecost += (*it)->sectionTime;
        }
        else
        {
            msgCache = msgCache + msg + '\n';
            ui->textBrowser_msg->setText(msgCache);
            ui->textBrowser_msg->repaint();
            if(ttsFlag)     tts->say(tr("%1").arg(msg));   // 语音播报
            moveTimer->start(1000);
        }
        connect(userTimer, SIGNAL(timeout()), this, SLOT(updatePath()));
        userTimer->start(1000/timeFlag * (*it)->sectionTime + 4*timeFlag); // 系统时间为10倍真实时间推进
        // 额外加了4倍timeFlag的修正时间，用于校正usetTimer与sysTimer间的开启计时误差(主要针对校区间移动，校区内几乎可忽略)

        // do nothing but wait
        QEventLoop eventLoop;   // 使用局部事件循环让主线程等待，但仍保持响应。
        QTimer::singleShot(1000/timeFlag * (*it)->sectionTime + 4*timeFlag, &eventLoop, SLOT(quit()));
        eventLoop.exec();

        if(timeFlag==TIME_FLAG_CITY)
        {
            timeFlag=TIME_FLAG_CAMPUS;
            sysTimer->start(1000);
            updatePath();
        }

        if(load->isVisible())   load->hide();
        ui->userLabel->move(graph_nodes[uuser.curNode->to]->COI);
        if(!uuser.Path.isEmpty())   uuser.Path.pop_front();

        uuser.walked += uuser.curNode->remainingDistance;
        uuser.curNode->remainingDistance=0;
        uuser.location = graph_nodes[uuser.curNode->to]->COI;
        uuser.campus = graph_nodes[uuser.curNode->to]->campus;
        if(graph_nodes[uuser.curNode->from]->campus != graph_nodes[uuser.curNode->to]->campus)
        {
            whichMap = graph_nodes[uuser.curNode->to]->campus;
            ui->mapChange->click();
        }
    }//end of for
    if(!movePause)
    {
        if(uuser.dstAccurate.seq)
        {
            ui->userLabel->move(uuser.dstAccurate.COI);
            uuser.campus = uuser.dstAccurate.campus;
        }
        else
        {
            ui->userLabel->move(uuser.dst.COI);
            uuser.campus = uuser.dst.campus;
        }
    }


    ui->userLabel->repaint();
}

void campusGuide::travelFinished()
{
    timeFlag = TIME_FLAG_TRUE;
    uuser.userState = "等待中";
    moveTimer->stop();

    uuser.end_time = datetime.toString(tr("yyyy-MM-dd hh:mm:ss"));
    ui->lineEdit_src->setText(uuser.dst.name);
    if(uuser.dst.campus=="西土城校区")   ui->comboBox_src->setCurrentIndex(1);
    else  ui->comboBox_src->setCurrentIndex(0);
    ui->lineEdit_dst->clear();    ui->comboBox_dst->setCurrentIndex(0);
    ui->lineEdit_trans->clear(); ui->comboBox_trans->setCurrentIndex(0);

    // 时间计量转换
    QString fin = QString(tr("本次导航已完成，共行进%1米，耗时%2。\n").arg(uuser.walked).arg(Guide::timeTransfer(uuser.timecost)));
    this->tts->say(fin);

    msgCache += fin;
    ui->textBrowser_msg->setText(msgCache);
    ui->textBrowser_msg->repaint();

    Guide::pathLogInsert(msgCache);
    database::getPreferredPath(uuser.userName, commonPath);
    pathModel.setStringList(commonPath);
    ui->preferredView->setModel(&pathModel);

    uuser.timecost=0;
    uuser.walked=0;
    uuser.Path.clear();
    msgCache.clear();

   //removeStagnation();
}

void campusGuide::updatePath()
{
//    uuser.walked += uuser.curNode->remainingDistance;
//    uuser.curNode->remainingDistance=0;
//    uuser.location = graph_nodes[uuser.curNode->to]->COI;
//    uuser.campus = graph_nodes[uuser.curNode->to]->campus;

//    if(graph_nodes[uuser.curNode->from]->campus != graph_nodes[uuser.curNode->to]->campus)
//    {
//        whichMap = graph_nodes[uuser.curNode->to]->campus;
//        ui->mapChange->click();
//    }
}

void campusGuide::userLabelChange()
{
    if(Guide::isCampusMoving())
    {
        ui->userLabel->setPixmap(QPixmap(":/image/bus.png"));
    }
    else
    {
        int direction = graph_nodes[uuser.curNode->to]->COI.x() - graph_nodes[uuser.curNode->from]->COI.x();
        if(direction >= 0)
        {
            if(uuser.strategy=="最短时间(校内可选交通工具)")
                if(uuser.curNode->bicycle)  ui->userLabel->setPixmap(QPixmap(":/image/man_bicycle_right.png"));
                else                                   ui->userLabel->setPixmap(QPixmap(":/image/man_right.png"));
            else
                ui->userLabel->setPixmap(QPixmap(":/image/man_right.png"));
        }
        else
        {
            if(uuser.strategy=="最短时间(校内可选交通工具)")
                if(uuser.curNode->bicycle)  ui->userLabel->setPixmap(QPixmap(":/image/man_bicycle_left.png"));
                else                                   ui->userLabel->setPixmap(QPixmap(":/image/man_left.png"));
            else
                ui->userLabel->setPixmap(QPixmap(":/image/man_left.png"));
        }
    }
    ui->userLabel->repaint();
}

void campusGuide::mapChange()
{
    QString map = QString("<!DOCTYPE HTML PUBLIC %1 %2>\n<html><head><meta name=%3 content=%4 /><style type=%5>\np, li { white-space: pre-wrap; }\n</style></head><body style=%6>\n<p style=%7><img src=%8 /></p></body></html>")
                                        .arg("-//W3C//DTD HTML 4.0//EN")
                                        .arg("http://www.w3.org/TR/REC-html40/strict.dtd")
                                        .arg("qrichtext")
                                        .arg("1")
                                        .arg("text/css")
                                        .arg(" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;")
                                        .arg(" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;");
    QStringList mapList;
    mapList << "沙河校区" <<"西土城校区"<<"公寓"<<"教学楼";
    switch(mapList.indexOf(whichMap))
    {
    case 0: map = map.arg(":/image/[map]shahe.png");       break;
    case 1: map = map.arg(":/image/[map]xitucheng.png"); break;
    case 2: map = map.arg(":/image/[map]dormitory.png");  break;
    case 3: map = map.arg(":/image/[map]academic.png");  break;
    default:
        map = map.arg(":/image/[map]shahe.png");
    }
    ui->textBrowser->setHtml(map);
    ui->textBrowser->repaint();
    ui->textBrowser_msg->show();
    ui->textBrowser_msg->repaint();
}

void campusGuide::userMove()
{
    QPoint p = ui->userLabel->pos();
    double ratio =  static_cast<double>(timeFlag) / static_cast<double>(uuser.curNode->sectionTime);
    QPoint pNew = p + (graph_nodes[uuser.curNode->to]->COI - graph_nodes[uuser.curNode->from]->COI)*ratio;
//    qDebug() <<  p << "->" << pNew;

    ui->userLabel->move(pNew);
    ui->userLabel->repaint();
    uuser.location = pNew;
    uuser.timecost += timeFlag;
}

void campusGuide::on_logout_clicked()
{
    QSettings scfg("fzconfig.ini", QSettings::IniFormat);
    scfg.value("autoLogin", 0);

    if(userTimer->isActive())    userTimer->stop();
    if(moveTimer->isActive())   moveTimer->stop();
    uuser.Path.clear();
    this->hide();
    uuser.userState = "不在线";
    QMessageBox::information(nullptr, "登出", "已登出!", QMessageBox::Ok);
    Guide::msgLogInsert("登出");

    emit backToLogin();
}

void campusGuide::on_checkBox_talk_stateChanged(int)
{
    ttsFlag = ui->checkBox_talk->isChecked();
}

void campusGuide::slot_travelPause()
{
    // part1.清空路径暂停移动
    userTimer->stop();
    moveTimer->stop();
    uuser.Path.clear();

    // part1.以用户当前位置坐标新建一个夹在from/to之间的驻点插入地图节点映射中，用于恢复导航时重新规划路线
    Np from = graph_nodes[uuser.curNode->from], to=graph_nodes[uuser.curNode->to];
    Np stagnationNode = new Node;   // 生成驻点的基本信息
    stagnationNode->name = QString("[%1, %2]间的驻点").arg(from->name).arg(to->name);
    stagnationNode->COI = uuser.location;
    stagnationNode->seq = graph_nodes.size(); //插入映射尾，便于直接获取
    stagnationNode->campus = from->campus;

    Graph[stagnationNode->seq][from->seq] = Graph[from->seq][stagnationNode->seq] = distance(stagnationNode->COI, from->COI);
    Graph[stagnationNode->seq][to->seq] = Graph[to->seq][stagnationNode->seq] = distance(stagnationNode->COI, to->COI);
    Congestion[stagnationNode->seq][from->seq] = Congestion[from->seq][stagnationNode->seq] = Congestion[stagnationNode->seq][to->seq] = Congestion[to->seq][stagnationNode->seq] = Congestion[from->seq][to->seq];
    Bicycle[stagnationNode->seq][from->seq] = Bicycle[from->seq][stagnationNode->seq] = Bicycle[stagnationNode->seq][to->seq] = Bicycle[to->seq][stagnationNode->seq] = Bicycle[from->seq][to->seq];
    graph_nodes[stagnationNode->seq] = stagnationNode;

    // part2.修改导航参数，为恢复做准备
    ui->lineEdit_src->setText(stagnationNode->name);
    if(stagnationNode->campus=="西土城校区") ui->comboBox_src->setCurrentIndex(1);
    else  ui->comboBox_src->setCurrentIndex(0);

    if(Guide::isTransferArrived())
    {
        ui->lineEdit_trans->clear();
        ui->groupBox_trans->setEnabled(false);
    }
}

#include <synchapi.h>
void campusGuide::slot_travelContinue()
{
    ui->make->click();
    Sleep(1500);
    ui->start->click();
}

void campusGuide::removeStagnation()
{
    while(graph_nodes.last()->name.contains("驻点", Qt::CaseSensitive))  // 当尾节点是驻点时，将其移除(本次导航已结束，临时驻点失去意义)
    {
        unsigned seq = graph_nodes.lastKey();
        for(int i=0; i<MAX_NUM; i++)
        {
            if(Graph[i][seq] != INF)
            {
                Graph[i][seq] = Graph[seq][i] = INF;
                Congestion[i][seq] = Congestion[seq][i] = 0;
                Bicycle[i][seq] = Bicycle[seq][i] = 0;
            }
        }

        graph_nodes.remove(seq);  // 将该驻点移除
    }// end of while
}

void campusGuide::on_pause_clicked()
{
    if(Guide::isCampusMoving())  // 校区间移动时不可暂停!!
    {
        QMessageBox::information(nullptr, "暂停", "校区间移动中不可暂停!", QMessageBox::Ok);
        return;
    }
    movePause = !movePause;
    if(movePause)
    {
        // 先设置暂停状态
        ui->pause->setText("继续");
        Guide::msgLogInsert("暂停行进");
        uuser.userState = "暂停行进";
        buttonStateChange(2);
        timeFlag = TIME_FLAG_TRUE;

        if(!source) source = uuser.src.seq;   // 保存出发点

        emit signal_travelPause();      // 发出暂停信号，暂停模拟移动并插入驻点
    }
    else
    {
        ui->pause->setText("暂停");
        Guide::msgLogInsert("继续前进");
        buttonStateChange(0);

        emit signal_travelContinue(); // 发出继续信号，继续移动
        pauseFlag = true;
    }
}

void campusGuide::on_campusGuide_destroyed()
{
    Guide::msgLogInsert("登出");
}

void campusGuide::closeEvent(QCloseEvent*)
{
    Guide::msgLogInsert("登出");
}

void campusGuide::on_dstChange_clicked()
{
    Guide::msgLogInsert("行进途中变更目的地");

    ui->pause->click();
}

void campusGuide::on_strategyChange_clicked()
{
    Guide::msgLogInsert("行进途中改变行进策略");

    ui->pause->click();
}

void campusGuide::on_search_clicked()
{
    unsigned ridus = ui->searchRidus->text().toUInt();
    if(!ridus)  ridus = Search_Ridus;
    QString siteName = "范围内所有";
    if(!ui->searchName->text().isEmpty())   siteName = ui->searchName->text();

    _searchModel = new QStandardItemModel(this);
    Guide::searchSurroundingBuildings(_searchModel, siteName, ridus);
    ui->searchList->setModel(_searchModel);
    ui->searchList->repaint();

    Guide::msgLogInsert("查询周边建筑物");
}

// 查询显示部件的双击信号槽
void campusGuide::on_searchList_doubleClicked(const QModelIndex &index)
{
    // 1.解析该行的数据
    QString siteName, siteCampus; // 分离出地名和校区
    siteName = index.data().toString().split(":")[0].split(" ")[1];
    siteCampus = index.data().toString().split(":")[0].split(" ")[0].replace('[', "").replace(']', "");

    ui->pause->click();

    // 2.设置新目的地及最短时间导航策略
    ui->lineEdit_dst->setText(siteName);
    if(siteCampus == "西土城校区")   ui->comboBox_dst->setCurrentIndex(1);
    else  ui->comboBox_dst->setCurrentIndex(0);
    ui->comboBox_strategy->setCurrentIndex(1);

    // 3.以新目的地为目标继续前进
    Guide::msgLogInsert("查询后选择了新的目的地");
    msgCache += QString("查询后选择了新的目的地[%1]，导航策略变更为[最短时间策略]。\n").arg(siteName);
    ui->pause->click();
}

void campusGuide::on_checkBox_accurate_stateChanged(int)
{
    accurateFlag = ui->checkBox_accurate->isChecked();
//    if(accurateFlag)
//    {
//        ui->groupBox_src->setEnabled(true);
//        ui->groupBox_dst->setEnabled(true);
//        ui->groupBox_trans->setEnabled(true);
//    }
//    else
//    {
//        ui->groupBox_src->setEnabled(false);
//        ui->groupBox_dst->setEnabled(false);
//        ui->groupBox_trans->setEnabled(false);
//    }
}

void campusGuide::on_siteView_clicked(const QModelIndex &index)
{
    QString siteName, siteCampus;   // 分离出地名和校区
    unsigned roomId=0;  // 可能存在的房间号
    siteName = index.data().toString().split(" ")[1];
    siteCampus = index.data().toString().split("]")[0].replace("[", "");
    bool flag = false;
    if(siteCampus == "西土城校区")   flag=true;
    if(siteName.split('-').size()>1)
    {
        roomId = siteName.split('-')[1].mid(0,2).toUInt();
        siteName = siteName.split('-')[0];
        if(Guide::isEnterIndoor(roomId))    ui->checkBox_accurate->setChecked(true);
    }

    if(ui->label->text() == "起点")
    {
        ui->lineEdit_src->setText(siteName);
        ui->comboBox_src->setCurrentIndex(static_cast<int>(flag));
        accurateIsOk(getIndexOfGraph(ui->lineEdit_src->text(), ui->comboBox_src->currentText()), 0);
        if(ui->srcAccurate_academic->isEnabled())   ui->srcAccurate_academic->setCurrentIndex(static_cast<int>(roomId));
        if(ui->srcAccurate_dormitory->isEnabled())   ui->srcAccurate_dormitory->setCurrentIndex(static_cast<int>(roomId));
    }
    else if(ui->label->text() == "终点")
    {
        ui->lineEdit_dst->setText(siteName);
        ui->comboBox_dst->setCurrentIndex(static_cast<int>(flag));
        accurateIsOk(getIndexOfGraph(ui->lineEdit_dst->text(), ui->comboBox_dst->currentText()), 2);
        if(ui->dstAccurate_academic->isEnabled())   ui->dstAccurate_academic->setCurrentIndex(static_cast<int>(roomId));
        if(ui->dstAccurate_dormitory->isEnabled())   ui->dstAccurate_dormitory->setCurrentIndex(static_cast<int>(roomId));
    }
    else if(ui->label->text() == "中转点")
    {
        ui->lineEdit_trans->setText(siteName);
        ui->comboBox_trans->setCurrentIndex(static_cast<int>(flag));
        accurateIsOk(getIndexOfGraph(ui->lineEdit_trans->text(), ui->comboBox_trans->currentText()), 1);
        if(ui->transAccurate_academic->isEnabled())   ui->transAccurate_academic->setCurrentIndex(static_cast<int>(roomId));
        if(ui->transAccurate_dormitory->isEnabled())   ui->transAccurate_dormitory->setCurrentIndex(static_cast<int>(roomId));
    }
}

void campusGuide::on_preferredView_doubleClicked(const QModelIndex &index)
{
    QString pathMsg = index.data().toString().split(':')[1];
    QList<QString> msgList = pathMsg.replace('(', "").replace(')', "").replace(' ', "").split(',');

    QString campus, siteName;
    unsigned roomId, flag=0;

    // 1.读取设置出发地各项参数
    Guide::getSitePara(msgList[0], campus, siteName, roomId);
    ui->lineEdit_src->setText(siteName);
    if(campus == "西土城校区")  ui->comboBox_src->setCurrentIndex(1);
    else  ui->comboBox_src->setCurrentIndex(0);
    if(roomId)
    {
        ui->checkBox_accurate->setChecked(true);
        ui->groupBox_src->setEnabled(true);
        unsigned siteSeq = getIndexOfGraph(siteName, campus);
        if(graph_nodes[siteSeq]->symbol == "教学楼")
        {
            ui->srcAccurate_academic->setEnabled(true);
            ui->srcAccurate_dormitory->setEnabled(false);
            ui->srcAccurate_academic->show();
            ui->srcAccurate_dormitory->hide();

            ui->srcAccurate_academic->setCurrentIndex(roomId);
        }
        else if(graph_nodes[siteSeq]->symbol == "公寓")
        {
            ui->srcAccurate_academic->setEnabled(false);
            ui->srcAccurate_dormitory->setEnabled(true);
            ui->srcAccurate_academic->hide();
            ui->srcAccurate_dormitory->show();

            ui->srcAccurate_dormitory->setCurrentIndex(roomId);
        }
        flag++;
    }

    // 2.读取设置中转地各项参数
    Guide::getSitePara(msgList[1], campus, siteName, roomId);
    ui->lineEdit_trans->setText(siteName);
    if(campus == "西土城校区")  ui->comboBox_trans->setCurrentIndex(1);
    else  ui->comboBox_trans->setCurrentIndex(0);
    if(roomId)
    {
        ui->checkBox_accurate->setChecked(true);
        ui->groupBox_trans->setEnabled(true);
        unsigned siteSeq = getIndexOfGraph(siteName, campus);
        if(graph_nodes[siteSeq]->symbol == "教学楼")
        {
            ui->transAccurate_academic->setEnabled(true);
            ui->transAccurate_dormitory->setEnabled(false);
            ui->transAccurate_academic->show();
            ui->transAccurate_dormitory->hide();

            ui->transAccurate_academic->setCurrentIndex(roomId);
        }
        else if(graph_nodes[siteSeq]->symbol == "公寓")
        {
            ui->transAccurate_academic->setEnabled(false);
            ui->transAccurate_dormitory->setEnabled(true);
            ui->transAccurate_academic->hide();
            ui->transAccurate_dormitory->show();

            ui->transAccurate_dormitory->setCurrentIndex(roomId);
        }
        flag++;
    }

    // 3.读取设置终点各项参数
    Guide::getSitePara(msgList[2], campus, siteName, roomId);
    ui->lineEdit_dst->setText(siteName);
    if(campus == "西土城校区")  ui->comboBox_dst->setCurrentIndex(1);
    else  ui->comboBox_dst->setCurrentIndex(0);
    if(roomId)
    {
        ui->checkBox_accurate->setChecked(true);
        ui->groupBox_dst->setEnabled(true);
        unsigned siteSeq = getIndexOfGraph(siteName, campus);
        if(graph_nodes[siteSeq]->symbol == "教学楼")
        {
            ui->dstAccurate_academic->setEnabled(true);
            ui->dstAccurate_dormitory->setEnabled(false);
            ui->dstAccurate_academic->show();
            ui->dstAccurate_dormitory->hide();

            ui->dstAccurate_academic->setCurrentIndex(roomId);
        }
        else if(graph_nodes[siteSeq]->symbol == "公寓")
        {
            ui->dstAccurate_academic->setEnabled(false);
            ui->dstAccurate_dormitory->setEnabled(true);
            ui->dstAccurate_academic->hide();
            ui->dstAccurate_dormitory->show();

            ui->dstAccurate_dormitory->setCurrentIndex(roomId);
        }
        flag++;
    }

    if(!flag)   ui->checkBox_accurate->setChecked(false);

    // 4.设置导航策略   tips: 过滤时括号被去掉了
    if(msgList[3] == "最短距离")         ui->comboBox_strategy->setCurrentIndex(0);
    else if(msgList[3] == "最短时间")  ui->comboBox_strategy->setCurrentIndex(1);
    else if(msgList[3] == "最短距离途径某地")     ui->comboBox_strategy->setCurrentIndex(2);
    else if(msgList[3] == "最短时间校内可选交通工具") ui->comboBox_strategy->setCurrentIndex(3);

    Guide::msgLogInsert("选择了偏好路径");
}
