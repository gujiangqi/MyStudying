/* 罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/roman-to-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */
#include <string>
#include <cstdlib>
#include <iostream>
#include <unordered_map>
using namespace std;
// 罗马数字转换成数字
// 自己的解法
/* class Solution
{
public:
    int romanToInt(string s)
    {
        int tempInt = 0, sum = 0;
        for (int i = 0; i < s.length(); i++)
        {
            switch (s[i])
            {
            case 'I':
                tempInt = 1;
                break;
            case 'V':
                tempInt = 5;
                break;
            case 'X':
                tempInt = 10;
                break;
            case 'L':
                tempInt = 50;
                break;
            case 'C':
                tempInt = 100;
                break;
            case 'D':
                tempInt = 500;
                break;
            case 'M':
                tempInt = 1000;
                break;
            default:
                break;
            }
            if (i > 0)
            {
                if(((tempInt == 5) && (s[i - 1] == 'I'))||((tempInt == 10) && (s[i - 1] == 'I')))
                {
                    tempInt -= 2;
                }else if (((tempInt == 50) && (s[i - 1] == 'X'))||((tempInt == 100) && (s[i - 1] == 'X')))
                {
                    tempInt -= 20;
                }else if (((tempInt == 500) && (s[i - 1] == 'C'))||((tempInt == 1000) && (s[i - 1] == 'C')))
                {
                    tempInt -= 200;
                }
            }
            sum += tempInt;
        }
        return sum;
    }
}; */

// 采用哈希表
class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<string, int> m = {{"I", 1}, {"IV", 3}, {"IX", 8}, {"V", 5}, {"X", 10}, {"XL", 30}, {"XC", 80}, {"L", 50}, {"C", 100}, {"CD", 300}, {"CM", 800}, {"D", 500}, {"M", 1000}};

        int r = m[s.substr(0, 1)];
        for (int i = 1; i < s.size(); i++)
        {
            string two = s.substr(i - 1, 2);
            string one = s.substr(i, 1);
            cout << m[two] << endl;
            r += m[two] ? m[two] : m[one];
        }
        return 0;
    }
};
int main(int argc, char const *argv[])
{
    Solution so;
    string str = "V";
    unordered_map<string, int> m = {{"I", 1}, {"IV", 3}, {"IX", 8}, {"V", 5}, {"X", 10}, {"XL", 30}, {"XC", 80}, {"L", 50}, {"C", 100}, {"CD", 300}, {"CM", 800}, {"D", 500}, {"M", 1000}};
    cout << m["sad"] << endl;
    int a = so.romanToInt(str);
    cout << a << endl;
    system("pause");
    return 0;
}
