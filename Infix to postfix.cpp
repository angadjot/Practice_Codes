//(3+2)*(6-2)/8-2
#include<iostream>
#include<string.h>
#include<stdio.h>
#include <stdlib.h>
using namespace std;

void printline();
int precedence(char operand);

class Stack{
    
private:
    char stack_array[50];
    int top;
    
public:
    
    Stack(){
        top=-1;
    }
    
    void push(char val){
        if (top==49) {
            cout<<"Stack Full"<<endl;
        }
        else{
            stack_array[++top]=val;
        }
    }
    
    char pop(){
        if (top==-1) {
            cout<<"Stack Underflow"<<endl;
            return('#');
        }
        else{
            return (stack_array[top--]);
        }
    }
    void display(){
        
        if (top==-1) {
            cout<<"Stack Underflow"<<endl;
        }
        else{
            cout<<"Postfix : ";
            for (int i=top-1; i>=0; i--) {
                cout<<array[i]<<"\t";
            }
        }
        cout<<endl;
    }
};

class Expression {
    char infix[50],postfix[50];
    
public:
    
    void read(){
        cout<<"Enter the Mathematical Expression to be Evaluated"<<endl;
        cin>>infix;
    }
    
    void ConvertToPostfix(){
        Stack stack;
        char entry1,entry2;
        
        for (int i=0; infix[i] != '\0'; i++) {
            entry1=infix[i];
            
            switch (entry1) {
                
                case '(':
                    stack.push(enrty1);
                    break;
                
                case ')':
                    while((entery2=stack.pop())!='('){
                    	postfix[p++]=entry2;
                    }
                    
                case '+':
        		case '-':
        		case '*':
        		case '/':
        			
        		
                default:
                    break;
            }
        }
    }
};
int main(){
    
    char infix[100],temp,temp1,temp2;
    Stack stack(100),postfix(100);
    int len;
    cout<<"Enter the Mathematical Expression to be Evaluated"<<endl;
    cin>>infix;
    
    len=strlen(infix);
    
    infix[len]=')';
    infix[++len]='\0';
    
    stack.push('(');
    cout<<infix<<endl;
    
    for (int i=0; infix[i] != '\0'; i++){
        
        if(infix[i] > 47 && infix[i] < 58){
            postfix.push(infix[i]);
            postfix.display();
        }
        
        else if(infix[i] == '('){
            stack.push(infix[i]);
            stack.display();
        }
                
        else if(infix[i] ==')'){
            
            while((temp=stack.pop())!='('){
                postfix.push(temp);
                postfix.display();
            }
        }
                
        else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^'){
            
            while ( ( temp = stack.pop() ) != '(' ) {
                if ( precedence(temp) >= precedence(infix[i]) ) {
                    postfix.push(temp);
                    postfix.display();
                }
                else{
                    postfix.push(infix[i]);
                    postfix.display();
                }
            }
        }
    }
    stack.display();
    postfix.display();

    return 0;
}

void printline(){
    
    for (int i=0; i<50; i++) {
        cout<<"-";
    }
    cout<<endl;
    
}

int precedence(char operand){
    
    switch (operand) {
        case '^':
            return 5;
            break;
            
        case '/':
            return 4;
            break;
        
        case '*':
            return 3;
            break;
        
        case '+':
            return 2;
            break;
        
        case '-':
            return 1;
            break;
        
        default:
            return -1;
            break;
    }
}