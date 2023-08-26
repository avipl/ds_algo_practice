class Solution {
    unordered_map<int, int> um;
public:
    TreeNode* getSubtree(int l, int r, vector<int>& postorder, int& pos){
        if(l > r) return NULL;
        
        int val = postorder[pos--];
        TreeNode* root = new TreeNode(val);
        root->right = getSubtree(um[val] + 1, r, postorder, pos);
        root->left = getSubtree(l, um[val] - 1, postorder, pos);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++){
            um[inorder[i]] = i;
        }
        
        int len = postorder.size() - 1;
        return getSubtree(0, postorder.size() - 1, postorder, len);
    }
};