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
  app.ShowSplashScreen();

  app.Start();
  return 0;
}
