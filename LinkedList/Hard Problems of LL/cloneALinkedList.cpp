/*
Problem Statement: A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.
Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.
Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

Example 1:
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

Example 2:
Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
*/

void insertNodesInBetween(Node* head){
    Node* temp = head;
    while(temp != NULL){
        Node* newNode = new Node(temp->data);

        newNode->next = temp->next;
        temp->next = newNode;

        temp = temp->next->next;
    }
}

void connectRandomPointers(Node* head){
    Node* temp = head;

    while(temp != NULL){
        Node* copyNode = temp->next;

        if(temp->random == NULL) copyNode->random = NULL;
        else copyNode->random = temp->random->next;

        temp = temp->next->next;
    }
}

Node* connectNextPointers(Node* head){
    Node* dummyNode = new Node(-1);
    Node* curr = dummyNode;
    Node* temp = head;

    while(temp != NULL){
        curr->next = temp->next;
        curr = curr->next;

        temp->next = temp->next->next;
        temp = temp->next;
    }
    return dummyNode->next;
}

Node* copyRandomList(Node* head) {
    // Appraoch-2: insert nodes in-place
    // Time Complexity: O(3*n) and Space Complexity: O(1)
    insertNodesInBetween(head); 

    connectRandomPointers(head);

    return connectNextPointers(head);


    // Approach-1: using Hashmap
    // Time Complexity: O(2*n) and Space Complexity: O(n)
    /*
    unordered_map<Node*, Node*> mpp;

    Node* temp = head;
    while(temp != NULL){
        Node* newNode = new Node(temp->val); // create new (copy) node

        mpp[temp] = newNode; // put it into the map
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL){
        Node* copyNode = mpp[temp];

        copyNode->next = mpp[temp->next]; // point the orignal next into as copy next
        copyNode->random = mpp[temp->random]; // point the orginal random into as copy random

    temp = temp->next;
    }
    return mpp[head];
    */
}