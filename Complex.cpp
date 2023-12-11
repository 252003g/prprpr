#include<iostream>
using namespace std;

class complex
{
    float realp,imagp;
    public:
        complex()
        {
            realp = 0;
            imagp =  0;
        }
        complex operator+(complex &);
        complex operator*(complex &);
        complex(float,float);
        friend istream & operator>>(istream &,complex &);
        friend ostream & operator<<(ostream &,complex &);
};

complex :: complex(float x, float y)
{
    realp = x;
    imagp = y;
}
istream & operator>>(istream & din,complex &c)
{
    cout<<"\nEnter real part of complex number 2 :";
    din>>c.realp;
    cout<<"\nEnter imaginary part of complex number 2 : ";
    din>>c.imagp;
    return din;
}
ostream & operator<<(ostream & dout,complex & c)
{
    dout<<c.realp<<"+"<<c.imagp<<"i";
    dout<<endl;
    return dout;
}
complex complex ::operator+(complex & c)
{
    complex add;
    add.realp = realp + c.realp;
    add.imagp = imagp + c.imagp;
    return add;
}
complex complex ::operator*(complex &c)
{
    complex mul;
    mul.realp = (realp*c.realp)-(imagp*c.imagp);
    mul.imagp = (imagp*c.realp)+(realp*c.imagp);
    return mul;
}

int main()
{
    complex c2,c3;
    complex c1(3.4,4.5);
    cout<<"Complex no  is : \n"<<c1;
    cout<<"\nEnter complex no 2 : ";
    cin>>c2;
    cout<<"Complex no 1 is : ";
    cout<<c1;
    cout<<"Complex no 2 is : ";
    cout<<c2;
    cout<<"Complex no 3 is : ";
    cout<<c3;
    cout<<"Addition of two complex numbers is : ";
    c3 = c1 + c2;
    cout<<c3;
    cout<<"Multiplication of two complex numbers is : ";
    c3 = c1*c2;
    cout<<c3;

    return 0;
}
