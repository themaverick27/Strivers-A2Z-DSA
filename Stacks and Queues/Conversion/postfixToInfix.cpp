/*
Problem Statement: You are given a string that represents the postfix form of a valid mathematical expression. Convert it to its infix form.

Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.

Example 1:
Input: ab*c+
Output: ((a*b)+c)
*/
#include<bits/stdc++.h>
using namespace std;

string postfixToInfix(string &s){
    stack<string> st;

    int i = 0;
    while(i < s.length()){
        // operand
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            string temp = "";
            temp += s[i];
            st.push(temp);
        }
        // operator
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            string exp = "(" + t2 + s[i] + t1 + ")";
            st.push(exp);
        }
        i++;
    }
    return st.top();
}

int main(){
    string s = "AB-DE+F*/";

    string ans = postfixToInfix(s);
    cout << ans << endl;

    return 0;
}
// Time Complexity: O(n)
// Space Complexity: O(n)