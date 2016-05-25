//(3+2)*(6-2)/8-2
//(3–(4/5)*6+7)*8
//(A+(B/C)*D+E)*F

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
            for (int i=0; i<top; i++) {
                cout<<stack_array[i]<<"\t";
            }
        }
        cout<<endl;
    }
};


int main(){
    
    char infix[100],postfix[100],temp,entry1,entry2;
    Stack stack;
    int len,p=0;
    cout<<"Enter the Mathematical Expression to be Evaluated"<<endl;
    cin>>infix;
    
    len=strlen(infix);
    
    infix[len]=')';
    infix[++len]='\0';
    
    stack.push('(');
    stack.display();
    for (int i=0; infix[i] != '\0'; i++){
        entry1=infix[i];
        
        switch (entry1) {
            case '(':
                stack.push(entry1);
                break;
                
            case ')':
                while((entry2=stack.pop()) !='('){
                    postfix[p++]=entry2;
                }
                break;
                
            case '%':
            case '/':
            case '*':
            case '+':
            case '-':
                entry2=stack.pop();
                if (entry2=='(') {
                    stack.push(entry2);
                    stack.push(entry1);
                }
                
                else if(precedence(entry1)>=precedence(entry2)){
                    stack.push(entry2);
                    stack.push(entry1);
                }
                
                else if(precedence(entry2)>precedence(entry1)){
                    
                    while (precedence(entry2)>precedence(entry1)) {
                        postfix[p++]=entry2;
                        entry2=stack.pop();
                        
                        if (entry2=='(') {
                            stack.push(entry2);
                            stack.push(entry1);
                            break;
                        }
                        else if(precedence(entry1)>=precedence(entry2)){
                            stack.push(entry2);
                            stack.push(entry1);
                        }
                    }
                }
                break;
                
            default:
                postfix[p++]=entry1;
                break;
        }
    }
                
    stack.display();
    postfix[p]='\0';
    cout<<"Postfix Expression : ";
    cout<<postfix<<endl;

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
            return 4;
            break;
        
        case '+':
            return 3;
            break;
        
        case '-':
            return 3;
            break;
            
        default:
            return -1;
            break;
    }
}