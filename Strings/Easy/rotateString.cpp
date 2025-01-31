#include<bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal){
    int m = s.size();
    int n = goal.size();

    // Approach-3: string concatenation and finding the goal as substring 
    // Time Complexity: O(n) and Space Complexity: O(n)
    if(m != n) return false;

    for(int i = 0; i < m; i++){
        if((s+s).find(goal) != string::npos) return true;
    }
    return false;

    // Approach-2: string matching - KMP Algorithm
    // Time Complexity: O(n) and Space Complexity: O(n)
    

    // Approach-1: by performing all possible shifts on s
    // Time Complexity: O(n*n) and Space Complexity: O(1)
    /*
    if(m != n) return false;

    for(int i = 0; i < m; i++){
        if(s == goal) return true;
        rotate(s.begin(), s.begin() + 1, s.end()); // left rotate by 1 place
    }
    return false;
    */
}

int main(){
    string s = "abcde";
    string goal = "cdeab";

    if(rotateString(s, goal)) cout << "true" << endl;
    else cout << "false" << endl;

    return 0;
}