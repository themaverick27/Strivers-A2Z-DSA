#include<bits/stdc++.h>
using namespace std;

string largestOddNumber(string s){
    int n = s.size();

    // Approach-1: iterating from the last and finding the odd digit
    // Time Complexity: O(n) and Space Complexity: O(n)
    if(s[n-1] == '1' || s[n-1] == '3' || s[n-1] == '5' || s[n-1] == '7' || s[n-1] == '9') return s;

    for(int i = n-2; i >= 0; i--){
        if(s[i] == '1' || s[i] == '3' || s[i] == '5' || s[i] == '7' || s[i] == '9'){
            return s.substr(0, i+1);
        }
    }

    return "";
}

int main(){
    string num = "523478";

    string ans = largestOddNumber(num);
    cout << ans << endl;

    return 0;
}