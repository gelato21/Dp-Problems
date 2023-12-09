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
    // vector<int> ans;
    // void f(TreeNode* root){
    //     if(root==nullptr) return;
    //     f(root->left);
    //     ans.push_back(root->val);
    //     f(root->right);
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode* > st;
        TreeNode* curr=root;
        vector<int> ans;
        while(curr || st.empty()==false){
            while(curr!=nullptr){
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top();
            st.pop();
            ans.push_back(curr->val);
            curr=curr->right;
        }
        return ans;
    }
};