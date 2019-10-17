/* 
    给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

    有效字符串需满足：

    左括号必须用相同类型的右括号闭合。
    左括号必须以正确的顺序闭合。
    注意空字符串可被认为是有效字符串。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/valid-parentheses
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */
#include <string>
#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <stack>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        if (s.size() % 2 != 0)
        {
            return false;
        }

        unordered_map<char, char> dic = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        stack<char> ch;

        for (int i = 0; i < s.size(); ++i)
        {
            if (dic.find(s[i]) != dic.end())
            {
                ch.push(s[i]);
            }
            else
            {
                if (dic.find(s[i]) == dic.end() && ch.empty() == true)
                {
                    return false;
                }

                char temp = ch.top();
                ch.pop();
                if (dic.find(temp)->second != s[i])
                {

                    return false;
                }
            }
        }

        return ch.empty();
    }
};
int main()
{
    Solution so;
    string strs = "((";
    bool flag = so.isValid(strs);
    stack<char> ch2;
  //  ch2.push('a');
    bool flag2 = ch2.empty();
    cout << flag2 << endl;
    // cout << ch << endl;
    cout << flag << endl;
    system("pause");
    return 0;
}