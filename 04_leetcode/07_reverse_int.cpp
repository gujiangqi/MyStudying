/*  给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

    示例 1:

    输入: 123
    输出: 321

    示例 2:
    输入: -123
    输出: -321

    示例 3:
    输入: 120
    输出: 21
    注意:

    假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/reverse-integer
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include "math.h"
using namespace std;

class Solution
{
public:
    int rev = 0;
    while (x != 0)
    {
        int pop = x % 10;
        x /= 10; //只要判断整数值是否为0就行了
        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
            return 0;
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
            return 0;

        rev = rev * 10 + pop; //这种往前推的思想，太牛逼了
    }
};

int main()
{
    Solution so;
    int a = so.reverse(1234);
    std::cout << "a:" << a << std::endl;
    system("pause");
    return 0;
}