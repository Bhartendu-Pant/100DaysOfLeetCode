/*
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
*/

//Solution:
//T.C. O(k)  using min priority queue
 int findKthLargest(vector<int>& nums, int k) {
       //Default priority queue in cpp is max priority queue
       //To make it min priority queue use greater operator

       priority_queue<int,vector<int>,greater<int>>pq;
       for(int i=0;i<nums.size();i++){
           if(pq.size()<k){
               pq.push(nums[i]);
           }
           else if(pq.top()<nums[i]){
               pq.pop();
               pq.push(nums[i]);
           }
       }
       return pq.top();
    }
