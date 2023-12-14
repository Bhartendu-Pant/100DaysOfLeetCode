/*
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
Example 1:

Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
Example 2:

Input: n = 1
Output: [[1]]
 
Constraints:
1 <= n <= 20
*/

//Solution:

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
       int count=1;
       int minRow=0;
       int minCol=0;
       int maxCol=n-1;
       int maxRow=n-1;
       vector<vector<int>>ans(n,vector<int>(n));
       while(count<=n*n)
       {
           //fixed minRow (minCol --> maxCol)
           for(int c=minCol;c<=maxCol;c++)
           {
               ans[minRow][c]=count++;
           }
           //fixed maxCol (minRow+1--> maxRow)
           for(int r=minRow+1;r<=maxRow;r++)
           {
               ans[r][maxCol]=count++;
           }
           //fixed maxRow (maxCol-1--> minCol)
           for(int c=maxCol-1;c>=minCol;c--)
           {
               ans[maxRow][c]=count++;
           }
           //fixed minCol (maxRow-1--> minRow+1)
           for(int r=maxRow-1;r>=minRow+1;r--)
           {
               ans[r][minCol]=count++;
           }
           minCol +=1;
           minRow +=1;
           maxRow -=1;
           maxCol -=1;
       }
        return ans;
    }
};
