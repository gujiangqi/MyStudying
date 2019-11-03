#ifndef _SPIDERAPP_H_
#define _SPIDERAPP_H_

#define CONF_PATH "spider.conf"

class SpiderApp
{
public:// for class
	SpiderApp();
	~SpiderApp();
public:
	// init environment
	// return:1 OK 0 ERR
	int initApp(int argc, char* argv[]);
	// main process 
	int run();
	// jiang chengxu anzhao shouhu jincheng fangshi yunxing 
	int deamon();

private:
	int initArgv(int argc,char*argv[]);

private:
	int isDeamon;  // is shouhu process mode
};

#endif
