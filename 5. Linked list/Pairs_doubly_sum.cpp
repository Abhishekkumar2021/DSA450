/*
Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list whose sum is equal to given value x, without using any extra space? 

Example:  

Input : head : 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
        x = 7
Output: (6, 1), (5,2)
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
    Node():data(0),next(NULL),prev(NULL){}
    Node(int data):data(data),next(NULL),prev(NULL){}
};

void pairsSum(Node *head, int x){
    Node *first = head;
    Node *last = head;
    while(last->next != NULL){
        last = last->next;
    }
    bool found = false;
    while(first != last && last->next != first){
        if((first->data + last->data) == x){
            found = true;
            cout<<"("<<first->data<<", "<<last->data<<")"<<endl;
            first = first->next;
            last = last->prev;
        }
        else if((first->data + last->data) < x){
            first = first->next;
        }
        else{
            last = last->prev;
        }
    }
    if(found == false){
        cout<<"No pair found"<<endl;
    }
}