/*
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

 

Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 109
*/

//Solution:
 bool compare(int s1,int s2){
        return to_string(s1)+to_string(s2) > to_string(s2)+to_string(s1);
    }
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),compare); // custom sort function
        string ansString="";
        
        for(int i=0;i<nums.size();i++){
            ansString += to_string(nums[i]);
        }
        if(ansString[0]=='0')return "0";
        return ansString;
    }
};
