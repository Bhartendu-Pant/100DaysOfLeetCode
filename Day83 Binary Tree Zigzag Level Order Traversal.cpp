/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100


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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;

        vector<int>currAns;
        stack<TreeNode*>main;
        stack<TreeNode*>helper;
        int level=0;
        main.push(root);
        while(!main.empty()){
            TreeNode* currNode=main.top();
            main.pop();
            currAns.push_back(currNode->val);
            if(level==0){
                if(currNode->left){
                    helper.push(currNode->left);
                }
                if(currNode->right){
                    helper.push(currNode->right);
                }
            }
            else{
                if(currNode->right){
                    helper.push(currNode->right);
                }
                if(currNode->left){
                    helper.push(currNode->left);
                }
            }

            if(main.size()==0){
                ans.push_back(currAns);
                currAns={};
                level=1-level;
                main=helper;
                stack<TreeNode*>().swap(helper);
            }
        }
        return ans;
    }
};
