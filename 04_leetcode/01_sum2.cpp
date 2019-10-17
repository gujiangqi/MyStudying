/*
    给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
    你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/two-sum
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/*
    1. 哈希表map的使用
    2. 函数存在返回值，有时候没有返回值时，return {}
    3. vector的遍历

*/
#include <vector>
#include <unordered_map>
#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;

//暴力解决方法
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int>::iterator itBegin = nums.begin();
        vector<int>::iterator itEnd = nums.end();
        for (vector<int>::iterator it1 = itBegin; it1 != (nums.end() - 1); ++it1)
        {
            for (vector<int>::iterator it2 = it1 + 1; it2 != nums.end(); ++it2)
            {
                int sum = *it1 + *it2;
                if (sum == target)
                {
                    int index1 = std::distance(nums.begin(), it1) + 1;
                    int index2 = std::distance(nums.begin(), it2) + 1;
                    vector<int> result = {index1, index2};
                    return result;
                }
            }
        }

        vector<int> str = {0, 0};
        return str;
    }
};

class Solution2
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> record;       //去哈希表中去查找结果 ，其中key是原始nums的值，value是nums值得索引
        for (int i = 0; i < nums.size(); i++) //依次遍历原始数组中的数
        {
            int complement = target - nums[i];           //需要查询的数值是target-nums[i]
            if (record.find(complement) != record.end()) //如果不等于最后的地址，就表示找到了对应的值
            {
                int res[] = {i, record[complement]}; //新建一个数字存取的值
                return vector<int>(res, res + 2);    // 返回一个数组
            }

            record[nums[i]] = i; //采用下标进行索性值，没必要使用迭代器
        }
        return {};
    }
};
//链接：https://leetcode-cn.com/problems/two-sum/solution/dong-hua-tu-jie-suan-fa-liang-shu-zhi-he-fu-shi-pi/

//哈希表
class Solution3
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> record;
        for (int i = 0; i != nums.size(); ++i) //遍历原来数组
        {
            int complete = target - nums[i];
            if (record.find(complete) != record.end()) //找到这个数值
            {
                //记录当前的索引号 record[complete]
                vector<int> result = {i, record[complete]};
                return result;
            }
            record.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};
int main()
{
    Solution so;
    Solution2 so2;
    Solution3 so3;
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int target = 6;
    vector<int> result = so.twoSum(nums, target);
    vector<int> result2 = so2.twoSum(nums, target);
    vector<int> result3 = so3.twoSum(nums, target);
    // cout << "[";
    // for (vector<int>::iterator it = result.begin(); it < result.end(); it++)
    // {
    //     cout << *it << " ";
    // }
    // cout << "]";
    // cout << endl;

    // cout << "[";
    // for (vector<int>::iterator it = result2.begin(); it < result2.end(); it++)
    // {
    //     cout << *it << " ";
    // }
    // cout << "]";
    // cout << endl;
    for (int i = 0; i < result3.size(); ++i)
    {
        cout << result3[i];
    }
    system("pause");
    return 0;
}