#include <deque>
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main()
{
    int iArray[] = {1, 2, 3, 4, 5};
    deque<int> dq;
    dq.assign(iArray, iArray + 5);
    cout << "deque结果输出是 " << endl;
    for (deque<int>::iterator it = dq.begin(); it != dq.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    dq.pop_front();
    dq.pop_back();
    dq.push_back(12);
    cout << "deque操作后的结果是： " << endl;
    for (deque<int>::iterator it = dq.begin(); it != dq.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << dq.front() << endl;
    cout << dq.back() << endl;
    system("pause");
    return 0;
}
