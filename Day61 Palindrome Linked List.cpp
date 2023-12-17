/*
Given the head of a singly linked list, return true if it is a 
palindrome
 or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 
*/

//Solution:
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
    bool isPalindrome(ListNode* head) {
        stack<int>st;

        ListNode* ptr=head;
        while(ptr != NULL)
        {
            st.push(ptr->val);
            ptr=ptr->next;
        }
        ListNode* ptr2=head;
        while(ptr2!=NULL)
        {
            int val1=ptr2->val;
            int val2=st.top();
            st.pop();

            if(val1 != val2)
            return false;

            ptr2=ptr2->next;
        }
        return true;
    }
};
