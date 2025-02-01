#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(const string& s, int low, int high){
    while(low < high){
        if(s[low] != s[high]) return false;

        low++;
        high--;
    }
    return true;
}

string longestPalindromicSubstring(string s){
    int n = s.size();

    // Approach-3: expansion from center - using two pointers
    // Time Complexity: O(n*n) and Space Complexity: O(1)

    int maxLen = 1, start = 0;
    for(int i = 0; i < n; i++){
        // this runs for two times - for odd length and for even length
        for(int j = 0; j <= 1; j++){
            int low = i;
            int high = i + j;   
            // Expand substring while it is a palindrome and in bounds
            while((low >= 0 && high < n) && (s[low] == s[high])){
                int currentLen = high - low + 1;
                if(currentLen > maxLen){
                    start = low;
                    maxLen = currentLen;
                }
                low--;
                high++;
            }
        }
    }
    return s.substr(start, maxLen);


    // Approach-2: Dynamic programming 

    // Approach-1: generate all substring and check if it is palindrome or not
    // Time Complexity: O(n*n*n) and Space Complexity: O(1)
    /*
    int maxLen = 1;
    int start = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){

            if(checkPalindrome(s, i, j) && (j - i + 1) > maxLen){
                start = i;
                maxLen = j - i + 1;
            }
        }
    }
    return s.substr(start, maxLen);
    */
}

int main(){
    string s = "babca";

    string ans = longestPalindromicSubstring(s);
    cout << ans << endl;

    return 0;
}