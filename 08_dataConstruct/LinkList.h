#pragma onca
typedef struct _tag_LinkListNode
{
    _tag_LinkListNode *next;
} LinkListNode;

typedef struct _tag_data
{
    LinkListNode node;
    void *data;
} DataType;

template <typename T>
class LinkList
{

public:
    LinkList();
    ~LinkList();
    void insert(T &t, int index);
    T at(int index);
    void del(int index);
    int len();

private:
    int length;
    LinkListNode *header;
};