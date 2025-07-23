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
    ListNode *removeElements(ListNode *head, int val)
    {
        // 删除头节点
        while(head != NULL && head->val == val){
            ListNode *temp = head;
            head = temp->next;
            delete temp;
        }

        // 删除非头节点
        ListNode *cur = head;
        while(cur != nullptr && cur->next != nullptr){
            if(cur->next->val == val){
                ListNode *temp = cur->next;
                cur->next = temp->next;
                delete temp;
            }else{
                cur = cur->next;
            }
        }

        // 返回结果
        return head;
    }
};