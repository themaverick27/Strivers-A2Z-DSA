/*
Problem Statement: You are given a string that represents the prefix form of a valid mathematical expression. Convert it to its postfix form.

Prefix Expression: The expression of type op a b. when the operator is placed before the operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.

Example 1:
Input: *-A/BC-/AKL
Output: ABC/-AK/L-*
*/
#include<bits/stdc++.h>
using namespace std;

string prefixToPostfix(string &s){
    stack<string> st;

    int i = s.length() - 1;
    while(i >= 0){
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

            st.push(t1 + t2 + s[i]);
        }
        i--;
    }
    return st.top();
}

int main(){
    string s = "/-AB*+DEF";

    string ans = prefixToPostfix(s);
    cout << ans << endl;

    return 0;
}
// Time Complexity: O(n)
// Space Complexity: O(n)