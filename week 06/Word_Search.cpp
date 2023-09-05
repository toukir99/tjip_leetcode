class Solution {
private:
    int n,m; 
    constexpr static int dir[] = {+1, 0, -1, 0, +1};
    bool search(int x,int y,int pos,string &word,vector<vector<char>>&board,vector<vector<bool>> &visited){
        //all characters are found
        if(pos>=word.size()) return true;

        //out of the box/ visited cell
        if(x<0 || y<0 || x>=n || y>=m || visited[x][y]) return false;
        visited [x][y] =1;
        bool status = false;
        for(int i=0;i<4;i++){
            int nx= x + dir[i];
            int ny= y + dir[i+1];
            if(board[x][y] == word[pos]){
                status |= search(nx,ny,pos+1,word,board,visited);
            }
            if(status) break;
        }
        visited [x][y] = 0;
        return status;
    }

    bool search(int x,int y,string &word,vector<vector<char>>&board){
         n=board.size();
         m=board[0].size();
         vector<vector<bool>>visited(n+1,vector<bool>(m+1,false));
         return search(x,y,0,word,board,visited);
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    if(search(i,j,word,board)) return true;
                }
            }
        }
        return false;
    }
};
