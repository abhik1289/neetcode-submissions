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
    ListNode* revNode(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr) {
            ListNode* f = curr->next;
            curr->next = prev;
            prev = curr;
            curr = f;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* rNode = revNode(slow->next);
        ListNode* temp = head;
        // cout << rNode->val << endl;
        while (rNode && temp) {
            if (rNode->val != temp->val) {
                return false;
            }
            rNode = rNode->next;
            temp = temp->next;
        }
        return true;
    }
};