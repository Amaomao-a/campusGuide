#ifndef GUIDE_H
#define GUIDE_H

#include <QList>
#include <QString>
#include <QStack>
#include <QObject>
#include <QTime>
#include <QObject>
#include <QStandardItemModel>
#include "public.h"
#include "database.h"

class Guide
{
public:
    Guide();

    static bool isEnterIndoor(int seq);   // 判断精确导航节点是否有效，101为楼道、136位电梯口不是严格的室内节点
    static void pathSchedule();          //  根据用户参数进行路径规划
    static void travelMsgConcat(QString &msg); // 导航信息实时播报并将信息返回做记录
    static QString timeTransfer(unsigned time); // 将毫秒时间转化为(hh:mm:ss)形式的时间
    static void makePath(QList<unsigned> &myList);  // 制定路线
    static void pathGenerate(int path[][MAX_NUM], QList<unsigned> &myPath, unsigned u, unsigned v);
    static QString pathOutput(); // 输出当前用户的路线

    static void msgLogInsert(QString msg);
    static void pathLogInsert(QString msg);

    static void shortestDistance(QList<unsigned> &myPath, unsigned from, unsigned to); // 最短距离算法
    static void shortestTime(QList<unsigned> &myPath, unsigned from, unsigned to);       // 最短时间算法
    static void shortestDistanceByTransfer(QList<unsigned> &myPath, unsigned from, unsigned to); // 最短距离算法(途径某地)
    static void shortestTimeWithBicycle(QList<unsigned> &myPath, unsigned from, unsigned to);     // 最短时间算法(校内可选交通工具)

    static void addListItem(QStandardItemModel* _model, const QString _str, const unsigned people);
    static void searchSurroundingBuildings(QStandardItemModel *_model, QString name, unsigned ridus);  // 查询周边ridus米内的建筑物

    static bool isTransferArrived(); // 判断当前时刻是否已经通过中转点
    static bool isCampusMoving();  // 判断当前[from, to]是否为校区间移动
    static bool isGuideBetweenIndoorAndOutdoor(unsigned from, unsigned to);
    static int findSuitableBus(QTime start_time, QDate date , unsigned from, unsigned to, unsigned type, int &waitTime); // 返回该车次对应于容器的一个序号，以及等待时间
    static void getSitePara(QString str, QString &campus, QString &siteName, unsigned &roomId);
};

#endif // GUIDE_H
