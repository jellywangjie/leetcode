class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.empty()){return false;}
        vector<vector<int>> row(9,vector<int>(9,0));
        vector<vector<int>> column(9,vector<int>(9,0));
        vector<vector<int>> box(9,vector<int>(9,0));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.'){
                    continue;
                }
                int index = board[i][j] - '1';// 1-9 -> 0-8
                int box_index = (i/3) * 3 + j/3;
                std::cout<<"i--j--box_index--index--"<<i<<"--"<<j<<"--"<<box_index<<"--"<<index<<std::endl;
                if(row[i][index]==0 && column[index][j]==0 && box[box_index][index]==0){
                    row[i][index]=1;//在row的第6列，column的第6行，box的第1行，第6列加以标记
                    column[index][j]=1;//例如判断第0行第4列的数字“7”是否合法,就在row[0][6],column[6][4],box[1][6]查询是否标记过
                    box[box_index][index]=1;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};
