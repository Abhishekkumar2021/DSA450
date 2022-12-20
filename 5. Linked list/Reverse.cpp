#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node():data(0),next(NULL){}
    Node(int data):data(data),next(NULL){}
    Node(int data, Node *next):data(data),next(next){}
};

Node* reverseIteratively(Node *head){
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

Node* reverseRecursively(Node *head){
    if(head==NULL || head->next==NULL) return head;
    Node *rest = reverseRecursively(head->next);
    Node* last = head->next;
    last->next = head;
    head->next = NULL;
    return rest;   
}
