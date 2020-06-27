class Solution {
public:
    int heightChecker(vector<int>& heights) {//计数的方法，或先排序再比较不同
        vector<int> myarray(101);
        int count=0;
        for(auto h:heights){
            myarray[h]++;
        }
        for(int i=1,j=0;i<myarray.size();i++){
            // std::cout<<"myarray["<<i<<"]="<<myarray[i]<<std::endl;
            while(myarray[i]-- > 0){//数组中存在i
                // std::cout<<"heights["<<j<<"]======"<<heights[j]<<std::endl;
                if(heights[j++] != i) {
                    count++;
                    // std::cout<<"count++"<<count<<std::endl;
                };
            }
        }
        return count;
    }
};