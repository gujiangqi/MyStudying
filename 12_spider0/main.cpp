#include <iostream>
#include "spiderApp.h"
using namespace std;

int main(int argc, char * argv[])
{
    SpiderApp app;
    if(app.initApp() == -1)
    {
        SPIDER_LOG(SPIDER_LEVER_ERROR,"app init is failed!, app exit\n");
        return -1;
    }

    // begin main run
    if(app.run() == -1)
    {
        SPIDER_LOG(SPIDER_LEVER_ERROR,"main process is failed!, app exit\n");
        return -1;

    }


    return 0;
}

