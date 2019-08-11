#include<dso.h>

int DSO_Manager::load(char* path, name)
{
    Module *module = new Module;
    void *handle = dlopen(path, RTLD_GLOBAL | RTLD_NOW);
    if(handle == NULL)
    {
        return MODULE_ERROR;
    }
     

    module.init = (*init)( dlsym(handle, "init"));
    if(module.init == NULL)
    {
        return MODULE_ERROR;
    }

    module.handle = (*handle)dlsym(handle, "handle");
    if(module.handle == NULL)
    {
         return MODULE_ERROR;
    }

    dlclose(handle);
    
	void *rv = NULL;
    void *handle = NULL;
    Module *module = NULL;

    char * npath = strcat2(3, path, name, ".so");

    if ((handle = dlopen(npath, RTLD_GLOBAL | RTLD_NOW)) == NULL) {	
        SPIDER_LOG(SPIDER_LEVEL_ERROR, "Load module fail(dlopen): %s", dlerror());
    }
    if ((rv = dlsym(handle, name)) == NULL) {
        SPIDER_LOG(SPIDER_LEVEL_ERROR, "Load module fail(dlsym): %s", dlerror());
    }
    module = (Module *)rv;
    module->init(module);

    return module;
	
	
	
    modules.insert(name, module);

    return MODULE_OK;
}

Module*DSO_Manager::getModule(char* name)
{
    return this->modules.find(name);
}
