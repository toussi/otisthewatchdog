#ifndef LABELWIDGET_H
#define LABELWIDGET_H

#include <QWidget>
#include <QLabel>

class LabelWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LabelWidget(QWidget *parent = 0);
    QLabel *fadingLabel;

signals:

public slots:

};

#endif // LABELWIDGET_H
