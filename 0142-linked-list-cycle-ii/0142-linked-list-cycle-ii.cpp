/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL) {
            fast = fast->next;
            if(fast != NULL) {
                fast = fast->next;
                slow = slow->next;
            }
            if(fast == slow) {
                //loop present hai.
                break;
            }
        }
        if(fast == NULL) {
            return fast;
        }
        slow = head;
        while(fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;//koi v reutn kra skte ho slow and fast me se.
    }
};