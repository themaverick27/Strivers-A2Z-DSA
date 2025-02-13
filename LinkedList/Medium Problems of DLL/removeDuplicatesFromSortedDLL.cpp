/*
Problem Statement: Given a doubly linked list of n nodes sorted by values, 
the task is to remove duplicate nodes present in the linked list.

Example 1:
Input: n = 6, 1<->1<->1<->2<->3<->4
Output: 1<->2<->3<->4
Explanation:Only the first occurance of node with value 1 is retained, rest nodes with value = 1 are deleted.

Example 2:
Input: n = 7, 1<->2<->2<->3<->3<->4<->4
Output: 1<->2<->3<->4
Explanation: Only the first occurance of nodes with values 2,3 and 4 are retained, rest repeating nodes are deleted.
*/

Node* removeDuplicates(Node* head){
    // Approach-1: traverse and find duplicates, delete them and do the neccessart link changes
    // Time Complexity: O(n) and Space Complexity: O(1)
    Node* temp = head;
    while(temp != nullptr && temp->next != nullptr){

        Node* front = temp->next;
        while(front != nullptr && temp->data == front->data){
            Node* duplicates = front;
            front = front->next;
            delete duplicates; // free 
        }
        temp->next = front;
        if(front != nullptr) front->prev = temp;
            
        temp = temp->next; // temp = front;
    }
    return head;
}