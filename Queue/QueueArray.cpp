#include<bits/stdc++.h>
using namespace std;
const int mod = 1000;

class Queue{
    int arr[mod];
    int front = -1;
    int back = -1;
    public:
    void push_back(int val){
        if(front == -1){
            front++;
            arr[++back] = val;
            return;
        }
        arr[++back] = val;
    }
    int frontE(){
        if(front == -1 || front>back){
            return INT32_MIN;
        }
        return arr[front];
    }
    bool pop_front(){
        if(front > back && (front != -1 && back != -1)){
            front = -1;
            back = -1;
            return 0;
        }else if((front == -1 && back == -1)){
            cout << "\tEmpty Queue.\n";
            return 0;
        }
        front++;
        return 1;
    }
    void Print(){
        for(int i=front;i<=back && (back!=-1 && front!=-1);i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    bool empty(){
        if(front == -1 && back == -1 || front>back){
            return 1;
        }
        return 0;
    }
};

int main(){
    Queue q;
    int choice;
    system("CLS");
    do
    {
        cout << "\t\tEnter Your Choice\n\t1.Push an element into Queue.\n\t2.Get front element\n\t3.Delete front element\n\t4.Check if Queue is Empty.\n\t5.Show elements in the queue\n\t6.To exit\n\t";
        cin >> choice;
        if (choice == 1)
        {
            int n;
            cout << "\tEnter Element to Insert.\n\t";
            cin >> n;
            q.push_back(n);
        }
        else if (choice == 2)
        {
            if (q.frontE() == INT32_MIN)
            {
                cout << "\tEmpty Queue\n";
            }
            else
            {
                cout << "\tFront Element : " << q.frontE()<<endl;
            }
        }
        else if (choice == 3)
        {
            if (q.pop_front())
            {
                cout << "\tElement removed successfully" << endl;
            }else{
                cout<<"\tEmpty queue."<<endl;
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