/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

//Solution
class Solution {
public:
    bool isValid(string s) {
       stack<char>st;
        char x;
        int len=s.length();
        int i;
        for( i=0;i<len;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }       
        if(st.empty())
            return false; 
        switch(s[i]){
            case ')':
            x=st.top();
            st.pop(); 
            if(x=='{' || x=='[')
                return false;
            break;
            
            case '}':
            x=st.top();
            st.pop();
            
            if(x=='(' || x=='[')
                return false;
            break;
        
        
            case ']':
            x=st.top();
            st.pop();
            
            if(x=='{' || x=='(')
                return false;
            break;
        
        }
        }
        
        return (st.empty());
        
        
    }
};
