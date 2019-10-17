/* 
    栈的应用
    1. 括号的就近匹配功能
    2. 中缀表达式和后缀表达式
 */
#include <stack>
#include <iostream>
#include <cstdlib>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<int, string> myMap = {{1, "abc"}};
    unordered_map<int, string>::iterator it = myMap.find(1);
    cout << it->second << endl;
    system("pause");
    return 0;
}