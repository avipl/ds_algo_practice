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
    bool countTrees(TreeNode* root, int &cnt){
        if(root == NULL) return true;

        bool leftUni = countTrees(root->left, cnt);
        bool rightUni = countTrees(root->right, cnt);

        if(leftUni && rightUni){   
            if(root->left && root->left->val != root->val){
                return false;
            }
            if(root->right && root->right->val != root->val){
                return false;
            }

            cnt++;
            return true;
        }
        
        return false;        
    }
    
    int countUnivalSubtrees(TreeNode* root) {
        int cnt = 0;
        countTrees(root, cnt);

        return cnt;
    }
};