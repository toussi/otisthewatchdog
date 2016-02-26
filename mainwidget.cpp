#include "mainwidget.h"
#include "verticalbox.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

mainWidget::mainWidget(QWidget *parent) :
    QWidget(parent)
{

    QHBoxLayout *hbox = new QHBoxLayout();

    QWidget *widg = new QWidget();
    widg->setStyleSheet("image: url(:/puppy2.gif); image-position: bottom right;");
    widg->setFixedHeight(90);

    QVBoxLayout *vbox = new QVBoxLayout(this);
    vbox->setSpacing(1);

    //add the vertical box
    vertBox = new VerticalBox(this);
    vbox->addWidget(vertBox, Qt::AlignRight);
    hbox->addWidget(widg);
    vbox->addLayout(hbox);

    layout()->setContentsMargins(0,0,0,0);
}
