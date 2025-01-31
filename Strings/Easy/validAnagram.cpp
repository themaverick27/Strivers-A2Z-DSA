#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t){
    // Approach-2: using frequency array
    // Time Complexity: O(m + n) and Space Complexity: O(1)

    if(s.size() != t.size()) return false;

    vector<int> frequency(26, 0);
    for(int i = 0; i < s.size(); i++){
        frequency[s[i] - 'a']++;
        frequency[t[i] - 'a']--;
    }

    for(int i = 0; i < 26; i++){
        if(frequency[i] != 0) return false;
    }
    return true;


    // Approach-1: using sorting
    // Time Complexity: O(m*log(m) + n*log(n)) and Space Complexity: O(1)
    /*
    if(s.size() != t.size()) return false;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    for(int i = 0; i < s.size(); i++){
        if(s[i] != t[i]) return false;
    }
    return true;

    // return s1 == s2;
    */
}

int main(){
    string s = "car";
    string t = "rat";

    if(isAnagram(s, t)) cout << "ANAGRAMS" << endl;
    else cout << "NOT ANAGRAMS" << endl;

    return 0;
}