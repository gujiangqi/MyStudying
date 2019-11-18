#ifndef URL_H
#define URL_H
#include "spider_include.h"
typedef struct stru_url
{
    string url;
    string protocal;
    string path;
    string filename;
    int    state;
    int    deep;
    string filetype;
} URL;

class Url
{
public :
    Url(string url_str);
    int paraseUrl();
    struct stru_url* getUrlData();
    ~Url();
private:
    struct stru_url m_url;
};


#endif // URL_H
