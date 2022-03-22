#include "dialog.h"

Dialog::Dialog(QWidget *parent):
    QDialog (parent)
{
    label = new QLabel(this);
    this->setFixedSize(200,200);
    this->setWindowOpacity(0.8);
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    this->setStyleSheet("background-color:transparent;");

    background = new QFrame(this);
    background->setStyleSheet("background-color: rgb(55, 135,215);border-radius:10px;");
    background->setGeometry(0, 0, 200, 200);

    label = new QLabel(background);
    label->setStyleSheet("background-color:transparent;");
    label->setGeometry(60,30,80,80);
    movie = new QMovie(":/image/loading2.gif");
    label->setScaledContents(true);
    label->setMovie(movie);

    tip_label = new QLabel(background);
    tip_label->setText("正在校区间移动......");
    tip_label->setStyleSheet("color:white; background-color:transparent;");
    tip_label->setGeometry(20,140,160,40);
    movie->start();
}

Dialog::~Dialog()
{

}

void Dialog::dialogDestroy()
{
    delete label;
    delete movie;
    delete tip_label;
    delete background;
}
