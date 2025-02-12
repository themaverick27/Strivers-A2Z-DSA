/*
Problem Statement: Given the head of a singly linked list, group all the nodes with odd indices together 
followed by the nodes with even indices, and return the reordered list.

Note: The first node is considered odd, and the second node is even, and so on.
Note: that the relative order inside both the even and odd groups should remain as it was in the input.

Example 1:
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Example 2:
Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
*/

ListNode *oddEvenList(ListNode *head){

    // Approach-3: by changing the links of odd nodes and then even node (two pointers)
    // Time Complexity: O(n) and Space Complexity: O(1)
    if(head == nullptr || head->next == nullptr) return head;

    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenHead = head->next; // preserve it, to link odd list with even

    while(even != nullptr && even->next != nullptr){
        odd->next = odd->next->next;
        odd = odd->next;

        even->next = even->next->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;

    
    // Approach-2: creating odd and even separate list and linking it
    // Time Complexity: O(n) and Space Complexity: O(n)
    /*
    if(head == nullptr || head->next == nullptr) return head;

    ListNode* dummy1 = new ListNode();
    ListNode* curr1 = dummy1;
    ListNode* dummy2 = new ListNode();
    ListNode* curr2 = dummy2;

    ListNode* temp = head; // to traverse the linked list
    int count = 0;
    while(temp != nullptr){
        count++;
        // odd list
        if(count % 2 != 0){
            ListNode *node = new ListNode(temp->val);
            curr1->next = node;
            curr1 = curr1->next;
        }
        // even list
        else{
            ListNode *node = new ListNode(temp->val);
            curr2->next = node;
            curr2 = curr2->next;
        }
        temp = temp->next;
    }
    curr1->next = dummy2->next; // linking the two lists (odd list with the even list)
    return dummy1->next;
    */


    // Appraoch-1: storing data into lists and replacing it in the linked list
    // Time Complexity: O(2*n) and Space Complexity: O(n)
    /*
    if(head == nullptr || head->next == nullptr) return head;

    vector<int> arr;
    ListNode *temp = head;

    while(temp != nullptr && temp->next != nullptr){
        arr.push_back(temp->val);
        temp = temp->next->next;
    }
    if(temp != nullptr) arr.push_back(temp->val);

    temp = head->next;
    while(temp != nullptr && temp->next != nullptr){
        arr.push_back(temp->val);
        temp = temp->next->next;
    }
    if(temp != nullptr) arr.push_back(temp->val);

    temp = head;
    int i = 0;
    while(temp != nullptr){
        temp->val = arr[i];
        i++;
        temp = temp->next;
    }
    return head;
    */
}