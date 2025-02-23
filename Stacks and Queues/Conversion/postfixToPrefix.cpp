/*
Problem Statement: You are given a string that represents the postfix form of a valid mathematical expression. Convert it to its prefix form.

Prefix Expression: The expression of type op a b. when the operator is placed before the operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.

Example 1:
Input: ABC/-AK/L-*
Output: *-A/BC-/AKL

Example 2:
Input: ab+
Output: +ab
*/
#include<bits/stdc++.h>
using namespace std;

string postfixToPrefix(string &s){
    stack<string> st;

    int i = 0;
    while(i < s.length()){
        // operand
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            string op(1, s[i]);
            st.push(op);
        }
        // operator
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            st.push(s[i] + t2 + t1);
        }
        i++;
    }
    return st.top();
}

int main(){
    string s = "AB-DE+F*/";

    string ans = postfixToPrefix(s);
    cout << ans << endl;

    return 0;
}
// Time Complexity: O(n)
// Space Complexity: O(n)