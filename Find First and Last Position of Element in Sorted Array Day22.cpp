/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/

//Solution:
 vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans = {-1,-1};
        if(nums.size() == 0)
        return ans;

        ans[0]=firstOccurence(nums,target);
        ans[1]=lastOccurence(nums,target);

        return ans; 
    }
    int firstOccurence(vector<int>& nums, int target){
        int start = 0;
        int end = nums.size() - 1;
        int ans = -1;
        while(start <= end){
            int mid = end - (end - start)/2;
            if(nums[mid] == target){
                ans = mid;
                end = mid -1;
            }
            else if(nums[mid] < target)
            start = mid + 1;
            else
            end = mid -1;
        }
        return ans;
    } // for lasOccurence do start = mid + 1 when nums[mid]==target
    int lastOccurence(vector<int>& nums, int target){
        int start = 0;
        int end = nums.size() - 1;
        int ans = -1;
        while(start <= end){
            int mid = end - (end - start)/2;
            if(nums[mid] == target){
                ans = mid;
                start = mid + 1;
            }
            else if(nums[mid] < target)
            start = mid + 1;
            else
            end = mid -1;
        }
        return ans;
        
    }
