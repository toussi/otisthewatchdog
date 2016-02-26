#include "verticalbox.h"
#include "buttons.h"
#include "wDogFunctions.h"
#include "spinbox.h"
#include "countdown.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QObject>
#include <QDebug>
#include <QPropertyAnimation>

VerticalBox::VerticalBox(QWidget *parent)
    : QWidget(parent)
{
  /* timer section*/
  iTimer = new QTimer(this);
  i = 2;

  QVBoxLayout *vbox = new QVBoxLayout(this);
  QHBoxLayout *hbox = new QHBoxLayout();

  vbox->setSpacing(1);

  //widget for the buttons
  btns = new Buttons(this);
  btns->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);


  //all the text
  topLabel = new QLabel();
  QString message1 = "Watchdog is set to:   ";
  QString minutes = QString::number(getWDogTimeLimit());
  message1.append(minutes);
  message1.append(" seconds");
  topLabel->setText(message1);

  //widget for the spinbox setting
  integerSpinBox = new QSpinBox;
  integerSpinBox->setMinimum(2);
  integerSpinBox->setMaximum(100);
  integerSpinBox->setSuffix(" seconds");

  //label to go with the spinbox
  midLabel = new QLabel();
  QString message2 = "Kick timer every: ";
  midLabel->setText(message2);

  //add widgets to hbox
  hbox->addWidget(midLabel, 0, Qt::AlignLeft);
  hbox->addWidget(integerSpinBox, 1, Qt::AlignLeft);

  //layout all the widgets
  vbox->addWidget(topLabel, 0, Qt::AlignTop);
  vbox->addLayout(hbox); //hbox in the middle
  vbox->addWidget(btns, 1, Qt::AlignBottom);

  //When the iTimer times out
  connect(this->iTimer, SIGNAL(timeout()), btns, SLOT(kickTheDog()));
  connect(this->iTimer, SIGNAL(timeout()), this, SLOT(timedOut()));

  //When the spinbox is touched
  connect(this->integerSpinBox, SIGNAL(valueChanged(int)), this, SLOT(stopTimer()));
  connect(this->integerSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setTimerValue(int)));

  //When 'Enable' is pressed
  connect(btns, SIGNAL(signalBtnEnable()), this, SLOT(greyOutSpinBox()));
  connect(btns, SIGNAL(signalBtnEnable()), this, SLOT(startTimer()));

  //When 'Kick' is pressed
  connect(btns, SIGNAL(signalBtnKick()), this, SLOT(startTimer()));

  //final layout set
  setLayout(vbox);

}

void VerticalBox::startTimer() {
  qDebug() << "Timer has been started";
  qDebug() << "Timing out every " << i << " seconds";
  iTimer->start(i * 1000);
}

void VerticalBox::stopTimer() {
  qDebug() << "Timer has been stopped";
  iTimer->stop();
}

void VerticalBox::setTimerValue(int seconds) {
    i = seconds;
}

void VerticalBox::timedOut(){
    qDebug() << "iTimer just timed out";
}

void VerticalBox::greyOutSpinBox() {
    integerSpinBox->setDisabled(1);
}
