/*
Problem Statement: Given a singly linked list. The task is to find the length of the linked list, 
where length is defined as the number of nodes in the linked list.

Example 1:
Input: LinkedList : 1->2->3->4->5
Output: 5

Example 2:
Input: LinkedList : 2->4->6->7->5->1->0
Output: 7
*/

// function to find the length of linked list
int getCount(struct Node* head){
    int count = 0;

    Node *temp = head;
    while(temp != nullptr){
        count++;
        temp = temp->next;
    }
    return count;
}
// Time Complexity: O(n)
// Space Complexity: O(1)