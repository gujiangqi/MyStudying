#include <iostream>
using namespace std;
//多继承始终存在问题
//有同一个祖宗类的情况能够解决，其他的不能解决
class B
{
public:
    B()
    {
        cout << "B的构造函数" << endl;
    }
    int b;
};
class B1 : virtual public B
{
public:
    int b1;
};

class B2 : virtual public B
{
public:
    int b2;
};
 
class C : public B1, public B2
{
public:
    int c;
};
int main()
{
    C c1;
    c1.b1 = 100;
    c1.b2 = 200;
    c1.c = 102;
    c1.b = 105; //缁ф壙鐨勪簩涔夋�у拰铏氱户鎵?
    system("pause");
    return 0;
}