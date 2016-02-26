#include "labelwidget.h"

LabelWidget::LabelWidget(QWidget *parent) :
    QWidget(parent)
{

    fadingLabel = new QLabel();
    QString fadingMsg = "Timer stopped!.";
    fadingLabel->setText(fadingMsg);

}
