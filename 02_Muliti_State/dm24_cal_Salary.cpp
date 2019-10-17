#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "string.h"
using namespace std;

class programme
{
public:
    virtual void getSal() = 0;
};

class junior_programme : public programme
{
public:
    junior_programme(char *name, char *job, int sal)
    {
        this->name = name;
        this->job = job;
        this->sal = sal;
    }
    void getSal()
    {
        cout << name << " " << job << " " << sal << endl;
    }

private:
    char *name;
    char *job;
    int sal;
};

class mid_programme : public programme
{
public:
    mid_programme(char *name, char *job, int sal)
    {
        this->name = name;
        this->job = job;
        this->sal = sal;
    }
    void getSal()
    {
        cout << name << " " << job << " " << sal << endl;
    }

private:
    char *name;
    char *job;
    int sal;
};

class adv_programme : public programme
{
public:
    adv_programme(char *name, char *job, int sal)
    {
        this->name = name;
        this->job = job;
        this->sal = sal;
    }
    void getSal()
    {
        cout << name << " " << job << " " << sal << endl;
    }

private:
    char *name;
    char *job;
    int sal;
};

class architect : public programme
{
public:
    architect(char *name, char *job, int sal)
    {
        this->name = name;
        this->job = job;
        this->sal = sal;
    }
    void getSal()
    {
        cout << name << " " << job << " " << sal << endl;
    }

private:
    char *name;
    char *job;
    int sal;
};
//计算函数
void CalProSal(programme *base)
{
    base->getSal();
};
int main()
{
    mid_programme mp("xiaozhang", "ISO", 10000);
    junior_programme jp("xiaozhang", "ISO", 10000);
    adv_programme ap("xiaozhang", "ISO", 10000);
    architect acp("gu", "jiagoushi", 159000);
    CalProSal(&mp);
    CalProSal(&ap);
    CalProSal(&jp);
    CalProSal(&acp);
    system("pause");
    return 0;
}