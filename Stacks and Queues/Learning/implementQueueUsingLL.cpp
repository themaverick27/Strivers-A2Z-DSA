#include<bits/stdc++.h> 
using namespace std;

class QueueNode{
    public: 
        int val;
        QueueNode *next;
        QueueNode(int data){
            val = data;
            next = nullptr;
        }
};      
QueueNode *Front = nullptr, *Rare = nullptr;

class QueueImp{
    public:
        int size = 0;

        bool Empty();
        void Enqueue(int x);
        void Dequeue();
        int Peek();
};  

bool QueueImp :: Empty(){
    return (Front == nullptr);
}  

int QueueImp :: Peek(){
    if(Empty()){  
        cout << "Queue is Empty" <<endl;
        return -1;
    } 
    else return Front->val;
}   

void QueueImp :: Enqueue(int x){
    QueueNode *Temp = new QueueNode(x); 

    if(Temp == nullptr){
        cout << "Queue is Full" << endl;
    }
    else{
        if(Front == nullptr){
            Front = Temp;
            Rare = Temp;
        } 
        else{
            Rare->next = Temp;
            Rare = Temp;
        }
        cout << "Inserted into Queue: " << x <<endl;
        size++;
    } 
}      

void QueueImp :: Dequeue() {
    if(Front == nullptr){
        cout << "Queue is Empty" << endl;
    }
    else{ 
        cout << Front->val << " Removed From Queue" << endl;
        QueueNode *Temp = Front;
        Front = Front->next;
        delete Temp;
        size--;
    }  
} 


int main(){
    QueueImp q;

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);
    
    q.Dequeue();
    cout << "The size of the Queue is: " << q.size << endl;
    cout << "The Peek element of the Queue is: " << q.Peek() << endl;

    return 0;
} 