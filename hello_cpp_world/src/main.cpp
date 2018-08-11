#include <psp2/kernel/processmgr.h>
#include <sstream>
#include <vector>
#include <string>
#include <cstdio>
#include <map>
#include "app.h"
#include "widgets/mainwindow.h"
#include "myappcentralwidget.h"

int main(int argc, char *argv[]) {
  auto app = App();

  auto mainWindow = std::make_shared<MainWindow>();
  auto centralWidget = std::make_shared<MyAppCentralWidget>(mainWindow.get());
  mainWindow->setCentralWidget(centralWidget.get());
  app.AddWindow(mainWindow);

  app.showSplashScreen();
  app.run();
  return 0;
}
