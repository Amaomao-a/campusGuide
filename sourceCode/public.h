#ifndef PUBLIC_H
#define PUBLIC_H
#include <QPoint>
#include <QString>
#include <QVector>
#include <QDebug>
#include <QMap>
#include <QLabel>
#include <QFile>
#include <QDateTime>
#include <math.h>
#include <QPointF>

#include "database.h"
using namespace std;

//p1.结构体定义

// 地图结点
typedef struct node{
    unsigned seq;   // 结点编号
    QString name;  // 结点名称
    QPoint COI;      // 中心点坐标
    QString campus;  // 结点所属校区
    QString symbol;  // 结点标记，如食堂、教学楼、公寓等
    unsigned people;  //  结点人数
    QString logicAddress; // 逻辑地址
}Node, *Np;

typedef struct section{
    unsigned from, to;
    bool bicycle;               // 用户在当前区段骑自行车
    double curSpeed;        // 用户在区段[from,to]上的行进速度
    unsigned sectionCongestion;    // 当前区段的拥挤度
    unsigned remainingDistance;   // 距离下一节点的剩余距离
    unsigned sectionTime; // 到达下一节点的总时间
}Route, *Rp;

typedef struct user{
    QString userName, userState; // 用户名、用户状态
    QString strategy, campus;      // 行进策略、用户当前所处的校区
    QString start_time, end_time;// 记录一次导航的开始与结束时间，主要用于日志记录

    Node src, dst, transPoint;       // 起点、终点、中转点
    Node srcAccurate, dstAccurate, transAccurate; // 可能存在的精确制导点
    unsigned timecost, walked;   // 走过的总时间和距离
    QPoint location;      // 用户的当前位置

    QList<Rp>   Path;  // 总的行进路线
    Rp curNode;          // 行进路线中的当前节点
}User, *Up;

typedef struct busRecord{
    QString date;   // 日期
    QString origin, destination; // 出发地、目的地
    QString start_time, arrive_time; // 开始时间、结束时间
    QString type;  // 交通方式，"校车"、"班车"
}bR, *bRP;


//p2.全局变量及宏定义
#define  MAX_NUM   256  // 最大节点数
#define  INF   0x3f3f3f3f  // 不可达距离
#define  coordinateCorrect QPoint(18,20)  // 使用坐标导航时排除用户标签本身的大小
#define  Search_Ridus   500 // 查询功能的查找半径为中心点向外500m
#define  TIME_FLAG_TRUE       1     // 等待状态，系统时间1s=真实时间1s
#define  TIME_FLAG_CAMPUS  10   // 校区内移动，系统时间1s=真实时间10s
#define  TIME_FLAG_WAITBUS 60  // 等车，系统时间1s=真实时间1min
#define  TIME_FLAG_CITY       300 // 校区间移动，系统时间1s=真实时间5min

extern int walkSpeed, bicycleSpeed, busSpeed;     // 步行、骑行、校车的理想速度
extern int Graph[MAX_NUM][MAX_NUM];              // 连通矩阵，Graph[i][j]的值为两节点的连通距离
extern double Congestion[MAX_NUM][MAX_NUM]; // 拥挤度矩阵，Congestion[i][j]的值为两节点间的拥挤度
extern bool Bicycle[MAX_NUM][MAX_NUM];  // 邻接矩阵，表示两节点间是否可以骑自行车
extern QMap<unsigned, Np> graph_nodes;  // 地图节点映射，将节点序号与节点结构相关联
extern QVector<bRP> busTable;         // 交通时刻表
extern User uuser;          // 全局用户
extern QDateTime datetime; // 系统时间
extern QMap<QString, QString> mappingRelation; // 自定义的逻辑地址向物理地址的映射

//p3.地图初始化
void graph_init();          // 从数据库读取节点数据建立无向图及其邻接矩阵
void specialNodeAvaliable();  // 对一些特殊的节点设置
void specialNodeForbidden(); // 在室外移动时需禁用室内节点，防止意外的走近路。
void busTable_init();    // 交通时刻表初始化
void mappingRelation_init(); // 映射关系表初始化
unsigned getIndexOfGraph(QString nodeName, QString campus);
unsigned getIndexOfGraph(QString nodeName);
int distance(unsigned A, unsigned B);
int distance(QPoint &A, QPoint &B);
void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg);
#endif // PUBLIC_H
