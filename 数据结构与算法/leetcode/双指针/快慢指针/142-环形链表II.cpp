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
        if(head == nullptr || head->next == nullptr) return nullptr;
            
        auto slow = head, fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) break;
        }

        if(slow != fast) return nullptr;

        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};