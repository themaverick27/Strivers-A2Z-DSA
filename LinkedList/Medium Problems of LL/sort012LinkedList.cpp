/*
Problem Statement: Given a linked list where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s 
linked list such that all zeros segregate to the head side, 2s at the end of the linked list, and 1s in the middle of 0s and 2s.

Example 1:
Input: LinkedList: 1->2->2->1->2->0->2->2
Output: 0->1->1->2->2->2->2->2
Explanation: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between.

Example 2:
Input: LinkedList: 2->2->0
Output: 0->2->2
Explanation: After arranging all the 0s, 1s and 2s in the given format, the output will be 0 2 2.
*/
Node* sort012(Node* head){

    // Approach-2: by changing links - one pass
    // Time Complexity: O(n) and Space Complexity: O(1)
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);
        
    Node *zero = zeroHead, *one = oneHead, *two = twoHead;
    Node *temp = head;
    while(temp != nullptr){
        if(temp->data == 0){
            zero->next = temp;
            zero = zero->next;
        }
        else if(temp->data == 1){
            one->next = temp;
            one = one->next;
        }
        else{
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    // linking 0, 1, 2 lists 
    two->next = nullptr;
    one->next = twoHead->next;
    zero->next = oneHead->next;

    Node* newHead = zeroHead->next;
    
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead;


    // Approach-1: by counting 0, 1, 2 and replacing data - two pass
    // Time Complexity: O(2*n) and Space Complexity: O(1)
    /*
    if(head == nullptr || head->next == nullptr) return head;

    int countZero = 0, countOne = 0, countTwo = 0;
    Node* temp = head;
    while(temp != nullptr){
        if(temp->data == 0) countZero++;
        else if(temp->data == 1) countOne++;
        else countTwo++;

        temp = temp->next;
    }
    temp = head;
    while(countZero){
        temp->data = 0;
        temp = temp->next;
        countZero--;
    }
    while(countOne){
        temp->data = 1;
        temp = temp->next;
        countOne--;
    }
    while(countTwo){
        temp->data = 2;
        temp = temp->next;
        countZero--;
    }
    return head;
    */
}