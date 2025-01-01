class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> result(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sum =0 ;
                int count = 0;
                for(int k = i-1;k<=i+1;k++){
                    for(int l = j-1;l<=j+1;l++){

                        if(0<=k && k<m && 0<=l && l<n){
                            sum += grid[k][l];
                            count++;
                        } 

                    }
                }
                result[i][j] = sum/count;

            }
        }
        return result;
        
    }
};