/*
Problem Statement: Given a doubly linked list. Your task is to reverse the doubly linked list and return its head.

Example 1:
Input: LinkedList: 3 <-> 4 <-> 5
Output: 5 <-> 4 <-> 3

Example 2:
Input: LinkedList: 75 <-> 122 <-> 59 <-> 196
Output: 196 <-> 59 <-> 122 <-> 75
*/

Node* reverseDLL(Node* head){
    // Approach-2: swapping technique
    // Time Complexity: O(n) and Space Complexity: O(1)

    if(head == nullptr || head->next == nullptr) return head;
    
    Node* currentNode = head;
    Node* prevNode = nullptr;
    while(currentNode != nullptr){
        prevNode = currentNode->prev;
        currentNode->prev = currentNode->next;
        currentNode->next = prevNode;
        // move to next node
        currentNode = currentNode->next;
    }
    return prevNode->prev; // this is the new head



    // Approach-1: using Stack 
    // Time Complexity: O(2*n) - 2 passes and Space Complexity: O(n)
    /*
    stack<int> st;

    Node* temp = head;
    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
    */
}