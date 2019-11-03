/* main programme */

#include <spiderApp.h>
#include <spider.h>

int main(int argc, char* argv[])
{
	/* init main */
	SpiderApp app;
	if(app.initApp(argc, argv) == 0)
	{
		SPIDER_LOG(SPIDER_LEVEL_ERROR, "app init is failed!, app has exited ");
		return 0
	};

	/* begin main process */
	if(app.run() == 0)
	{
		SPIDER_LOG(SPIDER_LEVEL_ERROR, "app run is failed!, app has exited ");
	};

	return 0;
}
