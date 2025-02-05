/*
Problem Statement: Given a Doubly Linked list and a position. The task is to delete a node from a given position 
(position starts from 1) in a doubly linked list and return the head of the doubly Linked list.

Example 1:
Input: LinkedList = 1 <--> 3 <--> 4, x = 3
Output: 1 <--> 3
Explanation: After deleting the node at position 3 (position starts from 1),the linked list will be now as 1 <--> 3.

Example 2:
Input: LinkedList = 1 <--> 5 <--> 2 <--> 9, x = 1
Output: 5 <--> 2 <--> 9
Explanation: After deleting the node at position 1 (position starts from 1),the linked list will be now as 5 <--> 2 <--> 9.
*/

Node* deleteKth(Node* head, int k){
    Node* temp = head;

    int count = 0;
    while(temp->next != nullptr){
        count++;
        if(k == count) break;
        temp = temp->next;
    }

    Node* back = temp->prev;
    Node* front = temp->next;

    if(back == NULL && front == NULL) return NULL; // list is empty
    else if(back == NULL){
        // kth node is head node
        Node* last = head;
        head = head->next;

        head->prev = nullptr;
        last->next = nullptr;

        delete last;
        return head;
    }
    else if(front == NULL){
        // kth node is tail node
        Node* last = temp->prev;
        last->next = nullptr;
        temp->prev = nullptr;
        delete temp;
        return head;
    }
    
    back->next = front;
    front->prev = back;

    temp->next = nullptr;
    temp->prev = nullptr;
    delete temp;

    return head;
}
// Time Complexity: O(n)
// Space Complexity: O(1)