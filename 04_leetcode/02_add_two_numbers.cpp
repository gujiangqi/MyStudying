/*
    题目：
    给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
    如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
    您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/add-two-numbers
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
    输出：7 -> 0 -> 8
    原因：342 + 465 = 807
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int len1 = 1;
        int len2 = 1;
        ListNode *p = l1;
        ListNode *q = l2;
        while (p->next != NULL)
        {
            len1++;
            p = p->next;
        }
        while (q->next != NULL)
        {
            len2++;
            q = q->next;
        }
        if (len1 > len2)
        {
            // 在q最后补上len1-len2个0
            // 现在p跟q就在最后一个元素的位置，直接补上
            for (int i = 1; i < len1 - len2; i++)
            {
                ListNode *newNode = new ListNode(0);
                q->next = newNode;
                q = q->next;
            }
            else
            {
                ListNode *newNode = new ListNode(0);
                p->next = newNode;
                p = p->next;
            }
        }
        p = l1;
        q = l2;
        int count = 0;
        ListNode *l3 = new ListNode(-1);
        ListNode *w = l3;
        int i = 0; //记录相加结果
        while (p != NULL && q != NULL)
        {
            i = count + (p->val + q->val);
            w->next = new ListNode(i % 10); //个位数相加取余
            count = i > 10 ? 1 : 0;
            w = w->next;
            p = p->next;
            q = q->next;
        }
        if (count)
        {
            w->next = new ListNode(1);
            w = w->next;
        }
        return l3->next;
    }
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(-1);
        ListNode *h = head;
        int sum = 0;
        bool carry = false;
        while (l1 != NULL || l2 != NULL)
        {
            sum = 0;
            if (l1 != NULL)
            {
                sum += l1 - val;
                l1 = l1->next
            }
            if (l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            if (carry)
            {
                sum++;
            }
            h->next = new ListNode(sum % 10);
            h = h->next;
            carry = sum > 10 ? true : false;
        }
        if (carry)
        {
            h->next = new ListNode(1);
        }
        return head->next;
    }
};
