/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {//DFS
public:
    int maxDepth(TreeNode* root) {
       if(root==NULL) return 0;
       return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};
// class Solution {//BFS
// public:
//     int maxDepth(TreeNode* root) {
//         if(root==NULL) return 0;
//         queue<TreeNode*> myqueue;
//         myqueue.emplace(root);
//         int current_level=0,current_level_size,i;
//         TreeNode* current_node;
//         while(!myqueue.empty()){
//             current_level_size=myqueue.size();
//             for(i=0;i<current_level_size;i++){
//                 current_node=myqueue.front();
//                 myqueue.pop();
//                 if(current_node->left!=NULL){myqueue.emplace(current_node->left);}
//                 if(current_node->right!=NULL){myqueue.emplace(current_node->right);}
//             }
//             current_level++;
//         }
//         return current_level;
//     }
// };

