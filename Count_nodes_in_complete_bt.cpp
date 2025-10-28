#define tn TreeNode*
class Solution {
public:
    int right_h(TreeNode*root){
        int rh=0;
        while(root){
            rh++;
            root=root->right;
        }
        return rh;
    }
    int left_h(TreeNode*root){
        int lh=0;
        while(root){
            lh++;
            root=root->left;
        }
        return lh;
    }
    int countNodes(TreeNode* root) {
      if(!root) return 0;

      int l_h=left_h(root);
      int r_h=right_h(root);

      if(l_h==r_h) return (1<<l_h)-1;

      return 1+countNodes(root->left)+countNodes(root->right);

    }
};

#leetcode->https://leetcode.com/problems/count-complete-tree-nodes/description/
