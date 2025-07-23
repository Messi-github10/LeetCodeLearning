#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // 快慢指针
        ListNode *dummdyHead = new ListNode(0); // 虚拟头节点
        dummdyHead->next = head;
        ListNode *fast = dummdyHead;
        ListNode *slow = dummdyHead;
        while(n-- && fast != nullptr){
            fast = fast->next;
        }
        fast = fast->next;  // 因为添加了虚拟头节点，往后移动多一步，才能让slow能指向待删除节点的前一个节点
        while(fast != nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return dummdyHead->next;
    }
};