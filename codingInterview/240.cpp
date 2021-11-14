//240. Search a 2D Matrix II
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int maxRow=matrix.size()-1,minCol=0;
        int row=0,col=matrix[0].size()-1;
        while(col>=minCol && row<=maxRow){
            if(matrix[row][col]==target)
                return true;
            if((matrix[row][col]>target))
                col--;
            else if(matrix[row][col]<target)
                row++;
        }
        return false;
    }
};
