#ifndef VERTICALBOX_H
#define VERTICALBOX_H

#include <QWidget>
#include <QLabel>
#include "spinbox.h"
#include "labelwidget.h"
#include <QPropertyAnimation>

class VerticalBox : public QWidget
{
    Q_OBJECT
public:
    explicit VerticalBox(QWidget *parent = 0);
    QWidget *btns;
    QLabel *topLabel;
    QLabel *midLabel;
    QSpinBox *integerSpinBox;
    QTimer *iTimer;
    QLabel *timeLabel;
    int i;

signals:

public slots:
    void startTimer();
    void stopTimer();
    void setTimerValue(int seconds);
    void timedOut();
    void greyOutSpinBox();
};

#endif // VERTICALBOX_H
