#include <psp2/kernel/processmgr.h>
#include <sstream>
#include <vector>
#include <string>
#include <cstdio>
#include "debugScreen.h"


class DebugScreen {
public:
    DebugScreen() {
        psvDebugScreenInit();
    }

    void printf(const std::string& msg) {
        psvDebugScreenPrintf("%s\n", msg.c_str());
    }
};

int main(int argc, char *argv[]) {
	std::stringstream output;
	std::vector<std::string> hello = { "Hello" };
	hello.push_back(",");
	hello.push_back(" C++ ");
	hello.push_back("world!");
	for (auto &s : hello) {
		// std::cout does't work ATM :(
		output << s;
	}
    auto ds = new DebugScreen();
	output << std::endl;
    ds->printf(output.str());
    ds->printf("\e[10;20H TEST");

    sceKernelDelayThread(20*1000*1000);
	sceKernelExitProcess(0);
    return 0;
}
