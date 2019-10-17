/* 
    1. 递归一定要想好结束条件
    2. 递归就是自己调用自己

 */
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;
typedef struct _tag_tree
{
    char data;
    _tag_tree *left, *right;
    _tag_tree(char x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
} DataTree;

// 前序遍历
DataTree *preTravelTree(DataTree *root)
{
    DataTree *LRoot = new DataTree(0);
    DataTree *RRoot = new DataTree(0);
    // 递归结束条件
    if (root == NULL)
    {
        return root;
    }
    printf("%c ", root->data);
    // LRoot = root->left;
    preTravelTree(root->left);
    // RRoot = root->right;
    preTravelTree(root->right);
    return root;
}
// 中序遍历
void inTravelTree(DataTree *root)
{
    // 递归结束条件
    if (root == NULL)
    {
        return;
    }

    inTravelTree(root->left);

    // 打印该节点
    printf("%c ", root->data);
    inTravelTree(root->right);

    return;
}
// 后序遍历
void postTravelTree(DataTree *root)
{
    if (root == NULL)
    {
        return;
    }

    postTravelTree(root->left);

    postTravelTree(root->right);
    printf("%c ", root->data);
}

// #法创建二叉树
DataTree *J_CreateTree()
{
    DataTree *tmp = NULL;

    char a;

    scanf("%c", &a);
    if (a == '#')
    {
        return NULL;
    }
    else
    {
        tmp = new DataTree(0);
        if (tmp == NULL)
        {
            return NULL;
        }
        tmp->data = a;
        tmp->left = J_CreateTree();
        tmp->right = J_CreateTree();
        return tmp;
    } 
    return NULL;
}
//
int inleftbegin = 0;
int find(string &pre, string &in)
{
    size_t ret = in.find(pre[inleftbegin]);
    return ret;
}
//    string pre = "ADEBCF";
//     string in = "DEACFB";
DataTree *Create_Tree_preIn(string &pre, string &in)
{
    int length = in.size();
    DataTree *ret = NULL;
    if (length == 0)
    {
        return ret;
    }
    // 找到根节点先赋值
    ret = new DataTree(pre[inleftbegin]);

    // 找到根節點在中序中的位置
    int index = find(pre, in);
    inleftbegin++;
    if (length > 1)
    {
        string leftStr = in.substr(0, index);
        // cout << leftStr << " ";
        string rightStr = in.substr(index + 1);
        // cout << rightStr << " ";
        ret->left = Create_Tree_preIn(pre, leftStr);
        ret->right = Create_Tree_preIn(pre, rightStr);
    }

    return ret;
}
int main()
{
    // DataTree t1(1), t2(2), t3(3), t4(4), t5(5), t6(6), t7(7), t8(8), t9(9), t10(10), t11(11);

    // t1.left = &t2, t1.right = &t7;
    // t2.left = &t3, t2.right = &t4;
    // // t4.left = &t5;
    // t4.right = &t6;
    // t7.left = &t8, t7.right = &t9;
    // // t8.left = &t10;
    // t8.right = &t11;

    // // t1.right = &t2;
    // // t2.right = &t3;
    // DataTree *temp = preTravelTree(&t1);
    // cout << endl;

    // inTravelTree(&t1);
    // cout << endl;

    // postTravelTree(&t1);
    // cout << endl;

    // ab#c##de##f##
    // printf("pls input char :");
    // DataTree *temp = J_CreateTree();
    // inTravelTree(temp);
    // cout << endl;
    string pre = "ADEBCF";
    string in = "DEACFB";
    cout << "in.size: " << in.size() << endl;

    size_t ret = in.find(pre[0]);
    cout << "ret: " << ret << endl;
    cout << pre.substr(1, ret + 1) << endl;
    cout << in.substr(0, ret - 1) << endl;
    DataTree *temp = Create_Tree_preIn(pre, in);
    cout << endl;
    preTravelTree(temp);

    system("pause");
    return 0;
}