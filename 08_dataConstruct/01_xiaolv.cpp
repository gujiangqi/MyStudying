/* 比较不同算法执行的效率 */

// 算法的最终要编译成具体的计算机指令
// 每一个指令 在具体的计算机 cpu上运行的时间是固定的
// 通过具体的n的步骤多少就可以推到出算法的复杂度

/* 
    时间换空间
    空间换时间
*/

/* 
    在一个数组由1-1000中某些数字所组成的数组中，每个数字可能出现0次
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main11(int p[], int num)
{
    int tmp[10] = {0};
    for (int i = 0; i < num; i++)
    {
        cout << *(p + i) << " ";
        int tempInt = *(p + i);
        tmp[tempInt]++;
        // cout << *(p + 1) << endl;
    }
    cout << endl;
    for (int k = 0; k < 10; k++)
    {
        cout << tmp[k] << " ";
    }

    int index = 0;
    int max = 0;
    for (int j = 0; j < 10; j++)
    {
        if (tmp[j] > max)
        {
            max = tmp[j];
            index = j;
        }
    }
    return index;
}
int main()
{
    // srand(int(time(0)));
    int myInt[20];
    for (int i = 0; i < 20; i++)
    {
        myInt[i] = rand() % 10;
        cout << myInt[i] << " ";
    }
    cout << endl;
    // 定义一个数组类型
    typedef int(mp)[20];
    typedef int(*myP)[20];
    myP MYPArray = &myInt;
    int(*p)[20] = NULL;
    p = &myInt;

    // main11(myInt);
    size_t num = sizeof(myInt) / sizeof(int); // 时间换空间
    cout << endl;

    int a = main11(myInt, num);
    cout << endl;
    cout << a << endl;

    // cout << answer << endl;
    system("pause");
    return 0;
}