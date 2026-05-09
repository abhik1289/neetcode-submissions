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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // int count = 0;
        ListNode* temp = head;
        int count = 0;
        while (temp) {
            count++;
            temp = temp->next;
        }
        temp = head;

        if(n==1 && count==1)
        return NULL;

        if (n == 0||(count-n)==0) {
            return head->next;

        } else if (n == count) {
            while (temp && temp->next) {
                temp = temp->next;
            }
            return head;
        } else {
             count = count - n;
             ListNode* prev = NULL;
             ListNode* curr = head;
            while(count--)
            {
                prev = curr;
                curr= curr->next;
            }
            prev->next = curr->next; 
        }
        return head;
    }
};
