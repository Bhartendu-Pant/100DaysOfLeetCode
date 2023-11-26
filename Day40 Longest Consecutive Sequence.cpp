/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

//Solution:
/**********           Using a Set  O(n)           ************/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;

        int longest = 1;
        unordered_set<int>set;
        for(int i=0;i<len;i++){
            set.insert(nums[i]);
        }

        for(auto it:set){
            if(set.find(it-1)==set.end()){
                int count = 1;
                int temp = it;
                while(set.find(temp+1) != set.end()){
                    temp = temp + 1;
                    count = count + 1;
                }
                longest =max(longest,count);
            }
        }
        return longest;
    }
};




/********** Using a priority queue (greater than O(n) ************/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
        return 0;
        if(nums.size()==1)
        return 1;
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int length=1;
        int tempLength = 1;
        int currVal = pq.top();
        pq.pop();
        while(! pq.empty()){
            if(pq.top()==currVal){
                pq.pop();
                continue;
            }
            
            if(pq.top()+1 == currVal){
                currVal = pq.top();
                tempLength++;
                if(tempLength > length)
                length = tempLength;

                pq.pop();
            }
            else{
                currVal=pq.top();
                pq.pop();
                tempLength=1;
            }
            

        }
        return length;
    }
};
