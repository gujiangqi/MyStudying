#include "confparser.h"
#include "spider.h"


#define INF 0x7FFFFFFF

Config* initconfig()
{
    Config * conf = (Config*)malloc(sizeof(Config));

    conf->max_job_num = 10;
    conf->seeds = NULL;
    conf->include_prefixes = NULL;
    conf->exclude_prefixes = NULL;
    conf->logfile = NULL;
    conf->log_level = 0;
    conf->max_depth = INF;
    conf->make_hostdir = 0;
    conf->module_path = NULL;
    conf->stat_interval = 0;

    return conf;
}

void loadconfig(Config *conf)
{
    FILE* fp = fopen(CONF_FILE,"r");
    if(fp == NULL)
    {
        printf("CONF_FILE Open fail!!\n");
        return;
    }else
    {
        printf("file open success!\n");
    }
}
