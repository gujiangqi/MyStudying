#ifndef CONFPARSER_H
#define CONFPARSER_H
class ConfigParser
{
public:
    int loader(char * conf_filepath);

    // for single
    static ConfigParser* instance();
    static void release();
};

#endif // CONFPARSER_H
