/*
Problem Statement: Given an array of integer arr. Your task is to construct the linked list from arr & 
return the head of the linked list.

Example 1:
Input: arr = [1, 2, 3, 4, 5]
Output: LinkedList: 1->2->3->4->5

Example 2:
Input: arr = [2, 4, 6, 7, 5, 1, 0]
Output: LinkedList: 2->4->6->7->5->1->0
*/
Node* constructLL(vector<int>& arr){
    Node *head, *last, *temp;
    
    head = new Node();
    head->data = arr[0];
    head->next = nullptr;
    last = head;

    for(int i = 1; i < arr.size(); i++){
        temp = new Node();
        temp->data = arr[i];
        temp->next = nullptr;

        last->next = temp;
        last = temp;
    }
    return head;
}
// Time Complexity: O(n)
// Space Complexity: O(n)