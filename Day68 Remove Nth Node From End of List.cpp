/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 
*/

//Solution:
/***** Solution with 2 passes *****/
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         if (!head) return NULL;
//         ListNode* temp = head;
//         int count = 0;
//         while (temp) {
//             count++;
//             temp = temp->next;
//         }
//         temp = head;
//         int target = count - n;
//         if (target == 0) {
//             head = head->next;
//             delete temp;
//             return head;
//         }
//         for (int i = 0; i < target - 1; i++) {
//             temp = temp->next;
//         }
//         temp->next = temp->next->next;
//         return head;
//     }
// };


/**** Optimized solution having only 1 pass *****/
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
        if (!head) return nullptr;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* toRemove = slow->next;
        slow->next = slow->next->next;
        delete toRemove;

        return dummy->next;
    }
};
