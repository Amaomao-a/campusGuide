#include "guide.h"

Guide::Guide()
{

}

bool Guide::isEnterIndoor(int seq)
{
    return seq && (seq!=101) && (seq!=136);
}

void Guide::pathSchedule()
{
    uuser.Path.clear();
    QList<unsigned> myPath;
    if(uuser.strategy == "最短距离")
    {
        if(isEnterIndoor(uuser.dstAccurate.seq))
        {
            shortestDistance(myPath, uuser.dst.seq, uuser.dstAccurate.seq);
            myPath.removeLast();
        }
        shortestDistance(myPath, uuser.src.seq, uuser.dst.seq);
        if(isEnterIndoor(uuser.srcAccurate.seq))
        {
            myPath.removeLast();
            shortestDistance(myPath, uuser.srcAccurate.seq, uuser.src.seq);
        }
    }// end of 最短距离
    else if(uuser.strategy == "最短时间")
    {
        if(isEnterIndoor(uuser.dstAccurate.seq))
        {
            shortestTime(myPath, uuser.dst.seq, uuser.dstAccurate.seq);
            myPath.removeLast();
        }
        shortestTime(myPath, uuser.src.seq, uuser.dst.seq);
        if(isEnterIndoor(uuser.srcAccurate.seq))
        {
            myPath.removeLast();
            shortestTime(myPath, uuser.srcAccurate.seq, uuser.src.seq);
        }
    }// end of 最短时间
    else if(uuser.strategy == "最短距离(途径某地)")
    {
        if(isEnterIndoor(uuser.dstAccurate.seq))
        {
            shortestDistanceByTransfer(myPath, uuser.dst.seq, uuser.dstAccurate.seq);
            myPath.removeLast();
        }
        if(isEnterIndoor(uuser.transAccurate.seq))
        {
            shortestDistanceByTransfer(myPath, uuser.transPoint.seq, uuser.dst.seq);
            myPath.removeLast();
            shortestDistanceByTransfer(myPath, uuser.transAccurate.seq, uuser.transPoint.seq);
            myPath.removeLast();
            shortestDistanceByTransfer(myPath, uuser.transPoint.seq, uuser.transAccurate.seq);
            myPath.removeLast();

            if(uuser.srcAccurate.seq)
            {
                shortestDistanceByTransfer(myPath, uuser.src.seq, uuser.transPoint.seq);
                myPath.removeLast();
                shortestDistanceByTransfer(myPath, uuser.srcAccurate.seq, uuser.src.seq);
            }
            else
            {
                shortestDistanceByTransfer(myPath, uuser.src.seq, uuser.transPoint.seq);
            }
        }
        else if(uuser.transPoint.seq)
        {
            shortestDistanceByTransfer(myPath, uuser.transPoint.seq, uuser.dst.seq);
            myPath.removeLast();

            if(uuser.srcAccurate.seq)
            {
                shortestDistanceByTransfer(myPath, uuser.src.seq, uuser.transPoint.seq);
                myPath.removeLast();
                shortestDistanceByTransfer(myPath, uuser.srcAccurate.seq, uuser.src.seq);
            }
            else
            {
                shortestDistanceByTransfer(myPath, uuser.src.seq, uuser.transPoint.seq);
            }
        }
        else
        {
            if(isEnterIndoor(uuser.srcAccurate.seq))
            {
                shortestDistanceByTransfer(myPath, uuser.src.seq, uuser.dst.seq);
                myPath.removeLast();
                shortestDistanceByTransfer(myPath, uuser.srcAccurate.seq, uuser.src.seq);
            }
            else
            {
                shortestDistanceByTransfer(myPath, uuser.src.seq, uuser.dst.seq);
            }
        }
    }// end of 最短距离(途径某地)
    else if(uuser.strategy == "最短时间(校内可选交通工具)")
    {
        if(isEnterIndoor(uuser.dstAccurate.seq))
        {
            shortestTimeWithBicycle(myPath, uuser.dst.seq, uuser.dstAccurate.seq);
            myPath.removeLast();
        }
        shortestTimeWithBicycle(myPath, uuser.src.seq, uuser.dst.seq);
        if(isEnterIndoor(uuser.srcAccurate.seq))
        {
            myPath.removeLast();
            shortestTimeWithBicycle(myPath, uuser.srcAccurate.seq, uuser.src.seq);
        }
    }// end of 最短时间(校内可选交通工具)

    specialNodeAvaliable();
    makePath(myPath);   // 由输出的路线指定用于导航的路径path
}

void Guide::travelMsgConcat(QString &msg)
{
    QString travelMsg;
    Np from=graph_nodes[uuser.curNode->from], to=graph_nodes[uuser.curNode->to];
    if(Guide::isCampusMoving())
    {
        travelMsg = QString("正坐[%1]从[%2-%3]前往[%4-%5]，预计在[%6]后到达。")
                                    .arg(from->symbol)
                                    .arg(from->campus).arg(from->name)
                                    .arg(to->campus).arg(to->name)
                                    .arg(Guide::timeTransfer(uuser.curNode->sectionTime));
    }// end of if
    else
    {
        int delta_x=(to->COI-from->COI).x(), delta_y=(to->COI-from->COI).y();
        travelMsg += "从当前位置";

        if(uuser.curNode->bicycle && uuser.strategy=="最短时间(校内可选交通工具)")  travelMsg += "[骑自行车]";
        if(sqrt(delta_x)<5 && delta_y>0)          travelMsg += "向正南";
        else if(sqrt(delta_x)<5 && delta_y<0)   travelMsg += "向正北";
        else if(sqrt(delta_y)<5 && delta_x>0)   travelMsg += "向正东";
        else if(sqrt(delta_y)<5 && delta_x<0)   travelMsg += "向正西";
        else if(delta_x>0 && delta_y>0)     travelMsg += "向东南";
        else if(delta_x>0 && delta_y<0)     travelMsg += "向东北";
        else if(delta_x<0 && delta_y>0)     travelMsg += "向西南";
        else if(delta_x<0 && delta_y<0)     travelMsg += "向西北";
        else    qDebug()<<"错误的行进方向";

        travelMsg += QString("前进[%1]米，预计在[%2]后到达[%3]。")
                                    .arg(uuser.curNode->remainingDistance)
                                    .arg(Guide::timeTransfer(uuser.curNode->sectionTime))
                                    .arg(graph_nodes[uuser.curNode->to]->name);
    }// end of else

    msg += travelMsg;
}

bool Guide::isCampusMoving()
{
    return (graph_nodes[uuser.curNode->from]->symbol=="校车" && graph_nodes[uuser.curNode->to]->symbol=="校车")
            || (graph_nodes[uuser.curNode->from]->symbol=="班车" && graph_nodes[uuser.curNode->to]->symbol=="班车");
}

bool Guide::isGuideBetweenIndoorAndOutdoor(unsigned from, unsigned to)
{    
    if(graph_nodes[from]->campus.contains("校区", Qt::CaseSensitive)
            && graph_nodes[to]->campus.contains("校区", Qt::CaseSensitive))
        return false;
    return true;
}

bool Guide::isTransferArrived()
{
    if(uuser.strategy!="最短距离(途径某地)")    return true;
    if(!uuser.transPoint.seq)   return true;
    for(auto it=uuser.Path.begin(); it!=uuser.Path.end(); it++)
    {
        if((*it)->to == uuser.transPoint.seq)   return false;
        if(uuser.transAccurate.seq && ((*it)->to == uuser.transAccurate.seq)) return false;
    }
    return true;
}

int Guide::findSuitableBus(QTime start_time, QDate date, unsigned from, unsigned to, unsigned type, int &waitTime)
{
    int seq=-1;
    QString day = date.toString().split(' ')[0];
    if(type==4 || type==58)  // 校车，需要查找筛选
    {
        for(int i=0; i < busTable.size(); i++)
        {
            if(busTable[i]->date != day)  continue;
            if(busTable[i]->origin!=graph_nodes[from]->campus
                    || busTable[i]->destination!=graph_nodes[to]->campus)
                continue;

            // 当日期、校区都对应时，筛选出等待时间最短的那一班车
            int timeDiff = start_time.secsTo(QTime::fromString(busTable[i]->start_time));
            if(timeDiff>=0 && timeDiff<waitTime)
            {
                waitTime = timeDiff;
                seq = i;
            }
        }// end of for
        return seq;
    }
    else if(type==53 || type==94) // 班车，等间隔发车，直接取得(1h)
    {
        waitTime = (60-start_time.minute())*60 + (60-start_time.second());
        return INF;
    }

    waitTime = -1;
    return seq;
}

void Guide::shortestDistance(QList<unsigned> &myPath, unsigned from, unsigned to)
{
    int n=graph_nodes.size(); // 顶点个数
    int path[MAX_NUM][MAX_NUM];  // path[i][j]记录从i→j经过了哪个点
    memset(path, -1, sizeof path);

    if(isGuideBetweenIndoorAndOutdoor(from, to))
        specialNodeAvaliable();
    else
        specialNodeForbidden();

    int graphTemp[n+1][n+1], time[n+1][n+1];
    for(int i=1;i<=n;i++)
        for(int j=1; j<=n;j++)
        {
            graphTemp[i][j] =  Graph[i][j];
            double cg = Congestion[i][j];
            cg = 1- cg/10;

            if(Graph[i][j] != INF)  time[i][j] = Graph[i][j] / cg;
            else          time[i][j] = INF;
        }

    // Floyd算法
    for(int k=1;k<=n;k++){ //选中的中间值
        for(int i=1;i<=n;i++){ //数组横坐标
            for(int j=1;j<=n;j++){ //数组纵坐标
                int waitTime = 0;
                if(k==4 || k==58 || k==53 || k==94)
                {
                    waitTime=INF;
                    int seq = findSuitableBus(datetime.addSecs(time[i][k]).time(), QDate::currentDate(), i, j, k, waitTime);
                    if(seq == -1)   continue;
                }

                if(graphTemp[i][j]>graphTemp[i][k]+graphTemp[k][j]){    //如果以k为中间点检测到路径更短
                   graphTemp[i][j]=graphTemp[i][k]+graphTemp[k][j];      //更新路径值
                   time[i][j] = time[i][k] + time[k][j]+waitTime;    // 更新该路径上的时间
                   path[i][j]=k;   //更新要经过的中间点
                }
            }// end of for j
        }// end of for i
    }//end of for k

    // 根据得到的floyd结果矩阵输出节点序列
    pathGenerate(path, myPath, from, to);
}

void Guide::shortestTime(QList<unsigned> &myPath, unsigned from, unsigned to)
{
    int n=graph_nodes.size(); // 顶点个数
    int path[MAX_NUM][MAX_NUM];  // path[i][j]记录从i→j经过了哪个点
    memset(path, -1, sizeof path);

    if(isGuideBetweenIndoorAndOutdoor(from, to))
        specialNodeAvaliable();
    else
        specialNodeForbidden();

    int graphTemp[n+1][n+1], time[n+1][n+1];
    for(int i=1;i<=n;i++)
        for(int j=1; j<=n;j++)
        {
            graphTemp[i][j] =  Graph[i][j];
            double cg = Congestion[i][j];
            cg = 1- cg/10;

            if(Graph[i][j] != INF)  time[i][j] = Graph[i][j] / cg;
            else          time[i][j] = INF;
        }

    // Floyd算法
    for(int k=1;k<=n;k++){ //选中的中间值
        for(int i=1;i<=n;i++){ //数组横坐标
            for(int j=1;j<=n;j++){ //数组纵坐标
                int waitTime=0; // 可能存在的乘车等待时间
                if(k==4 || k==58 || k==53 || k==94)
                {
                    waitTime=INF;
                    int seq = findSuitableBus(datetime.addSecs(time[i][k]).time(), QDate::currentDate(), i, j, k, waitTime);
                    if(seq == -1)   continue;
                }
                if(time[i][j]>time[i][k]+time[k][j] + waitTime){    //如果以k中间点为中间点检测到路径更短
                   graphTemp[i][j]=graphTemp[i][k]+graphTemp[k][j];      //更新路径值
                   time[i][j] = time[i][k] + time[k][j]+waitTime;    // 更新该路径上的时间
                   path[i][j]=k;   //更新要经过的中间点
                }
            }// end of for j
        }// end of for i
    }//end of for k

    // 根据得到的floyd结果矩阵输出节点序列
    pathGenerate(path, myPath, from, to);
}

void Guide::shortestDistanceByTransfer(QList<unsigned> &myPath, unsigned from, unsigned to)
{
    int n=graph_nodes.size(); // 顶点个数
    int path[MAX_NUM][MAX_NUM];  // path[i][j]记录从i→j经过了哪个点
    memset(path, -1, sizeof path);

    if(isGuideBetweenIndoorAndOutdoor(from, to))
        specialNodeAvaliable();
    else
        specialNodeForbidden();

    int graphTemp[n+1][n+1], time[n+1][n+1];
    for(int i=1;i<=n;i++)
        for(int j=1; j<=n;j++)
        {
            graphTemp[i][j] =  Graph[i][j];
            double cg = Congestion[i][j];
            cg = 1- cg/10;

            if(Graph[i][j] != INF)  time[i][j] = Graph[i][j] / cg;
            else          time[i][j] = INF;
        }

    // Floyd算法
    for(int k=1;k<=n;k++){ //选中的中间值
        for(int i=1;i<=n;i++){ //数组横坐标
            for(int j=1;j<=n;j++){ //数组纵坐标
                int waitTime = 0;
                if(k==4 || k==58 || k==53 || k==94)
                {
                    waitTime=INF;
                    int seq = findSuitableBus(datetime.addSecs(time[i][k]).time(), QDate::currentDate(), i, j, k, waitTime);
                    if(seq == -1)   continue;
                }

                if(graphTemp[i][j]>graphTemp[i][k]+graphTemp[k][j]){    //如果以k中间点为中间点检测到路径更短
                   graphTemp[i][j]=graphTemp[i][k]+graphTemp[k][j];      //更新路径值
                   time[i][j] = time[i][k] + time[k][j]+waitTime;    // 更新该路径上的时间
                   path[i][j]=k;   //更新要经过的中间点
                }
            }// end of for j
        }// end of for i
    }//end of for k

    pathGenerate(path, myPath, from, to); // 根据得到的floyd结果矩阵输出节点序列
}

void Guide::shortestTimeWithBicycle(QList<unsigned> &myPath, unsigned from, unsigned to)
{
    int n=graph_nodes.size(); // 顶点个数
    int path[MAX_NUM][MAX_NUM];  // path[i][j]记录从i→j经过了哪个点
    memset(path, -1, sizeof path);

    if(isGuideBetweenIndoorAndOutdoor(from, to))
        specialNodeAvaliable();
    else
        specialNodeForbidden();

    int graphTemp[n+1][n+1], time[n+1][n+1];
    for(int i=1;i<=n;i++)
        for(int j=1; j<=n;j++)
        {
            graphTemp[i][j] =  Graph[i][j];
            double ratio = (double)bicycleSpeed / (double)walkSpeed;

            if(Bicycle[i][j])
            {
                if(Graph[i][j] != INF)  time[i][j] = Graph[i][j] / ratio;
                else  time[i][j] = INF;
            }
            else
            {
                double cg = Congestion[i][j];
                cg = 1- cg/10;

                if(Graph[i][j] != INF)  time[i][j] = Graph[i][j] * cg;
                else          time[i][j] = INF;
            }
        }

    // Floyd算法
    for(int k=1;k<=n;k++){ //选中的中间值
        for(int i=1;i<=n;i++){ //数组横坐标
            for(int j=1;j<=n;j++){ //数组纵坐标
                int waitTime=0; // 可能存在的乘车等待时间
                if(k==4 || k==58 || k==53 || k==94)
                {
                    waitTime=INF;
                    int seq = findSuitableBus(datetime.addSecs(time[i][k]).time(), QDate::currentDate(), i, j, k, waitTime);
                    if(seq == -1)   continue;
                }
                if(time[i][j]>time[i][k]+time[k][j]+waitTime){    //如果以k中间点为中间点检测到路径更短
                   graphTemp[i][j]=graphTemp[i][k]+graphTemp[k][j];      //更新路径值
                   time[i][j] = time[i][k] + time[k][j]+waitTime;    // 更新该路径上的时间
                   path[i][j]=k;   //更新要经过的中间点
                }
            }// end of for j
        }// end of for i
    }//end of for k

    pathGenerate(path, myPath, from, to);   // 根据得到的floyd结果矩阵输出节点序列
}

void Guide::pathGenerate(int path[][MAX_NUM], QList<unsigned> &myPath, unsigned u, unsigned v)
{
    bool reverse=false;
    if(u<v)
    {
        reverse = true;
        swap(u,v);
    }

    QStack<unsigned> S;
    S.push(u);

    while(path[u][v] != -1)
    {
        unsigned temp = path[u][v];
        if(Graph[temp][u] != INF) // Graph[v][temp] 当big→small √ ; but small→big × 大概率是无向图造成的
        {
            S.push(temp);
            u = temp;
        }
        else
        {
            unsigned mid = path[u][temp];
            while(path[u][mid] != -1)
            //while(Graph[u][mid]!=INF)
            {
                if(Graph[u][mid] != INF)
                {
                    u = path[u][mid];
                    S.push(u);
                }
                else
                {
                    mid = path[u][mid];
                }
            }
            S.push(mid);
            u = mid;
        }// end of else
    }// end of while
    S.push(v);

    // 将栈中的内容弹出到链表中
    if(reverse) // 如果u、v翻转过则直接转化为正序列表，否则逆序弹出
    {
        myPath.append(S.toList());
    }
    else
    {
        while(!S.empty())   myPath.append(S.pop());
    }
}

void Guide::makePath(QList<unsigned> &myList)
{
    // 逆序遍历列表获得正确的行进节点顺序
    for(int i=myList.size()-1; i>0; i--)
    {
        // 节点常规属性设置
        Rp rNode = new Route;
        rNode->from = myList[i];
        rNode->to = myList[i-1];
        rNode->bicycle = Bicycle[rNode->from][rNode->to];
        rNode->sectionCongestion = Congestion[rNode->from][rNode->to];
        if((graph_nodes[rNode->from]->symbol=="校车" && graph_nodes[rNode->to]->symbol=="校车")
                || (graph_nodes[rNode->from]->symbol=="班车" && graph_nodes[rNode->to]->symbol=="班车"))
        {
            rNode->curSpeed = busSpeed;
        }
        else if(uuser.strategy == "最短时间(校内可选交通工具)" && Bicycle[rNode->from][rNode->to])     // 当前为可选交通工具的行进策略
        {
            rNode->curSpeed = bicycleSpeed;
        }
        else
        {   // 其他策略仅考虑拥挤度的影响
            double cg = rNode->sectionCongestion;
            cg = 1 - cg/10;
            rNode->curSpeed = walkSpeed * cg;    //当前路段的真实速度
        }

        rNode->remainingDistance = Graph[rNode->from][rNode->to];
        rNode->sectionTime = rNode->remainingDistance / rNode->curSpeed;
//        qDebug() << __LINE__ << QString("[%1 -> %2]").arg(graph_nodes[rNode->from]->name).arg(graph_nodes[rNode->to]->name)<<rNode->remainingDistance << rNode->curSpeed << rNode->sectionTime;
        uuser.Path.append(rNode);  // 将当前节点加入路径
    }// end of for
}

QString Guide::pathOutput()
{
    unsigned pathLength=0, pathTimecost=0;
    QString pathMsg;
    for(auto it=uuser.Path.begin(); it!=uuser.Path.end(); it++)
    {
        if(it == uuser.Path.begin())    pathMsg += QString("[%1]%2").arg((*it)->from).arg(graph_nodes[(*it)->from]->name);
        pathMsg += QString(" -> [%1]%2").arg((*it)->to).arg(graph_nodes[(*it)->to]->name);
        pathLength += (*it)->remainingDistance;
        pathTimecost += (*it)->sectionTime;
    }
    return QString("路径长度: %1米\t总耗时: %2\n路径: %3")
                        .arg(pathLength).arg(timeTransfer(pathTimecost))
                        .arg(pathMsg);
}

QString Guide::timeTransfer(unsigned time)
{
    return QTime(0,0,0).addSecs(time).toString(QObject::tr("hh:mm:ss"));
}

void Guide::msgLogInsert(QString msg)
{
    database::msgLogInsert(QDateTime::currentDateTime().toString(QObject::tr("yyyy-MM-dd hh:mm:ss")),
                                                             uuser.userName, uuser.userState,
                                                             msg);
}

void Guide::pathLogInsert(QString msg)
{
    QString src = QString("%1-%2").arg(uuser.src.campus).arg(uuser.src.name);
    if(uuser.srcAccurate.seq)   src += QString("-%3").arg(uuser.srcAccurate.name);

    QString dst = QString("%1-%2").arg(uuser.dst.campus).arg(uuser.dst.name);
    if(uuser.dstAccurate.seq)   dst += QString("-%3").arg(uuser.dstAccurate.name);

    QString trans = QString("%1-%2").arg(uuser.transPoint.campus).arg(uuser.transPoint.name);
    if(uuser.transAccurate.seq)   trans += QString("-%3").arg(uuser.transAccurate.name);

    database::pathLogInsert(uuser.userName,
                                         uuser.start_time,
                                         src,
                                         trans,
                                         dst,
                                         uuser.strategy,
                                         msg,
                                         Guide::timeTransfer(uuser.timecost));
}

void Guide::addListItem(QStandardItemModel* _model, const QString _str, const unsigned people)
{
    QStandardItem *item = new QStandardItem(_str);
    QLinearGradient linearGrad(QPointF(0,0), QPointF(200,200));
    QBrush brush(linearGrad);

    if(people==0)
    {
        linearGrad.setColorAt(0, Qt::darkBlue);
        linearGrad.setColorAt(1, Qt::white);
    }
    else if(people<=100)
    {
        linearGrad.setColorAt(0, Qt::green);
        linearGrad.setColorAt(1, Qt::white);
    }
    else if(people<=200)
    {
        linearGrad.setColorAt(0, Qt::blue);
        linearGrad.setColorAt(1, Qt::white);
    }
    else if(people<=300)
    {
        linearGrad.setColorAt(0, Qt::darkRed);
        linearGrad.setColorAt(1, Qt::red);
    }

    item->setBackground(linearGrad);
    _model->appendRow(item);
}

void Guide::searchSurroundingBuildings(QStandardItemModel *_model, QString name, unsigned ridus)
{
    // 在校区间移动时，无法给出任何查询信息。
    if(Guide::isCampusMoving())
    {
        QMessageBox::information(nullptr,
                                                "查询周边建筑物",
                                                QString("当前正在从[%1校区]向[%2校区]移动").arg(graph_nodes[uuser.curNode->from]->campus)
                                                            .arg(graph_nodes[uuser.curNode->to]->campus),
                                                QMessageBox::Ok);
        return ;
    }

    for(int i=1; i<graph_nodes.size(); i++)
    {
        if(graph_nodes[i]->campus != uuser.campus)  continue;
        if(graph_nodes[i]->name.contains("路口") )    continue;
        if(graph_nodes[i]->name.contains("节点") )    continue;
        auto P2Pdistance = distance(graph_nodes[i]->COI, uuser.location);
        if(0<P2Pdistance && P2Pdistance<= ridus)
        {
            if(name == "范围内所有"
                    || (!name.isEmpty() && graph_nodes[i]->name.contains(name, Qt::CaseSensitive)) )
            {
                QString _str =  QString("[%1] %2: %3米").arg(graph_nodes[i]->campus).arg(graph_nodes[i]->name).arg(P2Pdistance);
                addListItem(_model, _str, graph_nodes[i]->people);
            }
        }//end of if
    }// end of for
}

void Guide::getSitePara(QString str, QString &campus, QString &siteName, unsigned &roomId)
{
    QList<QString> strList = str.split('-');
    campus = strList[0];
    siteName = strList[1];
    if(strList.size()>2)
    {
        bool flag;
        unsigned seq = strList[2].mid(0, 2).toUInt(&flag);
        if(flag)    roomId = seq;
        else        roomId = 0;
    }
    else roomId = 0;
}
