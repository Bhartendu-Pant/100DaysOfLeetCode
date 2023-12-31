/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 
*/

//Solution:

/*** Time complexity  O(n log n)  ***/

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        if(s==t)return true;
        else return false;
    }
};


/*** Time complexity O(n)  ***/

class Solution {
public:
    bool isAnagram(string s, string t) {
        int freqTable[256]={0};
        for(int i=0;i<s.size();i++){
            freqTable[s[i]]++;
        }

         for(int i=0;i<t.size();i++){
            freqTable[t[i]]--;
        }

        for(int i=0 ;i<256;i++){
            if(freqTable[i]!=0)
            return false;
        }

        return true;
    }
};
