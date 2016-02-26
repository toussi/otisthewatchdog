#include "spinbox.h"
#include "buttons.h"

spinbox::spinbox(QWidget *parent) :
    QWidget(parent)
{
    integerSpinBox = new QSpinBox;
    integerSpinBox->setMinimum(0);
    integerSpinBox->setMaximum(100);
    integerSpinBox->setPrefix("seconds");

}

void spinbox::greyOutSpinBox() {
    integerSpinBox->setDisabled(1);
}
