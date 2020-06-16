class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {//动态规划
        if(nums.size()==0) return 0;
        int res=1;
        vector<int> dp(nums.size()+1);//+1 ???
        for(int i=0;i<nums.size();++i) dp[i]=1;
        for(int i=1;i<nums.size();++i){
            for(int j=0;j<i;++j){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);//当前状态只与前一状态有关，充分信任
                }
            }
            res=max(res,dp[i]);
        }
        return res;
    }
};