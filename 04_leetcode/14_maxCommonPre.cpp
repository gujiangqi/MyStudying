/* ��дһ�������������ַ��������е������ǰ׺��

��������ڹ���ǰ׺�����ؿ��ַ���?""��

ʾ��?1:

����: ["flower","flow","flight"]
���: "fl"
ʾ��?2:

����: ["dog","racecar","car"]
���: ""
����: ���벻���ڹ���ǰ׺��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/longest-common-prefix
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע�������� */
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

//�������1
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
            strAns = strs[0].substr(0, pos); //��ѭ��ȫ�����㣬�Ͱ�����ĸ��ֵ��ȥ��
            pos++;
        }
    }
};

//ˮƽɨ�跨
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

        for (int i = 1; i < strs.size(); i++) //���������һ��
        {
            string strTemp = "";
            //cout << strAns << endl;
            //cout << strAns.size() << endl;
            string one = strs[i]; //�ڶ���
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

//�˼ҵ�˼·
class Solution3
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int lenVec = strs.size();
        if (lenVec == 0)
            return ""; // ���vector��û��string�����ؿմ�
        if (lenVec == 1)
            return strs.at(0); //���vector����һ��string��ֱ�ӷ��ظô�

        int j = 0; //��¼��󹫹�ǰ׺����
        while (1)
        {
            for (int i = 0; i < lenVec; i++)
            {
                if (j >= strs.at(i).size())
                    return strs.at(i).substr(0, j); //��������ִ��������������ҵ���ǰ׺

                char c = strs.at(0).at(j);
                if (c != strs.at(i).at(j))
                    return strs.at(i).substr(0, j); //��������ִ�����ĸ����ȣ��������ҵ���ǰ׺
            }
            j++;
        }
    }
};
//�������
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
        while (true) //ֻҪ�ų����Ĳ�һ���ľ��� ֻҪ���һ�����Ȳ�һ�£����ߵ�n���ַ���һ���ͷ���
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
//�ٷ��� ˮƽɨ�跨
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

//�ٷ��� ˮƽɨ��
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

//�ٷ��� ����
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

// ���ַ����
class solution8
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        //���strs��û���ַ������򷵻ؿ�
        if (strs.size() == 0)
        {
            return "";
        }

        // 1.�õ�strs�е���С�ַ����ĳ���
        int minLen = 1;
        int highLen = strs[0].size();
        for (int i = 0; i < strs.size(); i++)
        {
            highLen = strs[i].size() < highLen ? strs[i].size() : highLen;
        }

        while (minLen <= highLen)
        {
            int mid = (minLen + highLen) / 2; //�õ��м�ֵ
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
    // �ж��Ƿ���ǰ����
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