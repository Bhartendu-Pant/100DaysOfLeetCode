/*
Given an integer array nums, find the 
subarray
 with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
*/

/*Solution:
Kadane's Algorithm-
Kadane's Algorithm is a dynamic programming algorithm used to find the maximum subarray sum in a given array of integers. The subarray must have at least one element.
*/


  int maxSubArray(vector<int>& nums) {
        int tempSum = nums[0];
        int maxSum = nums[0];

        for(int i=1;i<nums.size();i++){
            if(tempSum + nums[i] > nums[i]){
                tempSum = tempSum + nums[i];
            }
            else{
                tempSum = nums[i];
            }
            maxSum = max(maxSum,tempSum);
        }
        return maxSum;
    }
