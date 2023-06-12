class Solution {
public:

    int diam(TreeNode* root,int* height){
        if(root==NULL){
            *height=0;
            return 0;
        }
        int lh=0,rh=0;
        int ld = diam(root->left,&lh);
        int rd = diam(root->right,&rh);
        int currd = lh +rh;
        *height = max(lh,rh)+1;
        return max(currd,max(ld,rd)); 
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int height = 0;
        int a = diam(root,&height);
        return a;
    }
};