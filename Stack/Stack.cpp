#include<bits/stdc++.h>
using namespace std;
#define max_element 100

class node{
    public:
    int val;
    node* next=NULL;
    node(int val){
        this->val = val;
    }
    node(int val,node* tp){
        this->val = val;
        this->next = tp;

    }
};

node* push(node* &head,int val){
    node* toInsert ;
    if(head==NULL){
        toInsert = new node(val);
    }else{
        toInsert = new node(val,head);
    }
    head = toInsert;
}

void pop(node *&head){
    node* toDelete = head;
    head = head->next;
    free(toDelete);
}

bool isEmpty(node *&head){
    if(head==NULL){
        return 1;
    }else{
        return 0;
    }
}

void printList(node *&head)
{
    node* temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

int main(){
    node* head = NULL;
    push(head,10);
    push(head,45);
    push(head,20);
    push(head,40);
    push(head,4120);
    printList(head);
    pop(head);
    pop(head);
    pop(head);
    pop(head);
    printList(head);
    cout<<isEmpty(head);
    return 0;
}