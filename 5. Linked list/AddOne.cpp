/*
A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

Example 1:

Input:
LinkedList: 4->5->6
Output: 457 
Example 2:

Input:
LinkedList: 1->2->3
Output: 124 
Your Task:
Your task is to complete the function addOne() which takes the head of the linked list as the only argument and returns the head of the modified linked list. The driver code prints the number.
Note: The head represents the left-most digit of the number.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 10^1000
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node():data(0),next(NULL){}
    Node(int data):data(data),next(NULL){}
    Node(int data, Node *next):data(data),next(next){}
};

Node* reverse(Node *head){
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* addOne(Node *head) 
{
    // Your Code here
    // return head of list after adding one
    Node* rev = reverse(head);
    Node* curr = rev;
    Node* prev = NULL;
    int carry = 1;
    while(curr!=NULL){
        int sum = curr->data + carry;
        carry = sum/10;
        curr->data = sum%10;
        prev = curr;
        curr = curr->next;
    }
    if(carry){
        Node* temp = new Node(carry);
        prev->next = temp;
    }
    return reverse(rev);
}