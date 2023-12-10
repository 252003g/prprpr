#include <iostream>
using namespace std;

class node
{
public:
    node* next;
    node* prev;
    int seat;
    string id;
    int status;
};

class Cinemax
{
public:
    node* head, *tail, *temp;

    Cinemax()
    {
        head = NULL;
        tail = NULL;
    }

    void createList();
    void display();
    void book();
    void cancel();
    void avail();
};

void Cinemax::createList()
{
    int i = 1;
    head = new node;
    head->seat = 1;
    head->status = 0;
    head->id = "null";
    tail = head;

    for (int i = 2; i <= 70; i++)
    {
        node* p = new node;
        p->seat = i;
        p->status = 0;
        p->id = "null";
        tail->next = p;
        p->prev = tail;
        tail = p;
        tail->next = head;
        head->prev = tail;
    }
}

void Cinemax::display()
{
    int count = 0;
    node* temp = head;

    cout << "\n-----------------------------------------\n";
    cout << "               Screen\n";
    cout << "-----------------------------------------\n";

    do
    {
        cout << "S";
        if (temp->seat < 10)
            cout << "0";  // Add leading zero for single-digit seat numbers
        cout << temp->seat << " : ";
        cout << (temp->status == 0 ? "|___| " : "|_B_| ");

        count++;

        if (count % 7 == 0)
        {
            cout << "\n";
        }

        temp = temp->next;
    } while (temp != head);
}

void Cinemax::book()
{
    int x;
    string y;
    cout << "\n\n\nEnter seat number to be booked\n";
    cin >> x;
    cout << "Enter your ID number\n";
    cin >> y;

    if (x < 1 || x > 70)
    {
        cout << "Enter correct seat number to book (1-70)\n";
        return;
    }

    node* temp = head;
    do
    {
        if (temp->seat == x)
        {
            if (temp->status == 1)
            {
                cout << "Seat already booked!\n";
            }
            else
            {
                temp->status = 1;
                temp->id = y;
                cout << "Seat " << x << " booked!\n";
            }
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Invalid seat number!\n";
}

void Cinemax::cancel()
{
    int x;
    string y;

    cout << "Enter seat number to cancel booking\n";
    cin >> x;
    cout << "Enter your ID\n";
    cin >> y;

    if (x < 1 || x > 70)
    {
        cout << "Enter correct seat number to cancel (1-70)\n";
        return;
    }

    node* temp = head;
    do
    {
        if (temp->seat == x)
        {
            if (temp->status == 0)
            {
                cout << "Seat not booked yet!!\n";
            }
            else
            {
                if (temp->id == y)
                {
                    temp->status = 0;
                    cout << "Seat Cancelled!\n";
                }
                else
                {
                    cout << "Wrong User ID !!! Seat cannot be cancelled!!!\n";
                }
            }
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Invalid seat number!\n";
}

void Cinemax::avail()
{
    int count = 0;
    node* temp = head;

    cout << "\n\n\n\n";
    cout << "\n-----------------------------------------\n";
    cout << "               Screen\n";
    cout << "-----------------------------------------\n";

    do
    {
        cout << "S";
        if (temp->seat < 10)
            cout << "0";  // Add leading zero for single-digit seat numbers
        cout << temp->seat << " : ";
        cout << (temp->status == 0 ? "|___| " : " ");

        count++;

        if (count % 7 == 0)
        {
            cout << "\n";
        }

        temp = temp->next;
    } while (temp != head);
}

int main()
{
    Cinemax obj;
    obj.createList();
    int ch;
    char c = 'y';

    while (c == 'y')
    {
        obj.display();
        cout << "\n*********************************************\n";
        cout << "         CINEMAX MOVIE THEATRE\n";
        cout << "*********************************************\n";
        cout << "\nEnter Choice\n1. Current Seat Status\n2. Book Seat\n3. Available Seat\n4. Cancel Seat\n";
        cin >> ch;

        switch (ch)
        {
            case 1:
                obj.display();
                break;
            case 2:
                obj.book();
                break;
            case 3:
                obj.avail();
                break;
            case 4:
                obj.cancel();
                break;
            default:
                cout << "Wrong choice input\n";
        }

        cout << "\nDo you want to perform any other operation? (y/n)\n";
        cin >> c;
    }

    return 0;
}
