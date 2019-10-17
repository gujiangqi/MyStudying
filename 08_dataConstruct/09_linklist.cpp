/* 线性模板类链表测试 */

#include <iostream>
#include <cstdlib>
#include "LinkList.cpp"
using namespace std;
struct Teacher
{
    int age;
    char name[64];
};

int main()
{
    Teacher t1, t2, t3;

    t1.age = 31;
    t2.age = 32;
    t3.age = 33;
    LinkList<Teacher> list;
    list.insert(t1, 0);
    list.insert(t2, 0);
    list.insert(t3, 0);

    for (int i = 0; i < list.len(); i++)
    {
        Teacher tmp = list.at(i);
        cout << tmp.age << endl;
    }

    //链表的删除
    while (list.len() > 0)
    {
        list.del(0);
        // cout << tmp->age << endl;
    }

    system("pause");
    return 0;
}