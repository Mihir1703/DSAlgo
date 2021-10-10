#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int val;
    node *next = NULL;
    node(int val)
    {
        this->val = val;
    }
    node(int val,node* next){
        this->val = val;
        this->next = next;
    }
};
void insert(node *&head, int val)
{
    node *toInsert = new node(val);
    if (head == NULL)
    {
        head = toInsert;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = toInsert;
}
void insertAt(node *&head, int val,int key)
{
    node *temp = head, *prev = NULL;
    int k = 1;
    if (key == 0)
    {
        insert(head,val);
        return;
    }
    else
    {
        k = 0;
        while (temp != NULL && k != key)
        {
            k++;
            prev = temp;
            temp = temp->next;
        }
        if (temp != NULL)
        {
            node *toInsert = new node(val,temp);
            prev->next = toInsert;
        }
    }
}
void deleteNode(node *&head, int val)
{
    node *temp = head, *prev = NULL;
    if (temp != NULL && temp->val == val)
    {
        head = temp->next;
        delete temp;
        return;
    }
    else
    {
        while (temp != NULL && temp->val != val)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp != NULL)
        {
            prev->next = temp->next;
            delete temp;
        }
    }
}
void deleteNodeKey(node *&head, int key)
{
    node *temp = head, *prev = NULL;
    int k = 1;
    if (key == 0)
    {
        head = temp->next;
        delete temp;
        return;
    }
    else
    {
        k = 0;
        while (temp != NULL && k != key)
        {
            k++;
            prev = temp;
            temp = temp->next;
        }
        if (temp != NULL)
        {
            prev->next = temp->next;
            delete temp;
        }
    }
}
void printList(node *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
}
void deleteAll(node *&head)
{
    while (head != NULL)
    {
        node *temp = head;
        head = head->next;
        free(temp);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    node *head = NULL;
    insert(head,5);
    insert(head,6);
    insert(head,7);
    insert(head,8);
    insert(head,9);
    insert(head,10);
    insert(head,11);
    insert(head,12);
    insert(head,13);
    printList(head);
    cout<<endl;
    deleteNode(head,9);
    insertAt(head,10,2);
    printList(head);
    cout<<endl;
    deleteAll(head);
    return 0;
}
