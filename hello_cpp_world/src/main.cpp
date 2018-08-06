#include <psp2/kernel/processmgr.h>
#include <sstream>
#include <vector>
#include <string>
#include <cstdio>
#include <map>
#include "app.h"

int main(int argc, char *argv[]) {
  App();
  sceKernelDelayThread(20*1000*1000);
  sceKernelExitProcess(0);
  return 0;
}
