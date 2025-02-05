/*
Problem Statement: Given a doubly-linked list, a position p, and an integer x. The task is to add a new node with value x at the 
position just after pth node in the doubly linked list and return the head of the updated list.

Example 1: 
Input: LinkedList: 2<->4<->5, p = 2, x = 6 
Output: 2<->4<->5<->6
Explanation: p = 2, and x = 6. So, 6 is inserted after p, i.e, at position 2 (0-based indexing).

Example 2:
Input: LinkedList: 1<->2<->3<->4, p = 0, x = 44
Output: 1<->44<->2<->3<->4
Explanation: p = 0, and x = 44 . So, 44 is inserted after p, i.e, at position 0 (0-based indexing).
*/

Node *addNode(Node *head, int pos, int data) {
    int count = -1;
    Node* temp = head;
    while(temp->next != NULL){
        count++;
        if(pos == count) break;
        temp = temp->next;
    }
        
    // we reached to the end of LL
    if(temp->next == NULL){
        Node* newNode = new Node(data);
        newNode->prev = temp;        
        temp->next = newNode;
        return head;
    }
        
    Node* front = temp->next;
    Node* newNode = new Node(data);
    newNode->next = front;
    newNode->prev = temp;
        
    temp->next = newNode;
    front->prev = newNode;
        
    return head;
}
// Time Complexity: O(n)
// Space Complexity: O(1)