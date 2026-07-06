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
    TreeNode* invertTree(TreeNode* root) {
        if( root == NULL )
        {
            return root;
        }
        TreeNode* left_inverted_tree = invertTree( root->left ); 
        TreeNode* right_inverted_tree = invertTree( root->right ); 
        root->left = right_inverted_tree;
        root->right = left_inverted_tree;
        return root;
    }
};
