/**
Time = O(m*n)
Space = O(m*n)
**/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int,int>> q;
        int time = 0;
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto p = q.front(); q.pop();
                int x = p.first;
                int y = p.second;
                
                for(int i = 0; i<4; i++){
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    
                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1){
                        q.push({nx,ny});
                        grid[nx][ny] = 2;
                    }
                }
            }
            time++;
        }
        
        for(int i =0;i <m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return time==0?0:time-1;
    }
};
