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

void main41()
{
    vector<int> vecInt;
    vecInt.push_back(1);
    vecInt.push_back(1);
    vecInt.push_back(2);
    vecInt.push_back(2);
    vecInt.push_back(3);
    vecInt.push_back(4);
    vecInt.push_back(5);
    vecInt.push_back(5);

    vector<int>::iterator it = adjacent_find(vecInt.begin(), vecInt.end()); // 默认是 equal_to
    if (it == vecInt.end())
    {
        std::cout << "no find this element!" << std::endl;
    }
    else
    {
        std::cout << "this element is " << *it << std::endl;
    }
    int index = distance(vecInt.begin(), it);
    std::cout << index << std::endl;
}

void main42()
{
    vector<int> vecInt;
    vecInt.push_back(1);
    vecInt.push_back(1);
    vecInt.push_back(2);
    vecInt.push_back(2);
    vecInt.push_back(3);
    vecInt.push_back(4);
    vecInt.push_back(5);
    vecInt.push_back(5);

    binary_search(vecInt.begin(), vecInt.end(), 2); // 返回bool类型的数据 速度快
}

void main43()
{
    vector<int> vecInt;
    vecInt.push_back(1);
    vecInt.push_back(1);
    vecInt.push_back(2);
    vecInt.push_back(2);
    vecInt.push_back(3);
    vecInt.push_back(4);
    vecInt.push_back(5);
    vecInt.push_back(5);

    int num = count(vecInt.begin(), vecInt.end(), 5);
    cout << num << endl;
}
bool myGreater(int &a) { return a > 2; }
void main44()
{
    vector<int> vecInt;
    vecInt.push_back(1);
    vecInt.push_back(1);
    vecInt.push_back(2);
    vecInt.push_back(2);
    vecInt.push_back(3);
    vecInt.push_back(4);
    vecInt.push_back(5);
    vecInt.push_back(5);

    int num = count_if(vecInt.begin(), vecInt.end(), myGreater);
    cout << num << endl;
}

void main45()
{
    vector<int> vecInt;
    vecInt.push_back(1);
    vecInt.push_back(1);
    vecInt.push_back(2);
    vecInt.push_back(2);
    vecInt.push_back(3);
    vecInt.push_back(4);
    vecInt.push_back(5);
    vecInt.push_back(5);

    vector<int>::iterator it = find(vecInt.begin(), vecInt.end(), 5);
    int dis = distance(vecInt.begin(), it);
    cout << dis << endl;
}

void main46()
{
    vector<int> vecInt;
    vecInt.push_back(1);
    vecInt.push_back(1);
    vecInt.push_back(2);
    vecInt.push_back(2);
    vecInt.push_back(3);
    vecInt.push_back(4);
    vecInt.push_back(5);
    vecInt.push_back(5);

    vector<int>::iterator it = find_if(vecInt.begin(), vecInt.end(), myGreater);
    int dis = distance(vecInt.begin(), it);
    cout << dis << endl;
}
int main()
{
    // main41(); // adjacent_find ：相邻查找
    // main42(); // 二分法查找
    // main43(); // 求与这个值相等的个数
    // main44(); // count_if : 满足一定条件的个数
    // main45(); //find : 查询函数，查找元素的第一个位置
    main46();
    system("pause");
    return 0;
}