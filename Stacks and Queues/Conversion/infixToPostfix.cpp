/*
Problem Statement: Given an infix expression in the form of string str, convert it to a postfix expression.

Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.

Note: The order of precedence is: ^ greater than * equals to / greater than + equals to -.

Example 1:
Input: s = "a+b*(c^d-e)^(f+g*h)-i"
Output: abcd^e-fgh*+^*+i-

Example 2:
Input: s = "A*(B+C)/D"
Output: ABC+*D/
*/
#include<bits/stdc++.h>
using namespace std;

int priority(char ch){
    if(ch == '^') return 3;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '+' || ch == '-') return 1;
    return -1;
}

string infixToPostfix(string &s){
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
            // keep popping out and add operator to the ans, till you get '(' opening braces at top of the stack
            while(st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop(); // pop out the '('
        }
        else{
            if(!st.empty() && (priority(s[i]) <= priority(st.top()))){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }

        i++;
    }
    // add the operator from the stack to the ans and pop it out
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
}


int main(){
    string s = "a+b*(c^d-e)";

    string postfix = infixToPostfix(s);
    cout << postfix << endl;

    return 0;
}
// Time Complexity: O(n)
// Space Complexity: O(n)