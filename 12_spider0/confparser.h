#ifndef CONFPARSER_H
#define CONFPARSER_H
#include "spider.h"


#define MAX_CONF_LEN 1024
#define CONF_FILE "spider.conf"


/* see the spiderq.conf to get meaning for each member variable below */
typedef struct Config {
    int              max_job_num;
    char            *seeds;
    char            *include_prefixes;
    char            *exclude_prefixes;
    char            *logfile;
    int              log_level;
    int              max_depth;
    int              make_hostdir;
    int              stat_interval;

    char *           module_path;
    vector<char *>   modules;
    vector<char *>   accept_types;
};


extern Config *initconfig();
extern void loadconfig(Config *conf);

#endif // CONFPARSER_H
