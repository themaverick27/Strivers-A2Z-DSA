/*
Problem Statement: Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.

Example 1:
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Example 2:
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
*/


Node *findMiddle(Node *head){

    // Approach-2: Tortoise-Hare Method 
    // Time Complexity: O(n) approx and Space Complexity: O(1)
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;


    // Approach-1: by counting total nodes 
    // Time Complexity: O(n) + O(n/2) approx and Space Complexity: O(1)
    /*
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }

    temp = head;
    int middle = (count / 2) + 1;
    while(temp != NULL){
        middle--;
        if(middle == 0) break;

        temp = temp->next;
    }
    return temp;
    */
}
