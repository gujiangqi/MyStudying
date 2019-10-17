#include <iostream>
#include <cstdlib>
// 模板类需要引用CPP
#include "SeqList.cpp"
using namespace std;
struct Teacher
{
    char name[64];
    int age;
};

void main01()
{
    Teacher t1, t2, t3, tmp;
    t1.age = 31;
    t2.age = 32;
    t3.age = 33;
    SeqList<Teacher> list(10);
    list.insert(t1, 0);
    list.insert(t2, 0);
    list.insert(t3, 0);

    for (int i = 0; i < list.getL(); i++)
    {
        list.get(i, tmp);
        cout << tmp.age << endl;
    }

    //链表的销毁
    while (list.getL() > 0)
    {
        list.del(0, tmp);
        cout << tmp.age << endl;
    }

    // list.insert(t1, 0);
    // system("pause");
    // return 0;
}
void main02()
{
    Teacher t1, t2, t3;
    Teacher *p1, *p2, *p3;
    p1 = &t1;
    p2 = &t2;
    p3 = &t3;
    Teacher *tmp = NULL;
    t1.age = 31;
    t2.age = 32;
    t3.age = 33;
    SeqList<Teacher *> list(10);
    list.insert(p1, 0);
    list.insert(p2, 0);
    list.insert(p3, 0);

    for (int i = 0; i < list.getL(); i++)
    {
        list.get(i, tmp);
        cout << tmp->age << endl;
    }

    //链表的销毁
    while (list.getL() > 0)
    {
        list.del(0, tmp);
        cout << tmp->age << endl;
    }

    // list.insert(t1, 0);
    // system("pause");
    // return 0;
}
int main(int argc, char const *argv[])
{
    main01();
    main02();
    system("pause");
    return 0;
}
