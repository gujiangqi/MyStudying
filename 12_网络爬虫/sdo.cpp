#include <sdo.h>
#include <dlfcn.h>

int DSO_Manager::load(char *path, char *name)
{
    Module *module = new Module;
    void *handle = dlopen(path, name);
    if (handle == NULL)
    {
        return MODULE_ERR;
    }

    module->init = (*init)(dlsym(handle, "init"));
    if (module.init == NULL)
    {
        return MODULE_ERR;
    }

    module->handle = (*handle)dlsym(handle, "handle");
    if (module.handle == NULL)
    {
        return MODULE_ERR;
    }
    dlclose(handle);
    modules.insert(name, moduls);
    return MODULE_OK;
}
Module *DSO_Manager::getModule(char *name)
{
    return this->modules.find(name);
}
