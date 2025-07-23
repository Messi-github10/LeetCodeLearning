#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 我走过你走过的路，你走过我走过的路
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *A = headA, *B = headB;
        while(A != B){  // 若A和B不同时为nullptr或者不同时指向公共节点
            A = (A != nullptr ? A->next : headB);
            B = (B != nullptr ? B->next : headA);
        }
        return A;
    }
};