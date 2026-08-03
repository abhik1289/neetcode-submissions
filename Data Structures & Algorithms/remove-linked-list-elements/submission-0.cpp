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
    ListNode* removeElements(ListNode* head, int val) {
        vector<int> t;
        ListNode* temp = head;
        while (temp) {
            if(temp->val!=val)
            t.push_back(temp->val);
            temp = temp->next;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* tail=dummy;
        for (int x : t) {
            // cout << x;
            ListNode* node = new ListNode(x);
            tail->next = node;
            tail = node;
        }
        return dummy->next;
    }
};