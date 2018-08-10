#include <psp2/kernel/processmgr.h>
#include <sstream>
#include <vector>
#include <string>
#include <cstdio>
#include <map>
#include "app.h"
#include "widgets/background.h"
#include "widgets/statusBar.h"

int main(int argc, char *argv[]) {
  auto app = App();
  app.showSplashScreen();
  auto bg = std::make_shared<Background>();
  app.AddView(bg);
  auto sb = std::make_shared<StatusBar>();
  app.AddView(sb);

  app.start();
  return 0;
}
