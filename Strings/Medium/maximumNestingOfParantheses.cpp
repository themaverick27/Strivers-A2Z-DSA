#include<bits/stdc++.h>
using namespace std;

int maxDepth(string s){
    int n = s.size();

    // Approach-1: traverse and count the () and update the maximum depth (ans) with the current max value
    // Time Complexity: O(n) and Space Complexity: O(1)
    int ans = 0, count = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            count++;
        }
        else if(s[i] == ')'){ 
            count--;
        }
        ans = max(ans, count);
    }
    return ans;
}


int main(){
    string s = "(1+(2*3)+((8)/4))+1";

    int ans = maxDepth(s);
    cout << ans  << endl;

    return 0;
}