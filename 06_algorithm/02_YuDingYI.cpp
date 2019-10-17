#include <cstdlib>
#include <algorithm>
#include <list>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <numeric>
#include "functional"
using namespace std;

//plus<int> 预定义好的函数对象，能实现不同类型的数据的 + 运算

//思考：怎么样知道plus<type> 是两个参数
void main21()
{
    plus<int> indAdd;
    int x = 10, y = 20;
    int z = indAdd(x, y);
    cout << "z: " << z << endl;

    plus<string> stringAdd;
    string s1 = "aaa";
    string s2 = "bbb";
    string s3 = stringAdd(s1, s2);
    cout << s3 << endl;

    vector<string> v1;
    v1.push_back("aaa");
    v1.push_back("ccc");
    v1.push_back("bbb");
    v1.push_back("ccc");
    v1.push_back("ccc");

    //求ccc出现的次数
    //函数适配器就是强行的将函数与参数进行绑定
    //equal_to<string>（）有两个参数来自容器，right参数来自sc
    //bind2nd 函数适配器, 还有bind1nd
    string sc = "ccc";
    int num = count_if(v1.begin(), v1.end(), bind2nd(equal_to<string>(), sc));
    cout << num << endl;
    sort(v1.begin(), v1.end(), greater<string>()); //从大到小

    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << endl;
    }
}
class IsGreat
{
public:
    IsGreat(int i)
    {
        _i = i;
    }
    bool operator()(int &num)
    {
        return num > _i;
    }

private:
    int _i;
};

void main22()
{
    vector<int> v1;
    for (int i = 0; i <= 10; i++)
    {
        v1.push_back(i);
    }
    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
        cout << *it << " ";
    cout << endl;
    // count :统计参数的个数
    int num1 = count(v1.begin(), v1.end(), 3);
    cout << "num1: " << num1 << endl;

    // 通过谓词求大于2的个数
    int num2 = count_if(v1.begin(), v1.end(), IsGreat(2));
    cout << "num2: " << num2 << endl;

    // 通过预定义的函数对象的个数 //函数适配器的绑定函数
    int num3 = count_if(v1.begin(), v1.end(), bind2nd(greater<int>(), 2));
    cout << "num3: " << num3 << endl;

    // 求奇数的个数

    int num4 = count_if(v1.begin(), v1.end(), bind2nd(modulus<int>(), 2));
    cout << "num4: " << num4 << endl;

    
    // 求偶数的个数
    int num5 = count_if(v1.begin(), v1.end(), not1(bind2nd(modulus<int>(), 2)));
    cout << "num5: " << num5 << endl;
}
int main(int argc, char const *argv[])
{
    // main21();
    main22(); // 函数适配器综合案例
    system("pause");
    return 0;
}
