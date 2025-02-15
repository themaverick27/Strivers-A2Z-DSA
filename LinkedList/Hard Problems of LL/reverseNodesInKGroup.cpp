/*
Problem Statement: Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
*/

Node* reverseLL(Node* temp){
    Node* prev = NULL;
    Node* curr = temp;
    Node* front;

    while(curr != NULL){
        front = curr->next;
        curr->next = prev;

        prev = curr;
        curr = front;
    }
    return prev;
}

Node* findKthNode(Node* temp, int k){
    k -= 1;
    while(temp != NULL && k != 0){
        k--;
        temp = temp->next;
    }
    return temp;
}

Node* reverseKGroup(Node* head, int k) {
    // Approach-1: identifying K group one by one and reversing the nodes
    // Time Complexity: O(2*n) and Space Complexity: O(1)

    Node* temp = head;
    Node* back = NULL;
    while(temp != NULL){
        Node* kthNode = findKthNode(temp, k);
            
        // No kth Group exists
        if(kthNode == NULL){
            if(back != NULL) back->next = temp;
            break;
        }

        // kth Group exists
        Node* front = kthNode->next; // preserve next node
        kthNode->next = NULL; // individual LL 

        reverseLL(temp);
        if(temp == head){ // first K Group
            head = kthNode;
        }
        else{
            back->next = kthNode;
        }

        back = temp; // remember previous node
        temp = front;
    }   
    return head;
}