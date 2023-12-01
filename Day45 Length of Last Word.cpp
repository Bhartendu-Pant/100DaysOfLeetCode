/*
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal 
substring
 consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
 

Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.
*/

//Solution:

class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int itr=s.length()-1;
        int cnt=0;
        while(s[itr]==' '){
            itr--;
        }
        while( itr>=0 && s[itr]!=' '){
            if(typeid(s[itr])==typeid(char)){  //typeid to check current value is char or not
            cnt++;
            }
            itr--;
        }
        return cnt;
    }
};
