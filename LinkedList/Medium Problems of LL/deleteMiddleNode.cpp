/*
Problem Statement: You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

Note: The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, 
where ⌊x⌋ denotes the largest integer less than or equal to x.

Example 1:
Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation: Since n = 7, node 3 with value 7 is the middle node. We return the new list after removing this node. 

Example 2:
Input: head = [1,2,3,4]
Output: [1,2,4]
Explanation: Since n = 4, node 2 with value 3 is the middle node. We return the new list after removing this node. 
*/


Node* deleteMiddle(Node* head){
    // Approach-2: Tortoise Hare Algorithm
    // Time Complexity: O(n) and Space Complexity: O(1)
    if(head->next == NULL) return NULL;
        
    Node* slow = head;
    Node* fast = head;

    Node* prev = NULL;
    while(fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* front = slow->next;

    prev->next = front;
    slow->next = NULL;

    delete slow;
    return head;


    // Approach-1: couting nodes and then delete - two pass traversal
    // Time Complexity: O(n) approx and Space Complexity: O(1)
    /*
    if(head->next == NULL) return NULL; // single node

    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }

    int middle = count / 2;
    temp = head;
    Node* prev = NULL;
    while(middle){
        prev = temp;
        temp = temp->next;

        middle--;
    }
    prev->next = prev->next->next;
    temp->next = NULL;

    delete temp;
    return head;
    */
}