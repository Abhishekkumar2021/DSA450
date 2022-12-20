/*
Given a sorted doubly linked list of distinct nodes(no two nodes have the same data) and a value x. Count triplets in the list that sum up to a given value x.
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

int countTriplets(Node *head, int x){
    Node *first = head;
    Node *last = head;
    while(last->next != NULL){
        last = last->next;
    }
    int count = 0;
    while(first != last && last->next != first){
        Node *mid = first->next;
        while(mid != last){
            if((first->data + mid->data + last->data) == x){
                count++;
                mid = mid->next;
            }
            else if((first->data + mid->data + last->data) < x){
                mid = mid->next;
            }
            else{
                break;
            }
        }
        first = first->next;
    }
    return count;
}