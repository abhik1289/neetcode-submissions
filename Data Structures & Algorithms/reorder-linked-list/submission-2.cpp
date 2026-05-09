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
    ListNode* revList(ListNode* head) {
        ListNode* p1 = head;
        ListNode* p2 = p1->next;
        p1->next = NULL;
        while (p2) {
            ListNode* p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        }
        return p1;
    }
    void reorderList(ListNode* head) {
        // divide center

       if(!head || !head->next)
       return ;

       

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* temp = head;
        while (fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // rev head
        ListNode* revHead = revList(slow->next);

        // cout << revHead->next->val << endl;

        slow->next = NULL;

        // reoder
        ListNode* dummy = new ListNode(-1);
        ListNode* ptr = dummy;
        while (temp && revHead) {
            ListNode* t1 = temp->next;
            ListNode* t2 = revHead->next;
            temp->next = revHead;
            revHead->next = t1;
            temp = t1;
            revHead = t2;
        }

        if (temp) {
            ptr->next = temp;
        }
        //    return dummy->next;
    }
};
