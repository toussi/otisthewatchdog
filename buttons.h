#ifndef BUTTONS_H
#define BUTTONS_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QProcess>
#include <QFile>

class Buttons : public QWidget
{
   Q_OBJECT

  public:
    Buttons(QWidget *parent = 0);
    QProcess process;


  private:
    QPushButton *btnKick;
    QPushButton *btnEnable;
    QLabel *buttonsLabel;

  public slots:
    void enableWasPressed();
    void kickTheDog();
    void ungreyEnableBtn();
    void greyEnableBtn();

  signals:
    void signalBtnEnable();
    void signalBtnKick();
};

#endif
