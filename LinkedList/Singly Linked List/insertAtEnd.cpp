/*
Problem Statement: Given the head of a Singly Linked List and a value x, insert that value x at the end of the LinkedList 
and return the modified Linked List.

Example 1:
Input: LinkedList: 1->2->3->4->5 , x = 6
Output: 1->2->3->4->5->6

Example 2:
Input: LinkedList: 5->4 , x = 1
Output: 5->4->1
*/

// function to insert node at the end of Linked List
Node* insertAtEnd(Node* head, int x){
    if(head == nullptr) return new Node(x);

    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    Node* newNode = new Node(x);
    temp->next = newNode;

    return head;
}
// Time Complexity: O(n)
// Space Complexity: O(1)