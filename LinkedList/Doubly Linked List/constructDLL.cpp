/*
Problem Statement: Given an integer array arr of size n. Construct the doubly linked list from arr and return the head of it.

Example 1:
Input: n = 5, arr = [1,2,3,4,5]
Output: 1 2 3 4 5
Explanation: Linked list for the given array will be 1<->2<->3<->4<->5.

Example 2:
Input: n = 1, arr = [1]
Output: 1
Explanation: Linked list for the given array will be 1.
*/

Node* constructDLL(vector<int> &arr){
    Node* head = new Node(arr[0]);

    Node *last = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, last);
        last->next = temp;
        last = last->next;
    }
    return head;
}
// Time Complexity: O(n)
// Space Complexity: O(n)