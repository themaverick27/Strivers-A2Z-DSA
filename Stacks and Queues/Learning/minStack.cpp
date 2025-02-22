#include<bits/stdc++.h>
using namespace std;

// Approach-1: using pairs to store the value and minimum element till now. 
// Time Complexity: O(1) and Space Complexity: O(2*n)
class MinStackImp{
    stack<pair<int, int>> st; 

    public: 
    void PUSH(int x){
        if(st.empty()){
            st.push({x, x});
        }
        else{
            st.push({x, min(st.top().second, x)});
        }
    }

    int POP(){
        int popped = st.top().first;
        st.pop();
        return popped;
    }

    int TOP(){
        return st.top().first;
    }

    int getMin(){
        return st.top().second;
    }
};

// Approach-2: using a variable that holds minimum value
// Time Complexity: O(1) and Space Complexity: O(n)
class MinStack{
    stack<long long> st;
    long long mini;

    public:
    MinStack(){
        while(st.empty() == false) st.pop();
        mini = INT_MAX;
    }

    void PUSH(int value){
        long long val = (long long) value;
        if(st.empty()){
            st.push(val);
            mini = val;
        }
        else{
            if(val < mini){
                st.push(2 * value - mini);
                mini = val;
            }
            else st.push(val);
        }
    }

    void POP(){
        if(st.empty()) return;

        long long popped = st.top();
        st.pop();

        if(popped < mini){
            // get back to the previous smaller or minimum
            mini = 2 * mini - popped;
        }
    }

    int TOP(){
        if(st.empty()) return -1;

        long long element = st.top();
        if(element < mini) return mini;
        return element;
    }

    int getMin(){
        return mini;
    }

};
