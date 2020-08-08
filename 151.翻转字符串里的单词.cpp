class Solution {
public
    string reverseWords(string s) {
        if (s.size() == 0) return s;
        string res;
        string res_temp;
        string temp = ' ' + s;
        int ss = temp.size();
        int count = 0;
        int i_temp;
        bool flag = 0;
        bool flag_null = 0;
        int i,j;
        for(i = ss-1;i = 0;i--){
            if(temp[i] != ' '){
                count++;
                flag = 1;
                flag_null = 0;
            }
            else if (flag == 1 && flag_null == 0){
                i_temp = i;
                for(j = 0;j  count;j++){
                    res_temp += temp[i_temp+1];
                    i_temp++;
                    flag_null = 1;
                }
                count = 0;
                flag = 0;
                res_temp += ' ';
            }
        }
        res = res_temp.substr(0,res_temp.size()-1);
        return res;
    }
};