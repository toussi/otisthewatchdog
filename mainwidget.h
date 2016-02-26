#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QLabel>
#include "verticalbox.h"

class mainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit mainWidget(QWidget *parent = 0);
    VerticalBox *vertBox;
    QWidget *pic;

signals:

};

#endif // MAINWIDGET_H
