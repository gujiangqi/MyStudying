#include <iostream>
using namespace std;

int main()
{
    int workNum, peopleNum;
    cin >> workNum >> peopleNum;
    int work[workNum][2];
    int (* workPtr)[2] ;
    workPtr = new int[workNum][2];
    for (int i = 0; i < workNum; i++)
    {
        
        
        cin >> workPtr[i][0]>>workPtr[i][1];
  
    }

    int ability[peopleNum]; //定义每个人的能力
    for (int i = 0; i < peopleNum; i++)
    {
        cin >> ability[i];
    }

    system("pause");
    return 0;
}