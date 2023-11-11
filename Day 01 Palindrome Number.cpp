/* Given an integer x, return true if x is a 
palindrome
, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome. */


// C++ Solution Function:

 bool isPalindrome(int x) {
        if(x < 0)           // edge case given in example 2
        return false; 
        int rem=0;
        long long  curr=0;  // long long because of the given constraints
        int target=x;  

        while( target != 0){

            rem=target%10;
            curr=curr*10+rem;
            target=target/10;
        }

        if(curr==x)return true;
        else return false;
    }
