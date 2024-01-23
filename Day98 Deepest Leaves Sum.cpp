/*
Given the root of a binary tree, return the sum of values of its deepest leaves.
 

Example 1:


Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15
Example 2:

Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
1 <= Node.val <= 100
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
    int ans=0;
    int height(TreeNode* root){
        if(root==nullptr)return 0;
        int lh=height(root->left);
        int rh=height(root->right);

        return max(lh,rh)+1;
    }
    void helper(TreeNode* root,int height){
        if(root==NULL)return ;
        if(height==1){
            ans+=root->val;
        }
        helper(root->left,height-1);
        helper(root->right,height-1);
    }
    int deepestLeavesSum(TreeNode* root) {
        int h=height(root);
        helper(root,h);
        return ans;

    }
};
