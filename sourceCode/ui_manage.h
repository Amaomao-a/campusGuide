/********************************************************************************
** Form generated from reading UI file 'manage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGE_H
#define UI_MANAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_manage
{
public:
    QStackedWidget *stackedWidget;
    QWidget *LoginPage;
    QLabel *label_bgp;
    QWidget *layoutWidget;
    QGridLayout *layout;
    QCheckBox *autoLogin;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QPushButton *regi;
    QLineEdit *lineEdit_passwd;
    QCheckBox *remPasswd;
    QLabel *label_pwd;
    QPushButton *help;
    QPushButton *fw;
    QPushButton *login;
    QLabel *label_12;
    QWidget *RegisterPage;
    QLabel *label_bgp_2;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout;
    QLineEdit *RP_pwdConfirm;
    QPushButton *RP_back;
    QLineEdit *RP_name;
    QLineEdit *RP_pwd;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *RP_note;
    QPushButton *RP_Register;
    QWidget *ForgetPage;
    QLabel *label_5;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QLineEdit *FP_note;
    QLabel *label_8;
    QLineEdit *FP_newPWD;
    QLineEdit *FP_pwdConfirm;
    QLineEdit *FP_name;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout;
    QPushButton *FP_back;
    QPushButton *FP_reset;

    void setupUi(QWidget *manage)
    {
        if (manage->objectName().isEmpty())
            manage->setObjectName(QString::fromUtf8("manage"));
        manage->resize(501, 632);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/exe.ico"), QSize(), QIcon::Normal, QIcon::Off);
        manage->setWindowIcon(icon);
        stackedWidget = new QStackedWidget(manage);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 551, 631));
        stackedWidget->setStyleSheet(QString::fromUtf8("font: 9pt \"Sarasa Term SC\";"));
        LoginPage = new QWidget();
        LoginPage->setObjectName(QString::fromUtf8("LoginPage"));
        label_bgp = new QLabel(LoginPage);
        label_bgp->setObjectName(QString::fromUtf8("label_bgp"));
        label_bgp->setGeometry(QRect(0, -330, 501, 971));
        label_bgp->setPixmap(QPixmap(QString::fromUtf8(":/image/bupt_4.jpg")));
        label_bgp->setScaledContents(true);
        label_bgp->setIndent(-1);
        layoutWidget = new QWidget(LoginPage);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 270, 453, 188));
        layout = new QGridLayout(layoutWidget);
        layout->setObjectName(QString::fromUtf8("layout"));
        layout->setContentsMargins(0, 0, 0, 0);
        autoLogin = new QCheckBox(layoutWidget);
        autoLogin->setObjectName(QString::fromUtf8("autoLogin"));
        autoLogin->setStyleSheet(QString::fromUtf8("color:white"));

        layout->addWidget(autoLogin, 2, 2, 1, 1);

        label_name = new QLabel(layoutWidget);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setStyleSheet(QString::fromUtf8("font: 9pt \"Sarasa Term SC\";\n"
"color:white;"));

        layout->addWidget(label_name, 0, 0, 1, 1);

        lineEdit_name = new QLineEdit(layoutWidget);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	border:1px rgb(170,170,255);\n"
"	background-color: rgba(170, 170, 255, 0);\n"
"	padding:1px 2px;\n"
"	border-style: solid;\n"
"	font-size : 15px ;\n"
"	font: 10pt \"Sarasa Term SC\";\n"
"	color: black;\n"
"}\n"
""));

        layout->addWidget(lineEdit_name, 0, 1, 1, 2);

        regi = new QPushButton(layoutWidget);
        regi->setObjectName(QString::fromUtf8("regi"));
        regi->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #555555;\n"
"    border-radius: 8px;\n"
"    padding: 6px 12px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    font-size: 12px;\n"
"	font: 9pt \"Sarasa Term SC\";\n"
"    margin: 4px 2px;\n"
"    color: white;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: white;\n"
"    color: brown\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #06AD56;\n"
"}"));

        layout->addWidget(regi, 0, 3, 1, 1);

        lineEdit_passwd = new QLineEdit(layoutWidget);
        lineEdit_passwd->setObjectName(QString::fromUtf8("lineEdit_passwd"));
        lineEdit_passwd->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	border:1px rgb(170,170,255);\n"
"\n"
"	background-color: rgba(170, 170, 255, 0);\n"
"	padding:1px 2px;\n"
"	border-style: solid;\n"
"	font-size : 15px ;\n"
"	font: 10pt \"Sarasa Term SC\";\n"
"	color: white;\n"
"}\n"
""));

        layout->addWidget(lineEdit_passwd, 1, 1, 1, 2);

        remPasswd = new QCheckBox(layoutWidget);
        remPasswd->setObjectName(QString::fromUtf8("remPasswd"));
        remPasswd->setStyleSheet(QString::fromUtf8("color:white\n"
""));

        layout->addWidget(remPasswd, 2, 1, 1, 1);

        label_pwd = new QLabel(layoutWidget);
        label_pwd->setObjectName(QString::fromUtf8("label_pwd"));
        label_pwd->setStyleSheet(QString::fromUtf8("font: 9pt \"Sarasa Term SC\";\n"
"color:white;"));

        layout->addWidget(label_pwd, 1, 0, 1, 1);

        help = new QPushButton(layoutWidget);
        help->setObjectName(QString::fromUtf8("help"));
        help->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #00916a;\n"
"    border-radius: 8px;\n"
"    padding: 6px 12px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    font-size: 12px;\n"
"	font: 9pt \"Sarasa Term SC\";\n"
"    margin: 4px 2px;\n"
"    color: white;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: white;\n"
"    color: brown\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #06AD56;\n"
"}"));

        layout->addWidget(help, 2, 3, 1, 1);

        fw = new QPushButton(layoutWidget);
        fw->setObjectName(QString::fromUtf8("fw"));
        fw->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #555555;\n"
"    border-radius: 8px;\n"
"    padding: 6px 12px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    font-size: 12px;\n"
"	font: 9pt \"Sarasa Term SC\";\n"
"    margin: 4px 2px;\n"
"    color: white;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: white;\n"
"    color: brown\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #06AD56;\n"
"}"));

        layout->addWidget(fw, 1, 3, 1, 1);

        login = new QPushButton(layoutWidget);
        login->setObjectName(QString::fromUtf8("login"));
        login->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-radius: 8px;\n"
"    color: #8d8dd3;\n"
"    padding: 8px 16px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    font-size: 16px;\n"
"    margin: 4px 2px;\n"
"    background-color: white;\n"
"    color: black;\n"
"    border: 2px solid #51f3f3;\n"
"}\n"
"QPushButton:hover {\n"
"    color: red;\n"
"	background-color: #a5a5f7\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #06AD56;\n"
"}"));

        layout->addWidget(login, 3, 1, 1, 2);

        label_12 = new QLabel(LoginPage);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(140, 170, 231, 51));
        label_12->setStyleSheet(QString::fromUtf8("font: 22pt \"Sarasa Term SC\";\n"
"color:black;"));
        stackedWidget->addWidget(LoginPage);
        RegisterPage = new QWidget();
        RegisterPage->setObjectName(QString::fromUtf8("RegisterPage"));
        label_bgp_2 = new QLabel(RegisterPage);
        label_bgp_2->setObjectName(QString::fromUtf8("label_bgp_2"));
        label_bgp_2->setGeometry(QRect(-10, -10, 581, 971));
        label_bgp_2->setPixmap(QPixmap(QString::fromUtf8(":/image/bupt_4.jpg")));
        label_bgp_2->setScaledContents(true);
        layoutWidget_2 = new QWidget(RegisterPage);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(120, 200, 241, 161));
        gridLayout = new QGridLayout(layoutWidget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        RP_pwdConfirm = new QLineEdit(layoutWidget_2);
        RP_pwdConfirm->setObjectName(QString::fromUtf8("RP_pwdConfirm"));

        gridLayout->addWidget(RP_pwdConfirm, 2, 2, 1, 1);

        RP_back = new QPushButton(layoutWidget_2);
        RP_back->setObjectName(QString::fromUtf8("RP_back"));
        RP_back->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: #aaaa7f;\n"
"    border-radius: 8px;\n"
"    padding: 2px 4px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    font-size: 12px;\n"
"	font: 10pt \"Sarasa Term SC\";\n"
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

        gridLayout->addWidget(RP_back, 4, 0, 1, 1);

        RP_name = new QLineEdit(layoutWidget_2);
        RP_name->setObjectName(QString::fromUtf8("RP_name"));

        gridLayout->addWidget(RP_name, 0, 2, 1, 1);

        RP_pwd = new QLineEdit(layoutWidget_2);
        RP_pwd->setObjectName(QString::fromUtf8("RP_pwd"));

        gridLayout->addWidget(RP_pwd, 1, 2, 1, 1);

        label_4 = new QLabel(layoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 10pt \"Sarasa Term SC\";"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 10pt \"Sarasa Term SC\";"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label = new QLabel(layoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 10pt \"Sarasa Term SC\";"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 10pt \"Sarasa Term SC\";"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        RP_note = new QLineEdit(layoutWidget_2);
        RP_note->setObjectName(QString::fromUtf8("RP_note"));

        gridLayout->addWidget(RP_note, 3, 2, 1, 1);

        RP_Register = new QPushButton(layoutWidget_2);
        RP_Register->setObjectName(QString::fromUtf8("RP_Register"));
        RP_Register->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: #d5d500;\n"
"    border-radius: 8px;\n"
"    padding: 2px 4px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    font-size: 12px;\n"
"	font: 10pt \"Sarasa Term SC\";\n"
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

        gridLayout->addWidget(RP_Register, 4, 2, 1, 1);

        stackedWidget->addWidget(RegisterPage);
        ForgetPage = new QWidget();
        ForgetPage->setObjectName(QString::fromUtf8("ForgetPage"));
        label_5 = new QLabel(ForgetPage);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(-580, -40, 1361, 811));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/image/bupt_4.jpg")));
        label_5->setScaledContents(false);
        layoutWidget1 = new QWidget(ForgetPage);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(153, 205, 261, 171));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        FP_note = new QLineEdit(layoutWidget1);
        FP_note->setObjectName(QString::fromUtf8("FP_note"));

        gridLayout_2->addWidget(FP_note, 1, 1, 1, 1);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("font: 10pt \"Sarasa Term SC\";"));

        gridLayout_2->addWidget(label_8, 1, 0, 1, 1);

        FP_newPWD = new QLineEdit(layoutWidget1);
        FP_newPWD->setObjectName(QString::fromUtf8("FP_newPWD"));

        gridLayout_2->addWidget(FP_newPWD, 2, 1, 1, 1);

        FP_pwdConfirm = new QLineEdit(layoutWidget1);
        FP_pwdConfirm->setObjectName(QString::fromUtf8("FP_pwdConfirm"));

        gridLayout_2->addWidget(FP_pwdConfirm, 3, 1, 1, 1);

        FP_name = new QLineEdit(layoutWidget1);
        FP_name->setObjectName(QString::fromUtf8("FP_name"));

        gridLayout_2->addWidget(FP_name, 0, 1, 1, 1);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("font: 10pt \"Sarasa Term SC\";"));

        gridLayout_2->addWidget(label_6, 3, 0, 1, 1);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("font: 10pt \"Sarasa Term SC\";"));

        gridLayout_2->addWidget(label_7, 2, 0, 1, 1);

        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setStyleSheet(QString::fromUtf8("font: 10pt \"Sarasa Term SC\";"));

        gridLayout_2->addWidget(label_9, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        FP_back = new QPushButton(layoutWidget1);
        FP_back->setObjectName(QString::fromUtf8("FP_back"));
        FP_back->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: #55aaff;\n"
"    border-radius: 8px;\n"
"    padding: 2px 4px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    font-size: 12px;\n"
"	font: 10pt \"Sarasa Term SC\";\n"
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

        horizontalLayout->addWidget(FP_back);

        FP_reset = new QPushButton(layoutWidget1);
        FP_reset->setObjectName(QString::fromUtf8("FP_reset"));
        FP_reset->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: #ffaa7f;\n"
"    border-radius: 8px;\n"
"    padding: 2px 4px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    font-size: 12px;\n"
"	font: 10pt \"Sarasa Term SC\";\n"
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

        horizontalLayout->addWidget(FP_reset);


        gridLayout_2->addLayout(horizontalLayout, 4, 1, 1, 1);

        stackedWidget->addWidget(ForgetPage);
        QWidget::setTabOrder(lineEdit_name, lineEdit_passwd);
        QWidget::setTabOrder(lineEdit_passwd, login);
        QWidget::setTabOrder(login, regi);
        QWidget::setTabOrder(regi, fw);
        QWidget::setTabOrder(fw, help);
        QWidget::setTabOrder(help, remPasswd);
        QWidget::setTabOrder(remPasswd, autoLogin);
        QWidget::setTabOrder(autoLogin, RP_name);
        QWidget::setTabOrder(RP_name, RP_pwd);
        QWidget::setTabOrder(RP_pwd, FP_name);
        QWidget::setTabOrder(FP_name, FP_note);
        QWidget::setTabOrder(FP_note, FP_newPWD);
        QWidget::setTabOrder(FP_newPWD, FP_pwdConfirm);
        QWidget::setTabOrder(FP_pwdConfirm, FP_back);
        QWidget::setTabOrder(FP_back, RP_pwdConfirm);
        QWidget::setTabOrder(RP_pwdConfirm, RP_note);

        retranslateUi(manage);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(manage);
    } // setupUi

    void retranslateUi(QWidget *manage)
    {
        manage->setWindowTitle(QApplication::translate("manage", "\346\240\241\345\233\255\345\257\274\350\247\210\347\263\273\347\273\237", nullptr));
        label_bgp->setText(QString());
        autoLogin->setText(QApplication::translate("manage", "\350\207\252\345\212\250\347\231\273\345\275\225", nullptr));
        label_name->setText(QApplication::translate("manage", "\347\224\250\346\210\267\345\220\215(Name)", nullptr));
        lineEdit_name->setText(QString());
        regi->setText(QApplication::translate("manage", "\346\263\250\345\206\214\350\264\246\345\217\267", nullptr));
        remPasswd->setText(QApplication::translate("manage", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        label_pwd->setText(QApplication::translate("manage", "\345\257\206\347\240\201(Password)", nullptr));
        help->setText(QApplication::translate("manage", "\347\224\250\346\210\267\346\211\213\345\206\214", nullptr));
        fw->setText(QApplication::translate("manage", "\351\207\215\347\275\256\345\257\206\347\240\201", nullptr));
        login->setText(QApplication::translate("manage", "\347\231\273\345\275\225", nullptr));
        label_12->setText(QApplication::translate("manage", "\346\240\241\345\233\255\345\257\274\350\247\210\347\263\273\347\273\237", nullptr));
        label_bgp_2->setText(QString());
        RP_back->setText(QApplication::translate("manage", "\350\277\224\345\233\236", nullptr));
        label_4->setText(QApplication::translate("manage", "\346\217\220\347\244\272", nullptr));
        label_3->setText(QApplication::translate("manage", "\345\257\206\347\240\201\347\241\256\350\256\244", nullptr));
        label->setText(QApplication::translate("manage", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QApplication::translate("manage", "\345\257\206\347\240\201", nullptr));
        RP_Register->setText(QApplication::translate("manage", "\346\263\250\345\206\214", nullptr));
        label_5->setText(QString());
        label_8->setText(QApplication::translate("manage", "\346\217\220\347\244\272", nullptr));
        label_6->setText(QApplication::translate("manage", "\345\257\206\347\240\201\347\241\256\350\256\244", nullptr));
        label_7->setText(QApplication::translate("manage", "\346\226\260\345\257\206\347\240\201", nullptr));
        label_9->setText(QApplication::translate("manage", "\347\224\250\346\210\267\345\220\215", nullptr));
        FP_back->setText(QApplication::translate("manage", "\350\277\224\345\233\236", nullptr));
        FP_reset->setText(QApplication::translate("manage", "\351\207\215\347\275\256\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class manage: public Ui_manage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGE_H
