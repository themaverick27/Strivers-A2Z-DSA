/*
Problem Statement: Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false
*/

Node* reverseLL(Node* newHead){
    Node* prev = nullptr;
    Node* curr = newHead;
    Node* front;

    while(curr != nullptr){
        front = curr->next;
        curr->next = prev;

        prev = curr;
        curr = front;
    }
    return prev;
}


Node* checkPalindrome(Node* head){
    // Approach-2: using two pointers and reversing the second half
    // Time Complexity: O(2*n) approx and Space Complexity: O(1)
    if(head == nullptr || head->next == nullptr) return head;

    Node* fast = head;
    Node* slow = head;
    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }

    Node* newHead = reverseLL(slow->next);

    Node* left = head;
    Node* right = newHead;
    while(right != nullptr){
        if(left->data != right->data){
            reverseLL(newHead);
            return false;
        }
        left = left->next;
        right = right->next;
    }
    reverseLL(newHead);
    return true;


    // Approach-1: using stack 
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
        if(temp->data != st.top()) return false;

        st.pop();
        temp = temp->next;
    }
    return true;
    */
}
