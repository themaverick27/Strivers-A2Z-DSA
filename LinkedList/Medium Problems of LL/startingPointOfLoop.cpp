/*
Problem Statement: Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Note: Do not modify the linked list.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.

Example 2:
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
*/

Node* detectCycle(Node* head) {

    // Approach-2: Tortoise-Hare Method 
    // Time Complexity: O(n) approx and Space Complexity: O(1)
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){ // cycle exists
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    } 
    return NULL; // cycle not exits


    // Approach-1: Hashmap 
    // Time Complexity: O(n) approx and Space Complexity: O(n)
    /*
    Node* temp = head;
        
    int pos = 0;
    unordered_map<ListNode*, int> mpp;
    while(temp != NULL){
         if(mpp.find(temp) != mpp.end()){
            return temp;
        }
        mpp[temp] = pos;
        pos++;

        temp = temp->next;
    }
    return NULL; 
    */
}
