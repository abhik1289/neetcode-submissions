class Solution {
public:
   
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};

    void BFS(vector<vector<char>>& grid,int row,int col)
    {
   queue<pair<int,int>> q;
   q.push({row,col});
   grid[row][col] = '0';

   while(!q.empty())
   {

       auto [r,c] = q.front();
       q.pop();
        
      for(int i=0;i<4;++i)
      {
           int newRow = r + dx[i];
           int newCol = c + dy[i];

           if(newRow>=0 && newRow<grid.size() 
           && newCol >=0 && newCol < grid[0].size() && 
           grid[newRow][newCol]=='1')
           {
               q.push({newRow,newCol});
                             grid[newRow][newCol]='0';
           }

      }


   }

    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;

   for(int i=0;i<grid.size();++i)
   {
    for(int j=0;j<grid[0].size();++j)
    {
        if(grid[i][j]=='1')
        {
            count++;
            BFS(grid,i,j);
        }
    }
   }
       
    return count;


    }
};
