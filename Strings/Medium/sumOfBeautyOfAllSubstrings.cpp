#include<bits/stdc++.h>
using namespace std;

int beautyString(string s){
    int n = s.size();

    // Approach-2: using map | generating all possible substring and finding max, min count 
    // Time Complexity: O(n*n) and Space Complexity: O(n) approx
    
    int sum = 0;
    for(int i = 0; i < n; i++){
        unordered_map<char, int> freq; // to store the count of each character in the current substring
        for(int j = i; j < n; j++){
            freq[s[j]]++;

            int maxx = INT_MIN; // maximum values in the frequency map
            int minn = INT_MAX; // minimum values in the frequency map

            for(auto it: freq){
                maxx = max(maxx, it.second);
                minn = min(minn, it.second);
            }
            sum += maxx - minn; // keep addding the difference of maximum and minimum
        }
    }
    return sum;

    // Approach-1: using vector | generating all possiv=ble substring and finding max, min count
    // Time Complexity: O(n*n) approx and Space Complexity: O(n) approx
    /*
    int sum = 0;
    for(int i = 0; i < n; i++){
        vector<int> freq(26, 0);
        for(int j = i; j < n; j++){
            char ch = s.at(j);
            freq[ch - 'a']++;

            int maxx = INT_MIN;
            int minn = INT_MAX;
            for(int k = 0; k < 26; k++){
                if(freq[k] > 0){
                    maxx = max(maxx, freq[k]);
                    minn = min(minn, freq[k]);
                }
            }
            sum += maxx - minn;
        }
    }
    return sum;
    */
}


int main(){
    string s = "aabcb";

    int ans = beautyString(s);
    cout << ans <<endl;

    return 0;
}