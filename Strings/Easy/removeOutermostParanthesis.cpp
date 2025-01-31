#include<bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s){
    int n = s.size();

    // Approach-1: iterate and check the valid paranthesis with the help of count variable
    // Time Complexity: O(n) and Space Complexity: O(n) 
    int count = 0;  // to keep track of ( and )
    string ans = ""; 

    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            // count > 0, means this is not the outermost opening paranthesis, add it to ans
            if(count > 0){
                ans += s[i];
            }
            count++;
        }
        else if(s[i] == ')'){
            count--;
            // count > 0, means this is not the outermost closing paranthesis, add it to ans
            if(count > 0){
                ans += s[i];
            }
        }
    }
    return ans;
}

int main(){
    string s = "(()())(())(()(()))";

    string ans = removeOuterParentheses(s);
    cout << ans << endl;

    return 0;
}