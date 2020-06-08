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
    TreeNode* convertBiNode(TreeNode* root) {
        stack<TreeNode*> mystack;
        TreeNode* temp=root;
        TreeNode* res;
        TreeNode* current;
        int count=0;
        if(root==NULL) return root;
        while(temp!=NULL||!mystack.empty()){
            while(temp!=NULL){
                mystack.emplace(temp);
                temp=temp->left;
            }
            temp=mystack.top();
            mystack.pop();
            if(count==0) res=current=temp;
            else{
                current->right=temp;
                current->left=NULL;
                current=current->right;
            }
            count++;
            temp=temp->right;
            if(current->left!=NULL){current->left=NULL;}
        }
        return res;


    }
};
//            4
//     2             5
//   1   3        null     6
// 0  
