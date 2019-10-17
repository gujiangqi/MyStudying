/* #法创建树 */
#include <iostream>
#include <cstdlib>
using namespace std;
struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
};
BiTNode *CreateBiThrTree()
{
    BiTNode *tmp = NULL;

    char ch;

    scanf("%c", &ch);
    if (ch == '#')
    {
        return NULL;
    }
    else
    {
        tmp = (BiTNode *)malloc(sizeof(BiTNode));
        if (tmp == NULL)
        {
            return NULL;
        }
        tmp->data = ch;
        tmp->lchild = CreateBiThrTree();
        tmp->rchild = CreateBiThrTree();
        return tmp;
    }
    return NULL;
}
int main()
{
    BiTNode *p = NULL;
    // char ch[20];
    // scanf("%c", &ch);
    // cout << ch << endl;
    printf("pls input char :");
    p = CreateBiThrTree();
    system("pause");
    return 0;
}