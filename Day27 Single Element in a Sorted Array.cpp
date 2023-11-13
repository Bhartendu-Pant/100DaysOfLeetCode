You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105/*

*/

//Solution:

   int singleNonDuplicate(vector<int>& nums) {
        int len = nums.size();
        if(len == 1 )
        return nums[0];
        if(nums[0] != nums[1])
        return nums[0];
        if(nums[len-1] != nums[len-2])
        return nums[len-1];

        int start = 0;
        int end = len-1;

        while(start <= end ){
            int mid = end - (end - start)/2;
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
            return nums[mid];
            else if(mid % 2 == 1){
                if(nums[mid-1]==nums[mid])
                start = mid+1;
                else
                end = mid-1;
            }
            else{
                if(nums[mid] == nums[mid+1])
                start = mid+1;
                else
                end = mid-1;
            }
        }
        return -1;
    }
