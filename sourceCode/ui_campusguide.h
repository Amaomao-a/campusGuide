/********************************************************************************
** Form generated from reading UI file 'campusguide.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMPUSGUIDE_H
#define UI_CAMPUSGUIDE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_campusGuide
{
public:
    QWidget *centralWidget;
    QLabel *userLabel;
    QWidget *layoutWidget;
    QGridLayout *travelMsgForm;
    QLabel *label_2;
    QLabel *label_5;
    QComboBox *comboBox_dst;
    QGroupBox *groupBox_src;
    QComboBox *srcAccurate_academic;
    QComboBox *srcAccurate_dormitory;
    QComboBox *comboBox_trans;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_4;
    QWidget *widget;
    QComboBox *comboBox_src;
    QGroupBox *groupBox_trans;
    QComboBox *transAccurate_academic;
    QComboBox *transAccurate_dormitory;
    QGroupBox *groupBox_dst;
    QComboBox *dstAccurate_academic;
    QComboBox *dstAccurate_dormitory;
    QLineEdit *lineEdit_dst;
    QLineEdit *lineEdit_trans;
    QLineEdit *lineEdit_src;
    QComboBox *comboBox_strategy;
    QTextBrowser *textBrowser_msg;
    QPushButton *make;
    QPushButton *dstChange;
    QPushButton *strategyChange;
    QPushButton *logout;
    QLabel *label;
    QPushButton *start;
    QPushButton *pause;
    QPushButton *mapChange;
    QTextBrowser *textBrowser;
    QWidget *layoutWidget1;
    QGridLayout *preference;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_2;
    QListView *preferredView;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *checkBox_accurate;
    QCheckBox *checkBox_talk;
    QListView *siteView;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_10;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *searchName;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *searchRidus;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *search;
    QSpacerItem *horizontalSpacer;
    QListView *searchList;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *campusGuide)
    {
        if (campusGuide->objectName().isEmpty())
            campusGuide->setObjectName(QString::fromUtf8("campusGuide"));
        campusGuide->resize(1499, 848);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/exe.ico"), QSize(), QIcon::Normal, QIcon::Off);
        campusGuide->setWindowIcon(icon);
        centralWidget = new QWidget(campusGuide);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8("QWidget#centralWidget{	\n"
"	background-image: url(:/image/bupt_2.jpg);\n"
"}"));
        userLabel = new QLabel(centralWidget);
        userLabel->setObjectName(QString::fromUtf8("userLabel"));
        userLabel->setGeometry(QRect(0, 0, 51, 51));
        userLabel->setPixmap(QPixmap(QString::fromUtf8(":/image/man_right.png")));
        userLabel->setScaledContents(true);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 650, 431, 140));
        travelMsgForm = new QGridLayout(layoutWidget);
        travelMsgForm->setSpacing(6);
        travelMsgForm->setContentsMargins(11, 11, 11, 11);
        travelMsgForm->setObjectName(QString::fromUtf8("travelMsgForm"));
        travelMsgForm->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 9pt \"Sarasa Term SC\";"));

        travelMsgForm->addWidget(label_2, 1, 1, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 9pt \"Sarasa Term SC\";"));

        travelMsgForm->addWidget(label_5, 4, 1, 1, 1);

        comboBox_dst = new QComboBox(layoutWidget);
        comboBox_dst->addItem(QString());
        comboBox_dst->addItem(QString());
        comboBox_dst->setObjectName(QString::fromUtf8("comboBox_dst"));
        comboBox_dst->setEnabled(true);
        comboBox_dst->setStyleSheet(QString::fromUtf8("font: 9pt \"Sarasa Term SC\";"));

        travelMsgForm->addWidget(comboBox_dst, 3, 4, 1, 1);

        groupBox_src = new QGroupBox(layoutWidget);
        groupBox_src->setObjectName(QString::fromUtf8("groupBox_src"));
        groupBox_src->setEnabled(true);
        srcAccurate_academic = new QComboBox(groupBox_src);
        srcAccurate_academic->addItem(QString());
        srcAccurate_academic->addItem(QString());
        srcAccurate_academic->addItem(QString());
        srcAccurate_academic->addItem(QString());
        srcAccurate_academic->addItem(QString());
        srcAccurate_academic->addItem(QString());
        srcAccurate_academic->addItem(QString());
        srcAccurate_academic->addItem(QString());
        srcAccurate_academic->addItem(QString());
        srcAccurate_academic->addItem(QString());
        srcAccurate_academic->addItem(QString());
        srcAccurate_academic->addItem(QString());
        srcAccurate_academic->addItem(QString());
        srcAccurate_academic->addItem(QString());
        srcAccurate_academic->addItem(QString());
        srcAccurate_academic->addItem(QString());
        srcAccurate_academic->addItem(QString());
        srcAccurate_academic->setObjectName(QString::fromUtf8("srcAccurate_academic"));
        srcAccurate_academic->setGeometry(QRect(0, 0, 101, 25));
        srcAccurate_academic->setStyleSheet(QString::fromUtf8("font: 9pt \"Sarasa Term SC\";"));
        srcAccurate_dormitory = new QComboBox(groupBox_src);
        srcAccurate_dormitory->addItem(QString());
        srcAccurate_dormitory->addItem(QString());
        srcAccurate_dormitory->addItem(QString());
        srcAccurate_dormitory->addItem(QString());
        srcAccurate_dormitory->addItem(QString());
        srcAccurate_dormitory->addItem(QString());
        srcAccurate_dormitory->addItem(QString());
        srcAccurate_dormitory->addItem(QString());
        srcAccurate_dormitory->addItem(QString());
        srcAccurate_dormitory->addItem(QString());
        srcAccurate_dormitory->addItem(QString());
        srcAccurate_dormitory->addItem(QString());
        srcAccurate_dormitory->addItem(QString());
        srcAccurate_dormitory->addItem(QString());
        srcAccurate_dormitory->addItem(QString());
        srcAccurate_dormitory->addItem(QString());
        srcAccurate_dormitory->addItem(QString());
        srcAccurate_dormitory->addItem(QString());
        srcAccurate_dormitory->addItem(QString());
        srcAccurate_dormitory->addItem(QString());
        srcAccurate_dormitory->addItem(QString());
        srcAccurate_dormitory->addItem(QString());
        srcAccurate_dormitory->addItem(QString());
        srcAccurate_dormitory->setObjectName(QString::fromUtf8("srcAccurate_dormitory"));
        srcAccurate_dormitory->setGeometry(QRect(0, 0, 101, 25));
        srcAccurate_dormitory->setStyleSheet(QString::fromUtf8("font: 9pt \"Sarasa Term SC\";"));
        srcAccurate_dormitory->raise();
        srcAccurate_academic->raise();

        travelMsgForm->addWidget(groupBox_src, 1, 3, 1, 1);

        comboBox_trans = new QComboBox(layoutWidget);
        comboBox_trans->addItem(QString());
        comboBox_trans->addItem(QString());
        comboBox_trans->setObjectName(QString::fromUtf8("comboBox_trans"));
        comboBox_trans->setStyleSheet(QString::fromUtf8("font: 9pt \"Sarasa Term SC\";"));

        travelMsgForm->addWidget(comboBox_trans, 2, 4, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("font: 9pt \"Sarasa Term SC\";"));

        travelMsgForm->addWidget(label_6, 2, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(101, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        travelMsgForm->addItem(horizontalSpacer_4, 4, 3, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 9pt \"Sarasa Term SC\";"));

        travelMsgForm->addWidget(label_4, 3, 1, 1, 1);

        widget = new QWidget(layoutWidget);
        widget->setObjectName(QString::fromUtf8("widget"));

        travelMsgForm->addWidget(widget, 0, 0, 1, 1);

        comboBox_src = new QComboBox(layoutWidget);
        comboBox_src->addItem(QString());
        comboBox_src->addItem(QString());
        comboBox_src->setObjectName(QString::fromUtf8("comboBox_src"));
        comboBox_src->setStyleSheet(QString::fromUtf8("font: 9pt \"Sarasa Term SC\";"));

        travelMsgForm->addWidget(comboBox_src, 1, 4, 1, 1);

        groupBox_trans = new QGroupBox(layoutWidget);
        groupBox_trans->setObjectName(QString::fromUtf8("groupBox_trans"));
        transAccurate_academic = new QComboBox(groupBox_trans);
        transAccurate_academic->addItem(QString());
        transAccurate_academic->addItem(QString());
        transAccurate_academic->addItem(QString());
        transAccurate_academic->addItem(QString());
        transAccurate_academic->addItem(QString());
        transAccurate_academic->addItem(QString());
        transAccurate_academic->addItem(QString());
        transAccurate_academic->addItem(QString());
        transAccurate_academic->addItem(QString());
        transAccurate_academic->addItem(QString());
        transAccurate_academic->addItem(QString());
        transAccurate_academic->addItem(QString());
        transAccurate_academic->addItem(QString());
        transAccurate_academic->addItem(QString());
        transAccurate_academic->addItem(QString());
        transAccurate_academic->addItem(QString());
        transAccurate_academic->addItem(QString());
        transAccurate_academic->setObjectName(QString::fromUtf8("transAccurate_academic"));
        transAccurate_academic->setGeometry(QRect(0, 0, 101, 25));
        transAccurate_academic->setStyleSheet(QString::fromUtf8("font: 9pt \"Sarasa Term SC\";"));
        transAccurate_dormitory = new QComboBox(groupBox_trans);
        transAccurate_dormitory->addItem(QString());
        transAccurate_dormitory->addItem(QString());
        transAccurate_dormitory->addItem(QString());
        transAccurate_dormitory->addItem(QString());
        transAccurate_dormitory->addItem(QString());
        transAccurate_dormitory->addItem(QString());
        transAccurate_dormitory->addItem(QString());
        transAccurate_dormitory->addItem(QString());
        transAccurate_dormitory->addItem(QString());
        transAccurate_dormitory->addItem(QString());
        transAccurate_dormitory->addItem(QString());
        transAccurate_dormitory->addItem(QString());
        transAccurate_dormitory->addItem(QString());
        transAccurate_dormitory->addItem(QString());
        transAccurate_dormitory->addItem(QString());
        transAccurate_dormitory->addItem(QString());
        transAccurate_dormitory->addItem(QString());
        transAccurate_dormitory->addItem(QString());
        transAccurate_dormitory->addItem(QString());
        transAccurate_dormitory->addItem(QString());
        transAccurate_dormitory->addItem(QString());
        transAccurate_dormitory->addItem(QString());
        transAccurate_dormitory->addItem(QString());
        transAccurate_dormitory->setObjectName(QString::fromUtf8("transAccurate_dormitory"));
        transAccurate_dormitory->setGeometry(QRect(0, 0, 101, 25));
        transAccurate_dormitory->setStyleSheet(QString::fromUtf8("font: 9pt \"Sarasa Term SC\";"));

        travelMsgForm->addWidget(groupBox_trans, 2, 3, 1, 1);

        groupBox_dst = new QGroupBox(layoutWidget);
        groupBox_dst->setObjectName(QString::fromUtf8("groupBox_dst"));
        dstAccurate_academic = new QComboBox(groupBox_dst);
        dstAccurate_academic->addItem(QString());
        dstAccurate_academic->addItem(QString());
        dstAccurate_academic->addItem(QString());
        dstAccurate_academic->addItem(QString());
        dstAccurate_academic->addItem(QString());
        dstAccurate_academic->addItem(QString());
        dstAccurate_academic->addItem(QString());
        dstAccurate_academic->addItem(QString());
        dstAccurate_academic->addItem(QString());
        dstAccurate_academic->addItem(QString());
        dstAccurate_academic->addItem(QString());
        dstAccurate_academic->addItem(QString());
        dstAccurate_academic->addItem(QString());
        dstAccurate_academic->addItem(QString());
        dstAccurate_academic->addItem(QString());
        dstAccurate_academic->addItem(QString());
        dstAccurate_academic->addItem(QString());
        dstAccurate_academic->setObjectName(QString::fromUtf8("dstAccurate_academic"));
        dstAccurate_academic->setGeometry(QRect(0, 0, 101, 25));
        dstAccurate_academic->setStyleSheet(QString::fromUtf8("font: 9pt \"Sarasa Term SC\";"));
        dstAccurate_dormitory = new QComboBox(groupBox_dst);
        dstAccurate_dormitory->addItem(QString());
        dstAccurate_dormitory->addItem(QString());
        dstAccurate_dormitory->addItem(QString());
        dstAccurate_dormitory->addItem(QString());
        dstAccurate_dormitory->addItem(QString());
        dstAccurate_dormitory->addItem(QString());
        dstAccurate_dormitory->addItem(QString());
        dstAccurate_dormitory->addItem(QString());
        dstAccurate_dormitory->addItem(QString());
        dstAccurate_dormitory->addItem(QString());
        dstAccurate_dormitory->addItem(QString());
        dstAccurate_dormitory->addItem(QString());
        dstAccurate_dormitory->addItem(QString());
        dstAccurate_dormitory->addItem(QString());
        dstAccurate_dormitory->addItem(QString());
        dstAccurate_dormitory->addItem(QString());
        dstAccurate_dormitory->addItem(QString());
        dstAccurate_dormitory->addItem(QString());
        dstAccurate_dormitory->addItem(QString());
        dstAccurate_dormitory->addItem(QString());
        dstAccurate_dormitory->addItem(QString());
        dstAccurate_dormitory->addItem(QString());
        dstAccurate_dormitory->addItem(QString());
        dstAccurate_dormitory->setObjectName(QString::fromUtf8("dstAccurate_dormitory"));
        dstAccurate_dormitory->setGeometry(QRect(0, 0, 101, 25));
        dstAccurate_dormitory->setStyleSheet(QString::fromUtf8("font: 9pt \"Sarasa Term SC\";"));

        travelMsgForm->addWidget(groupBox_dst, 3, 3, 1, 1);

        lineEdit_dst = new QLineEdit(layoutWidget);
        lineEdit_dst->setObjectName(QString::fromUtf8("lineEdit_dst"));
        lineEdit_dst->setStyleSheet(QString::fromUtf8("font: 9pt \"Sarasa Term SC\";"));

        travelMsgForm->addWidget(lineEdit_dst, 3, 2, 1, 1);

        lineEdit_trans = new QLineEdit(layoutWidget);
        lineEdit_trans->setObjectName(QString::fromUtf8("lineEdit_trans"));
        lineEdit_trans->setStyleSheet(QString::fromUtf8("font: 9pt \"Sarasa Term SC\";"));

        travelMsgForm->addWidget(lineEdit_trans, 2, 2, 1, 1);

        lineEdit_src = new QLineEdit(layoutWidget);
        lineEdit_src->setObjectName(QString::fromUtf8("lineEdit_src"));
        lineEdit_src->setStyleSheet(QString::fromUtf8("font: 9pt \"Sarasa Term SC\";"));

        travelMsgForm->addWidget(lineEdit_src, 1, 2, 1, 1);

        comboBox_strategy = new QComboBox(layoutWidget);
        comboBox_strategy->addItem(QString());
        comboBox_strategy->addItem(QString());
        comboBox_strategy->addItem(QString());
        comboBox_strategy->addItem(QString());
        comboBox_strategy->setObjectName(QString::fromUtf8("comboBox_strategy"));
        comboBox_strategy->setStyleSheet(QString::fromUtf8("font: 9pt \"Sarasa Term SC\";"));

        travelMsgForm->addWidget(comboBox_strategy, 4, 2, 1, 1);

        textBrowser_msg = new QTextBrowser(centralWidget);
        textBrowser_msg->setObjectName(QString::fromUtf8("textBrowser_msg"));
        textBrowser_msg->setGeometry(QRect(850, 650, 381, 161));
        textBrowser_msg->setStyleSheet(QString::fromUtf8("font: 9pt \"Sarasa Term SC\";"));
        make = new QPushButton(centralWidget);
        make->setObjectName(QString::fromUtf8("make"));
        make->setGeometry(QRect(459, 660, 91, 41));
        make->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: rgb(170, 170, 127);\n"
"    border-radius: 8px;\n"
"    padding: 2px 4px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    font-size: 12px;\n"
"	font: 9pt \"Sarasa Term SC\";\n"
"    margin: 4px 2px;\n"
"    color: white;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: white;\n"
"    border: 2px solid #555555;\n"
"    color: black\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #06AD56;\n"
"}"));
        dstChange = new QPushButton(centralWidget);
        dstChange->setObjectName(QString::fromUtf8("dstChange"));
        dstChange->setGeometry(QRect(560, 660, 101, 41));
        dstChange->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #7b3db8;\n"
"    border-radius: 8px;\n"
"    padding: 4px 8px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    font-size: 16px;\n"
"	font: 9pt \"Sarasa Term SC\";\n"
"    margin: 4px 2px;\n"
"    color: white;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: white;\n"
"    border: 2px solid #555555;\n"
"    color: black\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #06AD56;\n"
"}"));
        strategyChange = new QPushButton(centralWidget);
        strategyChange->setObjectName(QString::fromUtf8("strategyChange"));
        strategyChange->setGeometry(QRect(560, 700, 101, 41));
        strategyChange->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color:#009800;\n"
"    border-radius: 8px;\n"
"    padding: 2px 4px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    font-size: 12px;\n"
"	font: 9pt \"Sarasa Term SC\";\n"
"    margin: 4px 2px;\n"
"    color: white;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: white;\n"
"    border: 2px solid #555555;\n"
"    color: black\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #06AD56;\n"
"}"));
        logout = new QPushButton(centralWidget);
        logout->setObjectName(QString::fromUtf8("logout"));
        logout->setGeometry(QRect(560, 740, 101, 41));
        logout->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #9e9e9e;\n"
"    border-radius: 8px;\n"
"    padding: 4px 8px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    font-size: 16px;\n"
"	font: 9pt \"Sarasa Term SC\";\n"
"    margin: 4px 2px;\n"
"    color: white;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: white;\n"
"    border: 2px solid #555555;\n"
"    color: black\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #06AD56;\n"
"}"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(800, 650, 51, 20));
        label->setStyleSheet(QString::fromUtf8("font: 9.5pt \"Sarasa Term SC\";\n"
"color:white;"));
        start = new QPushButton(centralWidget);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(459, 700, 91, 41));
        start->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: #d5d500;\n"
"    border-radius: 8px;\n"
"    padding: 2px 4px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    font-size: 12px;\n"
"	font: 9pt \"Sarasa Term SC\";\n"
"    margin: 4px 2px;\n"
"    color: white;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: white;\n"
"    border: 2px solid #555555;\n"
"    color: black\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #06AD56;\n"
"}font: 10pt \"Sarasa Term SC\";"));
        pause = new QPushButton(centralWidget);
        pause->setObjectName(QString::fromUtf8("pause"));
        pause->setGeometry(QRect(459, 740, 91, 41));
        pause->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: #bf5f00;\n"
"    border-radius: 8px;\n"
"    padding: 2px 4px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    font-size: 12px;\n"
"	font: 9pt \"Sarasa Term SC\";\n"
"    margin: 4px 2px;\n"
"    color: white;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: white;\n"
"    border: 2px solid #555555;\n"
"    color: black\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #06AD56;\n"
"}font: 10pt \"Sarasa Term SC\";"));
        mapChange = new QPushButton(centralWidget);
        mapChange->setObjectName(QString::fromUtf8("mapChange"));
        mapChange->setGeometry(QRect(950, 710, 101, 41));
        mapChange->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #dc006e;\n"
"    border-radius: 8px;\n"
"    padding: 2px 4px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    font-size: 16px;\n"
"	font: 9pt \"Sarasa Term SC\";\n"
"    margin: 4px 2px;\n"
"    color: white;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: white;\n"
"    border: 2px solid #555555;\n"
"    color: black\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #06AD56;\n"
"}"));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(1, 1, 1231, 651));
        textBrowser->setStyleSheet(QString::fromUtf8("QTextBrowser#textBrowser{\n"
"background-image: url(:/image/bupt_2.jpg);\n"
"	border-width:0;\n"
"	border-style:outset;\n"
"}"));
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(1230, 0, 261, 181));
        preference = new QGridLayout(layoutWidget1);
        preference->setSpacing(6);
        preference->setContentsMargins(11, 11, 11, 11);
        preference->setObjectName(QString::fromUtf8("preference"));
        preference->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("font: 9.5pt \"Sarasa Term SC\";\n"
"color:white;"));

        horizontalLayout_5->addWidget(label_8);

        horizontalSpacer_2 = new QSpacerItem(128, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        preference->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        preferredView = new QListView(layoutWidget1);
        preferredView->setObjectName(QString::fromUtf8("preferredView"));
        preferredView->setStyleSheet(QString::fromUtf8("font: 9pt \"Sarasa Term SC\";"));

        preference->addWidget(preferredView, 2, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        checkBox_accurate = new QCheckBox(layoutWidget1);
        checkBox_accurate->setObjectName(QString::fromUtf8("checkBox_accurate"));
        checkBox_accurate->setStyleSheet(QString::fromUtf8("font: 9pt \"Sarasa Term SC\";\n"
"color:white;"));

        horizontalLayout_6->addWidget(checkBox_accurate);

        checkBox_talk = new QCheckBox(layoutWidget1);
        checkBox_talk->setObjectName(QString::fromUtf8("checkBox_talk"));
        checkBox_talk->setStyleSheet(QString::fromUtf8("font: 9pt \"Sarasa Term SC\";\n"
"color:white;"));

        horizontalLayout_6->addWidget(checkBox_talk);


        preference->addLayout(horizontalLayout_6, 1, 0, 1, 1);

        siteView = new QListView(centralWidget);
        siteView->setObjectName(QString::fromUtf8("siteView"));
        siteView->setGeometry(QRect(850, 650, 381, 161));
        siteView->setStyleSheet(QString::fromUtf8("font: 9pt \"Sarasa Term SC\";"));
        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(1231, 272, 171, 27));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("font: 9pt \"Sarasa Term SC\";"));

        horizontalLayout_7->addWidget(label_7);

        searchName = new QLineEdit(layoutWidget3);
        searchName->setObjectName(QString::fromUtf8("searchName"));
        searchName->setStyleSheet(QString::fromUtf8("font: 9pt \"Sarasa Term SC\";"));

        horizontalLayout_7->addWidget(searchName);

        layoutWidget4 = new QWidget(centralWidget);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(1230, 240, 171, 25));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 9pt \"Sarasa Term SC\";"));

        horizontalLayout_3->addWidget(label_3);

        searchRidus = new QSpinBox(layoutWidget4);
        searchRidus->setObjectName(QString::fromUtf8("searchRidus"));
        searchRidus->setStyleSheet(QString::fromUtf8("font: 9pt \"Sarasa Term SC\";"));
        searchRidus->setMinimum(100);
        searchRidus->setMaximum(500);
        searchRidus->setSingleStep(50);
        searchRidus->setValue(200);

        horizontalLayout_3->addWidget(searchRidus);

        layoutWidget5 = new QWidget(centralWidget);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(1231, 306, 258, 271));
        verticalLayout = new QVBoxLayout(layoutWidget5);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        search = new QPushButton(layoutWidget5);
        search->setObjectName(QString::fromUtf8("search"));
        search->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #4488cc;\n"
"    border-radius: 8px;\n"
"    padding: 4px 8px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    font-size: 16px;\n"
"	font: 9pt \"Sarasa Term SC\";\n"
"    margin: 4px 2px;\n"
"    color: white;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: white;\n"
"    border: 2px solid #555555;\n"
"    color: black\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #06AD56;\n"
"}"));

        horizontalLayout_4->addWidget(search);

        horizontalSpacer = new QSpacerItem(78, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_4);

        searchList = new QListView(layoutWidget5);
        searchList->setObjectName(QString::fromUtf8("searchList"));
        searchList->setStyleSheet(QString::fromUtf8("font: 9pt \"Sarasa Term SC\";"));

        verticalLayout->addWidget(searchList);

        campusGuide->setCentralWidget(centralWidget);
        layoutWidget->raise();
        layoutWidget->raise();
        mapChange->raise();
        layoutWidget->raise();
        textBrowser->raise();
        start->raise();
        pause->raise();
        textBrowser_msg->raise();
        layoutWidget->raise();
        userLabel->raise();
        make->raise();
        dstChange->raise();
        strategyChange->raise();
        logout->raise();
        label->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        siteView->raise();
        statusBar = new QStatusBar(campusGuide);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        campusGuide->setStatusBar(statusBar);
        QWidget::setTabOrder(lineEdit_src, lineEdit_trans);
        QWidget::setTabOrder(lineEdit_trans, lineEdit_dst);
        QWidget::setTabOrder(lineEdit_dst, comboBox_strategy);
        QWidget::setTabOrder(comboBox_strategy, search);
        QWidget::setTabOrder(search, dstChange);
        QWidget::setTabOrder(dstChange, strategyChange);
        QWidget::setTabOrder(strategyChange, logout);
        QWidget::setTabOrder(logout, textBrowser_msg);
        QWidget::setTabOrder(textBrowser_msg, textBrowser);
        QWidget::setTabOrder(textBrowser, comboBox_dst);
        QWidget::setTabOrder(comboBox_dst, srcAccurate_academic);
        QWidget::setTabOrder(srcAccurate_academic, srcAccurate_dormitory);
        QWidget::setTabOrder(srcAccurate_dormitory, comboBox_trans);
        QWidget::setTabOrder(comboBox_trans, checkBox_accurate);
        QWidget::setTabOrder(checkBox_accurate, checkBox_talk);
        QWidget::setTabOrder(checkBox_talk, transAccurate_academic);
        QWidget::setTabOrder(transAccurate_academic, transAccurate_dormitory);
        QWidget::setTabOrder(transAccurate_dormitory, dstAccurate_academic);
        QWidget::setTabOrder(dstAccurate_academic, dstAccurate_dormitory);
        QWidget::setTabOrder(dstAccurate_dormitory, start);
        QWidget::setTabOrder(start, make);
        QWidget::setTabOrder(make, comboBox_src);
        QWidget::setTabOrder(comboBox_src, pause);
        QWidget::setTabOrder(pause, mapChange);
        QWidget::setTabOrder(mapChange, searchList);
        QWidget::setTabOrder(searchList, preferredView);
        QWidget::setTabOrder(preferredView, siteView);

        retranslateUi(campusGuide);

        QMetaObject::connectSlotsByName(campusGuide);
    } // setupUi

    void retranslateUi(QMainWindow *campusGuide)
    {
        campusGuide->setWindowTitle(QApplication::translate("campusGuide", "campusGuide", nullptr));
        userLabel->setText(QString());
        label_2->setText(QApplication::translate("campusGuide", "\345\275\223\345\211\215\344\275\215\347\275\256", nullptr));
        label_5->setText(QApplication::translate("campusGuide", "\350\241\214\350\277\233\347\255\226\347\225\245", nullptr));
        comboBox_dst->setItemText(0, QApplication::translate("campusGuide", "\346\262\231\346\262\263\346\240\241\345\214\272", nullptr));
        comboBox_dst->setItemText(1, QApplication::translate("campusGuide", "\350\245\277\345\234\237\345\237\216\346\240\241\345\214\272", nullptr));

        groupBox_src->setTitle(QString());
        srcAccurate_academic->setItemText(0, QApplication::translate("campusGuide", "\346\245\274\351\201\223", nullptr));
        srcAccurate_academic->setItemText(1, QApplication::translate("campusGuide", "01\345\217\267\346\225\231\345\256\244", nullptr));
        srcAccurate_academic->setItemText(2, QApplication::translate("campusGuide", "02\345\217\267\346\225\231\345\256\244", nullptr));
        srcAccurate_academic->setItemText(3, QApplication::translate("campusGuide", "03\345\217\267\346\225\231\345\256\244", nullptr));
        srcAccurate_academic->setItemText(4, QApplication::translate("campusGuide", "04\345\217\267\346\225\231\345\256\244", nullptr));
        srcAccurate_academic->setItemText(5, QApplication::translate("campusGuide", "05\345\217\267\346\225\231\345\256\244", nullptr));
        srcAccurate_academic->setItemText(6, QApplication::translate("campusGuide", "06\345\217\267\346\225\231\345\256\244", nullptr));
        srcAccurate_academic->setItemText(7, QApplication::translate("campusGuide", "07\345\217\267\346\225\231\345\256\244", nullptr));
        srcAccurate_academic->setItemText(8, QApplication::translate("campusGuide", "08\345\217\267\346\225\231\345\256\244", nullptr));
        srcAccurate_academic->setItemText(9, QApplication::translate("campusGuide", "\347\224\267\345\216\225", nullptr));
        srcAccurate_academic->setItemText(10, QApplication::translate("campusGuide", "\345\245\263\345\216\225", nullptr));
        srcAccurate_academic->setItemText(11, QApplication::translate("campusGuide", "11\345\217\267\346\225\231\347\240\224\345\256\244", nullptr));
        srcAccurate_academic->setItemText(12, QApplication::translate("campusGuide", "12\345\217\267\346\225\231\347\240\224\345\256\244", nullptr));
        srcAccurate_academic->setItemText(13, QApplication::translate("campusGuide", "13\345\217\267\345\212\236\345\205\254\345\256\244", nullptr));
        srcAccurate_academic->setItemText(14, QApplication::translate("campusGuide", "14\345\217\267\345\212\236\345\205\254\345\256\244", nullptr));
        srcAccurate_academic->setItemText(15, QApplication::translate("campusGuide", "15\345\217\267\345\274\200\346\260\264\351\227\264", nullptr));
        srcAccurate_academic->setItemText(16, QApplication::translate("campusGuide", "16\345\217\267\344\274\232\350\256\256\345\256\244", nullptr));

        srcAccurate_dormitory->setItemText(0, QApplication::translate("campusGuide", "\347\224\265\346\242\257\345\217\243", nullptr));
        srcAccurate_dormitory->setItemText(1, QApplication::translate("campusGuide", "01\345\217\267\346\210\277\351\227\264", nullptr));
        srcAccurate_dormitory->setItemText(2, QApplication::translate("campusGuide", "02\345\217\267\346\210\277\351\227\264", nullptr));
        srcAccurate_dormitory->setItemText(3, QApplication::translate("campusGuide", "03\345\217\267\346\210\277\351\227\264", nullptr));
        srcAccurate_dormitory->setItemText(4, QApplication::translate("campusGuide", "04\345\217\267\346\210\277\351\227\264", nullptr));
        srcAccurate_dormitory->setItemText(5, QApplication::translate("campusGuide", "05\345\217\267\346\210\277\351\227\264", nullptr));
        srcAccurate_dormitory->setItemText(6, QApplication::translate("campusGuide", "06\345\217\267\346\210\277\351\227\264", nullptr));
        srcAccurate_dormitory->setItemText(7, QApplication::translate("campusGuide", "07\345\217\267\346\210\277\351\227\264", nullptr));
        srcAccurate_dormitory->setItemText(8, QApplication::translate("campusGuide", "08\345\217\267\346\210\277\351\227\264", nullptr));
        srcAccurate_dormitory->setItemText(9, QApplication::translate("campusGuide", "09\345\217\267\346\210\277\351\227\264", nullptr));
        srcAccurate_dormitory->setItemText(10, QApplication::translate("campusGuide", "10\345\217\267\346\210\277\351\227\264", nullptr));
        srcAccurate_dormitory->setItemText(11, QApplication::translate("campusGuide", "11\345\217\267\346\210\277\351\227\264", nullptr));
        srcAccurate_dormitory->setItemText(12, QApplication::translate("campusGuide", "12\345\217\267\346\210\277\351\227\264", nullptr));
        srcAccurate_dormitory->setItemText(13, QApplication::translate("campusGuide", "13\345\217\267\346\210\277\351\227\264", nullptr));
        srcAccurate_dormitory->setItemText(14, QApplication::translate("campusGuide", "14\345\217\267\346\210\277\351\227\264", nullptr));
        srcAccurate_dormitory->setItemText(15, QApplication::translate("campusGuide", "15\345\217\267\346\210\277\351\227\264", nullptr));
        srcAccurate_dormitory->setItemText(16, QApplication::translate("campusGuide", "16\345\217\267\346\210\277\351\227\264", nullptr));
        srcAccurate_dormitory->setItemText(17, QApplication::translate("campusGuide", "17\345\217\267\346\210\277\351\227\264", nullptr));
        srcAccurate_dormitory->setItemText(18, QApplication::translate("campusGuide", "18\345\217\267\346\210\277\351\227\264", nullptr));
        srcAccurate_dormitory->setItemText(19, QApplication::translate("campusGuide", "19\345\217\267\346\210\277\351\227\264", nullptr));
        srcAccurate_dormitory->setItemText(20, QApplication::translate("campusGuide", "20\345\217\267\346\210\277\351\227\264", nullptr));
        srcAccurate_dormitory->setItemText(21, QApplication::translate("campusGuide", "21\345\217\267\346\210\277\351\227\264", nullptr));
        srcAccurate_dormitory->setItemText(22, QApplication::translate("campusGuide", "22\345\217\267\346\210\277\351\227\264", nullptr));

        comboBox_trans->setItemText(0, QApplication::translate("campusGuide", "\346\262\231\346\262\263\346\240\241\345\214\272", nullptr));
        comboBox_trans->setItemText(1, QApplication::translate("campusGuide", "\350\245\277\345\234\237\345\237\216\346\240\241\345\214\272", nullptr));

        label_6->setText(QApplication::translate("campusGuide", "\351\200\224\345\276\204\345\234\260", nullptr));
        label_4->setText(QApplication::translate("campusGuide", "\347\233\256\347\232\204\345\234\260", nullptr));
        comboBox_src->setItemText(0, QApplication::translate("campusGuide", "\346\262\231\346\262\263\346\240\241\345\214\272", nullptr));
        comboBox_src->setItemText(1, QApplication::translate("campusGuide", "\350\245\277\345\234\237\345\237\216\346\240\241\345\214\272", nullptr));

        groupBox_trans->setTitle(QString());
        transAccurate_academic->setItemText(0, QApplication::translate("campusGuide", "\346\245\274\351\201\223", nullptr));
        transAccurate_academic->setItemText(1, QApplication::translate("campusGuide", "01\345\217\267\346\225\231\345\256\244", nullptr));
        transAccurate_academic->setItemText(2, QApplication::translate("campusGuide", "02\345\217\267\346\225\231\345\256\244", nullptr));
        transAccurate_academic->setItemText(3, QApplication::translate("campusGuide", "03\345\217\267\346\225\231\345\256\244", nullptr));
        transAccurate_academic->setItemText(4, QApplication::translate("campusGuide", "04\345\217\267\346\225\231\345\256\244", nullptr));
        transAccurate_academic->setItemText(5, QApplication::translate("campusGuide", "05\345\217\267\346\225\231\345\256\244", nullptr));
        transAccurate_academic->setItemText(6, QApplication::translate("campusGuide", "06\345\217\267\346\225\231\345\256\244", nullptr));
        transAccurate_academic->setItemText(7, QApplication::translate("campusGuide", "07\345\217\267\346\225\231\345\256\244", nullptr));
        transAccurate_academic->setItemText(8, QApplication::translate("campusGuide", "08\345\217\267\346\225\231\345\256\244", nullptr));
        transAccurate_academic->setItemText(9, QApplication::translate("campusGuide", "\347\224\267\345\216\225", nullptr));
        transAccurate_academic->setItemText(10, QApplication::translate("campusGuide", "\345\245\263\345\216\225", nullptr));
        transAccurate_academic->setItemText(11, QApplication::translate("campusGuide", "11\345\217\267\346\225\231\347\240\224\345\256\244", nullptr));
        transAccurate_academic->setItemText(12, QApplication::translate("campusGuide", "12\345\217\267\346\225\231\347\240\224\345\256\244", nullptr));
        transAccurate_academic->setItemText(13, QApplication::translate("campusGuide", "13\345\217\267\345\212\236\345\205\254\345\256\244", nullptr));
        transAccurate_academic->setItemText(14, QApplication::translate("campusGuide", "14\345\217\267\345\212\236\345\205\254\345\256\244", nullptr));
        transAccurate_academic->setItemText(15, QApplication::translate("campusGuide", "15\345\217\267\345\274\200\346\260\264\351\227\264", nullptr));
        transAccurate_academic->setItemText(16, QApplication::translate("campusGuide", "16\345\217\267\344\274\232\350\256\256\345\256\244", nullptr));

        transAccurate_dormitory->setItemText(0, QApplication::translate("campusGuide", "\347\224\265\346\242\257\345\217\243", nullptr));
        transAccurate_dormitory->setItemText(1, QApplication::translate("campusGuide", "01\345\217\267\346\210\277\351\227\264", nullptr));
        transAccurate_dormitory->setItemText(2, QApplication::translate("campusGuide", "02\345\217\267\346\210\277\351\227\264", nullptr));
        transAccurate_dormitory->setItemText(3, QApplication::translate("campusGuide", "03\345\217\267\346\210\277\351\227\264", nullptr));
        transAccurate_dormitory->setItemText(4, QApplication::translate("campusGuide", "04\345\217\267\346\210\277\351\227\264", nullptr));
        transAccurate_dormitory->setItemText(5, QApplication::translate("campusGuide", "05\345\217\267\346\210\277\351\227\264", nullptr));
        transAccurate_dormitory->setItemText(6, QApplication::translate("campusGuide", "06\345\217\267\346\210\277\351\227\264", nullptr));
        transAccurate_dormitory->setItemText(7, QApplication::translate("campusGuide", "07\345\217\267\346\210\277\351\227\264", nullptr));
        transAccurate_dormitory->setItemText(8, QApplication::translate("campusGuide", "08\345\217\267\346\210\277\351\227\264", nullptr));
        transAccurate_dormitory->setItemText(9, QApplication::translate("campusGuide", "09\345\217\267\346\210\277\351\227\264", nullptr));
        transAccurate_dormitory->setItemText(10, QApplication::translate("campusGuide", "10\345\217\267\346\210\277\351\227\264", nullptr));
        transAccurate_dormitory->setItemText(11, QApplication::translate("campusGuide", "11\345\217\267\346\210\277\351\227\264", nullptr));
        transAccurate_dormitory->setItemText(12, QApplication::translate("campusGuide", "12\345\217\267\346\210\277\351\227\264", nullptr));
        transAccurate_dormitory->setItemText(13, QApplication::translate("campusGuide", "13\345\217\267\346\210\277\351\227\264", nullptr));
        transAccurate_dormitory->setItemText(14, QApplication::translate("campusGuide", "14\345\217\267\346\210\277\351\227\264", nullptr));
        transAccurate_dormitory->setItemText(15, QApplication::translate("campusGuide", "15\345\217\267\346\210\277\351\227\264", nullptr));
        transAccurate_dormitory->setItemText(16, QApplication::translate("campusGuide", "16\345\217\267\346\210\277\351\227\264", nullptr));
        transAccurate_dormitory->setItemText(17, QApplication::translate("campusGuide", "17\345\217\267\346\210\277\351\227\264", nullptr));
        transAccurate_dormitory->setItemText(18, QApplication::translate("campusGuide", "18\345\217\267\346\210\277\351\227\264", nullptr));
        transAccurate_dormitory->setItemText(19, QApplication::translate("campusGuide", "19\345\217\267\346\210\277\351\227\264", nullptr));
        transAccurate_dormitory->setItemText(20, QApplication::translate("campusGuide", "20\345\217\267\346\210\277\351\227\264", nullptr));
        transAccurate_dormitory->setItemText(21, QApplication::translate("campusGuide", "21\345\217\267\346\210\277\351\227\264", nullptr));
        transAccurate_dormitory->setItemText(22, QApplication::translate("campusGuide", "22\345\217\267\346\210\277\351\227\264", nullptr));

        groupBox_dst->setTitle(QString());
        dstAccurate_academic->setItemText(0, QApplication::translate("campusGuide", "\346\245\274\351\201\223", nullptr));
        dstAccurate_academic->setItemText(1, QApplication::translate("campusGuide", "01\345\217\267\346\225\231\345\256\244", nullptr));
        dstAccurate_academic->setItemText(2, QApplication::translate("campusGuide", "02\345\217\267\346\225\231\345\256\244", nullptr));
        dstAccurate_academic->setItemText(3, QApplication::translate("campusGuide", "03\345\217\267\346\225\231\345\256\244", nullptr));
        dstAccurate_academic->setItemText(4, QApplication::translate("campusGuide", "04\345\217\267\346\225\231\345\256\244", nullptr));
        dstAccurate_academic->setItemText(5, QApplication::translate("campusGuide", "05\345\217\267\346\225\231\345\256\244", nullptr));
        dstAccurate_academic->setItemText(6, QApplication::translate("campusGuide", "06\345\217\267\346\225\231\345\256\244", nullptr));
        dstAccurate_academic->setItemText(7, QApplication::translate("campusGuide", "07\345\217\267\346\225\231\345\256\244", nullptr));
        dstAccurate_academic->setItemText(8, QApplication::translate("campusGuide", "08\345\217\267\346\225\231\345\256\244", nullptr));
        dstAccurate_academic->setItemText(9, QApplication::translate("campusGuide", "\347\224\267\345\216\225", nullptr));
        dstAccurate_academic->setItemText(10, QApplication::translate("campusGuide", "\345\245\263\345\216\225", nullptr));
        dstAccurate_academic->setItemText(11, QApplication::translate("campusGuide", "11\345\217\267\346\225\231\347\240\224\345\256\244", nullptr));
        dstAccurate_academic->setItemText(12, QApplication::translate("campusGuide", "12\345\217\267\346\225\231\347\240\224\345\256\244", nullptr));
        dstAccurate_academic->setItemText(13, QApplication::translate("campusGuide", "13\345\217\267\345\212\236\345\205\254\345\256\244", nullptr));
        dstAccurate_academic->setItemText(14, QApplication::translate("campusGuide", "14\345\217\267\345\212\236\345\205\254\345\256\244", nullptr));
        dstAccurate_academic->setItemText(15, QApplication::translate("campusGuide", "15\345\217\267\345\274\200\346\260\264\351\227\264", nullptr));
        dstAccurate_academic->setItemText(16, QApplication::translate("campusGuide", "16\345\217\267\344\274\232\350\256\256\345\256\244", nullptr));

        dstAccurate_dormitory->setItemText(0, QApplication::translate("campusGuide", "\347\224\265\346\242\257\345\217\243", nullptr));
        dstAccurate_dormitory->setItemText(1, QApplication::translate("campusGuide", "01\345\217\267\346\210\277\351\227\264", nullptr));
        dstAccurate_dormitory->setItemText(2, QApplication::translate("campusGuide", "02\345\217\267\346\210\277\351\227\264", nullptr));
        dstAccurate_dormitory->setItemText(3, QApplication::translate("campusGuide", "03\345\217\267\346\210\277\351\227\264", nullptr));
        dstAccurate_dormitory->setItemText(4, QApplication::translate("campusGuide", "04\345\217\267\346\210\277\351\227\264", nullptr));
        dstAccurate_dormitory->setItemText(5, QApplication::translate("campusGuide", "05\345\217\267\346\210\277\351\227\264", nullptr));
        dstAccurate_dormitory->setItemText(6, QApplication::translate("campusGuide", "06\345\217\267\346\210\277\351\227\264", nullptr));
        dstAccurate_dormitory->setItemText(7, QApplication::translate("campusGuide", "07\345\217\267\346\210\277\351\227\264", nullptr));
        dstAccurate_dormitory->setItemText(8, QApplication::translate("campusGuide", "08\345\217\267\346\210\277\351\227\264", nullptr));
        dstAccurate_dormitory->setItemText(9, QApplication::translate("campusGuide", "09\345\217\267\346\210\277\351\227\264", nullptr));
        dstAccurate_dormitory->setItemText(10, QApplication::translate("campusGuide", "10\345\217\267\346\210\277\351\227\264", nullptr));
        dstAccurate_dormitory->setItemText(11, QApplication::translate("campusGuide", "11\345\217\267\346\210\277\351\227\264", nullptr));
        dstAccurate_dormitory->setItemText(12, QApplication::translate("campusGuide", "12\345\217\267\346\210\277\351\227\264", nullptr));
        dstAccurate_dormitory->setItemText(13, QApplication::translate("campusGuide", "13\345\217\267\346\210\277\351\227\264", nullptr));
        dstAccurate_dormitory->setItemText(14, QApplication::translate("campusGuide", "14\345\217\267\346\210\277\351\227\264", nullptr));
        dstAccurate_dormitory->setItemText(15, QApplication::translate("campusGuide", "15\345\217\267\346\210\277\351\227\264", nullptr));
        dstAccurate_dormitory->setItemText(16, QApplication::translate("campusGuide", "16\345\217\267\346\210\277\351\227\264", nullptr));
        dstAccurate_dormitory->setItemText(17, QApplication::translate("campusGuide", "17\345\217\267\346\210\277\351\227\264", nullptr));
        dstAccurate_dormitory->setItemText(18, QApplication::translate("campusGuide", "18\345\217\267\346\210\277\351\227\264", nullptr));
        dstAccurate_dormitory->setItemText(19, QApplication::translate("campusGuide", "19\345\217\267\346\210\277\351\227\264", nullptr));
        dstAccurate_dormitory->setItemText(20, QApplication::translate("campusGuide", "20\345\217\267\346\210\277\351\227\264", nullptr));
        dstAccurate_dormitory->setItemText(21, QApplication::translate("campusGuide", "21\345\217\267\346\210\277\351\227\264", nullptr));
        dstAccurate_dormitory->setItemText(22, QApplication::translate("campusGuide", "22\345\217\267\346\210\277\351\227\264", nullptr));

        comboBox_strategy->setItemText(0, QApplication::translate("campusGuide", "\346\234\200\347\237\255\350\267\235\347\246\273", nullptr));
        comboBox_strategy->setItemText(1, QApplication::translate("campusGuide", "\346\234\200\347\237\255\346\227\266\351\227\264", nullptr));
        comboBox_strategy->setItemText(2, QApplication::translate("campusGuide", "\346\234\200\347\237\255\350\267\235\347\246\273(\351\200\224\345\276\204\346\237\220\345\234\260)", nullptr));
        comboBox_strategy->setItemText(3, QApplication::translate("campusGuide", "\346\234\200\347\237\255\346\227\266\351\227\264(\346\240\241\345\206\205\345\217\257\351\200\211\344\272\244\351\200\232\345\267\245\345\205\267)", nullptr));

        make->setText(QApplication::translate("campusGuide", "\345\210\266\345\256\232\350\267\257\347\272\277", nullptr));
        dstChange->setText(QApplication::translate("campusGuide", "\345\210\207\346\215\242\347\233\256\347\232\204\345\234\260", nullptr));
        strategyChange->setText(QApplication::translate("campusGuide", "\345\210\207\346\215\242\350\241\214\350\277\233\347\255\226\347\225\245", nullptr));
        logout->setText(QApplication::translate("campusGuide", "\346\263\250\351\224\200", nullptr));
        label->setText(QApplication::translate("campusGuide", "\350\267\257\347\272\277", nullptr));
        start->setText(QApplication::translate("campusGuide", "\345\274\200\345\247\213\345\257\274\350\210\252", nullptr));
        pause->setText(QApplication::translate("campusGuide", "\346\232\202\345\201\234", nullptr));
        mapChange->setText(QApplication::translate("campusGuide", "\345\210\207\346\215\242\345\234\260\345\233\276", nullptr));
        textBrowser->setHtml(QApplication::translate("campusGuide", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/image/[map]shahe.png\" /></p></body></html>", nullptr));
        label_8->setText(QApplication::translate("campusGuide", "\347\224\250\346\210\267\345\201\217\345\245\275", nullptr));
        checkBox_accurate->setText(QApplication::translate("campusGuide", "\347\262\276\347\241\256\345\210\266\345\257\274", nullptr));
        checkBox_talk->setText(QApplication::translate("campusGuide", "\350\257\255\351\237\263\346\222\255\346\212\245", nullptr));
        label_7->setText(QApplication::translate("campusGuide", "\346\237\245\350\257\242\345\273\272\347\255\221   ", nullptr));
        searchName->setText(QApplication::translate("campusGuide", "\350\214\203\345\233\264\345\206\205\346\211\200\346\234\211", nullptr));
        label_3->setText(QApplication::translate("campusGuide", "\346\237\245\350\257\242\345\215\212\345\276\204(m)", nullptr));
        search->setText(QApplication::translate("campusGuide", "\346\237\245\350\257\242\345\221\250\350\276\271\345\273\272\347\255\221", nullptr));
    } // retranslateUi

};

namespace Ui {
    class campusGuide: public Ui_campusGuide {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMPUSGUIDE_H
