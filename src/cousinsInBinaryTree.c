/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode *x_parent, *y_parent;
int l_h, r_h;

int util(struct TreeNode *root, struct TreeNode *parent, int x, int y, int depth){
    if(!root)
        return 0;
        
    if(root->val == x){
        x_parent = parent;
        l_h = depth;
        return 1;
    }
    if(root->val==y){
        y_parent = parent;
        r_h = depth;
        return 1;
    }
    
    int l = util(root->left, root, x, y, depth+1);
    int r = util(root->right, root, x, y, depth+1);
    // printf("level %d %d\n", l, r);
    return (l_h==r_h) && (x_parent!=y_parent);
}//isCousin

bool isCousins(struct TreeNode* root, int x, int y){
    
    if(!root || (!root->left && !root->right))
        return 0;
    
    if(x==root->val || y==root->val)
        return 0;
    
    return util(root, NULL, x, y, 0);
}
