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
    int depthTree( TreeNode* root )
    {
        if( root == NULL )
        {
            return 0;
        }
        int leftDepthTree = 1 + depthTree( root->left );
        int rightDepthTree = 1 + depthTree( root->right );
        return max( leftDepthTree , rightDepthTree );
    }
    int diameterOfBinaryTree(TreeNode* root) {

        if( root == NULL )
        {
            return 0;
        }
        int leftDepthTree = depthTree( root->left );
        int rightDepthTree = depthTree( root->right );
        return max( leftDepthTree + rightDepthTree , max( diameterOfBinaryTree( root->left ) , diameterOfBinaryTree(root->right) ));
    }
};