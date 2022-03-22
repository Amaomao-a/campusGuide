#ifndef CAMPUSGUIDE_H
#define CAMPUSGUIDE_H

#include <QMainWindow>
#include <QTimer>
#include <QLabel>
#include <QDateTime>
#include <QTime>
#include <QStack>
#include <QtTextToSpeech/QTextToSpeech>     // 语音播报
#include <QSettings>    // 记住密码、自动登录
#include <QPainter>      // 模拟移动
#include <QCloseEvent>
#include <QStringListModel>
#include <QList>
#include <QLineEdit>
#include <QStandardItem>

#include "guide.h"
#include "dialog.h"
#pragma execution_character_set("utf-8")

namespace Ui {
class campusGuide;
}

class campusGuide : public QMainWindow
{
    Q_OBJECT

public:
    explicit campusGuide(QWidget *parent = nullptr);
    ~campusGuide();

    void uiSetLoad();   // 加载界面的初始设置
    void objcetAndSignalsInit();   // 对象初始化、信号关联

    void buttonStateChange(int arg);  // 对各个状态的按钮状态修改
    void userLabelChange(); // 根据行进方向及交通方式修改标签图片
    bool userDataRead();    // 读取用户参数
    void travelStart();         // 根据已规划好的路线模拟前进
    void travelFinished();   //  当前路线已完成

    void accurateIsOk(unsigned seq, unsigned lineEdit); // 判断当前序号对应的建筑物是否是可以精确制导的"教学楼"、"公寓"
    void removeStagnation();

signals:
    void backToLogin();   // 返回登录界面
    void signal_travelPause();
    void signal_travelContinue();

private slots:
    void updateTime();   // 时间更新
    void updatePath();   //  路径更新
    void userMove();      //  每隔1个定时器时间，用户移动一次
    void closeEvent(QCloseEvent *event);    // 关闭窗口时插入一条[登出]记录
    void updatePeople(); // 每分钟更新一次建筑物内的人数
    void editFinished();     // 命令分析完成

public slots:
    void commandParse();  // 命令分析
    void preferredPathShow();      // 获取并展示常用路径
    void mapChange();  // 当导航的校区改变时切换显示的地图
    void slot_travelPause();
    void slot_travelContinue();

private slots:  // 按钮槽
    void on_logout_clicked();
    void on_checkBox_talk_stateChanged(int arg1);
    void on_start_clicked();
    void on_make_clicked();
    void on_pause_clicked();
    void on_campusGuide_destroyed();
    void on_dstChange_clicked();
    void on_strategyChange_clicked();
    void on_search_clicked();
    void on_searchList_doubleClicked(const QModelIndex &index);
    void on_checkBox_accurate_stateChanged(int arg1);
    void on_siteView_clicked(const QModelIndex &index);
    void on_preferredView_doubleClicked(const QModelIndex &index);

private:
    Ui::campusGuide *ui;

    QLabel *permanent;        // 置于状态栏显示时间的标签
    QTextToSpeech *tts;        // 语音播报
    bool ttsFlag=false;          // 是否开启语音播报
    bool accurateFlag=false;  // 是否开启精确导航
    QString msgCache;         // 导航信息缓存

    QTimer *sysTimer, *userTimer, *moveTimer, *randTimer;
    unsigned timeFlag=TIME_FLAG_TRUE;

    bool movePause=false, pauseFlag; // 前者记录当前的暂停状态，后者记录上一段路程是否暂停过
    unsigned source=0;
    Dialog *load;  // 校区转换的中转对话框

    // 查询视图--周边建筑物
    QList<QString> commonPath;
    QStringListModel pathModel;

    // 编辑时按名匹配
    QStandardItemModel *_matchModel, *_searchModel;
    QString whichMap; // 当前展示的地图名
};


#endif // CAMPUSGUIDE_H
