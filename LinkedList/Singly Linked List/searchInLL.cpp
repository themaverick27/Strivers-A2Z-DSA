/*
Problem Statement: Given a linked list of n nodes and a key, the task is to check if the key is present in the linked list or not.

Example 1:
Input: n = 4, key = 3, Linked List: 1->2->3->4
Output: true
Explanation: 3 is present in Linked List, so the function returns true.

Example 2:
Input: n = 4, key = 3, Linked List: 1->2->7->4
Output: false
Explanation: 3 is not present in Linked List, so the function returns false.
*/

// function to search key in a linked list
bool searchKey(Node* head, int key){
    Node* temp = head;

    while(temp){
        if(temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}
// Time Complexity: O(n)
// Space Complexity: O(1)
