#ifndef _DSO_H_
#define _DSO_H_

#include <stdio.h>
#include <map>
#include <string>
using namespace std;

#define MODULE_OK 0
#define MODULE_ERR 1

#define MODULE_MAIN_VERSION 1
#define MODULE_SUB_VERSION 0


typedef struct Module
{
	int vaersion;
	int sub_ver;
	char *name;
	void(*init)(Module*);
	int(*handle)(void*);	
}Module;

class DSO_Manager
{
public:
	int load(char *path,char* name);
	Module * getModule(char *name);
	~DSO_Manager();
private:
	map<string,Module*> modules;
};

#endif
