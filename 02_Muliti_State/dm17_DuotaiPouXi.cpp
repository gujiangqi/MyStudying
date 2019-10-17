#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "string.h"
using namespace std;

/*
    多态成立的三个条件�?
        要有继承，要有虚函数重写，父类指针指向子类对�?
*/

class parent
{
public:
    parent(int a = 0)
    {
        this->a = a;
    }
    //�麯�����洢�����ĵ�ַ
    virtual void print() //1.���ֽŵĵط���Э��vitual�ؼ��֣�c++�����⴦��
    {
        cout << "���ǵ�" << endl;
    }

private:
    int a;
};

class child : public parent
{
public:
    child(int a = 0, int b = 0) : parent(a)
    {
        this->b = b;
    }
    virtual void print()
    {
        cout << "���Ƕ���" << endl;
    }

private:
    int b;
};

void HowToPlay(parent *base)
{
    base->print();//���ж�̬����//���ݴ����Ķ���ִ�в�ͬ�ĺ���������ִ�и���ĳ�������ִ������ĳ���
    //C++��������������Ҫ����
    //���������������ֱ���һ��vptrָ�룬==>�麯����==>��������ڵ�ַ������˳ٰ󶨵�Ч��
    //�ٰ󶨣����е�ʱ��c++��ȥ�жϣ�
}
int main()
{
    parent p1;//��ǰ�������ඨ������ʱ��C++���������ڶ��������һ��VPTRָ�룬
    child c1;//�������Ҳ��һ��VPTRָ�룬����
    HowToPlay(&p1);
    HowToPlay(&c1);
    system("pause");
    return 0;
}