#include "mainwidget.h"
#include <QDesktopWidget>
#include <QApplication>
#include <centre.h>

/*  Class structure:  (child of -> parent)
  Buttons -> VerticalBox -> MainWidget -> main.cpp
*/

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  mainWidget window;

  window.setWindowTitle("Watchdog Testing Utility");
  window.show();
  centre(window);

  window.setStyleSheet("background-color: white;");

  return app.exec();
}
