#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main()
{
    //鏃犲弬鏋勯�犲嚱锟??
    vector<int> vecInt;
    vector<float> vecFloat;
    vector<string> vecString;

    //甯﹀弬鏁版瀯閫犲嚱锟??
    int iArray[] = {0, 1, 2, 3, 4};
    vecInt.assign(3, 9);
    vector<int> vecIntA(iArray, iArray + 5);
    vector<int> vectorB(vecIntA.begin(), vecIntA.end());
    vector<int> vectorC(vecIntA.begin(), vecIntA.begin() + 3);
    vector<int> vectorD(3, 9); //灏辨槸锟??3锟??9鏀捐繘vecIntD
    vector<int> vectorE(vectorC);

    //vector鐨勮祴锟??
    vecIntA.assign(iArray, iArray + 5);
    vectorB.assign(vecIntA.begin(), vecIntA.end());

    vectorC.assign(3, 9);

    vectorD = vectorC;

    vectorE.swap(vectorD);

    //vector鐨勫ぇ锟??
    int iSize = vecInt.size();
    bool flag = vecInt.empty(); //锟叫讹拷falg锟角凤拷为锟秸ｏ拷锟秸的伙拷锟斤拷锟斤拷1锟斤拷锟斤拷为锟秸凤拷锟斤拷0锟斤拷
    cout << flag << endl;
    if (flag)
    {
        cout << "vecInt锟角匡拷元锟斤拷" << endl;
    }
    else
    {
        cout << "vecInt锟斤拷锟角空碉拷 " << endl;
    }
    cout << iSize << endl;
    vecInt.resize(10);    //重新设置扩容至10，并用默认值进行填充
    vecInt.resize(12, 4); //重新设置扩容至12，并用4进行填充

    //vector的移除与添加操作
    vecIntA.push_back(2);
    vecIntA.pop_back();

    //vector数据的存取
    vecIntA[2] = 10;
    vecIntA.at(3) = 11;
    vecIntA.front(); //返回首元素的引用
    vecIntA.back();  //返回最后一个元素的引用

    //迭代器
    vector<int>::iterator it;
    int A[] = {1, 3, 5, 7, 9};
    vector<int> vecIntB;
    vecIntB.assign(A, A + 5);
    it = vecIntB.begin(); //

    //正向遍历
    for (vector<int>::iterator i = vecIntB.begin(); i != vecIntB.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    //反向遍历
    for (vector<int>::reverse_iterator i = vecIntB.rbegin(); i != vecIntB.rend(); i++)
    {
        int iltem = *i;
        cout << iltem << " ";
    }

    //vector的插入
    vecIntB.insert(vecIntB.begin(), 11);                             //{11, 1, 3, 5, 7, 9}
    vecIntB.insert(vecIntB.begin() + 1, 2, 33);                      //{11,33,33,1,3,5,7,9}
    vecIntB.insert(vecIntB.begin(), vecIntB.begin(), vecIntB.end()); //{2,4,6,8,11,33,33,1,3,5,7,9}

    //vector的删除
    cout << "vecIntB的遍历结果为：" << endl;
    for (vector<int>::iterator it = vecIntB.begin(); it != vecIntB.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    vecIntB.erase(vecIntB.begin(), vecIntB.begin() + 2);
    //vecIntB.clear();  //清楚vecIntB中的所有元素
    cout << "vecIntB删除后的结果为：" << endl;
    for (vector<int>::iterator it = vecIntB.begin(); it != vecIntB.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}