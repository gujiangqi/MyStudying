#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main()
{
    //无参构造函�??
    vector<int> vecInt;
    vector<float> vecFloat;
    vector<string> vecString;

    //带参数构造函�??
    int iArray[] = {0, 1, 2, 3, 4};
    vecInt.assign(3, 9);
    vector<int> vecIntA(iArray, iArray + 5);
    vector<int> vectorB(vecIntA.begin(), vecIntA.end());
    vector<int> vectorC(vecIntA.begin(), vecIntA.begin() + 3);
    vector<int> vectorD(3, 9); //就是�??3�??9放进vecIntD
    vector<int> vectorE(vectorC);

    //vector的赋�??
    vecIntA.assign(iArray, iArray + 5);
    vectorB.assign(vecIntA.begin(), vecIntA.end());

    vectorC.assign(3, 9);

    vectorD = vectorC;

    vectorE.swap(vectorD);

    //vector的大�??
    int iSize = vecInt.size();
    bool flag = vecInt.empty(); //�ж�falg�Ƿ�Ϊ�գ��յĻ�����1����Ϊ�շ���0��
    cout << flag << endl;
    if (flag)
    {
        cout << "vecInt�ǿ�Ԫ��" << endl;
    }
    else
    {
        cout << "vecInt���ǿյ� " << endl;
    }
    cout << iSize << endl;
    vecInt.resize(10);    //��������������10������Ĭ��ֵ�������
    vecInt.resize(12, 4); //��������������12������4�������

    //vector���Ƴ�����Ӳ���
    vecIntA.push_back(2);
    vecIntA.pop_back();

    //vector���ݵĴ�ȡ
    vecIntA[2] = 10;
    vecIntA.at(3) = 11;
    vecIntA.front(); //������Ԫ�ص�����
    vecIntA.back();  //�������һ��Ԫ�ص�����

    //������
    vector<int>::iterator it;
    int A[] = {1, 3, 5, 7, 9};
    vector<int> vecIntB;
    vecIntB.assign(A, A + 5);
    it = vecIntB.begin(); //

    //�������
    for (vector<int>::iterator i = vecIntB.begin(); i != vecIntB.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    //�������
    for (vector<int>::reverse_iterator i = vecIntB.rbegin(); i != vecIntB.rend(); i++)
    {
        int iltem = *i;
        cout << iltem << " ";
    }

    //vector�Ĳ���
    vecIntB.insert(vecIntB.begin(), 11);                             //{11, 1, 3, 5, 7, 9}
    vecIntB.insert(vecIntB.begin() + 1, 2, 33);                      //{11,33,33,1,3,5,7,9}
    vecIntB.insert(vecIntB.begin(), vecIntB.begin(), vecIntB.end()); //{2,4,6,8,11,33,33,1,3,5,7,9}

    //vector��ɾ��
    cout << "vecIntB�ı������Ϊ��" << endl;
    for (vector<int>::iterator it = vecIntB.begin(); it != vecIntB.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    vecIntB.erase(vecIntB.begin(), vecIntB.begin() + 2);
    //vecIntB.clear();  //���vecIntB�е�����Ԫ��
    cout << "vecIntBɾ����Ľ��Ϊ��" << endl;
    for (vector<int>::iterator it = vecIntB.begin(); it != vecIntB.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}