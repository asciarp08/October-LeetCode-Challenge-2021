/**
Time = O(n*m*3^L) 
Space = O(L), L = size of the word(size of the dfs recursion stack) 
**/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int l = word.size();
        
        for(int i = 0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]==word[0]){
                    if(dfs(i,j, m,n, l, board, word, 0))
                        return true;
                }
            }
        }
        return false;
    }
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    
    bool dfs(int x, int y, int& m, int& n, int& l, vector<vector<char>>& board, string& word, int idx){
        if(idx==l-1){
            return true;
        }
        
        char c = board[x][y];
        board[x][y] = '#';
        
        for(int i = 0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            
            if(nx>=0 && nx<m && ny>=0 && ny<n && board[nx][ny] == word[idx+1]){
                if(dfs(nx, ny, m, n, l, board, word, idx+1))
                    return true;
            }
        }
        board[x][y] = c;
        return false;
    }
};
