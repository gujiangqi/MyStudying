/* 编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串?""。

示例?1:

输入: ["flower","flow","flight"]
输出: "fl"
示例?2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-prefix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

//暴力解决1
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0 || strs[0] == "")
        {
            return "";
        }
        else if (strs.size() == 1)
        {
            return strs[0];
        }
        string strAns = "";
        int pos = 1;
        while (true)
        {
            for (int i = 1; i < strs.size(); ++i)
            {
                cout << strAns << endl;
                cout << strs[i] << endl;
                if (strAns.size() >= strs[i].size())
                    return strAns;
                while (strs[0].substr(0, pos) != strs[i].substr(0, pos))
                {
                    return strAns;
                }
            }
            strAns = strs[0].substr(0, pos); //当循环全部满足，就把首字母赋值过去；
            pos++;
        }
    }
};

//水平扫描法
class solution2
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
        {
            return "";
        }

        string strAns = strs[0];

        for (int i = 1; i < strs.size(); i++) //遍历到最后一个
        {
            string strTemp = "";
            //cout << strAns << endl;
            //cout << strAns.size() << endl;
            string one = strs[i]; //第二个
            for (int j = 1; j <= strAns.size(); ++j)
            {
                if (strAns.substr(0, j) == one.substr(0, j))
                {
                    strTemp = strAns.substr(0, j);
                }
            }
            strAns = strTemp;
        }
        return strAns;
    }
};

//人家的思路
class Solution3
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int lenVec = strs.size();
        if (lenVec == 0)
            return ""; // 如果vector中没有string，返回空串
        if (lenVec == 1)
            return strs.at(0); //如果vector中有一个string，直接返回该串

        int j = 0; //记录最大公共前缀长度
        while (1)
        {
            for (int i = 0; i < lenVec; i++)
            {
                if (j >= strs.at(i).size())
                    return strs.at(i).substr(0, j); //如果遇到字串结束，返回已找到的前缀

                char c = strs.at(0).at(j);
                if (c != strs.at(i).at(j))
                    return strs.at(i).substr(0, j); //如果遇到字串中字母不相等，返回已找到的前缀
            }
            j++;
        }
    }
};
//暴力解决
class Solution4
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0 || strs[0] == "")
        {
            return "";
        }
        else if (strs.size() == 1)
        {
            return strs[0];
        }
        int pre = 0;
        int pos = 1;
        while (true) //只要排出长的不一样的就行 只要与第一个长度不一致，或者第n个字符不一样就返回
        {
            for (int i = 0; i < strs.size(); ++i)
            {
                if (strs[i].size() <= pre)
                {
                    return strs[i].substr(0, pre);
                }
                char c = strs[i][pre];
                if (strs[0][pre] != c)
                {
                    return strs[i].substr(0, pre);
                }
            }
        }

        pre++;
    }
};
//官方答案 水平扫描法
class Solution5
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
            return "";
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++)
        {
            while (strs[i].find(prefix, 0) != 0)
            {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty())
                {
                    return "";
                }
            }
        }
        return prefix;
    }
};

//官方答案 水平扫描
class Solution6
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
        {
            return "";
        }
        for (int i = 0; i < strs[0].size(); i++)
        {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++)
            {
                if (i == strs[j].size() || strs[j][i] != c)
                {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

//官方答案 分治
// class Solution7
// {
// public:
//     string longestCommonPrefix(vector<string> &strs)
//     {
//         if (strs.size() == 0)
//         {
//             return "";
//         }
//         return longestCommonPrefix(vector<string> strs, 0, strs.size() - 1);
//     }

// private:
//     string longestCommonPrefix(vector<string> &strs, int l, int r)
//     {
//         if (l == r)
//         {
//             return strs[l];
//         }
//         else
//         {
//             int mid = (l + r) / 2;
//             string lcpLeft = longestCommonPrefix(vector<string> strs, l, mid);
//             string lcpLeft = longestCommonPrefix(vector<string> strs, mid + 1, r);
//             return commonPrefix(lcpLeft, lcpRight);
//         }
//     }

//     string commonPrefix(string left, string right)
//     {
//         int min = left.size() > right.size() ? right.size() : left.size();
//         for (int i = 0; i < min; i++)
//         {
//             if (left.at(i) != right.at(i))
//             {
//                 return left.substr(0, i);
//             }
//         }
//         return left.substr(0, min);
//     }
// };

// 二分法求解
class solution8
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        //如果strs中没有字符串，则返回空
        if (strs.size() == 0)
        {
            return "";
        }

        // 1.得到strs中的最小字符串的长度
        int minLen = 1;
        int highLen = strs[0].size();
        for (int i = 0; i < strs.size(); i++)
        {
            highLen = strs[i].size() < highLen ? strs[i].size() : highLen;
        }

        while (minLen <= highLen)
        {
            int mid = (minLen + highLen) / 2; //得到中间值
            if (isCommonPrefix(strs, mid))
                minLen = mid + 1;
            else
            {
                highLen = mid - 1;
            }
        }
        return strs[0].substr(0, (minLen + highLen) / 2);
    }

private:
    // 判断是否是前几项
    bool isCommonPrefix(vector<string> &strs, int len)
    {
        string strIni = strs[0].substr(0, len);
        for (int i = 0; i < strs.size(); i++)
        {
            size_t index = strs[i].find(strIni, 0);
            if (index == string::npos || index != 0)
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    vector<string> vecStr = {"flower", "flow", "flight"};
    //cout << vecStr[0] << endl;
    Solution so;
    solution2 so2;
    Solution5 so5;
    solution8 so8;
    string resultAns = so8.longestCommonPrefix(vecStr);
    // string strResult = so.longestCommonPrefix(vecStr);
    // cout << strResult << endl;
    // string strResult2 = so2.longestCommonPrefix(vecStr);
    // cout << strResult2 << endl;

    // string strResult5 = so5.longestCommonPrefix(vecStr);
    cout << resultAns << endl;
    system("pause");
    return 0;
}