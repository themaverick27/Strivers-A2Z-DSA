/*
Problem Statement: Given the head of a linked list, rotate the list to the right by k places.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]
*/

int getNodesCount(Node* node){
    int count = 0;
    while(node != NULL){
        count++;
        node = node->next;
    }
    return count;
}

Node* rotateRightKTimes(Node* head, int k){

    // Approach-1: By changing pointer of kth node 
    // Time Complexity: O(n) approx and Space Complexity: O(1)

    if(k == 0 || head == NULL) return head;

    int length = getNodesCount(head); // length of LL
    k = k % length;

    if(k == 0) return head;

    ListNode* curr = head;
    // move to the tail of LL
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = head; // make the LL circular

    // reach to the (k-1)th node
    for(int i = 0; i <= k; i++){
        curr = curr->next;
    }
    head = curr->next; // update the head 
    curr->next = NULL; // Break the loop by updating curr pointer of (k-1)th node
    return head;
}