#include <psp2/kernel/processmgr.h>
#include <sstream>
#include <vector>
#include <string>
#include <cstdio>
#include <map>
#include "app.h"
#include "Views/background.h"

int main(int argc, char *argv[]) {
  auto app = App();
  app.showSplashScreen();
  auto mainView = std::make_shared<Background>();
  app.AddView(mainView);

  app.start();
  return 0;
}
