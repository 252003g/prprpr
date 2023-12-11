#include<iostream>
#include<string.h>
using namespace std;

class db
{
    int roll;
    char Name[20];
    char Class[10];
    char Div[10];
    char Dob[20];
    char Bg[5],City[10];
    char Phone[12],License[12];

    public:
        static int stdno;
        
        db()
        {
            roll = 39;
            strcpy(Name,"Gauri");
            strcpy(Class,"SE");
            strcpy(Div,"B");
            strcpy(Dob,"25/03/2003");
            strcpy(Bg,"O+");
            strcpy(City,"Pune");
            strcpy(Phone,"9172400912");
            strcpy(License,"B2424");
            stdno++;
        }

        void getdata()
        {
            cout<<"\nEnter : name,roll,class,div,dob,bg,city,phone,license\n\n";
            cin>>Name>>roll>>Class>>Div>>Dob>>Bg>>City>>Phone>>License;
        }
        friend void display(db d);

        static void count()
        {
            cout<<"Number of objects created : "<<stdno;
        }

        ~db()
        {
            cout<<"\n\n"<<this->Name<<"(Object) is destroyed\n";
        }
}; 

void display(db d)
{
    cout<<"\n Name : "<<d.Name;
    cout<<"\n Roll no : "<<d.roll;
    cout<<"\n Class : "<<d.Class;
    cout<<"\n Div : "<<d.Div;
    cout<<"\n Dob : "<<d.Dob;
    cout<<"\n Bg : "<<d.Bg;
    cout<<"\n City : "<<d.City;
    cout<<"\n Phone : "<<d.Phone;
    cout<<"\n License : "<<d.License;
}
int db::stdno = 0;

int main()
{
    int n,i;
    db d1,*ptr[5];
    cout<<"\nDefault values";
    display(d1);

    d1.getdata();
    display(d1);

    cout<<"\nHow many objetcs you want to create?";
    cin>>n;
    for(i= 0;i<n;i++)
    {
        ptr[i] = new db();
        ptr[i]->getdata();
    }
    cout<<"\n"<<"name"<<"roll"<<"Class"<<"Div"<<"dob"<<"bg"<<"phone"<<"license";
    for(i = 0;i<n;i++)
    { 
        display(*ptr[i]);
        db::count();
    }

    for(i = 0;i<n;i++)
    {
        delete(ptr[i]);
    }
    cout<<"\nObjects deleted!";

    return 0;
}