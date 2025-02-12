/*
Problem Statement: Given head, the head of a linked list, determine if the linked list has a cycle in it.

Note: There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
*/

Node* hasCycle(Node* head){

    // Approach-2: Tortoise-Hare Method
    // Time Complexity: O(n) approx and Space Complexity: O(1)
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) return true; // loop exists
    }
    return false; // loop not exists


    // Approach-1: using Hashmap - memorize the visited nodes in the map 
    // Time Complexity: O(n) and Space Complexity: O(n)
    /*
    unordered_map<Node*, int> mpp; 

    Node* temp = head;
    while(temp != NULL){
        if(mpp.find(temp) != mpp.end()) return true; // loop exists 

        mpp[temp] = 1; // mark as 1 (visited)
        temp = temp->next;
    }
    return false; // loop not exists
    */
}
