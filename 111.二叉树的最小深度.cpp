/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {//DFS递归+分治
public:
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int left=minDepth(root->left);
        int right=minDepth(root->right);
        return (left==0||right==0) ? left+right+1 : min(left,right)+1;
    }
};

// class Solution {//BFS执行更快
// public:
//     int minDepth(TreeNode* root) {
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
//                 if(current_node->left==NULL&&current_node->right==NULL){return current_level+1;} 
//                 if(current_node->left!=NULL){myqueue.emplace(current_node->left);}
//                 if(current_node->right!=NULL){myqueue.emplace(current_node->right);} 
//             }
//             current_level++;
//         }
//         return current_level;
//     }
// };
