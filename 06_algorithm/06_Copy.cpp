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
void printV(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
void main61()
{
    vector<int> v1;
    v1.push_back(2);
    v1.push_back(5);
    v1.push_back(3);
    v1.push_back(7);

    vector<int> v2;
    v2.resize(v1.size());
    copy(v1.begin(), v1.end(), v2.begin());
    printV(v1);
    cout << endl;
    printV(v2);
}
bool greater5(int &a)
{
    return a > 5;
}
void main62()
{
    vector<int> v1;
    v1.push_back(2);
    v1.push_back(5);
    v1.push_back(3);
    v1.push_back(3);
    v1.push_back(3);
    v1.push_back(3);
    v1.push_back(7);
    printV(v1);
    cout << endl;
    replace(v1.begin(), v1.end(), 3, 8);
    printV(v1);
    cout << endl;
    replace_if(v1.begin(), v1.end(), greater5, 5);
    printV(v1);
}
void main63()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);

    vector<int> v2;
    v2.push_back(2);
    v2.push_back(4);
    v2.push_back(6);

    printV(v1);
    cout << endl;
    printV(v2);
    cout << endl;

    swap(v1, v2);
    printV(v1);
    cout << endl;
    printV(v2);
    cout << endl;
}
void main64()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    int temp = accumulate(v1.begin(), v1.end(), 100); // 指定范围内的数值求和，然后加上初始值
    cout << temp << endl;
}
void main65()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    fill(v1.begin(), v1.end(), 8);
    printV(v1);
}
void main66()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);

    vector<int> v2;
    v2.push_back(1);
    v2.push_back(3);
    v2.push_back(5);

    vector<int> v3;
    v3.resize(v1.size() + v2.size());
    set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
}
int main()
{
    // main61(); //copy函数，使得一个式子里面的值等于另外一个
    // main62(); //replace 替换函数；replace_if 条件替换
    // main63(); // swap:交换函数
    // main64(); // accumulate
    // main65(); // fill
    main66(); // union
    system("pause");
    return 0;
}