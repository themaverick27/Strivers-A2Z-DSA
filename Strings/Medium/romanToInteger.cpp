#include<bits/stdc++.h>
using namespace std;

/*
int number(char ch){
    if(ch == 'I') return 1;
    else if(ch == 'V') return 5;
    else if(ch == 'X') return 10;
    else if(ch == 'L') return 50;
    else if(ch == 'C') return 100;
    else if(ch == 'D') return 500;
    else if(ch == 'M') return 1000;
}
*/

int romanToInt(string s){
    int n = s.size();

    // Approach-1: by converting each char to its corresponding int value
    // Time Complexity: O(n) and Space Complexity: O(1)

    unordered_map<char, int> number = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

    int sum = 0;
    for(int i = 0; i < n; i++){
        // if the next character is greater than current, take -ve value of current
        if(number[s[i]] < number[s[i + 1]]){
            sum -= number[s[i]];
        }
        // if the next character is smaller or equal to current, take +ve value of current
        else sum += number[s[i]];
    }
    return sum;
}

int main(){
    string s = "XLIII";

    int ans = romanToInt(s);
    cout << ans << endl;

    return 0;
}