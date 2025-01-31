#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& s){
    int n = s.size();

    // Approach-1: sort the list lexicographically, then iterate over the vector, and check append accordingly
    // Time Complexity: O(n*log n) approx and Space Complexity: O(1)
    
    // Sorting the list lexicographically
    sort(s.begin(), s.end());

    string first = s[0];
    string last = s[n-1];

    string ans = "";
    for(int i = 0; i < min(first.size(), last.size()); i++){
        // current character of the first string is not equal to the current character of the last string
        if(first[i] != last[i]){
            return ans; 
        }
        ans += first[i]; // add the current character to the ans string
    }
    return ans; 
}

int main(){
    vector<string> strs{"flower","flow","flight"};

    string ans = longestCommonPrefix(strs);
    cout << ans << endl;

    return 0;
}