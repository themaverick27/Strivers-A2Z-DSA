/*
Problem Statement: Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

Note: An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false
*/
#include<bits/stdc++.h>
using namespace std;

bool isValid(string s){
    // Approach-1: using stack - to store last previous opening brackets
    // Time Complexity: O(n) and Space Complexity: O(n)

    stack<char> st;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            st.push(s[i]);
        }
        else{
            if(!st.empty() && (
                ((st.top() == '(' && s[i] == ')') ||
                (st.top() == '{' && s[i] == '}') ||
                (st.top() == '[' && s[i] == ']')
            ))){
                st.pop();
            }
            else return false; // not balanced
        }
    }
    return st.empty();
}

int main(){
    string s = "(){}{}[]";

    if(isValid(s)){
        cout << "Balanced/Valid Parantheses" << endl;
    }
    else cout << "Unbalanced/Not Valid Paranthese" << endl;

    return 0;
}