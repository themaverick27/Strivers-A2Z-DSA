#include<bits/stdc++.h>
using namespace std;

int myAtoi(string s){

    // Approach-1: 
    // Time Complexity: O(n) and Space Complexity: O(1)
    int sign = 1, ans = 0, start = 0;

    // skipping leading whitespaces
    while(s[start] == ' '){
        start++;
    }

    // check the nature of s (+ or -)
    if(s[start] == '-' || s[start] == '+'){
        if(s[start++] == '-') sign = -1;
    }

    // construct the number
    while(s[start] >= '0' && s[start] <= '9'){

        // handle overflow/underflow test case
        if(ans > INT_MAX/10 || (ans == INT_MAX/10 && s[start] - '0' > 7)){
            return sign == 1 ? INT_MAX : INT_MIN;
        }
        ans = 10 * ans + (s[start++] - '0');
    }
    return ans * sign;
}

int main(){
    string s = "42";

    int ans = myAtoi(s);
    cout << ans << endl;

    return 0;
}