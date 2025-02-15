/*
Problem Statement: Given a linked list containing n head nodes where every node in the linked list contains two pointers:
(i) next points to the next node in the list.
(ii) bottom pointer to a sub-linked list where the current node is the head.

Each of the sub-linked lists nodes and the head nodes are sorted in ascending order based on their data.
Your task is to flatten the linked list such that all the nodes appear in a single level while maintaining the sorted order.

Note: The flattened list will be printed using the bottom pointer instead of the next pointer.
*/

Node* constructLL(vector<int>& arr){
    Node* newHead = new Node(arr[0]);
        
    Node* curr = newHead;
    for(int i = 1; i < arr.size(); i++){
        curr->bottom = new Node(arr[i]);
        curr = curr->bottom;
    }
    return newHead;
}

Node* merge2List(Node* list1, Node* list2){
    Node* dummyNode = new Node(-1);
    Node* curr = dummyNode;

    while(list1 != NULL && list2 != NULL){
        if(list1->data < list2->data){
            curr->bottom = list1;
            curr = list1;
            list1 = list1->bottom;
        }
        else{
            curr->bottom = list2;
            curr = list2;
            list2 = list2->bottom;
        }
        curr->next = NULL;
    }

    if(list1 != NULL) curr->bottom = list1;
    else curr->bottom = list2;

    if(dummyNode->bottom != NULL) dummyNode->next->bottom = NULL;
    return dummyNode->bottom;
}


// Function which returns the root of the flattened linked list.
Node *flatten(Node *head) {
    // Approach-2: recursion (backtrack), merge two lists into one recusively
    // Time Complexity: O(N * 2*M) and Space Complexity: O(N) - recursive stack space 
    // where N - No. of horizontal nodes and M -  No. of vertical nodes

    if(head == NULL || head->next == NULL) return; // base condition

    Node* mergedHead = flatten(head->next);
    head = merge2List(head, mergedHead);

    return head;


    // Approach-1: storing elements into external ds, sorting it and constructing a new LL from the ds
    // Time Complexity: O(X) + O(X*log X) and Space Complexity: O(X) - where X = (n * m);
    /*
    vector<int> arr;
        
    Node* temp = head;
    while(temp != NULL){
        Node* child = temp;
        while(child != NULL){
            arr.push_back(child->data);
            child = child->bottom;
        }
        temp = temp->next;
    }    
    sort(arr.begin(), arr.end());
        
    Node* newHead = constructLL(arr);
    return newHead;
    */
}