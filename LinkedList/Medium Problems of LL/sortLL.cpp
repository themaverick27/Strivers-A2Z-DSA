/*
Problem Statement: Given the head of a linked list, return the list after sorting it in ascending order.

Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:alignasInput: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
*/

Node* findMiddleNode(Node* head){
    Node* slow = head;
    Node* fast = fast->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* sortList(Node* head) {
    // Approach-2: using merge sort 
    // Time Complexity: O(n*log n) and Space Complexity: O(1)
    
    if(head == NULL || head->next == NULL) return head;

    Node* middle = findMiddleNode(head);

    Node* leftHead = head;
    Node* rightHead = middle->next;
    middle->next = NULL;

    leftHead = sortList(leftHead);
    rightHead = sortList(rightHead);

    return merge2List(leftHead, rightHead);


    // Appraoch-1: store elements in ds, sort it and then replace data in the LL
    // Time Complexity: O(2*N) + O(N*log N) and Space Complexity: O(N) - where N is the number of nodes 
    /*
    vector<int> elements;

    Node* temp = head;
    while(temp != NULL){
        elements.push_back(temp->data); // store elements
        temp = temp->next;
    }
    sort(elements.begin(), elements.end()); // sort
        
    int i = 0;
    temp = head;
    while(temp != NULL){
        temp->data = elements[i]; // data replacement
        i++;
        temp = temp->next;
    }
    return head;
    */
}