#include<bits/stdc++.h>
using namespace std;

int countNumberOfSubstring(string &s, int k){
    int n = s.size();

    // Approach-1: 
    // Time Complexity: O(n*n) and Space Complexity: O(1)
    int ans = 0;
    for(int i = 0; i < n; i++){
        int distinctCount = 0;
        vector<int> freq(26, 0);

        for(int j = i; j < n; j++){
            if(freq[s[j] - 'a'] == 0) distinctCount++;

            freq[s[j] - 'a']++;

            if(distinctCount == k) ans++;
            if(distinctCount > k) break;
        }
    }
    return ans;
}

int main(){
    string s = "abaaca";
    int k = 1;

    int ans = countNumberOfSubstring(s, k);
    cout << ans << endl;

    return 0;
}