#include <../include/dso.h>
#include <dlfcn.h>

using namespace std;

int DSO_Manager::load(char *path, char*name)
{
	Module* module = new Module;
	void * handle = dlopen(path, RTLD_GLOBAL | RTLD_NOW);
	if(handle == NULL)
	{
		return MODULE_ERR;
	}
	
	/* erro */	
	module->init = (void(*)(Module *))dlsym(handle, "init");
	if(module->init == NULL)
	{
		return MODULE_ERR;
	}
	
	module->handle =(int(*)(void *)) dlsym(handle, "handle");
	if(module->handle == NULL)
	{
		return MODULE_ERR;
	}
	
	dlclose(handle);
	modules.insert(make_pair(name,module));

	return MODULE_OK; 
}

Module * DSO_Manager::getModule(char *name)
{
	map<string,Module *>::iterator it;
	it = modules.find(name);
	return it->second;
}

DSO_Manager::~DSO_Manager()
{
	map<string,Module *>::iterator it;
	for(it = modules.begin();it != modules.end();it++)
	{
		delete it->second;
		it->second = NULL;
		modules.erase(it);
	}
}

