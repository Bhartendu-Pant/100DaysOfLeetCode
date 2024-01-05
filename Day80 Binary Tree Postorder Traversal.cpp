/*
Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [3,2,1]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
 

Constraints:

The number of the nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?
*/

//Solution:
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // void postOrder(vector<int>&ans,TreeNode* root){
    //     if(root==NULL)return;
    //     postOrder(ans,root->left);
    //     postOrder(ans,root->right);
    //     ans.push_back(root->val);
    // }
    vector<int> postorderTraversal(TreeNode* root) {
        //<------Recursive approach----->
        // vector<int>ans;
        // postOrder(ans,root);
        // return ans;
        //<----Iterative approach using two stack---->
        if(root==NULL)return {};
        vector<int>ans;
        stack<TreeNode*>st1,st2;
        st1.push(root);
        while(!st1.empty()){
            TreeNode* temp=st1.top();
            st2.push(temp);
            st1.pop();
            if(temp->left){
                st1.push(temp->left);
            }
            if(temp->right){
                st1.push(temp->right);
            }
        }
        while(!st2.empty()){
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
};
