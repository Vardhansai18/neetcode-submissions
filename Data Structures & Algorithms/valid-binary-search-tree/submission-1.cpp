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
    int solve( TreeNode* root ,  long long int min , long long int max )
    {
        if( root == NULL )
        {
            return true;
        }
        if( min >= root->val || max <= root->val )
        {
            return false;
        }
        bool leftBst = solve( root->left , min , root->val );
        bool rightBst = solve( root->right , root->val , max );
        return leftBst && rightBst; 
    }
    bool isValidBST(TreeNode* root) {
        return solve( root , LONG_MIN , LONG_MAX );
    }
};