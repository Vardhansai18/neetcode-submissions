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
    int solve( TreeNode* root , int &res )
    {
        if( root == NULL ) return 0;
        int leftDiam = solve( root->left , res );
        int rightDiam = solve( root->right , res );
        res = max( res , leftDiam + rightDiam );
        return 1 + max( leftDiam ,rightDiam ); 
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        solve( root , res );
        return res;
    }
};
