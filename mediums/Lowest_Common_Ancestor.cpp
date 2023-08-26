/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* ca;
public:
    bool lcs(TreeNode* root, TreeNode *p, TreeNode* q){
        if(root == NULL) return false;
        
        bool left = lcs(root->left, p, q);
        bool right = lcs(root->right, p, q);
        
        if(ca == NULL && (left && right)) ca = root;
        
        if(root == p || root == q){
            if((left || right) && ca == NULL) ca = root;
            return true;
        }
        
        return (left || right);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lcs(root, p, q);
        
        return ca;
    }
};