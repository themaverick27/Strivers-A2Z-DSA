#include<bits/stdc++.h>
using namespace std;

typedef pair<char, int> P;

string sortCharByFrequency(string s){
    int n = s.size();

    // Approach-3: 
    // Time Complexity: O(n*log n) and Space Complexity: O(n)
    vector<P> v(123);

    for(char &ch: s){
        int freq = v[ch].second;
        v[ch] = {ch, freq+1}; // v [.... (e, 2) ... (r, 1) .. (t, 1)]
    } 

    // comparator fn
    auto lambda = [&](P &p1, P &p2){
        return p1.second > p2.second;
    };  

    // sorting in descending order with the frequency (second) value
    sort(v.begin(), v.end(), lambda); // v [(e, 2), (r, 1), (t, 1), (A, 0), (B, 0) ....]
    

    string ans;
    for(int i = 0; i < 123; i++){
        if(v[i].second > 0){
            char ch = v[i].first;
            int freq = v[i].second;

            string temp = string(freq, ch);
            ans += temp;
        }
    }
    return ans;


    // Approach-2: store the char with frequency in the map and then into the vector and sort the vector with comparator fn (descending order)
    // Time Complexity: O(n*log n) and Space Complexity: O(n)
    /*
    unordered_map<char, int> mpp;
    vector<pair<int, int>> vec;

    for(int i = 0; i < n; i++){
        mpp[s[i]]++;
    }

    for(auto it: mpp){
        vec.push_back({it.first, it.second});
    }

    auto lambda = [](pair<char, int> &p1, pair<char,int> &p2){
        return p1.second > p2.second;
    };

    sort(vec.begin(), vec.end(), lambda);

    string ans;
    for(int i = 0; i < vec.size(); i++){
        if(vec[i].second > 0){
            char ch = vec[i].first;
            int freq = vec[i].second;

            ans += string(freq, ch);
        }
    }
    return ans;
    */

   // Approach-1: Using Heap - priority queue
    
}

int main(){
    string s = "tree";

    string ans = sortCharByFrequency(s);
    cout << ans << endl;

    return 0;
}