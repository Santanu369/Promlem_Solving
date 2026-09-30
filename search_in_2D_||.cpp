#include<bits/stdc++.h>
using namespace std;

// start from top right
// if target < that then we can eleminate that col and move left
// if taget > that then we can  eleminate the row and move down
// elemination tactic

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int r = 0, c = cols-1;
        while (c >= 0 && r < rows)
        {
            if (matrix[r][c] == target) return true;
            else if (matrix[r][c] > target) c --;
            else r++; 
        }
        
        return false;

    }
};


int mian() {


}