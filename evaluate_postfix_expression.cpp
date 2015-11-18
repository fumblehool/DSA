#include <iostream>
using namespace std;

int stacks[20];
int top=-1;
int anser = 0;
bool isoperator(char a);
void push(int item);
void pop();
int top_();
bool isEmpty();
bool isFull();
void print();
void operate(int a , int b, char op);
int main()
{
    string s;
    cout<<"Enter postfix expression:";
    cin>>s;
    int total = s.length();
    int token = 0;

    while(token<s.length())
    {
       if(isoperator(s[token]))
        {
            int a1 = (top_());
            pop();
            int a2 = top_();
            pop();
            operate(a1,a2,s[token]);

        }
        else{
                push(int(s[token])-48);
       }
        token++;
    }
    cout<<"Result is "<<int(stacks[top])<<endl;

    return 0;
}

bool isoperator(char a)
{
    if(a == '+' || a == '-' || a == '*' || a == '/' || a == '^')
    {
        return true;
    }
    return false;
}

bool isEmpty()
{
    if(top==-1)
    {
        return true;
    }
    return false;
}

bool isFull()
{
    if(top==19)
    {
        return true;
    }
    return false;
}
void pop()
{
    if(isEmpty())
    {
        cout<<"Underflow"<<endl;
        return ;
    }
    top--;
}

void push(int item)
{
    if(isFull())
    {
        cout<<"Overflow"<<endl;
        return ;
    }
    top++;
    stacks[top]=item;
}
int top_()
{
    if(isEmpty())
    {
        return -1;
    }
    else {
        return stacks[top];
    }
}

void print()
{
    cout<<"stacks is ";
    for(int i=0;i<=top;i++)
    {
        cout<<stacks[i]<<" ";
    }
    cout<<endl;
}

void operate(int a , int b, char op)
{
    int x = int(a);
    int y = int (b);
    switch(op)
    {
    case '+':   push(x+y);
                break;
    case '-':   push(a-b);
                break;
    case '*':   push(a*b);
                break;
    case '/':   push(a/b);
                break;
    }
}
