#include <stdio.h>
#include <list>
#include <string>
using namespace std;

class ConfigParse
{
public:
	
	int loader(char * conf_pathname);
	
	// for single
	ConfigParse* instance();
	// operator
	int getJobNum();
	char getUrlSeed();
	int getDeep();
	int getLoglevel();
	char * getModulePath();
	list<string> getModules();
	list<string> getFiletypes();

private: // for single
	ConfigParse();
	static ConfigParse  _self();
private:
	int job_num;
	char * seed;
	int deeps;
	int log_levels;
	char *Module_name;
	list<string> Module_name;
	list<string> file_type;
};
