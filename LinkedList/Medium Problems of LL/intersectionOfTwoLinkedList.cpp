/*
Problem Statement: Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. 
If the two linked lists have no intersection at all, return null.

Example 1:
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'

Example 2;
Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Intersected at '2'
*/

int getNodesCount(Node* head){
    Node* curr = head;
    int count = 0;
    while(curr != NULL){
        count++;
        curr = curr->next;
    }
    return count;
}

Node* intersectionNode(Node* headA, Node* headB, int diff){
    Node* curr1 = headA;
    Node* curr2 = headB;

    for(int i= 0; i < diff; i++){
        curr1 = curr1->next;
    }

    while(curr1 != NULL && curr2 != NULL){
        if(curr1 == curr2) return curr1;

        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return NULL;
}


Node *getIntersectionNode(Node *headA, Node *headB){
    // Approach-3: Two pointers
    // Time Complexity: O(m + n) and Space Complexity: O(1)
    if(headA == nullptr || headB == nullptr) return nullptr;

    Node* curr1 = headA;
    Node* curr2 = headB;

    while(curr1 != curr2){
        curr1 = curr1->next;
        curr2 = curr2->next;

        if(curr1 == curr2) return curr1; // intersection or NULL 

        if(curr1 == nullptr) curr1 = headB;
        if(curr2 == nullptr) curr2 = headA;
    }
    return curr1; // first node is the intersection node


    // Approach-2: difference in node counts
    // Time Complexity: O(m + n) approx and Space Complexity: O(1)
    /*
    int length1 = getNodesCount(headA);
    int length2 = getNodesCount(headB);

    if(length1 > length2){
        return intersectionNode(headA, headB, length1 - length2);
    }
    else{
        return intersectionNode(headB, headA, length2 - length1);
    }
    return NULL;
    */


    // Approach-1: Hashing technique 
    // Time Complexity: O(m + n) and Space Complexity: O(m)
    /*
    unordered_map<Node* ,int> mpp;

    Node *temp = headA;
    // traverse in one LL and store it into map
    while(temp != nullptr){
        mpp[temp] = 1;
        temp = temp->next;
    }

    temp = headB;
    // now traverse in the second LL and check for intersection
    while(temp != nullptr){
        if(mpp.find(temp) != mpp.end()) return temp;

        temp = temp->next;
    }
    return NULL; // no intersection
    */
}
