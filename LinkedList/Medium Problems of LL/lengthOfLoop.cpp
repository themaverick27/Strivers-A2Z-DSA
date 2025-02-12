/*
Problem Statement: Given the head of a linked list, determine whether the list contains a loop. 
If a loop is present, return the number of nodes in the loop, otherwise return 0.

Note: 'c' is the position of the node which is the next pointer of the last node of the linkedlist. If c is 0, then there is no loop.

Example 1:
Input: N = 10, value[]={25,14,19,33,10,21,39,90,58,45}, c = 4
Output: 7
Explanation: The loop is 45->33. So, length of loop is 33->10->21->39->90->58->45 = 7. The number 33 is connected to the last node to form the
loop because according to the input the 4th node from the beginning(1 based index) will be connected to the last node for the loop.

Example 2:
Input: N = 2, value[] = {1,0}, c = 1
Output: 2
Explanation: The length of the loop is 2.
*/

int findLength(Node* slow, Node* fast){
    slow = slow->next;
    int count = 1;
        
    while(slow != fast){
        count++;
        slow = slow->next;
    }
    return count;
}

int countNodesinLoop(Node *head) {

    // Approach-2: Tortoise-Hare Method
    // Time Complexity: O(n) approx and Space Complexity: O(1)
    Node* slow = head;
    Node* fast = head;
        
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
            
        if(slow == fast) return findLength(slow, fast); 
    }
    return 0; // loop not exists, length 0
    

    // Approach-1: using Hashmap
    // Time Complexity: O(n) approx and Space Complexity: O(n)
    /*
    unordered_map<Node*, int> mpp; // <Node*, index or position> 
        
    Node* temp = head;
    int pos = 0;
    while(temp != NULL){
        pos++;
        if(mpp.find(temp) != mpp.end()){
            return (pos - mpp[temp]);
        }
        mpp[temp] = pos;    
        temp = temp->next;
    }
    return 0;
    */
}