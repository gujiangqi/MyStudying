#include <iostream>
using namespace std;

class HeroFighter
{
public:
    virtual int power()
    {
        return 10;
    }
};

class EnemyFighter
{
public:
    int attack()
    {
        return 15;
    }
};

class AdvHeroFighter : public HeroFighter
{
public:
    virtual int power()
    {
        return 20;
    }
};
//多态的威力
//1 PlayObj给对象搭建舞台 看成一个框架
//
//父类指针既可以指向父类对象，也可以指向子类对象
void PlayObj(HeroFighter *hf, EnemyFighter *ef)
{
    //静态联编：
    //动态联编：迟绑定//在运行的时候，根据具体对象(具体的类型)，执行不同对象的函数
    if (hf->power() > ef->attack()) //hf->power()这个函数将有多态放生
    {
        printf("win \n");
    }
    else
    {
        printf("flase \n");
    }
}

//多态的思想
//封装：突破了c函数的概念...可以使用对象的属性和对象的方法
//继承：A B 代码的复用
//多态：多态可以使用未来。。。
//C语言 简介赋值，是指针存在的最大意义
//是c语言的特有的现象（1定义两个定量
//

//1.要有虚函数重写
//2.要有继承
//3.用父类指针（父类引用）指向子类对象...



int main()
{
    HeroFighter hf;
    AdvHeroFighter Advhf;
    EnemyFighter ef;
    PlayObj(&hf, &ef);
    PlayObj(&Advhf, &ef);

    system("pause");
    return 0;
}