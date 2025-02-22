#include<bits/stdc++.h>
using namespace std;

// Approach-1: Using two stacks, Push Operation: O(2*N)
class QueueImp{
    stack<int> s1, s2;

    public:
    void PUSH(int x){
        // step 1 - take everything in stack 2
        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }
        // step 2 - push or add the element
        s1.push(x);

        // step 3 - take everything back in stack 1
        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    int POP(){
        if (s1.empty()) {
            cout << "Stack is empty";
            exit(0);
        }
        int popped = s1.top();
        s1.pop();
        return popped;
    }

    int SIZE(){
        return s1.size();
    }

    int FRONT(){
        if (s1.empty()) {
            cout << "Stack is empty";
            exit(0);
        }
        return s1.top();
    }

};

// Approach-2: Using two stacks, Push Operation: O(1)
class MyQueue{
    stack<int> s1, s2;
    public:
    void PUSH(int x){
        s1.push(x);
    }

    int POP(){
        if(s2.empty()){
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
        }

        int popped = s2.top();
        s2.pop();
        return popped;
    }

    int FRONT(){
        if(s2.empty()){
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    int SIZE(){
        return (s1.size() + s2.size());
    }
};


int main(){
    MyQueue q;

    q.PUSH(3);
    q.PUSH(4);
    cout << "The element popped is: " << q.POP() << endl;

    q.PUSH(5);
    cout << "The top of the queue is: " << q.FRONT() << endl;
    cout << "The size of the queue is: " << q.SIZE() << endl;

    return 0;
}