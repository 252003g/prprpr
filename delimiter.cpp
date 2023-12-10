#include<iostream>
#define size 10
using namespace std;

class stackexp
{
    private :
        int top;
        char stk[size];
    public:
        stackexp();
        void push(char);
        char pop();
        int isfull();
        int isempty();
};

stackexp::stackexp()
{
    top = -1;
}

void stackexp::push(char x)
{
    top = top+1;
    stk[size] = x;
}

char stackexp::pop()
{
    char s;
    s = stk[top];
    top = top-1;
    return s;
}

int stackexp::isfull()
{
    if(top == size)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int stackexp::isempty()
{
    if (top== -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    stackexp obj;
    char exp[20],ch;
    int i = 0;
    cout<<"\n\t Parenthesis Checker...!!!!"<<endl;
    cout<<"\nEnter the expression to be checked : \t";
    cin>>exp;
    if((exp[0] == ')') || (exp[0] == ']') || (exp[0] == '}'))
    {
        cout<<"\nInvalid expression...\n";
        return 0;
    }
    else
    {
        while(exp[i] != '\0')
        {
            ch = exp[i];
            switch(ch)
            {
                case '(': 
                    obj.push(ch);
                    break;
                case '[': 
                    obj.push(ch);
                    break;
                case '{': 
                    obj.push(ch);
                    break;
                case ')': 
                    obj.push(ch);
                    break;
                case ']': 
                    obj.push(ch);
                    break;
                case '}': 
                    obj.push(ch);
                    break;
            }
            i= i+1;
        }
    }
    if(obj.isempty())
    {
        cout<<"\nExpression is well parenthesized..\n";
    }
    else
    {
        cout<<"\nExpression is not well parenthesized...\n";
    }

    return 0;
}