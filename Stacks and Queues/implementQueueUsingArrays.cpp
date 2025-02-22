#include<bits/stdc++.h>
using namespace std;

class QueueImp{ 
    int *arr;
    int start, end, size, currSize;

    public:
    QueueImp(){
        size = 1000;
        start = -1;
        end = -1;
        currSize = 0;
        arr = new int[size];
    }

    void PUSH(int x){
        if(currSize == size){
            cout << "Queue is full" << endl;
            exit(0);
        }

        if(start == -1 && end == -1){
            start = 0;
            end = 0;
        }
        else end = (end + 1) % size;

        arr[end] = x;
        currSize += 1;
    }

    int POP(){
        if(currSize == 0){
            cout << "Queue is Empty" << endl;
            exit(0);
        }

        int popped = arr[start];
        if(currSize == 1){
            start = -1;
            end = -1;
        }
        else start = (start + 1) % size;
        currSize -= 1;

        return popped;
    }

    int TOP(){
        if(currSize == 0){
            cout << "Queue is Empty" << endl;
            exit(0);
        }
        return arr[start];
    }

    int SIZE(){
        return currSize;
    }
};

int main(){
    QueueImp q;
    q.PUSH(4);
    q.PUSH(14);
    q.PUSH(24);
    q.PUSH(34);

    cout << q.TOP() << endl;
    cout << q.SIZE() << endl;
    cout << q.POP() << endl;
    cout << q.TOP() << endl;
    cout << q.SIZE() << endl;

    return 0;
}