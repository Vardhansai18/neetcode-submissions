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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if( root == NULL ) return result;
        queue<TreeNode*> q;
        q.push( root );

        while( q.size() )
        {
            int size = q.size();
            vector<int> levelNodes;
            for( int i = 0 ; i < size ; i++ )
            {
                TreeNode* front = q.front();
                q.pop();
                cout << front->val << " ";
                levelNodes.push_back( front->val );
                if( front->left != NULL ) q.push( front->left );
                if( front->right != NULL ) q.push( front->right );
            }
            result.push_back( levelNodes );
            cout << endl;
        }
        return result;
        
    }
};
