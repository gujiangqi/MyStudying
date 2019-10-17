/* 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。 */
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "string.h"
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        // 全部反转的话，会遇到整型溢出的问题
        // 可以只反转一半
        if (x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }

        int temp = x;
        int sum = 0;
        while (x > sum)
        {
            sum = sum * 10 + x % 10; // sum = 3
            x = x / 10;
        }
        return (sum == x) || (sum / 10 == x); // 这样写可以很好节省程序运行时间
/*         if ((sum == x) || (sum / 10 == x))
        {
            return true
        }
        else
        {
            return false;
        } */
    }
};
int main()
{

    Solution so;
    int x = -323;
    bool flag = so.isPalindrome(x);

    cout << flag << endl;
    system("pause");
    return 0;
}
