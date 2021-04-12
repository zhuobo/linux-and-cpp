// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.04.
// Filename:        
// Descripton:       

#include "structure.h"

#include <queue>

using std::queue;

bool IsComplete(TreeNode* root) {
    if ( root == nullptr ) {
        return true;
    }
    queue<TreeNode*> que;
    que.push(root);
    bool flag = false;
    while ( !que.empty() ) {
        TreeNode* curr = que.front();
        que.pop();
        if ( curr->left ) {
            if ( flag ) {
                return false;
            } else {
                que.push(curr->left);
            }
        } else {
            flag = true;
        }
        if ( curr->right ) {
            if ( flag ) {
                return false;
            } else {
                que.push(curr->right);
            }
        } else {
            flag = true;
        }
    }
    return true;
}
