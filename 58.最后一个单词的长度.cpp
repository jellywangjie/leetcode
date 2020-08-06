class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        bool flag = 0;
        if(s.size()==0) return 0;
        // std::cout<<"s.size() = "<<s.size()<<std::endl;
        for(int i = s.size();i > 0;i--){
            if(s[i-1] != ' '){
                flag = 1;
                count++;
            }
            else if(flag == 1){
                return count;
            }
       } 
       return count;
    }
};