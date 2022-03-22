#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFrame>
#include <QMovie>
#include <QPainter>
#include <QLabel>

class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent=0);
    ~Dialog();

public slots:
    void dialogDestroy();

private:
    QMovie *movie;
    QLabel *label;
    QLabel *tip_label;
    QFrame *background;
};

#endif // DIALOG_H
