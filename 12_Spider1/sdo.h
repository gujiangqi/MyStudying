#pragma once

#include <map>
#include <string>
using namespace std;
#define MODULE_OK 0
#define MODULE_ERR 1

#define MODULE_MAIN_VERSION 1
#define MODULE_SUB_VERSION 0
typedef struct Module
{
    int version;
    int sub_ver;
    char *name;
    void (*init)(Module *); // 入口函数指针
    int (*handle)(void *);  // 初始化函数指针
} Module;

class DSO_Manager
{
public:
    int load(char *path, char *name);
    Module *getModule(char *name); // 得到模块
private:
    map<string, Module*> modules;
}