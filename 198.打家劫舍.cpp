class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        int past=nums[0],last,current = max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            // if (last_end+1 == current_begin && nums[last_end] < nums[current_begin] ){
            //     current += past;
            // }
            last = current;//上一次的current即为本次的last
            current = max(past+nums[i],last);//偷nums[i]就不能偷nums[i-1],或者不偷nums[i],last保持不变
            past = last;//本次的last成为本次的past；
            //past和last 的区别在于：last有可能包含nums[i-1],而past一定不包含nums[i-1];
            //不偷nums[i]就可以保持last状态不变，偷了nums[i]last就必须退化为past，即不能让nums[i-1]有机会被偷；
        }
        return current;
    }
};

