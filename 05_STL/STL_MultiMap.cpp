#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
using namespace std;

class Person
{
public:
    string name;
    int age;
    string tel;
    double sal;
};
void main01()
{
    Person p1, p2, p3, p4, p5;
    p1.name = "A";
    p1.age = 31;

    p2.name = "B";
    p2.age = 32;

    p3.name = "C";
    p3.age = 33;

    p4.name = "D";
    p4.age = 34;

    p5.name = "E";
    p5.age = 35;

    multimap<string, Person> map2;
    // sal部门
    map2.insert(make_pair("sal", p1));
    map2.insert(make_pair("sal", p2));

    // development部门
    map2.insert(make_pair("development", p3));
    map2.insert(make_pair("development", p4));

    // financial 部门
    map2.insert(make_pair("financial", p5));
    for (multimap<string, Person>::iterator it = map2.begin(); it != map2.end(); it++)
    {
        cout << it->first << "\t" << it->second.name << "\t"
             << it->second.age << endl;
    }

    multimap<string, Person>::size_type count = map2.count("development");
    multimap<string, Person>::iterator myIt = map2.find("development");
    for (multimap<string, Person>::size_type it = 0; it < count; it++,myIt++)
    {
        int age;
        cout << myIt->second.age << " ";
    }
    
}   
int main()
{
    main01();
    system("pause");
    return 0;
}