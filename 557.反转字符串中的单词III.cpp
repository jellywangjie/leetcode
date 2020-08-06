class Solution {
public:
    string reverseWords(string s) {
        // std::cout<<"size = "<<s.size()<<std::endl;
        if(s.size() == 0 || s.size() == 1) return s;
        // vector<string> temp;
        string temp;
        string res;
        bool flag = 0;
        int count = 0;
        int temp_end;
        int i,j;
        for(i=0;i<s.size();i++){
            // std::cout<<"i ============ "<<i<<std::endl;
            if(s[i] != ' '){
                count++;
                flag = 1;
            }
            else if(flag == 1 || i == s.size()-1){
                // std::cout<<"i = "<<i<<std::endl;
                // std::cout<<"count = "<<count<<std::endl;
                temp_end = i;
                for(j = 0;j < count;j++){
                    // temp[j] = s[temp_end-1];
                    temp += s[temp_end-1];
                    // temp.push_back(s[temp_end - 1]);
                    // std::cout<<"temp["<<j<<"] = "<<temp[j]<<std::endl;
                    temp_end--;
                    // std::cout<<"temp_end = "<<temp_end<<std::endl;
                    // std::cout<<"temp = "<<temp<<std::endl;
                }
                if (i != s.size()-1)  temp += ' ';
                flag = 0;
                count = 0;
                // std::cout<<"temp = "<<temp<<std::endl;
                // res += temp;
            }
        }
         if (count != 0){
                temp_end = i;
                for(j = 0;j < count;j++){
                    temp += s[temp_end-1];
                    temp_end--;
                }
            }
        return temp;
    }
};