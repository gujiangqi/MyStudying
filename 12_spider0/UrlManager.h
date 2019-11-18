#ifndef UMLMANAGER_H
#define UMLMANAGER_H
#include "spider_include.h"

class UrlManager
{
public:
    int addUrl(string urlStr);               // add a new Url and new index
    int addUrlList(list<string> urlStrs);                        // add list
    URL* getUrlForQueue();
    int setUrlState(URL* url);                       // set Url state

private:
    URL* findUrl(string urlStr);
    int removeUrlForQuque();

private:
    list<Url> m_urls;               // Url data
    map<string, m_url*> m_urlmap;   // index Url
    queue<Url*> m_urlqueue;         // wiehu dengdai zhuaqu de URL

};


#endif // UMLMANAGER_H
