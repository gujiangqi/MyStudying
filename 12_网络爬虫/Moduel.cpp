#pragma once
#include <list>
#include <map>
#include <queue>
#include <string>
class Url
{
public:
    // 初始化
    // set
    //
    int i;

private:
    int j;
}

class urlManager
{
public:
    // 外部接口
    int addUrl();
    int addUrlList();
    int getUrlForQueue();
    int removeUrlForQueue();
    // setUrlValue();

private:
    // 内部接口
    int findUrl();

private:
    list<Url> Urls;
    map<string, Url *> UrlMap;
    queue<Url *> UrlQueue;
}
