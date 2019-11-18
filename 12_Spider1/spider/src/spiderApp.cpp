#include "spiderApp.h"
#include "spider.h"
#include "confparser.h"

SpiderApp::SpiderApp()
{
}

SpiderApp::~SpiderApp()
{
}

int SpiderApp::initApp(int argc, char* argv[])
{
	/* */
	if(initArgv(int argc,char*argv[]));

	/* load conf file */	
	Confparser::instance()->loader(CONF_PATH);

	/* shi fou yi shouhu jincheng yunxing luoji*/
	if(isDeamon == 1)
	{
		this->deamon();
	}
	return 0;
}

int SpiderApp::run()
{
	/* wait */
	return 0;
}
int SpiderApp::deamon()
{
	return 0;
}
