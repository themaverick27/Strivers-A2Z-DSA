/*
Problem Statement: Given an infix expression in the form of string s. Convert this infix expression to a prefix expression.

Infix expression: The expression of the form a op b. When an operator is in between every pair of operands.
Prefix Expression: The expression of type op a b. when the operator is placed before the operands.

Example 1:
Input: x+y*z/w+u
Output: ++x/*yzwu

Example 2:
Input: a+b
Output: +ab
*/
#include<bits/stdc++.h>
using namespace std;

int priority(char ch){
    if(ch == '^') return 3;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '+' || ch == '-') return 1;
    return -1;
}

string infixToPostfix(string s){
    string ans = "";
    stack<char> st;

    int i = 0;
    while(i < s.length()){
        // operand
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            ans += s[i];
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        // operator
        else{
            if(s[i] == '^'){
                while(!st.empty() && (priority(s[i]) <= priority(st.top()))){
                    ans += st.top();
                    st.pop();
                }
            }
            else{
                while(!st.empty() && (priority(s[i]) < priority(st.top()))){
                    ans += st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
        i++;
    }
    // if the stack has still elements
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
}

string infixToPrefix(string &s){
    reverse(s.begin(), s.end());

    // convert the '(' to ')' and vice-verse
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(') s[i] = ')';
        else if(s[i] == ')') s[i] = '(';
    }

    string ans = infixToPostfix(s);
    reverse(ans.begin(), ans.end());

    return ans;
}

int main(){
    string s = "(A+B)*C-D+F";

    string ans = infixToPrefix(s);
    cout << ans << endl;

    return 0;
}
// Time Complexity: O(n)
// Space Complexity: O(n)