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
    ListNode* reverseUsingRecursion(ListNode* prev,ListNode* curr) {
        //Base case.
        if(curr == NULL) {
            return prev;
        }
        //1 case solve krdo.
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;

        //Baki recursion sambhal lega.
        return reverseUsingRecursion(prev,curr);
    }
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL) {
            fast = fast->next;
            if(fast->next != NULL) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }

    bool compareList(ListNode* head,ListNode* head2) {
        while(head != NULL && head2 != NULL) {
            if(head->val != head2->val) {
                return false;
            }
            else{
                head = head->next;
                head2 = head2->next;
            }
        }
        return true;
    }


    bool isPalindrome(ListNode* head) {
        //1.Break into two halfs.
        ListNode* midNode = middleNode(head);
        ListNode* head2 = midNode->next;
        midNode->next = NULL;

        //2.reverse second half.
        ListNode* prev = NULL;
        ListNode* curr = head2;
        head2 = reverseUsingRecursion(prev,curr);

        //3.compare both LL.
        bool ans = compareList(head,head2);
        return ans;
    }
};