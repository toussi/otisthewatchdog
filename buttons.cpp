#include "buttons.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QObject>
#include <QFile>
#include <QDebug>
#include <QMessageBox>


Buttons::Buttons(QWidget *parent)
    : QWidget(parent)
{
  QVBoxLayout *vbox = new QVBoxLayout(this);
  QHBoxLayout *hbox = new QHBoxLayout();

  btnKick = new QPushButton("Kick", this);
  btnEnable = new QPushButton("Enable", this);

  buttonsLabel = new QLabel;
  buttonsLabel->setText("Timer: ");

  hbox->addWidget(buttonsLabel, 3, Qt::AlignRight);
  hbox->addWidget(btnKick, 0, Qt::AlignRight);
  hbox->addWidget(btnEnable, 0, Qt::AlignRight);

  vbox->addStretch(1);
  vbox->addLayout(hbox, 1);

  //start off with btnDisable unclickable
  btnKick->setDisabled(1);

  //make connections
  connect(this->btnEnable, SIGNAL(clicked()), this, SLOT(enableWasPressed()));
  connect(this->btnKick, SIGNAL(clicked()), this, SLOT(kickTheDog()));

}

void Buttons::enableWasPressed() {
        QMessageBox msgBox;
        emit signalBtnEnable();
        btnEnable->setDisabled(1);
        btnKick->setEnabled(1);
        QFile file3("/dev/watchdog");
        if (file3.open(QFile::WriteOnly)) {
            QTextStream out3(&file3);
        } else {
            msgBox.setWindowTitle("Watchdog could not be started");
            msgBox.setText("Please check driver is installed and that the utility is being run with administrator privileges.");
            msgBox.exec();
        }
}

void Buttons::ungreyEnableBtn() {
        btnEnable->setEnabled(1);
}

void Buttons::greyEnableBtn() {
        btnEnable->setDisabled(1);
}

void Buttons::kickTheDog() {
        QMessageBox msgBox;
        emit signalBtnKick();   //resets iTimer only
        QFile file3("/dev/watchdog");
        if (file3.open(QFile::WriteOnly)) {
            QTextStream out3(&file3);
            out3 << 'a';
        }else{
            msgBox.setWindowTitle("Watchdog could not be kicked");
            msgBox.setText("Please check that the utility is being run with administrator privileges.");
            msgBox.exec();
        }
}

