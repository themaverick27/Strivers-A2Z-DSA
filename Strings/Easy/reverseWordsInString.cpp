#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s){
    int n = s.size();

    // Approach-1: Hashing, storing word one by one into vector and adding from the end to create reverse string
    // Time Complexity: O(n) approx and Space Complexity: O(n)

    // removing leading or trailing spaces
    int firstIndex = 0, lastIndex = n-1;
    while(s[firstIndex] == ' '){
        firstIndex++;
    }
    while(s[lastIndex] == ' '){
        lastIndex--;
    }
    // cout << firstIndex << " " << lastIndex << endl;

    vector<string> words;
    string temp;
    for(int i = firstIndex; i <= lastIndex; i++){
        if(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0' && s[i] <= '9' || s[i] >= 'a' && s[i] <= 'z'){
            temp += s[i];
        }
        else if(s[i] == ' ' && s[i-1] != ' '){
            words.push_back(temp);
            temp = "";
        }
    }
    words.push_back(temp);

    string ans = "";
    for(int i = words.size() - 1; i >= 0; i--){
        ans += words[i];
        if(i == 0) continue;;
        ans += ' ';
    }
    return ans;
}

int main(){
    string sentence = "   ";

    string ans = reverseWords(sentence);
    cout << ans << endl;

    return 0;
}

// "the sky is blue"
// "   hello   world   "   
// "a good   example"
// " "
// "          "
// "  h    "