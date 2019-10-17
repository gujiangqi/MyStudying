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
void main51()
{
    vector<int> v1;
    v1.push_back(2);
    v1.push_back(5);
    v1.push_back(3);
    v1.push_back(7);
    vector<int> v2;
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(4);
    v2.push_back(6);

    vector<int> v3;
    v3.resize(10);

    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    printV(v3);
}
class student
{
private:
    /* data */
public:
    student(string name, int id)
    {
        m_name = name;
        m_id = id;
    };
    void printT()
    {
        cout << m_id << " ";
    }
    ~student(){};

    string m_name;
    int m_id;
};

bool CompareS(student &s1, student &s2)
{
    return (s1.m_id < s2.m_id);
}
void main52()
{
    vector<int> v2;
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(4);
    v2.push_back(6);

    student s1("boss", 1);
    student s2("Second", 2);
    student s3("Third", 3);
    student s4("Forth", 4);
    vector<student> v1;
    v1.push_back(s2);
    v1.push_back(s3);
    v1.push_back(s1);
    v1.push_back(s4);
    for (vector<student>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        it->printT();
    }

    cout << endl;
    // 替换 算法的统一性 （实现的算法和数据类型的分离）
    sort(v1.begin(), v1.end(), CompareS); // 默认从小到大进行排序
    for (vector<student>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        it->printT();
    }
}
// void main53()
// {
//     vector<int> v2;
//     v2.push_back(1);
//     v2.push_back(2);
//     v2.push_back(4);
//     v2.push_back(6);

//     _Random_shuffle1(v2.begin(), v2.end());
//     printV(v2);
// }

void main54()
{
    vector<int> v2;
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(4);
    v2.push_back(6);

    reverse(v2.begin(), v2.end());
    printV(v2);
}
int main(int argc, char const *argv[])
{
    // main51(); //merge,从小到大排序后合并
    // main52(); //sort,默认从小到大排序
    // main53(); //随机排序
    main54(); //倒序
    system("pause");
    return 0;
}
