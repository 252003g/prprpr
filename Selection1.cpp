#include<iostream>
using namespace std;
int n;
#define size 10
template<class T>
void sel(T A[size])
{
    int i,j,min;
    T temp;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(A[j]<A[min])
            min=j;
        }
        temp=A[i];
        A[i]=A[min];
        A[min]=temp;
    }
    cout<<"\nSorted array:";
    for(i=0;i<n;i++)
    {
        cout<<" "<<A[i];
    }
}

int main()
{
    int A[size];
    float B[size];
    int i;
    int ch;
    do
	{
		cout<<"\n* * * * * SELECTION SORT SYSTEM * * * * *";
		cout<<"\n--------------------MENU-----------------------";
		cout<<"\n1. Integer Values";
		cout<<"\n2. Float Values";
		cout<<"\n3. Exit";
		cout<<"\n\nEnter your choice : ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				cout<<"\nEnter total no of int elements:";
                cin>>n;

                if(n <= 0 || n > size)
                {
                    cout<<"Invalid number of elements\n";
                    break;
                }
                cout<<"\nEnter int elements:";
                for(i=0;i<n;i++)
                {
                    cin>>A[i];
                }
                sel(A);
				break;
				
			case 2:
				cout<<"\nEnter total no of float elements:";
                cin>>n;
                if(n <= 0 || n > size)
                {
                    cout<<"Invalid number of elements\n";
                    break;
                }
                cout<<"\nEnter float elements:";
                for(i=0;i<n;i++)
                {
                    cin>>B[i];
                }
                sel(B);
				break;
				
			case 3:
                cout<<"Exiting the program..\n";
				exit(0);
            default:
                cout<<"INVALID CHOICE.PLEASE TRY AGAIN!!\n";
		}
	}while(ch!=3);
   
   return 0;
    
}