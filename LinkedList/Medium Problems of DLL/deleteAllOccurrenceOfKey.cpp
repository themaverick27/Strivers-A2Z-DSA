/*
Problem Statement: You are given the head of a doubly Linked List and a key. 
Your task is to delete all occurrences of the given key and return the new doubly Linked List.

Example 1:
Input: 2 <-> 2 <-> 10 <-> 8 <-> 4 <-> 2 <-> 5 <-> 2, Key = 2
Output: 10 <-> 8 <-> 4 <-> 5
Explanation: All occurrences of 2 have been deleted.

Example 2:
Input: 9<->1<->3<->4<->5<->1<->8<->4, key = 9
Output: 1<->3<->4<->5<->1<->8<->4
Explanation: All Occurences of 9 have been deleted.
*/

Node* deleteAllKeys(Node* head, int key){

    // Approach-1: simple traversing and deletion
    // Time Complexity: O(n) and Space Complexity: O(1)
    Node* temp = head;

    while(temp != nullptr){
        if(temp->data == key){

            if(temp == head){
                head = temp->next; // update the head 
            }
            Node* prevNode = temp->prev;
            Node* nextNode = temp->next;

            if(nextNode != nullptr) nextNode->prev = prevNode;
            if(prevNode != nullptr) prevNode->next = nextNode;

            delete temp;
            temp = nextNode;
        }
        else temp = temp->next;
    }
    return head;
}