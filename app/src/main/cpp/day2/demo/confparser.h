#include<stdio.h>

class ConfigParser
{
public:
    //ConfigParser();
    int loder(char* conf_filepath);
    // for single
    ConfigParser* instance();

    //opratons
    int getJobNum();
    char getUrlSeed()000;
    int getDeep();
    int getLogLevel();
    char* getmodulePath();
    list<string> getModules();
    list<string> getFileTypes();
private: //for single
    Configparser();
    static ConfigParser* _self;

private:
    int job_num;
    char* seed;
    int deeps;
    int log_level;
    char* Module_path;
    list<string> Module_name;
    list<string> file_type;



};
