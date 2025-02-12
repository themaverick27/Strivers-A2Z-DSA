/*
Problem Statement: You are given a linked list where each element in the list is a node and have an integer data. 
You need to add 1 to the number formed by concatinating all the list node numbers together and return the head of the modified linked list. 

Note: The head represents the first element of the given array.

Example 1:
Input: LinkedList: 4->5->6
Output: 4->5->7

Example 2: 
Input: LinkedList: 9->9
Output: 1->0->0
*/

int addOneUtil(Node* temp){
    if(temp == NULL) return 1; // base case

    int carry = addOneUtil(temp->next);

    temp->data = temp->data + carry;
    if(temp->data < 10){
        return 0;
    }
    temp->data = 0;
    return 1;
}

Node* reverseLinkedList(Node* newHead){
    Node* prev = nullptr;
    Node* curr = newHead;
    Node* front;

    while(curr != nullptr){
        front = curr->next;
        curr->next = front;

        prev = curr;
        curr = front;
    }
    return prev;
}


Node* add1(Node* head){
    // Appraoch-2: recursion (backtrack)
    // Time Complexity: O(n) and Space Complexity: O(n)
    int carry = addOneUtil(head);

    if(carry == 1){
        Node* newHead = new Node(1);
        newHead->next = head;
        return newHead;
    }
    return head;


    // Approach-1: reversing the LL and then adding, reversing back to original LL
    // Time Complexity: O(3*n) and Space Complexity: O(1)
    /*
    Node* newHeade = reverseLinkedList(head);

    Node* temp = newHead;
    while(temp != nullptr){
        if(temp == newHead) temp->data += 1;

        if(temp->data == 10){
            temp->data = 0;
            if(temp->next != nullptr) temp->next->data += 1;
            else break;
        }
        else{
            reverseLinkedList(newHead);
            return head;
        }
        temp = temp->next;
    }
    reverseLinkedList(newHead);

    Node* node = new Node*(1);
    node->next = head;

    return node;
    */
}
