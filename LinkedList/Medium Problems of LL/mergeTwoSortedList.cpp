/*
Problem Statement: You are given the heads of two sorted linked lists list1 and list2. Merge the two lists into one sorted list.
Return the head of the merged linked list.

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]
*/

Node* mergeTwoLists(Node* list1, Node* list2) {
    // Approach-3: two pointers 
    // Time Complexity: O(m + n) and Space Complexity: O(1)
    Node* temp1 = list1;
    Node* temp2 = list2;

    Node* dummy = new Node(-101);
    Node* back = dummy;

    while(temp1 != NULL && temp2 != NULL){
        if(temp1->data < temp2->data){
            back->next = temp1;
            back = temp1;

            temp1 = temp1->next;
        }
        else{
            back->next = temp2;
            back = temp2;

            temp2 = temp2->next;
        }
    }

    if(temp1 != NULL){
        back->next = temp1;
    }
    if(temp2 != NULL){
        back->next = temp2;
    }
    return dummy->next;


    // Approach-2: two pointers and creating a new list
    // Time Complexity: O(m + n) and Space Complexity: O(n)
    /*
    Node* temp1 = list1;
    Node* temp2 = list2;

    Node* dummy = new Node(-101);
    Node* back = dummy;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->data <= temp2->data){
            Node* node = new Node(temp1->data);
            back->next = node;
            back = node;
            temp1 = temp1->next;
        }
        else{
            Node* node = new Node(temp2->data);
            back->next = node;
            back = node;
            temp2 = temp2->next;
        }
    }

    // list2 exhausted or list1 remaining
    while(temp1 != NULL){
        Node* node = new Node(temp1->data);
        back->next = node;
        back = node; 
        temp1 = temp1->next;
    }
    // list1 exhausted or list2 remaining
    while(temp2 != NULL){
        Node* node = new Node(temp2->data);
        back->next = node;
        back = node; 
        temp2 = temp2->next;
    }
    return dummy->next;
    */


    // Approach-1: by using an external data structure and then sorting it, and construct a LL fron the sorted list
    // Time Complexity: O(2*N) + O(N*log N) and Space Complexity: O(2*N) - where (N = m + n)

}