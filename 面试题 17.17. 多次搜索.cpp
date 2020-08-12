class Solution {
public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        vector<vector<int>> res;
        string temp;
        vector<int> res_temp;
        for(int i = 0;i < smalls.size();i++){
            for(int j = 0;j < big.size();j++){
                if(big[j] == smalls[i][0]){
                    temp = big.substr(j,smalls[i].size());
                    if(temp == smalls[i]){
                        res_temp.push_back(j);
                    }
                }
            }
            res.push_back(res_temp);
            res_temp.clear();
        }
        return res;
    }
};