#include <iostream>
#include <cstdlib>
using namespace std;

// #define MAXSIZE 3
#define NodeType MyData
// #define ERROR 0
// typedef int DataType;

//创建一个节点类
struct MyData
{

    int data;
};

//创建一个顺序表类
class SqList
{
public:
    SqList(int _capacity);           //初始化顺序表
    ~SqList();                       //销毁顺序表
    NodeType *GetElemByIndex(int i); //根据下标查找顺序表中的元素
    bool isEmpty();                  //判断顺序表是否为空
    bool isFull();                   //判断顺序表是否满
    int GetLength();                 //获取顺序表的长度
    // int GetElemByElem(NodeType data);                  //查看顺序表中是否含有查找的值
    void *InsertSqList(NodeType *data, int index = 0); //向顺序表中插入新数据
    // void InsertSqListAtHead(DataType data);  //在头部插入新数据
    // void InsertSqListAtEnd(DataType data);   //向顺序表的最后插入数据
    void DeleteElem(int index); //删除指定位置的值
    // void DeleteElemAtElem(DataType data);    //按值删除元素
    void DeleteAll(); //删除所有元素
    // void DeleteAtHead();                     //在头部删除元素
private:
    int m_capacity;
    int m_length; //顺序表的长度
    unsigned int *node;
};

//初始化顺序表
SqList::SqList(int capacity)
{
    m_capacity = capacity;
    m_length = 0;

    node = (unsigned int *)malloc(sizeof(unsigned int) * capacity);
};
SqList::~SqList()
{
    m_length = 0;
    m_capacity = 0;
    free(node);
};

//获取长度
int SqList::GetLength()
{
    return m_length;
}

//根据下标查找元素
NodeType *SqList::GetElemByIndex(int i)
{
    void *ret = 0;
    if (i >= m_length)
    {
        ret = (void *)-1;
        printf("func GetElemByIndex err 'index too large': %d ", ret);
        system("pause");
        exit(0);
        return NULL;
    }
    NodeType *temp; // 定义一个节点指针
    temp = (NodeType *)node[i];
    return temp;
}

//向顺序表中插入新数据，默认从头插入
void *SqList::InsertSqList(NodeType *data, int index)
{
    int i = 0;
    void *ret = 0;
    if (index > m_length)
    {
        ret = (void *)-1;
        printf("func InsertSqlList err 'index > length': %d ", ret);
        system("pause");
        exit(0);
        return ret;
    }

    for (i = m_length; i > index; i--)
    {
        node[i] = node[i - 1];
    }
    node[index] = (unsigned int)data;
    m_length++;
    return this;
}

//判断顺序表是否为空
bool SqList::isEmpty()
{
    return !m_length;
}

//判断顺序表是否满了
bool SqList::isFull()
{
    return (m_capacity == m_length);
}

void SqList::DeleteElem(int index)
{
    int i = 0;
    void *ret = 0;
    if (index >= m_length)
    {
        ret = (void *)-1;
        printf("func InsertSqlList err 'index > length': %d ", ret);
        system("pause");
        exit(0);
    }
    for (i = index; i < (m_length - 1); i++)
    {
        node[i] = node[i + 1];
    }
    node[m_length - 1] = (unsigned int)0;
    m_length--;
}

void SqList::DeleteAll()
{
    for (int i = 0; i < m_length; i++)
    {
        node[i] = (unsigned int)NULL;
    }
    m_length = 0;
}
int main(int argc, char const *argv[])
{
    SqList mySql(10);

    // 插入一个数据
    NodeType node1;
    node1.data = 1;
    mySql.InsertSqList(&node1);

    NodeType node2;
    node2.data = 2;
    mySql.InsertSqList(&node2);

    NodeType node3;
    node3.data = 3;
    mySql.InsertSqList(&node3);

    // 按位置插入元素
    NodeType node4;
    node4.data = 4;
    mySql.InsertSqList(&node4, 1);
    // 获取数据
    NodeType *p = (NodeType *)mySql.GetElemByIndex(1);
    cout << "before delete : " << p->data << endl;

    // 遍历元素
    for (int i = 0; i < mySql.GetLength(); i++)
    {

        cout << mySql.GetElemByIndex(i)->data << " ";
    }
    cout << endl;
    // 是否为空
    cout << mySql.isEmpty() << endl;

    // 是否满
    cout << mySql.isFull() << endl;

    // 删除头部元素
    mySql.DeleteElem(1);
    NodeType *p2 = (NodeType *)mySql.GetElemByIndex(1);
    cout << "after delete : " << p2->data << endl;

    // 删除所有元素
    mySql.DeleteAll();
    system("pause");
    return 0;
}
