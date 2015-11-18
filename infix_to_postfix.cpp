#include <iostream>
#include <string>
using namespace std;

char i[20],p[20],s[20];

int top=-1;
void push(char item);
int importance(char a);
void pop();
int main()
{
    s[0]='(';
    int p_index=0;
    string str;
    cout<<"Enter infix expression: ";
    cin>>str;
    int j,k;
    k=str.length();
    str[k]=')';
    k++;
    
    for(j=0;j<k;j++)
    {
        if(str[j]=='*' || str[j]=='/' || str[j]=='+' || str[j]=='-' || str[j]=='^')
        {
            while(importance(str[j]) <= importance(s[top]))
            {
                p[p_index]=s[top];
                p_index++;
                pop();
            }
            push(str[j]);
        }
        else if(str[j]=='(')
        {
            push(str[j]);
        }
        else if(str[j]==')')
        {
            while(s[top]!='(')
            {
                p[p_index]=s[top];
                p_index++;
                pop();
            }
            top--;
        }
        else{
            p[p_index] = str[j];
            p_index++;
        }
    }
    
    if(top!=-1)
    {
        p[p_index]=s[top];
                pop();
    }
    
    cout<<"Postfix expression is: "<<p<<endl;
    return 0;
}
void push(char item)
{
    top++;
    s[top]=item;
}

void pop()
{
    top--;
}

int importance(char a)
{
    switch(a){
        case '+' :
                    return 2;
        case '-' :
                    return 2;
        case '*' :
                    return 3;
        case '/' :
                    return 3;
        case '^' :
                    return 4;
            }
        return -1;
}
