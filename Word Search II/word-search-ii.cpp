/**
Time = O(m*n*w*l); w = number of words, l = length of the longest word
Space = O(w*l)
**/

class Solution {
    
    static const int K = 26;
    struct trieNode{
        vector<int> next = vector<int>(K, -1);
        bool isWord = false;
    };
    
    vector<trieNode> trie = vector<trieNode> (1);
    
    void insert(string& word){
        int node = 0;
        
        for(auto c:word){
            if(trie[node].next[c-'a']==-1){
                trie[node].next[c-'a'] = trie.size();
                trie.emplace_back();
            }
            node = trie[node].next[c-'a'];
        }
        
        trie[node].isWord = true;
    }
public:
    vector<string> ans;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
      
        
        int m = board.size();
        int n = board[0].size();
        for(auto word:words){
            insert(word);
        }
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(trie[0].next[board[i][j]-'a']!=-1){
                    string word = "";
                    word+=board[i][j];
                    int node = trie[0].next[board[i][j]-'a'];
                    dfs(board, m, n, i, j, word, node);
                }
            }
        }
        return ans;
        
    }
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    void dfs(vector<vector<char>>& board, int m, int n, int x, int y, string word, int node){
        if(trie[node].isWord){
            ans.push_back(word);
            trie[node].isWord = false;
        }
        
        char org = board[x][y];
        board[x][y] = '#';
        
        for(int i = 0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            
            if(nx>=0 && nx<m && ny>=0 && ny<n && board[nx][ny]!='#'){
                char c = board[nx][ny];
                
                if(trie[node].next[c-'a']!=-1){
                    dfs(board, m, n, nx, ny, word+c, trie[node].next[c-'a']);
                }
            }
        }
        
        board[x][y] = org;
    }
};
