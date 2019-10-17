#include <map>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    //pair是C++空间中指定的一种结构体模板，有两个值组成
    map<int, string> myMap;
    pair<map<int, string>::iterator, bool> pairresult = myMap.insert(pair<int, string>(3, "小张"));
    //map的操作函数
    int iFirstFirst = pairresult.first->first;      //first 是一个map值，其中含有键与值，先读取键
    string iFirstSecond = pairresult.first->second; //first 是一个map值，其中含有键与值，后读取值
    bool iSecond = pairresult.second;               //读取结果的bool值

    myMap.insert(map<int, string>::value_type(1, "小李"));

    myMap[3] = "XiaoLiu";
    myMap[5] = "小王";

    string str1 = myMap[1];
    string str2 = myMap[2];

    //迭代器遍历
    for (map<int, string>::iterator it = myMap.begin(); it != myMap.end(); ++it)
    {
        pair<int, string> p = *it;
        int ikey = p.first;
        string ivalue = p.second;
        cout << ikey << endl;
        cout << ivalue << endl;
    }

    //map容器的大小
    int iSize = myMap.size();
    bool iflag = myMap.empty(); //判断是否为空

    //map的删除

    myMap.erase(1);
    myMap.erase(myMap.begin(), myMap.end());

    //map的查找
    map<int, string>::iterator it = myMap.find(3); //返回主键为3的位置的迭代器，如果没有则返回myMap.end()
    int iCount = myMap.count(3);                   //返回主键为3的个数，通常只能是0或者1，对于multimap的个数可能大于1
    /*
        map.upper_bound(5);查找主键大于的第一个元素
        map.lower_bound(5);查找主键大于等于5的第一个元素
    */
    cout << myMap[3] << endl;
    system("pause");
    return 0;
}