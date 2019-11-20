#ifndef SPIDER_H
#define SPIDER_H

// include

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <vector>
#include <time.h>
#include <sys/epoll.h>
#include <stdio.h>
#include <getopt.h>

using namespace std;


#include "confparser.h"

//#include "dso.h"

#define MAX_MESG_LEN 1024

#define SPIDER_LEVER_DEBUG 0
#define SPIDER_LEVER_INFO  1
#define SPIDER_LEVER_WARN  2
#define SPIDER_LEVER_ERROR 3
#define SPIDER_LEVER_CRIT  4

extern int deamonize;

static const char *LOG_STR[]={
    "DEBUG",
    "INFO",
    "WARN",
    "ERRO",
    "CRIT"
};

//extern Config *g_conf;

//#define SPIDER_LOG(level, format, ...) do{ \
//    if(level >= g_conf->log_level){\
//        time_t now = time(NULL);\
//        char msg[MAX_MESG_LEN];\
//        char buf[32];\
//        sprintf(msg,format,##__VA_ARGS__);\
//        strftime(buf,sizeof(buf),"%Y%m%d %H:%M:%S",localtime(&now));\
//        fprintf(stdout,"[%s][%s] %s\n",buf,LOG_STR[level],msg);\
//        fflush(stdout);\
//    }\
//    if(level == SPIDER_LEVER_ERROR){\
//        exit(-1);\
//}


//}
//void version()
//{
//    printf("Version: spider 1.0\n");
//    exit(1);
//}
//void usage()
//{
//    printf("Usage: ./spider [Options]\n"
//            "\nOptions:\n"
//            "  -h\t: this help\n"
//            "  -v\t: print spiderq's version\n"
//            "  -d\t: run program as a daemon process\n\n");
//    exit(1);
//}



#endif // SPIDER_H
