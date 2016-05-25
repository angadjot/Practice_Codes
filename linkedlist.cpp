#include<iostream>
using namespace std;

void printline();

class node{

private:
    int val;
    node *next;

public:

    node* Create_Node(int value);
    void insert_begin();
    //void insert_end();
    //void insert_pos();
    void display();
};

node *start;

int main(){
    int choice;
    node ob;

    for (int i=0; i<1; ) {

        do {
            printline();
            cout<<"Select One Option"<<endl;
            printline();
            cout<<"1. Insert Node at Beginning"<<endl;
            cout<<"2. Insert Node at End"<<endl;
            cout<<"3. Insert Node at a given position"<<endl;
            cout<<"4. Sort Link List"<<endl;
            cout<<"5. Delete First Node"<<endl;
            cout<<"6. Delete Last Node"<<endl;
            cout<<"7. Display Linked List"<<endl;
            cout<<"8. Reverse Linked List(iterative)"<<endl;
            cout<<"9. Rverse Linked List (Recursive)"<<endl;
            cout<<"10. Exit"<<endl;
            printline();
            cout<<"Enter the Choice"<<endl;
            cin>>choice;
        } while (choice <0 || choice >11 );

        switch (choice) {
            case 1:
                ob.insert_begin();
                break;

            case 7:
                ob.display();
                break;

            case 8:
                return 0;
        }
    }

}

node* node::Create_Node(int value){
    node *temp=new node;

    if (temp == NULL) {
        cout<<"Memory Not Allocated"<<endl;
        return 0;
    }
    else{
        temp->val=value;
        temp->next=NULL;
        return temp;
    }
}

void node::insert_begin(){
    int value;
    cout<<"Enter the value to be inserted: "<<endl;
    cin>>value;
    node *temp,*p;
    temp = Create_Node(value);

    if (start == NULL) {
        start =temp;
        start->next=NULL;
    }
    else{
        p=start;
        start=temp;
        start->next=p;
    }
    cout<<"Element Inserted at Beginning"<<endl;
}

void node::display(){
    node *temp;
    if (start == NULL) {
        cout<<"The List is Empty"<<endl;
    }
    temp=start;
    cout<<"Element of List are: "<<endl;
    while (temp != NULL) {
        cout<<temp->val<<"\t";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void printline(){
    for (int i=0; i<50; i++) {
        cout<<"-";
    }
    cout<<endl;
}