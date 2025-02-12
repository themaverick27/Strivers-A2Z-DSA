/*
Problem Statement: Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]
*/

ListNode* removeNthFromEnd(ListNode* head, int n) {

    // Approach-2: using two pointer 
    // Time Complexity: O(n) approx and Space Complexity: O(1)
    ListNode* fast = head;
    ListNode* slow = head;
    for(int i = 0; i < n; i++) fast = fast->next;

    // head node delete
    if(fast == nullptr){
        ListNode* newHead = head->next;
        delete head;
        return newHead;
    }

    while(fast->next != nullptr){
        slow = slow->next;
        fast = fast->next;
    }
    ListNode* delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;

    return head;

        
    // Approach-1: finding position from the start of the nth node and then deleting the node
    // Time Complexity: O(2*length) approx and Space Complexity: O(1)
    /*
    ListNode* temp = head;
    int size = 0;
    while(temp != nullptr){
        size++;
        temp = temp->next;
    }

    // head node delete
    if(size == n){
        ListNode* newHead = head->next;
        delete head;
        return newHead;
    }

    temp = head;
    int pos = size - n, count = 0;
    while(temp != nullptr){
        count++;
        // reach to the previous node of nth node
        if(count == pos){
            ListNode* delNode = temp->next;
            temp->next = temp->next->next;
            delete delNode;
        }
        temp = temp->next;
    }
    return head;
    */
}