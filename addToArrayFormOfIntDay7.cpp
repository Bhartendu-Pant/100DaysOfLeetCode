/*
The array-form of an integer num is an array representing its digits in left to right order.

For example, for num = 1321, the array form is [1,3,2,1].
Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.

 

Example 1:

Input: num = [1,2,0,0], k = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234
Example 2:

Input: num = [2,7,4], k = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455
Example 3:

Input: num = [2,1,5], k = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021
 */

// solution function:
 vector<int> addToArrayForm(vector<int>& nums, int k) {
    vector<int> sum;
    int iterator = nums.size() - 1;
    int carry = 0;

    while (iterator >= 0 || k > 0) {
        int num;
        if(iterator >= 0)
        num=nums[iterator];
        else
        num=0;

        int k_rem = k % 10;
        int bigSum = carry + num + k_rem;
        int positionValue = bigSum % 10;
        carry = bigSum / 10;
        sum.insert(sum.begin(), positionValue);

        if (iterator >= 0) iterator--;
        if (k > 0) k /= 10;
    }
    if (carry > 0) sum.insert(sum.begin(), carry);
    return sum;
    }
