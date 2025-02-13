/*
Problem Statement: Given a sorted doubly linked list of positive distinct elements, 
the task is to find pairs in a doubly-linked list whose sum is equal to given value target.

Example 1:
Input:  1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9, target = 7
Output: (1, 6), (2,5)
Explanation: We can see that there are two pairs (1, 6) and (2,5) with sum 7.

Example 2:
Input: 1 <-> 5 <-> 6, target = 6
Output: (1,5)
Explanation: We can see that there is one pairs  (1, 5) with sum 6.
*/

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target){

    // Appraoch-2: two pointers (as the list is sorted)
    // Time Complexity: O(n) approx and Space Complexity: O(1)
    Node* left = head;
    Node* right = head;
    
    // finding the tail of LL
    while(right->next != nullptr){
        right = right->next;
    }
        
    vector<pair<int, int>> ans; // to store answer
    while(right->data > left->data){
        int sum = left->data + right->data;
            
        if(sum == target){
            ans.push_back({left->data, right->data});
                
            left = left->next;
            right = right->prev;
        }
        else if(sum > target) right = right->prev;
        else left = left->next;
    }
    return ans;


    // Approach-1: using nested loops
    // Time Complexity: O(n*n) approx and Space Complexity: O(1)
    /*
    Node* temp1 = head;
    vector<pair<int, int>> ans;
    while(temp1 != nullptr){
        Node* temp2 = temp1->next;
            
        while(temp2 != nullptr && (temp1->data + temp2->data <= target)){
            if(temp1->data + temp2->data == target){
                ans.push_back({temp1->data, temp2->data});
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return ans;
    */     
}