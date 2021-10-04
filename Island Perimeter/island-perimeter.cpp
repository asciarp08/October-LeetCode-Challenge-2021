class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int perimeter = 0;
        
        int dx[] = {0,0,1,-1};
        int dy[] = {-1,1,0,0};
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]==0)continue;
                for(int k = 0; k<4; k++){
                    int x = i+dx[k];
                    int y = j+dy[k];
                    if(x<0 || x>=m || y<0 || y>=n || (x>=0 && x<m && y>=0 && y<n && grid[x][y] == 0))
                        perimeter++;
                }
            }
        }
        return perimeter;
    }
};
