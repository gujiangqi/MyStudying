#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <list>
#include <string>
#include <set>
#include <vector>
#include <numeric>
#include "functional"
using namespace std;
template <typename T>
class showElement
{
public:
    showElement()
    {
        n = 0;
    }
    void operator()(T &t)
    {
        n++;
        // printN();
        cout << t << " ";
    }
    void printN()
    {
        cout << "n:" << n << endl;
    }

private:
    int n;
};
// 函数模板
template <typename T>
void FuncShowEle(T &t)
{
    cout << t << endl;
}

void FuncShowEle2(int &t)
{
    cout << t << endl;
}

//函数对象的好处
void mian01()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);

    // for_each(v1.begin(), v1.end(), showElement<int>());

    // std::cout << std::endl;

    // for_each(v1.begin(), v1.end(), FuncShowEle2); // 通过回调函数，谁使用for_each 谁去填写回调函数的入库地址

    showElement<int> show1;

    // 函数对象做函数参数

    // FUNCTION TEMPLATE for_each
    /*
    template <class _InIt, class _Fn>
    inline _Fn for_each(_InIt _First, _InIt _Last, _Fn _Func) { // perform function for each element [_First, _Last)
    _Adl_verify_range(_First, _Last);
    auto _UFirst      = _Get_unwrapped(_First);
    const auto _ULast = _Get_unwrapped(_Last);
    for (; _UFirst != _ULast; ++_UFirst) {
        _Func(*_UFirst);
    }

        return _Func;
    }
    */
    // for_each 函数参数是函数对象
    // for_each 函数的返回值也是函数对象
    for_each(v1.begin(), v1.end(), show1);
    show1.printN();
    std::cout << "通过for_each算法的返回值看调用的次数" << std::endl;
    show1 = for_each(v1.begin(), v1.end(), show1);
    show1.printN();

    // show1.print
}
template <typename T>
class isDiv
{
private:
    T divisor;

public:
    isDiv(const T &divisor) { this->divisor = divisor; }
    bool operator()(T &t)
    {
        return (t % divisor == 0);
    }
    ~isDiv() {}
};

void main03()
{
    vector<int> v2;
    for (int i = 10; i < 33; i++)
    {
        v2.push_back(i);
    }
    const int a = 4;
    isDiv<int> myDiv(a);
    vector<int>::iterator it;
    /* 
    // FUNCTION TEMPLATE find_if
    template <class _InIt, class _Pr>
    _NODISCARD inline _InIt find_if(_InIt _First, const _InIt _Last, _Pr _Pred) { // find first satisfying _Pred
        _Adl_verify_range(_First, _Last);
        auto _UFirst      = _Get_unwrapped(_First);
        const auto _ULast = _Get_unwrapped(_Last);
        for (; _UFirst != _ULast; ++_UFirst) {
            if (_Pred(*_UFirst)) {
                break;
            }
        }

        _Seek_wrapped(_First, _UFirst);
        return _First;
    }
    // 返回的是一个迭代器
     */
    it = find_if(v2.begin(), v2.end(), myDiv); //返回第一个被整数的数的迭代器的位置
    if (it != v2.end())
    {
        cout << "container have the answer " << *it << endl;
    }
    else
    {
        cout << "container have no the answer " << endl;
    }
}

template <typename T>
class SumAdd
{
public:
    T operator()(T &t1, T &t2)
    {
        return t1 + t2;
    }
};
void main04()
{
    //v1 v2==>v3
    vector<int> v1, v2;
    vector<int> v3;

    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);

    v2.push_back(2);
    v2.push_back(4);
    v2.push_back(6);

    v3.resize(10);
    /* 
    template <class _InIt1, class _InIt2, class _OutIt, class _Fn>
    inline _OutIt transform(const _InIt1 _First1, const _InIt1 _Last1, const _InIt2 _First2, _OutIt _Dest,
        _Fn _Func) { // transform [_First1, _Last1) and [_First2, ...) with _Func
        _Adl_verify_range(_First1, _Last1);
        auto _UFirst1      = _Get_unwrapped(_First1);
        const auto _ULast1 = _Get_unwrapped(_Last1);
        const auto _Count  = _Idl_distance<_InIt1>(_UFirst1, _ULast1);
        auto _UFirst2      = _Get_unwrapped_n(_First2, _Count);
        auto _UDest        = _Get_unwrapped_n(_Dest, _Count);
        for (; _UFirst1 != _ULast1; ++_UFirst1, (void) ++_UFirst2, ++_UDest) {
            *_UDest = _Func(*_UFirst1, *_UFirst2);
        }

        _Seek_wrapped(_Dest, _UDest);
        return _Dest;
    }
    把运算结果的迭代器的开始位置返回出来
 */
    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), SumAdd<int>());
    for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
    {
        cout << *it << endl;
    }
}
bool MyCompare(const int &a, const int &b)
{
    return a < b;
}
// 二元谓词
void main05()
{
    vector<int> v1(10);
    for (int i = 0; i < 10; ++i)
    {
        int tmp = rand() % 100;
        v1[i] = tmp;
    }
    /*     for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << endl;
    }
 */
    //采用算法进行遍历
    for_each(v1.begin(), v1.end(), showElement<int>());
    cout << endl;
    sort(v1.begin(), v1.end(), MyCompare);
    for_each(v1.begin(), v1.end(), showElement<int>());
}

struct compareNocase
{
    bool operator()(const string &str1, const string &str2)
    {
        string str1_;
        str1_.resize(str1.size());
        // transform(str1.begin(), str1.end(), str1_.begin(), tolower);//预定义函数对象
        string str2_;
        str2_.resize(str2.size());

        
        return (str1 < str2);
    }
};

void main06()
{
    set<string> set1;
    set1.insert("bbb");
    set1.insert("aaa");
    set1.insert("ccc");

    //find函数默认条件下是区分大小写的
    set<string>::iterator it = set1.find("aaa");
    if (it == set1.end())
    {
        cout << "find Fail" << endl;
    }
    else
    {
        cout << "find OK" << endl;
    }

    set<string, compareNocase> set2;
    set2.insert("aaa");
    set2.insert("bbb");
    set2.insert("ccc");

    set<string, compareNocase>::iterator iindex = set2.find("aaa");
    //不区分大小写的语法

    if (iindex == set2.end())
    {
        cout << "find Fail" << endl;
    }
    else
    {
        cout << "find OK" << endl;
    }
}
int main()
{
    // int a = 10;
    // showElement<int> showElement;
    // 通过重载（）对函数对象进行调用
    // showElement(a); //

    // FuncShowEle<int>(a);
    // FuncShowEle2(a);
    // mian01();
    // main03(); //一元函数谓词
    // main04(); //二元函数谓词
    // main05(); //二元谓词
    // main06(); //二元谓词在set集合中的应用

    system("pause");
    return 0;
}