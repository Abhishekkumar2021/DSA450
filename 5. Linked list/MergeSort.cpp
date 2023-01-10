#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node* merge(Node* headA, Node* headB){
    Node* head = NULL;
    Node* tail = NULL;
    if(headA->data < headB->data){
        head = headA;
        tail = headA;
        headA = headA->next;
    }
    else{
        head = headB;
        tail = headB;
        headB = headB->next;
    }
    while(headA != NULL && headB != NULL){
        if(headA->data < headB->data){
            tail->next = headA;
            tail = headA;
            headA = headA->next;
        }
        else{
            tail->next = headB;
            tail = headB;
            headB = headB->next;
        }
    }
    if(headA != NULL){
        tail->next = headA;
    }
    else{
        tail->next = headB;
    }
    return head;
}

Node* mergeSort(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* headB = slow->next;
    slow->next = NULL;
    head = mergeSort(head);
    headB = mergeSort(headB);
    head = merge(head, headB);
    return head;
}


