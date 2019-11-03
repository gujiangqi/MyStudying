#include <iostream>
#include <dlfcn.h>
using namespace std;

int main()
{
	cout << "C++ dlopen demo \n \n";
	
	// open the libray
		
	cout << "Opening test.so....\n";
	void * handle = dlopen("obj/libtest.so",RTLD_LAZY);
	if(!handle)
	{
		cerr << "Cannot open library: " << dlerror() << "\n";
		return 1;
	}
	
	// load the symbol
	
	cout << "Loading symblo hello...\n";
	typedef void (*hello_t)();
	
	
	// reset errors
	
	dlerror();
	
	hello_t hello = (hello_t)dlsym(handle, "hello");
	const char * dlsys_error = dlerror();
	
	if(dlsys_error){
		cerr << "Cannot load symbol 'hello': " << dlsys_error << "\n";
		dlclose(handle);
		return 1;
	}
	
	// use it to do the calculation
	cout << "Calling hello...\n";
	hello();
	
	// close the library
	
	cout << "Closing library...\n";
	dlclose(handle);
}
