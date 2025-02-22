#include<bits/stdc++.h>
using namespace std;

class StackImp{
    int size;
    int *arr;
    int top;

    public:
    StackImp(){
        size = 1000;
        arr = new int[size];
        top = -1;
    }

    void PUSH(int x){
        top = top + 1;
        arr[top] = x;
    }

    int POP(){
        if(top == -1){
            // empty stack
        }
        int popped = arr[top];
        top = top - 1;

        return popped;
    }

    int TOP(){
        if(top == -1){
            // empty stack, no top element
        }
        return arr[top];
    }

    int SIZE(){
        return top + 1;
    }
};

int main(){
    StackImp st;

    st.PUSH(4);
    st.PUSH(7);
    st.PUSH(12);
    st.PUSH(10);

    cout << st.TOP() << endl;
    cout << st.SIZE() << endl;

    cout << st.POP() << endl;

    st.PUSH(2);
    cout << st.SIZE() << endl;


    return 0;
}