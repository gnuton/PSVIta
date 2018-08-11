#include <psp2/kernel/processmgr.h>
#include <sstream>
#include <vector>
#include <string>
#include <cstdio>
#include <map>
#include "app.h"
#include "widgets/mainwindow.h"

int main(int argc, char *argv[]) {
  auto app = App();
  app.ShowSplashScreen();
  auto mainView = std::make_shared<MainWindow>();
  app.AddWindow(mainView);
  app.Start();
  return 0;
}
