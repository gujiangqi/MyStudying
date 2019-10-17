#include <cstdlib>
#include <algorithm>
#include <list>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <numeric>
#include "functional"
#include "iterator" // 输出流迭代器
using namespace std;
int increase(int &i)
{
    return i + 100;
};
void printV(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
void showEle(int &i)
{
    cout << i << " ";
}
int showEle2(int &i)
{
    cout << i << " ";
    return i;
}
template <class datatype>
void printL(list<datatype> &v)
{
    for (list<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
}
void main31()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    // 使用回调函数
    transform(v1.begin(), v1.begin(), v1.begin(), increase);
    printV(v1);
    cout << endl;

    // 使用预定义函数
    transform(v1.begin(), v1.end(), v1.begin(), negate<int>());
    printV(v1);
    cout << endl;

    // 使用函数适配器
    list<int> mylist;
    mylist.resize(v1.size());
    transform(v1.begin(), v1.end(), mylist.begin(), bind2nd(multiplies<int>(), 10));
    printL(mylist);
    cout << endl;

    //transform也可以将运算结果直接输出屏幕
    transform(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "), negate<int>());
}
void main32()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);

    vector<int> v2 = v1;
    for_each(v1.begin(), v1.end(), showEle);
    cout << endl;

    transform(v1.begin(), v1.end(), v2.begin(), showEle2);
}
int main()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    // main31(); // transform 函数
    main32(); // for_each pk transform
    system("pause");
    return 0;
}