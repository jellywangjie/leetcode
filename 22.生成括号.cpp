class Solution {//剪枝+递归
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        generate(0,0,n,"");
        return res;
    }
    void generate (int left,int right,int n,string temp){
        if(left==n && right==n){
            res.push_back(temp);
        }
        if(left<n){
           generate(left+1,right,n,temp+'(');
        }
        if(left>right && right<n){
           generate(left,right+1,n,temp+')');
        }
    }
};