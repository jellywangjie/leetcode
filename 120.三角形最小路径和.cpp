class Solution {//动态规划
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==0) return 0;
        vector<int> mini=triangle[triangle.size()-1];
        for(int i=triangle.size()-2;i>=0 ;--i){
            for(int j=0;j<triangle[i].size();++j){
                mini[j] = triangle[i][j]+min(mini[j],mini[j+1]);
            }
        }
        return mini[0];
    }
};
