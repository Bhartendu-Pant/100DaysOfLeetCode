/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/

//Solution:
 int trap(vector<int>& height) {
        int len = height.size();
        vector<int>leftMax(len);
         leftMax[0] = height[0];

        vector<int>rightMax(len);
        rightMax[len-1]=height[len-1];
       
        for(int i=1;i<len;i++){
            leftMax[i] =max(leftMax[i-1],height[i]);
        }

        for(int i=len-2;i>=0;i--){
            rightMax[i] = max(rightMax[i+1],height[i]);
        }

        int totalWater = 0;
        for(int i=0;i<len;i++)
        totalWater += min(leftMax[i],rightMax[i])-height[i];

        return totalWater;
    }
