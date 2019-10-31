// /*
//     数列的全排列
//  */
// #include "string.h"
// #include <string>
// #include <iostream>
// #include <cstdlib>
// using namespace std;

// // 交换两个字符
// void swap(string &a, int m, int n)
// {
//     char temp = a[m];
//     a[m] = a[n];
//     a[n] = temp;
// }
// void SortAll(string &a, int m, int n)
// {
//     if (m == n - 1)
//     {
//         cout << a << endl;
//         return;
//     }
//     int i;
//     for (i = m; i < n; i++)
//     {
//         swap(a, i, m);
//         SortAll(a, m + 1, n);
//         swap(a, i, m);
//     }
// }
// int main()
// {
//     string p = "abcd";
//     // cout << strs.size() << endl;
//     // strs.erase(1, 1);
//     // cout << strs.size() << endl;
//     SortAll(p, 0, p.size());
//     system("pause");
//     return 0;
// }

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    string str = "[hello]";
    if (str.find("=", 0) != string::npos)
    {
        cout << str << endl;
        printf("find success!");
    }
    else
    {
        cout << " no find " << endl;
    }

    system("pause");
    return 0;
}