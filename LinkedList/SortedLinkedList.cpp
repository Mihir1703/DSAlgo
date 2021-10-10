#include <bits/stdc++.h>
using namespace std;

int  cnt=0;

class node
{
public:
    char val;
    node *next = NULL;
    node(char val)
    {
        this->val = val;
    }
    node(char val, node *next)
    {
        this->val = val;
        this->next = next;
    }
};

void insert(node *&head, char val)
{
    node *temp = head;
    node *prev = NULL;
    if (head == NULL)
    {
        node *toInsert = new node(val);
        head = toInsert;
        return;
    }
    else
    {
        if (temp->val > val)
        {
            node *toInsert = new node(val, temp);
            head = toInsert;
            cnt++;
            return;
        }
        while (temp != NULL)
        {
            if (temp->val > val)
            {
                node *toInsert = new node(val, temp);
                prev->next = toInsert;
                cnt++;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            node *toInsert = new node(val, temp);
            prev->next = toInsert;
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

int main()
{
    node *head = NULL;
    insert(head,'m');
    insert(head,'i');
    insert(head,'h');
    insert(head,'i');
    insert(head,'r');
    insert(head,'w');
    insert(head,'a');
    printList(head);
    cout<<cnt;
    return 0;
}