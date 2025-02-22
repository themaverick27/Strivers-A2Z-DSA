#include<bits/stdc++.h>
using namespace std;

struct StackNode{
    int data;
    StackNode* next;
    StackNode(int x){
        data = x;
        next = NULL;
    }
};

class StackImp{
    StackNode* top;
    int size;

    public:
    StackImp(){
        top = NULL;
        size = 0;
    }

    void PUSH(int x){
        StackNode* element = new StackNode(x);
        element->next = top;
        top = element;
        size++;
    }

    int POP(){
        if(top == NULL){
            return -1;
        }
        StackNode* temp = top;

        int value = top->data;
        top = top->next;
        delete temp;
        size--;
        
        return value;
    }

    int SIZE(){
        return size;
    }

    int TOP(){
        if(top == NULL) return -1;
        return top->data;
    }

    bool ISEMPTY(){
        return top == NULL;
    }

    void printStack(){
        StackNode* curr = top;
        while(curr != NULL){
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
};

int main(){
    StackImp st;

    st.PUSH(10);
    st.PUSH(50);
    st.PUSH(30);

    cout << "Element popped: " << st.POP() << endl;
    cout << "Stack size: " << st.SIZE() << endl;
    cout << "Stack empty or not? "<< st.ISEMPTY() << endl;
    cout << "stack's top element: " << st.TOP() << endl;
    
    return 0;
}