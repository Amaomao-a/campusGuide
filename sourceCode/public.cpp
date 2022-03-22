#include "public.h"


int walkSpeed=1, bicycleSpeed=3, busSpeed=1;
int Graph[MAX_NUM][MAX_NUM];
double Congestion[MAX_NUM][MAX_NUM];
bool Bicycle[MAX_NUM][MAX_NUM];
QMap<unsigned, Np> graph_nodes;
QVector<bRP> busTable;
User uuser;
QDateTime datetime;
QMap<QString, QString> mappingRelation;

int distance(unsigned A, unsigned B)
{
    auto pA = graph_nodes[A]->COI, pB = graph_nodes[B]->COI;
    int x = (pA-pB).x(), y=(pA-pB).y();

    return static_cast<int>(sqrt(x*x + y*y));
}

int distance(QPoint &A, QPoint &B)
{
    int x = A.x() - B.x(), y = A.y() - B.y();
    return static_cast<int>(sqrt(x*x + y*y));
}

//从数据库中读取结点数据建立地图连通图
void graph_init()
{
    database mydb;
    QSqlDatabase db = QSqlDatabase::database("campus_prj");
    QSqlQuery   query(db);    // 创建一个关联的QSqlQuery对象
    query.exec("select * from node;");


    for(int i=1; query.next(); i++)
    {
        Np curNode = new Node;
        curNode->seq = query.value(0).toUInt();      // 序号
        curNode->name = query.value(1).toString();// 名称

        QString s1 = query.value(2).toString();         // 中心点坐标
        s1.remove(0,1).remove(s1.length()-1, 1).replace(',', ' ');
        curNode->COI = QPoint(s1.split(' ')[0].toInt(), s1.split(' ')[1].toInt()) - coordinateCorrect; //需要校正中心点坐标，因为label本身有面积

        QList<QString> s2 = query.value(3).toString().split('-');         // 连通状态
        curNode->campus = query.value(4).toString(); // 校区
        QByteArray congestion=query.value(6).toByteArray(), bicycle=query.value(5).toByteArray();
        curNode->symbol = query.value(7).toString();  // 标识
        curNode->people  = query.value(8).toUInt(); // 人数

        //邻接矩阵初始化
        for(int j=1; j<MAX_NUM; j++)
        {
            if(i==j)    Graph[i][j] = 0;// 到自身的距离为0
            else         Graph[i][j] = INF;// 到其他点初始距离为无穷大
            Congestion[i][j] = 0;
            Bicycle[i][j] = 0;
        }

        for(int i=0; i<s2.size(); i++)
        {
            Graph[curNode->seq][s2[i].toUInt()] = 2;
            Congestion[curNode->seq][s2[i].toUInt()] = congestion[i]-48;
            Bicycle[curNode->seq][s2[i].toUInt()] = bicycle[i]-48;
        }
        // 当前结点数据读取完毕，将该结点放入容器中后开始下一结点的读取
        graph_nodes[curNode->seq] = curNode;
    }//end of for

    for(int i=1; i<MAX_NUM; i++)
        for(int j=1; j<MAX_NUM; j++)
            if(Graph[i][j] == 2)
                Graph[i][j] = distance(i, j);

}

void specialNodeAvaliable()
{
    // 校区间周转距离
    Graph[4][58]  = 3600*busSpeed;    Graph[58][4] = 3600*busSpeed;     // 校区间的校车耗时1h
    Graph[53][94] = 4500*busSpeed;   Graph[94][53] = 4500*busSpeed;   // 校区间的班车耗时1.5h

    // 教学楼与外界的连接点距离设为1 (25-49-51-62-71-90-97)
    Graph[136][25]=1;    Graph[25][136]=1;
    Graph[136][49]=1;    Graph[49][136]=1;
    Graph[136][51]=1;    Graph[51][136]=1;
    Graph[136][62]=1;    Graph[62][136]=1;
    Graph[136][71]=1;    Graph[71][136]=1;
    Graph[136][90]=1;    Graph[90][136]=1;
    Graph[136][97]=1;    Graph[97][136]=1;

    // 公寓楼与外界的连接点距离设为1 (14-19-21-64-68-85-98)
    Graph[101][14]=1;    Graph[14][101]=1;
    Graph[101][19]=1;    Graph[19][101]=1;
    Graph[101][21]=1;    Graph[21][101]=1;
    Graph[101][64]=1;    Graph[64][101]=1;
    Graph[101][68]=1;    Graph[68][101]=1;
    Graph[101][85]=1;    Graph[85][101]=1;
    Graph[101][98]=1;    Graph[98][101]=1;

}

void specialNodeForbidden()
{
    // 校区间周转距离
    Graph[4][58]  = 3600*busSpeed;    Graph[58][4] = 3600*busSpeed;     // 校区间的校车耗时1h
    Graph[53][94] = 4500*busSpeed;   Graph[94][53] = 4500*busSpeed;   // 校区间的班车耗时1.5h

    // 教学楼与外界的连接点距离设为1 (25-49-51-62-71-90-97)
    Graph[136][25]=INF;    Graph[25][136]=INF;
    Graph[136][49]=INF;    Graph[49][136]=INF;
    Graph[136][51]=INF;    Graph[51][136]=INF;
    Graph[136][62]=INF;    Graph[62][136]=INF;
    Graph[136][71]=INF;    Graph[71][136]=INF;
    Graph[136][90]=INF;    Graph[90][136]=INF;
    Graph[136][97]=INF;    Graph[97][136]=INF;

    // 公寓楼与外界的连接点距离设为1 (14-19-21-64-68-85-98)
    Graph[101][14]=INF;    Graph[14][101]=INF;
    Graph[101][19]=INF;    Graph[19][101]=INF;
    Graph[101][21]=INF;    Graph[21][101]=INF;
    Graph[101][64]=INF;    Graph[64][101]=INF;
    Graph[101][68]=INF;    Graph[68][101]=INF;
    Graph[101][85]=INF;    Graph[85][101]=INF;
    Graph[101][98]=INF;    Graph[98][101]=INF;
}

void busTable_init()
{
    database mydb;
    QSqlDatabase db = QSqlDatabase::database("campus_prj");
    QSqlQuery   query(db);    // 创建一个关联的QSqlQuery对象
    query.exec("select * from bus_timetable;");

    for(int i=1; query.next(); i++)
    {
        bRP curNode = new bR;
        curNode->date = query.value(0).toString();
        curNode->origin = query.value(1).toString();
        curNode->destination = query.value(2).toString();
        curNode->start_time = query.value(3).toString();
        curNode->arrive_time = query.value(4).toString();
        curNode->type = query.value(5).toString();

        // 当前结点数据读取完毕，将该结点放入容器中后开始下一结点的读取
        busTable.push_back(curNode);
    }//end of for
}

void mappingRelation_init()
{
    database mydb;
    QSqlDatabase db = QSqlDatabase::database("campus_prj");
    QSqlQuery   query(db);    // 创建一个关联的QSqlQuery对象
    query.exec("select * from mappingRelation;");

    for(int i=1; query.next(); i++)
    {
        mappingRelation[query.value(0).toString()] = query.value(1).toString();
    }//end of for
}

unsigned getIndexOfGraph(QString nodeName, QString campus)
{
    for(auto it=graph_nodes.begin(); it!=graph_nodes.end(); it++)
    {
        if(nodeName==(*it)->name && campus==(*it)->campus) return (*it)->seq;
        else        continue;
    }
    return 0;
}

unsigned getIndexOfGraph(QString nodeName)
{
    for(auto it=graph_nodes.begin(); it!=graph_nodes.end(); it++)
    {
        if(nodeName==(*it)->name) return (*it)->seq;
        else        continue;
    }
    return 0;
}

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QFile file("log.txt");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return ;
    QTextStream gOutStream(&file);

    QByteArray localMsg = msg.toLocal8Bit();
    QString text;
    switch (type)
    {
    case QtDebugMsg:
        text = QString("Debug: %1 (%2:%3, %4)\n").arg(localMsg.constData()).arg(context.file).arg(context.line).arg(context.function);
        break;
    case QtInfoMsg:
        text = QString("Info: %1 (%2:%3, %4)\n").arg(localMsg.constData()).arg(context.file).arg(context.line).arg(context.function);
        break;
    case QtWarningMsg:
        text = QString("Warning: %1 (%2:%3, %4)\n").arg(localMsg.constData()).arg(context.file).arg(context.line).arg(context.function);
        break;
    case QtCriticalMsg:
        text = QString("Critical: %1 (%2:%3, %4)\n").arg(localMsg.constData()).arg(context.file).arg(context.line).arg(context.function);
        break;
    case QtFatalMsg:
        text = QString("Fatal: %1 (%2:%3, %4)\n").arg(localMsg.constData()).arg(context.file).arg(context.line).arg(context.function);
        abort();
    default:
        text = QString("Default: %1 (%2:%3, %4)\n").arg(localMsg.constData()).arg(context.file).arg(context.line).arg(context.function);
    }
    gOutStream << QDateTime::currentDateTime().toString("yyyy-MM-dd hh.mm.ss ") + text; //输出到txt文件
    gOutStream .flush(); //刷新缓冲区
}
