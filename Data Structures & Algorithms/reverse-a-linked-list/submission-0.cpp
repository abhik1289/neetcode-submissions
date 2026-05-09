/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
   public:
    ListNode* revList(ListNode* temp) {
        ListNode* p1 = temp;
        ListNode* p2 = p1->next;
        p1->next = NULL;
        while (p2) {
            ListNode* future = p2->next;
            p2->next =p1;
            p1=p2;
            p2=future;
        }
        return p1;
    }
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return NULL;
        }

        return revList(head);
    }
};
