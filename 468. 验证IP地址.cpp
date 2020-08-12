class Solution {
public:
    vector<vector<char>> split(string str,char spliter){
        vector<vector<char>> res;
        vector<char> temp;
        bool flag;
        for(int i = 0;i < str.size();i++){
            if(str[i] != spliter){
                temp.push_back(str[i]);
                flag = 1;
            }
            else if(flag == 1){
                res.push_back(temp);
                temp.clear();
                flag = 0;
            }
            else
            {
                res.clear();
                return res;
            }
        }
        res.push_back(temp);
        for(int k = 0;k < res.size();k++){
            for(int m = 0;m < res[k].size();m++){
                std::cout<<"res"<<"["<<k<<"]["<<m<<"] = "<<res[k][m]<<std::endl;
            }
        }
        return res;
    }
    string validIPAddress(string IP) {
        int IP_size = IP.size();
        std::cout<<"IP_size = "<<IP_size<<std::endl;
        if (IP_size >= 15 && IP_size <= 40 && IP[3] != '.'){
            vector<vector<char>> IPV6_temp =split(IP,':');
            if(IPV6_temp.size() != 8) return "Neither";
            for(int i = 0;i < IPV6_temp.size();i++){
                if(IPV6_temp[i].size() > 4 || IPV6_temp[i].size() < 1 ) return "Neither";
                for(int j = 0;j < IPV6_temp[i].size();j++){
                    if ((IPV6_temp[i][j] >= '0' && IPV6_temp[i][j] <= '9') || 
                       (IPV6_temp[i][j] >= 'A' && IPV6_temp[i][j] <= 'F') || 
                       (IPV6_temp[i][j] >= 'a' && IPV6_temp[i][j] <= 'f'))
                       {
                         continue;
                       }
                    else{ 
                        return "Neither";
                    }
                }
            }
            return "IPv6";
        }
        if (IP_size <= 15 && IP_size >= 7){
            vector<vector<char>> IPV4_temp = split(IP,'.');
            std::cout<<"IPv4_temp.size = "<<IPV4_temp.size()<<std::endl;
            if(IPV4_temp.size() != 4) return "Neither";
            for(int i = 0;i < 4;i++){
                if((IPV4_temp[i].size() != 1 &&
                   IPV4_temp[i][0] == '0') ||
                   IPV4_temp[i][0] > '2' ||
                   (IPV4_temp[i].size() == 3 && 
                   IPV4_temp[i][0] == '2' &&
                   IPV4_temp[i][1] >= '5' && 
                   IPV4_temp[i][2] > '5'))
                   {
                     return "Neither";
                   }
                for(int j = 0;j < IPV4_temp[i].size();j++){
                    if(IPV4_temp[i][j] < '0' || IPV4_temp[i][j] > '9'){
                        return "Neither";
                    }
                }
            }
            return "IPv4";
        }
        return "Neither";
    }
};