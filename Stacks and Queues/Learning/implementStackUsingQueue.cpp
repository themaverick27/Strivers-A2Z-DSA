#include<bits/stdc++.h>
using namespace std;

class StackImp{
    queue<int> q;

    public:
    void PUSH(int x){
        int s = q.size();
        q.push(x);

        for(int i = 0; i < s; i++){
            q.push(q.front());
            q.pop();
        }
    }

    int POP(){
        int popped = q.front();
        q.pop();
        return popped;
    }

    int SIZE(){
        return q.size();
    }

    int TOP(){
        return q.front();
    }
};

int main(){
    StackImp st;
    st.PUSH(4);
    st.PUSH(2);
    st.PUSH(8);
    st.PUSH(7);

    cout << "Top of the stack: " << st.TOP() << endl;
    cout << "Size of the stack before removing element: " << st.SIZE() << endl;
    cout << "The deleted element is: " << st.POP() << endl;
    cout << "Top of the stack after removing element: " << st.TOP() << endl;
    cout << "Size of the stack after removing element: " << st.SIZE() << endl;

    return 0;
}