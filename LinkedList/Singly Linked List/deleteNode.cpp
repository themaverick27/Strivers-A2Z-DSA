/*
Problem Statement: Given a singly linked list and an integer, x. Delete the xth node (1-based indexing) 
from the singly linked list.

Example 1:
Input: Linked list: 1 -> 3 -> 4, x = 3
Output: 1 -> 3

Example 2:
Input: Linked list: 1 -> 5 -> 2 -> 9, x = 2 
Output: 1 -> 2 -> 9
*/

// function to delete xth node from a linked list
Node* deleteNode(Node* head, int x){
    if(head == nullptr) return head;

    if(x == 1){
        Node* temp = head;
        head = temp->next;
        free(temp);
        return head;
    }

    int count = 0;
    Node* curr = head, *prev;
    while(curr != nullptr){
        count++;
        if(x == count){
            prev->next = curr->next->next;
            free(curr);
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    return head;
}
// Time Complexity: O(n) 
// Space Complexity: O(1)