/*
Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).
 

Example 1:

Input: nums = [3,4,5,2]
Output: 12 
Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 
Example 2:

Input: nums = [1,5,4,5]
Output: 16
Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum value of (5-1)*(5-1) = 16.

*/

// Solution function:

 //bruteforce
     //     int i;
     //     int j;
     //     int max=INT_MIN;
       
     //    for(i=0;i< nums.size()-1;i++){
     //        for(j=i+1;j<nums.size();j++){
    //            int currMax = (nums[i]-1)*(nums[j]-1);
     //            if(currMax > max)
     //            max = currMax;
     //        }
     //    }
     //    return max;


 int maxProduct(vector<int>& nums) {
    // optimal way - find first two largest numbers      
    int firstLargest = INT_MIN;
    int secondLargest = INT_MIN;                         
    for(int i=0;i<nums.size();i++){
        if(nums[i]>firstLargest){
            secondLargest = firstLargest;
            firstLargest = nums[i];
        }
        else if(nums[i] > secondLargest){
            secondLargest = nums[i];
        }
    }
    return (firstLargest-1)*(secondLargest-1);
    }

