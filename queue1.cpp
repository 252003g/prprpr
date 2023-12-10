#include<iostream>
#define size 10
using namespace std;

class Queue
{
    private:
        int data[size];
        int front,rear;
    public:
        Queue();
        bool isFull();
        bool isEmpty();
        void Enqueue(int no);
        void Dequeue();
        void Display();
};

Queue::Queue()
{
    front = -1;
    rear = -1;
}

bool Queue::isFull()
{
    return (rear == size-1);
}

bool Queue::isEmpty()
{
    return(front == -1 && rear == -1);
}

void Queue::Enqueue(int no)
{
    if(!isFull())
    {
        if(isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear++;
        }
        data[rear] = no;
        cout<<"Job added successfully!!!\n";
    }
    else
    {
        cout<<"Queue is full,Job cannot be added\n";
    }
}

void Queue::Dequeue()
{
    if(!isEmpty())
    {
        cout<<"Deleted job with data : "<<data[front]<<endl;
        if(front == rear)
        {
            front = rear = -1;
        }
        else //jobs = data,job = no
        {
            front++;
        }
    }
    else
    {
        cout<<"Queue is empty.No job to delete\n";
    }
}

void Queue::Display()
{
    if(!isEmpty())
    {
        cout<<"Jobs in the queue : ";
        for(int i = front; i<= rear;i++)
        {
            cout<<data[i]<<" ";
        }
        cout<<"\n";
    }
    else
    {
        cout<<"Queue is empty\n";
    }
}

int main()
{
    Queue obj;
    int ch,no;

    do
    {
        cout<<"\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter your choice : ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                cout<<"Enter job data : ";
                cin>>no;
                obj.Enqueue(no);
                break;
            case 2:
                obj.Dequeue();
                break;
            case 3:
                obj.Display();
                break;
            case 4:
                cout<<"Exiting program...\n";
                break;
            default:
                cout<<"Invalid choice .Please try again..\n";
        }
    } while (ch != 4);
    
    return 0;
}
