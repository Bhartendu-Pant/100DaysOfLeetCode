/*
You are given a 0-indexed integer array nums and a target element target.

A target index is an index i such that nums[i] == target.

Return a list of the target indices of nums after sorting nums in non-decreasing order. If there are no target indices, return an empty list. The returned list must be sorted in increasing order.

 

Example 1:

Input: nums = [1,2,5,2,3], target = 2
Output: [1,2]
Explanation: After sorting, nums is [1,2,2,3,5].
The indices where nums[i] == 2 are 1 and 2.
Example 2:

Input: nums = [1,2,5,2,3], target = 3
Output: [3]
Explanation: After sorting, nums is [1,2,2,3,5].
The index where nums[i] == 3 is 3.
Example 3:

Input: nums = [1,2,5,2,3], target = 5
Output: [4]
Explanation: After sorting, nums is [1,2,2,3,5].
The index where nums[i] == 5 is 4.
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i], target <= 100
*/

//Solution:

 vector<int> targetIndices(vector<int>& nums, int target) {
        
        // using inbuilt sort function t.c. = O(n log n);
         //vector<int>ans;
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==target)
        //     ans.push_back(i);
        // }
        // sort(ans.begin(),ans.end());
        // return ans;

        //better approach t.c. = O(n)
        int targetCount = 0;
        int lessThanTarget = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i] < target){
                lessThanTarget++;
            }
            if(nums[i] == target){
                targetCount++;
            }
        }

        vector<int>ans;

        while(targetCount--){
            ans.push_back(lessThanTarget++);
        }
        return ans;

    }
