#include "spider.h"
#include "spiderApp.h"
#include "confparser.h"
SpiderApp::SpiderApp()
{

}

SpiderApp::~SpiderApp()
{

}

int SpiderApp::initApp(int argc, char * argv[])
{
    if(initArgv(argc,argv) == -1)
    {

    }
    ConfigParser::instance()->loader(CONF_PATH);

    if(isDeamon() == 0)
    {
        this->deamon();
    }

    // load lib
    // wait complete

}

int SpiderApp::run()
{
    //

}

int SpiderApp::deamon()
{

}
