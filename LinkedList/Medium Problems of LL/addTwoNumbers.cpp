/*
Problem Statement: You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, 
and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

Note: You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
Explanation: 9999999 + 9999 = 10009998
*/

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { 

    // Approach-1: 
    // Time Complexity: O(n) and Space Complexity: O(1)
    int carry = 0;

    ListNode* dummy = new ListNode();
    ListNode* temp = dummy;
    while(l1 != nullptr || l2 != nullptr || carry){ 
        int sum = carry;
        if(l1 != nullptr){
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2 != nullptr){
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10; 

        ListNode* node = new ListNode(sum % 10);
        temp->next = node;
        temp = temp->next;
    }
    return dummy->next;
}