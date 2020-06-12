class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int i,j;
        for(i=0;i<board.size();i++){
            for(j=0;j<board[0].size();j++){
                if(traceback(board,word,0,i,j)) return true;
            }
        }
        return false;
    }
    //传值时每次递归调用都要在内存中新建立一个vector来保存传入的值，传引用直接在原始位置操作，不需要新建变量与赋值，节省了代码运行的空间与时间开销
    bool traceback(vector<vector<char>>& board, string &word,int index,int x,int y){
    // bool traceback(vector<vector<char>>& board, string word,int index,int x,int y){
        if(board[x][y]!=word[index]){
            return false;
        }
        if(word.size()-1==index){
            return true;
        }
        // char temp = board[x][y]; 
        board[x][y]=0;//避免该位重复访问，即使访问到也会直接返回false；
        index++;
        if((x<board.size()-1 && traceback(board,word,index,x+1,y))// x+1<board.size()
          ||(x>0 && traceback(board,word,index,x-1,y))//x-1>=0
          ||(y<board[0].size()-1 && traceback(board,word,index,x,y+1))
          ||(y>0 && traceback(board,word,index,x,y-1))){
              return true;
        }
        board[x][y]=word[index-1];
        // board[x][y]=temp;
        return false;
    }
};
