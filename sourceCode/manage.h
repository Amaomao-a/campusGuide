#ifndef MANAGE_H
#define MANAGE_H

#include <QWidget>
#include <QWizard>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QPixmap>
#include <QHBoxLayout>
#include <QSettings>
#include <QMessageBox>

#include "guide.h"
#include "campusguide.h"
#include "ui_campusguide.h"

namespace Ui {
class manage;
}

class manage : public QWidget
{
    Q_OBJECT

public:
    explicit manage(QWidget *parent = nullptr);
    ~manage();

    void saveCfg();
    void loadCfg();
    void uiSetLoad();

    QWizardPage *createPage1();
    QWizardPage *createPage2();
    QWizardPage *createPage3();
    QWizardPage *createPage4();

signals:
    void autoLogin();               // 自动登录信号
    void enterMainWindow();  // 登录进入主窗口

private slots:
    void switchPage();

    void on_help_clicked();
    void on_login_clicked();
    void on_FP_reset_clicked();
    void on_FP_back_clicked();
    void on_RP_Register_clicked();
    void on_RP_back_clicked();

    void on_autoLogin_stateChanged(int arg1);
    void on_remPasswd_stateChanged(int arg1);

private:
    Ui::manage *ui;
    campusGuide mainwindow;
};

#endif // MANAGE_H
