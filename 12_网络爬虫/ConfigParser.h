#pragma once

/* 
 * 实例化
 * 配置文件生成键值对 =
 * 按行读取
 * 不读取#注释
 * 忽略空格
 */
class ConfigParser()
{
public:
    int loader(char *conf_filepath);

    ConfigParser *instace();

    int get_jobNum();
    char *getUrlSeed();

private:
    ConfigParser();
    static ConfigParser *_self;

private:
    int job_num;
    char *seed;
    int deeps;
    int log_level;
}