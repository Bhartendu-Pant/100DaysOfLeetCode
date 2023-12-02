/*
Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is 
the smallest in lexicographical order
 among all possible results.

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.
 
*/

//Solution:

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string result;
        unordered_map<char,bool>hashmap;
        unordered_map<char, int> lastOccurrence;
        for (int i = 0; i < s.size(); ++i) {
            lastOccurrence[s[i]] = i;
        }
        for(int i=0;i<s.length();i++)
        {
            if(!hashmap[s[i]])
            {
                while(!result.empty() && s[i] < result.back() && i < lastOccurrence[result.back()])
                {
                    hashmap[result.back()]=false;
                    result.pop_back();
                }
                hashmap[s[i]]=true;
                result.push_back(s[i]);
            }
        }
        return result;
    }
};
