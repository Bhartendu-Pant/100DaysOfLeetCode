/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
 

Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
*/

//Solution:
//Bruteforce approach O(n log n):
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]==nums[i])
            return nums[i];
        }
        return -1;
    }
};


//****Better Approach****//
//Using hashmap time complexity O(n) but space complexity O(n)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>hashmap;

        for(int num:nums){
            if(hashmap.find(num) != hashmap.end())
            return num;
            else
            hashmap[num]=1;
        }

        return -1;
    }
};


/******OPTIMAL SOLUTION*****/
//Time complexity O(n) and space complexity O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      int ans = 0;
      for(int i=0;i<nums.size();i++){
          int element = nums[i];
          element = abs(element);

          if(nums[element] > 0){
              nums[element] = - nums[element];
          }else{
              ans = element ;
          }
      }
      for(int i=0;i<nums.size();i++){
          nums[i] = abs(nums[i]);
      }

      return ans;
    }
};

