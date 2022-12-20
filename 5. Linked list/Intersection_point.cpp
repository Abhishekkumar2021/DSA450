/*
Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.

 

Example 1:

Input:
LinkList1 = 3->6->9->common
LinkList2 = 10->common
common = 15->30->NULL
Output: 15
Explanation:
Y ShapedLinked List
Example 2:

Input: 
Linked List 1 = 4->1->common
Linked List 2 = 5->6->1->common
common = 8->4->5->NULL
Output: 8
Explanation: 

4              5
|              |
1              6
 \             /
  8   -----  1 
   |
   4
   |
  5
  |
  NULL       
Your Task:
You don't need to read input or print anything. The task is to complete the function intersetPoint() which takes the pointer to the head of linklist1(head1) and linklist2(head2) as input parameters and returns data value of a node where two linked lists intersect. If linked list do not merge at any point, then it should return -1.
Challenge : Try to solve the problem without using any extra space.

 

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(1)

 

Constraints:
1 ≤ N + M ≤ 2*105
-1000 ≤ value ≤ 1000

 
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

int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    Node* curr1 = head1;
    Node* curr2 = head2;
    int len1 = 0;
    int len2 = 0;
    while(curr1!=NULL){
        len1++;
        curr1 = curr1->next;
    }
    while(curr2!=NULL){
        len2++;
        curr2 = curr2->next;
    }
    curr1 = head1;
    curr2 = head2;
    if(len1>len2){
        int diff = len1-len2;
        while(diff--){
            curr1 = curr1->next;
        }
    }
    else{
        int diff = len2-len1;
        while(diff--){
            curr2 = curr2->next;
        }
    }
    while(curr1!=NULL && curr2!=NULL){
        if(curr1==curr2){
            return curr1->data;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return -1;
}