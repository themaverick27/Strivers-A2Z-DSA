#include<bits/stdc++.h>
using namespace std;

bool checkIsmorphic(string s, string t){
    int n = s.size();

    // Approach-1: Hashmap 
    // Time Complexity: O(n) and Space Complexity: O(n)
    unordered_map<char, char> mpp1; 
    unordered_map<char, char> mpp2;

    for(int i = 0; i < n; i++){
        char ch1 = s[i];
        char ch2 = t[i];

        if((mpp1.find(ch1) != mpp1.end() && mpp1[ch1] != ch2) || (mpp2.find(ch2) != mpp2.end() && mpp2[ch2] != ch1)){
            return false;
        }
        mpp1[s[i]] = t[i];
        mpp2[t[i]] = s[i];
    }
    return true;
}

int main(){
    string s = "add";
    string t = "egg";

    if(checkIsmorphic(s, t)){
        cout << "true" << endl;
    }
    else cout << "false" << endl;

    return 0;
}

// corner case examples to try -> s = "badc", t = "baba"
// corner case examples to try -> s = "xadc", t = "babt"