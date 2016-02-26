#ifndef SPINBOX_H
#define SPINBOX_H

#include <QWidget>
#include <QSpinBox>

class spinbox : public QWidget
{
    Q_OBJECT
public:
    explicit spinbox(QWidget *parent = 0);
    QSpinBox *integerSpinBox;

signals:

public slots:
    void greyOutSpinBox();

};

#endif // SPINBOX_H
