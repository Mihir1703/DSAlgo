#include <bits/stdc++.h>
using namespace std;

class queueNode
{
public:
    int element;
    queueNode *next = NULL;
    queueNode(int element)
    {
        this->element = element;
    }
};

class Queue
{
    queueNode *head = NULL;
    queueNode *back = NULL;

public:
    void enqueue(int element)
    {
        queueNode *toinsert = new queueNode(element);
        if (head == NULL){
            head = toinsert;
            back = toinsert;
        }
        else
        {
            back->next = toinsert;
            back = toinsert;
        }
    }
    bool dequeue()
    {
        queueNode *temp = head;
        if (head == NULL)
        {
            cout << "\tEmpty Queue.\n";
            return 0;
        }
        else
        {
            queueNode *toDelete = temp;
            head = temp->next;
            delete (toDelete);
            return 1;
        }
    }
    bool empty()
    {
        if (head == NULL)
            return 1;
        else
            return 0;
    }
    int front()
    {
        if (head == NULL)
            return INT32_MIN;
        return head->element;
    }
    void Print()
    {
        queueNode *temp = head;
        while (temp != NULL)
        {
            cout << temp->element << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    system("CLS");
    Queue q;
    int choice;
    do
    {
        cout << "\t\tEnter Your Choice\n\t1.Push an element into Queue.\n\t2.Get front element\n\t3.Delete front element\n\t4.Check if Queue is Empty.\n\t5.Show elements in the queue\n\t6.To exit\n\t";
        cin >> choice;
        if (choice == 1)
        {
            int n;
            cout << "\tEnter Element to Insert.\n\t";
            cin >> n;
            q.enqueue(n);
        }
        else if (choice == 2)
        {
            if (q.front() == INT32_MIN)
            {
                cout << "\tEmpty Queue\n";
            }
            else
            {
                cout << "\tFront Element : " << q.front()<<endl;
            }
        }
        else if (choice == 3)
        {
            if (q.dequeue())
            {
                cout << "\tElement removed successfully" << endl;
            }
        }
        else if (choice == 4)
        {
            if (q.empty())
            {
                cout << "\tEmpty Queue." << endl;
            }
            else
            {
                cout << "\nQueue is not Empty" << endl;
            }
        }
        else if (choice == 5)
        {
            cout << "Elements : ";
            q.Print();
            cout<<endl;
        }
        else if (choice == 6)
        {
            exit(0);
        }
    } while (true);
    return 0;
}