/*
Given a Circular Linked List of size N. The task is to delete the given node (excluding the first and last node) in the circular linked list and then print the reverse of the circular linked list.

 

Example 1:


Input:
5
2 5 7 8 10
8

Output:
10 7 5 2
Explanation: 
After deleting 8 from the given circular linked 
list, it has elements as 2, 5, 7, 10. Now, 
reversing this list will result in 10, 7, 5, 2.
 

Example 2:

Input:
4
1 7 8 10
8

Output:
10 7 1

Explanation:
After deleting 8 from the given circular linked 
list, it has elements as 1, 7,10. Now, reversing 
this list will result in 10, 7, 1.
 

Your Task:
You don't need to read, input, or print anything. Your task is to complete the function deleteNode( ), which takes Node head, and integer key as input parameters, and delete the node with data key. Also Complete function reverse() which reverses the linked list.

 

Constraints:
1 <= T <= 100
1 <= n <= 100
1 <= data <= 100
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node():data(0),next(NULL){}
    Node(int data):data(data),next(NULL){}
};

void deleteNode(Node *head, int key)
{
    //Your code here
    Node *temp = head;
    Node *prev = NULL;
    while(temp->next != head){
        if(temp->data == key){
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if(temp->data == key){
        if(temp == head){
            Node *temp1 = head;
            while(temp1->next != head){
                temp1 = temp1->next;
            }
            temp1->next = head->next;
            head = head->next;
        }
        else{
            prev->next = temp->next;
        }
    }
}

void reverse(Node **head)
{
    //Your code here
    Node *prev = NULL;
    Node *curr = *head;
    Node *next = NULL;
    while(curr->next != *head){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    curr->next = prev;
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
    *head = prev;
}