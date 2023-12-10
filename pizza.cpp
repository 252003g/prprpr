#include<iostream>
using namespace std;

class pizza
{
    private:
        int q[5];
        int front,rear;
    public:
        pizza();
        int isFull();
        int isEmpty();
        void add();
        void serve();
        void Display();
        void check();
};

pizza::pizza()
{
    front = -1;
    rear = -1;
}

int pizza::isFull()
{
    if((front == 0 && rear == 4) || (front == rear+1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pizza::isEmpty()
{
    if(front == -1 && rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void pizza::add()
{
    if(isFull() == 0)
    {
        cout<<"Enter the pizza id : \n";
        if(front == -1 && rear == -1)
        {
            front  = 0;
            rear = 0;
            cin>>q[rear];
        }
        else
        {
            rear = (rear+1)%5;
            cin>>q[rear];
        }
    
        char c;
        cout<<"Do you want to add another order ? ";
        cin>>c;
        if(c == 'y' || c == 'Y')
        {
            add();
        }
    }
            
    else
    {
        cout<<"\nOrders are full";
    }
}

void pizza :: serve()
{
    if(isEmpty() == 0)
    {
        if(front == rear)
        {
            cout<<"Order served is : "<<q[front];
            front = -1;
            rear = -1;
        }
        else
        {
            cout<<"\nOrder served is : "<<q[front];
            front = (front+1)%5;
        }
    }
    else
    {
        cout<<"\nOrders are empty";
    }
}

void pizza::Display()
{
    if(isEmpty() == 0)
    {
        for(int i = front;i != rear;i = (i+1)%5)
        {
            cout<<q[i]<<"<-";
        }
        cout<<q[rear];
    }
    else
    {
        cout<<"\nOrders are empty";
    }
}

void pizza::check()
{
    int ch;
    char ch1;
    do
    {
        cout<<"\n\n*****PIZZA PARLOUR******\n\n";
        cout<<"\n1.Add a pizza \n2.Display the orders \n3.Serve a pizza \n4.Exit \nEnter your choice : ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                add();
                break;

            case 2 :
                Display();
                break;

            case 3:
                serve();
                break;

            case 4:
                exit(0);

            default:
                cout<<"Invalid choice";
        }

        cout<<"\nDo you want to continue?";
        cin>>ch1;        
    } while (ch1 == 'y' || ch1 == 'Y');
}

int main()
{
    pizza obj;
    obj.check();
    return 0;
}