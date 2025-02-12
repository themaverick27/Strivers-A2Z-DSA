/*
Problem Statement: Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]
*/

Node* reverseLL(Node* head){
    // Approach-3: by changing links (iterative)
    // Time Complexity: O(n) and Space Complexity: O(1)
    if(head == nullptr || head->next == nullptr) return head;

    Node* prev = nullptr;
    Node* curr = head;
    Node* front;

    while(curr != nullptr){
        front = curr->next; // preserve or store next element 
        curr->next = prev; // change or reverse links

        prev = curr; // move previous to cuurent
        curr = front; // move current to front
    }
    return prev;


    // Approach-2: by changing links (recursive)
    // Time Complexity: O(n) and Space Complexity: O(n) - recursive stack space
    /*
    if(head == nullptr || head->next == nullptr) return head; // base case

    Node* newHead = reverseLL(head->next);

    Node* front = head->next;
    front->next = head;
    head->next = nullptr;

    return newHead;
    */


    // Approach-1: using stack (Data Replacement)
    // Time Complexity: O(2*n) and Space Complexity: O(n)
    /*
    if(head == nullptr || head->next == nullptr) return head;

    stack<int> st;
    Node* temp = head;
    while(temp != nullptr){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp != nullptr){
        temp->data = st.top();
        st.pop();

        temp = temp->next;
    }
    return head;
    */
}