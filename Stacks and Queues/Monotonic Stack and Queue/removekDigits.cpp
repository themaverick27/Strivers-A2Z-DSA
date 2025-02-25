/*
Problem Statement: Given string num representing a non-negative integer num, and an integer k, 
return the smallest possible integer after removing k digits from num.

Example 1:
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Example 2:
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

Example 3:
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/
#include<bits/stdc++.h>
using namespace std;

string removeKDigits(string& num, int k){
    int n = num.size();

    // Approach-1: using stack 
    // Time Complexity: O(n) approx and Space Complexity: O(n)
    stack<char> st;
    for(int i = 0; i < n; i++){

        while(!st.empty() && k > 0 && (st.top() - '0' > num[i] - '0')){
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    // if k is still remaining 
    while(k > 0){
        st.pop();
        k--;
    }
    // if stack became empty
    if(st.empty()) return "0";
    
    string ans = "";
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    // trim zeros
    while(ans.size() != 0 && ans.back() == '0'){
        ans.pop_back();
    }

    reverse(ans.begin(), ans.end());
    if(ans.empty()) return "0";
    return ans;

}

int main(){
    string num = "1432219";
    int k = 3;

    string ans = removeKDigits(num, k);
    cout << ans << endl;

    return 0;
}