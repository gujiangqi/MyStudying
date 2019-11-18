#ifndef SPIDERAPP_H
#define SPIDERAPP_H

#define CONF_PATH "spider.conf"

class SpiderApp
{
public:
    SpiderApp();  //
    ~SpiderApp(); // free all source
public:
    // init
    int initApp(int argc, char * argv[]);

    // 0:success ; -1:fail
    int run();
    // deamon() operator
    int  deamon();

private: //
    int initArgv(int argc,char *argv[]);

private:
    int isDeamon();

};

#endif // SPIDERAPP_H
