class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1) return x;
        int left=1,right=x,mid,res;
        while(left<=right){
            mid=left+(right-left)/2;//防止2147483647+1溢出
            if(mid==x/mid){
                return mid;
            }else if(mid<x/mid){
                left=mid+1;
                // res=mid;
            }else{right=mid-1;}
        }
        res=(left+right)/2;
        return res;
        
    }
};