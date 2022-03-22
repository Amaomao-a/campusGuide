#include "manage.h"
#include "ui_manage.h"

manage::manage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::manage)
{
    ui->setupUi(this);
    uiSetLoad();
    loadCfg();
}

manage::~manage()
{
    delete ui;
}

void manage::uiSetLoad()
{
    uuser.userState = "不在线";

    ui->lineEdit_passwd->setEchoMode(QLineEdit::Password);
    ui->RP_pwd->setEchoMode(QLineEdit::Password);
    ui->RP_pwdConfirm->setEchoMode(QLineEdit::Password);
    ui->FP_newPWD->setEchoMode(QLineEdit::Password);
    ui->FP_pwdConfirm->setEchoMode(QLineEdit::Password);

    connect(ui->lineEdit_name, SIGNAL(returnPressed()), ui->login, SIGNAL(clicked())); // 设回车为登录快捷键
    connect(ui->lineEdit_passwd, SIGNAL(returnPressed()), ui->login, SIGNAL(clicked())); // 设回车为登录快捷键
    connect(this, SIGNAL(autoLogin()), ui->login, SIGNAL(clicked()));  // 关联自动登录槽
    connect(&mainwindow, &campusGuide::backToLogin, this, &manage::show);     // 收到登出信号，返回登录界面

    ui->stackedWidget->setCurrentIndex(0);

    connect(ui->regi, SIGNAL(clicked()), this, SLOT(switchPage()));
    connect(ui->RP_Register, SIGNAL(clicked()), this, SLOT(switchPage()));
    connect(ui->fw, SIGNAL(clicked()), this, SLOT(switchPage()));

    connect(this, &manage::enterMainWindow, &mainwindow, &campusGuide::preferredPathShow);
}

void manage::switchPage()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());//得到按下的按钮的指针
    if(button==ui->regi)
        ui->stackedWidget->setCurrentIndex(1);//根据按下的button按索引显示相应的页面
    else if(button==ui->fw)
        ui->stackedWidget->setCurrentIndex(2);
    else if(button==ui->RP_back)
        ui->stackedWidget->setCurrentIndex(0);
}

void manage::saveCfg()
{
    QSettings scfg("fzconfig.ini", QSettings::IniFormat);

    scfg.setValue("Preference/userName", ui->lineEdit_name->text());
    scfg.setValue("Preference/passwd", ui->lineEdit_passwd->text());
    scfg.setValue("Preference/autoLogin", static_cast<int>(ui->autoLogin->isChecked()));
    scfg.setValue("Preference/remPasswd", static_cast<int>(ui->remPasswd->isChecked()));
    scfg.sync();
}

// 加载自动配置信息
void manage::loadCfg()
{
    QSettings cfg("fzconfig.ini", QSettings::IniFormat);

    bool autoLog = cfg.value("Preference/autoLogin").toBool();
    bool remPasswd = cfg.value("Preference/remPasswd").toBool();
    if(remPasswd)  // 如果记住了密码则载入
    {
        ui->lineEdit_name->setText(cfg.value("Preference/userName").toString());
        ui->lineEdit_passwd->setText(cfg.value("Preference/passwd").toString());
    }
    ui->autoLogin->setChecked(autoLog);
    ui->remPasswd->setChecked(remPasswd);

    if(autoLog)   // 如果选择了自动登录则触发信号
        emit autoLogin();
}

void manage::on_login_clicked()
{
    QString name = ui->lineEdit_name->text();
    QString pwd = ui->lineEdit_passwd->text();

    if(name.isEmpty() || pwd.isEmpty())
    {
        QMessageBox::information(nullptr, "登录", "请输入完整的用户名与密码", QMessageBox::Ok);
        return;
    }
    database *pdb = new database;
    if(pdb->queryPasswd(name, pwd)){    //登录成功
        uuser.userName = name;
        uuser.userState = "等待中";

        QMessageBox::information(nullptr, "登录", "登录成功!", QMessageBox::Ok);
        this->hide();
        mainwindow.show();      // 显示主窗口
        emit enterMainWindow();
    }
    else{
        QMessageBox::information(nullptr, "登录", "用户名或密码错误", QMessageBox::Ok);
        return;
    }

    saveCfg();
    ui->lineEdit_name->clear();
    ui->lineEdit_passwd->clear();
    Guide::msgLogInsert("登录");

}

void manage::on_FP_reset_clicked()
{
    QString userName = ui->FP_name->text();
    QString notes = ui->FP_note->text();
    QString passwd = ui->FP_newPWD->text();
    QString confirm = ui->FP_pwdConfirm->text();

    database *userDb = database::getDatabase();
    //判断用户名在数据库中是否存在
    if(!userDb->queryUserName(userName)){
        QMessageBox::information(nullptr, "重置密码", "用户名不存在", QMessageBox::Ok);
        return;
    }

    //当用户存在时，打开数据库
    if(!userDb->queryNotes(userName, notes))     //判断用户notes是否一致
    {
        QMessageBox::information(nullptr, "重置密码", "用户名不存在", QMessageBox::Ok);
        return;
    }

    if(passwd != confirm){
        QMessageBox::information(nullptr, "重置密码", "密码输入不一致", QMessageBox::Ok);
        return;
    }
    else{
        userDb->updatePasswd(userName, passwd, notes);
        ui->FP_back->click();
        QMessageBox::information(nullptr, "重置密码", "密码已重置!", QMessageBox::Ok);
    }

    database::msgLogInsert(QDateTime::currentDateTime().toString(tr("yyyy-MM-dd hh:mm:ss")),
                                        uuser.userName,
                                        uuser.userState,
                                        "重置密码");
}

void manage::on_RP_Register_clicked()
{
    QString userName = ui->RP_name->text();
    QString passwd = ui->RP_pwd->text();
    QString pdConfirm = ui->RP_pwdConfirm->text();
    QString notes = ui->RP_note->text();

    if(userName.isEmpty() || passwd.isEmpty() || pdConfirm.isEmpty() || notes.isEmpty())
    {
            QMessageBox::information(nullptr, "注册", "用户信息不完整", QMessageBox::Ok);
            return;
    }

    database *userDb = database::getDatabase();
    //判断用户名在数据库中是否存在，违规弹出注册失败弹窗
    if(userDb->queryUserName(userName)){
        QMessageBox::information(nullptr, "注册", "用户名已被注册", QMessageBox::Ok);
        return;
    }
    //判断用户密码是否前后一致，违规弹出注册失败弹窗
    if(passwd!=pdConfirm){
        QMessageBox::information(nullptr, "注册", "密码输入不一致", QMessageBox::Ok);
        return;
    }

    //不重名且密码一致时，打开数据库
    if(!userDb->userRegister(userName, passwd, notes)){
        QMessageBox::information(nullptr, "注册", "注册失败", QMessageBox::Ok);
        return ;
    }
    else{
        QMessageBox::information(nullptr, "注册", "注册成功", QMessageBox::Ok);
        ui->RP_back->click();
    }

    database::msgLogInsert(QDateTime::currentDateTime().toString(tr("yyyy-MM-dd hh:mm:ss")),
                                        uuser.userName,
                                        uuser.userState,
                                        "用户注册");
}

QWizardPage* manage::createPage1(){
    QWizardPage *firstPage = new QWizardPage;
    firstPage->setTitle(tr("校园导览系统介绍"));
    QLabel *text = new QLabel;
    text->setText(tr("本导览系统具备导航功能，\n当用户于某时刻请求导航时，\n系统将根据该同学的具体要求为其设计一条线路并输出。\n系统还提供查询服务，\n内容包括当前时刻用户所处的地点，\n一定范围内的建筑物等。"));

    QHBoxLayout *firstLayout = new QHBoxLayout;
    firstLayout->addWidget(text);
    firstPage->setLayout(firstLayout);

    firstPage->setButtonText(QWizard::NextButton, "下一页");
    firstPage->setButtonText(QWizard::CancelButton, "退出");
    return firstPage;
}

QWizardPage* manage::createPage2(){
    QWizardPage *secondPage = new QWizardPage;
    secondPage->setTitle(tr("用户操作指南——注册登录"));
    QLabel *text = new QLabel;
    text->setText(tr("(1) 用户注册: 输入用户名、密码以及提示，验证通过即注册。\n(2) 用户密码重置: 用户输入用户名、提示、新密码，验证通过则新密码生效。\n(3) 记住密码与自动登录: 勾选对应单选框。"));

    QHBoxLayout *secondLayout = new QHBoxLayout;
    secondLayout->addWidget(text);
    secondPage->setLayout(secondLayout);

    secondPage->setButtonText(QWizard::NextButton, "下一页");
    //secondPage->setButtonText(QWizard::BackButton, "上一页");
    secondPage->setButtonText(QWizard::CancelButton, "退出");
    return secondPage;
}

QWizardPage* manage::createPage3(){
    QWizardPage *thirdPage = new QWizardPage;
    thirdPage->setTitle(tr("用户操作指南——模拟导航"));
    QLabel *text = new QLabel;
    QString msg;
    msg += tr("(1) 【地点的输入】: 输入地名关键字，右侧栏会给出包含该关键字的所有地名，单击即可自动填入。\n");
    msg += tr("(2) 【暂停与恢复】: 移动过程中，点击“暂停”按钮可以暂停当前导航，点击“继续”按钮则恢复导航。\n");
    msg += tr("(3) 【临时修改目的地】: 点击“切换目的地”按钮让用户停留，设置新目的地，点击“继续”即可。\n");
    msg += tr("(4) 【临时修改导航策略】: 点击“切换导航策略”按钮让用户停留，设置新策略，点击“继续”即可。\n");
    msg += tr("(5) 【实时查询】: 移动过程中可以实时查询用户周边一定范围内的建筑物，双击项目可以将其设为新目的地。\n");

    text->setText(msg);

    QHBoxLayout *thirdLayout = new QHBoxLayout;
    thirdLayout->addWidget(text);
    thirdPage->setLayout(thirdLayout);

    thirdPage->setButtonText(QWizard::NextButton, "下一页");
    thirdPage->setButtonText(QWizard::CancelButton, "退出");
    return thirdPage;
}

QWizardPage* manage::createPage4(){
    QWizardPage *fourPage = new QWizardPage;
    fourPage->setTitle(tr("用户操作指南——导航扩展功能"));
    QLabel *text = new QLabel;

    QString msg;
    msg += tr("(6) 【精确制导】: 勾选“精确制导”选框后，可以在编辑栏后选择该建筑物对应的具体房间号。\n");
    msg += tr("(7) 【语音播报】: 勾选“语音播报”选框后，可以实时语音播报导航信息。\n");
    msg += tr("(8) 【偏好设置】: 点击偏好设置记录，可以将已有的导航记录参数设为当前导航参数。\n");
    msg += tr("(9) 【用户注销】: 点击“注销”按钮可以注销当前用户，返回登录界面。\n");

    text->setText(msg);

    QHBoxLayout *fourLayout = new QHBoxLayout;
    fourLayout->addWidget(text);
    fourPage->setLayout(fourLayout);

    fourPage->setButtonText(QWizard::FinishButton, "已知悉");
    fourPage->setButtonText(QWizard::CancelButton, "退出");
    return fourPage;
}

void manage::on_help_clicked()
{
    QWizard wizard(this);
    wizard.setWindowTitle(tr("用户手册"));
    wizard.addPage(createPage1());
    wizard.addPage(createPage2());
    wizard.addPage(createPage3());
    wizard.addPage(createPage4());
    wizard.exec();

    database::msgLogInsert(QDateTime::currentDateTime().toString(tr("yyyy-MM-dd hh:mm:ss")),
                                        uuser.userName,
                                        uuser.userState,
                                        "帮助手册");
}

void manage::on_autoLogin_stateChanged(int arg)
{
    if(arg)   ui->remPasswd->setChecked(true);
    QSettings cfg("fzconfig.ini", QSettings::IniFormat);
    cfg.setValue("Preference/autoLogin", arg);
    cfg.sync();

    QString str;
    if(arg) str = "选中自动登录";
    else    str = "取消自动登录";
    database::msgLogInsert(QDateTime::currentDateTime().toString(tr("yyyy-MM-dd hh:mm:ss")),
                                        uuser.userName,
                                        uuser.userState,
                                        str);
}

void manage::on_remPasswd_stateChanged(int arg)
{
    //当自动登录被选中但取消记住密码时，取消勾选自动登录
    if(!arg && ui->autoLogin->isChecked())  ui->autoLogin->setChecked(false);
    QSettings cfg("fzconfig.ini", QSettings::IniFormat);
    cfg.setValue("Preference/remPasswd", arg);
    cfg.sync();

    QString str;
    if(arg) str = "选中记住密码";
    else    str = "取消记住密码";
    database::msgLogInsert(QDateTime::currentDateTime().toString(tr("yyyy-MM-dd hh:mm:ss")),
                                        uuser.userName,
                                        uuser.userState,
                                        str);

}

void manage::on_RP_back_clicked()
{
    ui->RP_pwd->clear();
    ui->RP_name->clear();
    ui->RP_pwdConfirm->clear();
    ui->RP_note->clear();

    ui->stackedWidget->setCurrentIndex(0);
}

void manage::on_FP_back_clicked()
{
    ui->FP_name->clear();
    ui->FP_note->clear();
    ui->FP_newPWD->clear();
    ui->FP_pwdConfirm->clear();

    ui->stackedWidget->setCurrentIndex(0);
}
