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


#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty() || 
                (s[i] == ')' && st.top() != '(') ||
                (s[i] == ']' && st.top() != '[') ||
                (s[i] == '}' && st.top() != '{')) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};

int main() {
    Solution solution;
    
    // Example 1
    string example1 = "()";
    cout << "Example 1: " << solution.isValid(example1) << endl;
    
    // Example 2
    string example2 = "()[]{}";
    cout << "Example 2: " << solution.isValid(example2) << endl;
    
    // Example 3
    string example3 = "(]";
    cout << "Example 3: " << solution.isValid(example3) << endl;
    
    return 0;
}
