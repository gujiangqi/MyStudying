#include "spider.h"


void cmdLineDeal(int argc,char *argv[]);

int deamonize = 0;
Config *g_conf;

int main(int argc, char * argv[])
{
    /* Stores file descriptor information that triggers an event, and event information */
    struct epoll_event events[10];

    cmdLineDeal(argc,argv);

    g_conf = initconfig();

    loadconfig(g_conf);



    return 0;
}
void cmdLineDeal(int argc,char *argv[])
{
    char ch;
    while((ch = getopt(argc, (char* const*)argv,"vhd")) != -1)
    {
        switch(ch)
        {
        case 'v':
//            version();

            printf("Version: spider 1.0\n");
            exit(1);
            break;
        case 'd':
            deamonize = 1;
            break;
        case 'h':
        case '?':
        default:
//            usage();
            printf("Usage: ./spider [Options]\n"
                    "\nOptions:\n"
                    "  -h\t: this help\n"
                    "  -v\t: print spiderq's version\n"
                    "  -d\t: run program as a daemon process\n\n");
            exit(1);
        }
    }
}
