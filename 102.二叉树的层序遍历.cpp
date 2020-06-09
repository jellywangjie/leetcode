/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> temp;
        if(root==NULL) return res;
        queue<TreeNode*> myqueue;
        myqueue.emplace(root);
        int current_level=0,current_level_size,i;
        TreeNode* current_node;
        while(!myqueue.empty()){
            current_level_size=myqueue.size();
            for(i=0;i<current_level_size;i++){
                current_node=myqueue.front();
                myqueue.pop();
                temp.push_back(current_node->val);
                if(current_node->left!=NULL){myqueue.emplace(current_node->left);}
                if(current_node->right!=NULL){myqueue.emplace(current_node->right);}
            }
            res.push_back(temp);
            temp.erase(temp.begin(),temp.end());
            current_level++;
        }
        return res;
    }
};


// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> res;
//         vector<int> temp;
//         if(root==NULL) return res;
//         queue<TreeNode*> myqueue;
//         myqueue.emplace(root);
//         int current_level=0,current_level_size,i;
//         TreeNode* current_node;
//         while(!myqueue.empty()){
//             current_level_size=myqueue.size();
//             res.push_back({});
//             for(i=0;i<current_level_size;i++){
//                 current_node=myqueue.front();
//                 myqueue.pop();
//                 res[current_level].push_back(current_node->val);
//                 if(current_node->left!=NULL){myqueue.emplace(current_node->left);}
//                 if(current_node->right!=NULL){myqueue.emplace(current_node->right);}
//             }
//             current_level++;
//         }
//         return res;
//     }
// };