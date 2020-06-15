class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        int step1=1;//s1表示当前阶梯的前一个
        int step2=2;
        int current_step=step2,temp;
        for(int i=2;i<n;i++){
            temp=current_step;
            current_step=step1+step2;
            step1=current_step;
            step2=temp;
        }
        return current_step;
    }
};