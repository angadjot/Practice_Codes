#include<iostream>
using namespace std;

void printline();

class Stack{
    
    private:
        int array[100];
        int top;
        int maxlen;
    
    public:
        Stack(int num){
            top=0;
            maxlen=num;
        }
        void push(){
            if (top==maxlen) {
                cout<<"Stack Overflow"<<endl;
            }
            else
                cin>>array[top++];
        }
    
        void pop(){
            if (top == 0) {
                cout<<"Stack Underflow"<<endl;
            }
            else
                cout<<array[--top]<<endl;
        }
    
        void display(){
            if (top<0) {
                cout<<"Stack Underflow"<<endl;
            }
            else{
                cout<<"Stack : ";
                for (int i=top-1; i>=0; i--) {
                    cout<<array[i]<<"\t";
                }
            }
        }

};

int main(){
    
    int size,choice;
    cout<<"Enter the Size of Stack"<<endl;
    cin>>size;
    
    Stack stack(size);
    
    for (int i=1; i>0; i++) {
        cout<<endl;
        do{
            printline();
            cout<<"Select One Option:"<<endl;
            printline();
            cout<<"1. Push Element to Stack"<<endl;
            cout<<"2. Pop Element From Stack"<<endl;
            cout<<"3. Display the whole Stack"<<endl;
            cout<<"4. Exit"<<endl;
            printline();
            cin>>choice;
        }while (choice<0 || choice>5);
    
        switch (choice) {
            case 1:
                cout<<"Enter the element to push in the stack"<<endl;
                stack.push();
                break;
            
            case 2:
                cout<<"Poping the Element : ";
                stack.pop();
                break;
        
            case 3:
                stack.display();
                break;
            
            case 4:
                break;
        }
    }
    
    return 0;
}

void printline(){
    
    for (int i=0; i<50; i++) {
        cout<<"-";
    }
    cout<<endl;

}
