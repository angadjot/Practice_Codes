//Priority Queue
/*input
1
4
2
1
3
3
1
2
4
1
1
5
3
4
*/
#include<iostream>
using namespace std;

struct node{

    int priority,data;
    node *next;
};

node* root;

class Priority_Queue{

    private:
        node *front;

    public:

        Priority_Queue(){
            front=NULL;
        }

        void insert(int val,int priority){

            node *q;
            node *temp=new node;
            temp->data=val;
            temp->priority=priority;

            if (front == NULL || priority < front->priority){
                temp->next=front;
                front = temp;
            }
            else{
                q=front;
                while(q->next != NULL && q->next->priority <= priority){
                    q=q->next;
                }
                temp->next=q->next;
                q->next=temp;
            }
        }

        void del(){
            if (front == NULL){
                cout<<"Underflow"<<endl;
            }
            else{
                cout<<"Deleted Element: "<<front->data<<endl;
                front=front->next;
            }
        }

            void display(){
                node *ptr;
                ptr=front;
                if (front == NULL){
                    cout<<"Queue is Empty"<<endl;
                }
                else{
                    cout<<"Queue :"<<endl;
                    cout<<"Priority \t Element"<<endl;
                    while(ptr!=NULL) {
                        cout<<ptr->priority<<" \t "<<ptr->data<<endl;
                    }
                }

            }

};

int main(){
    int choice, item, priority;
    Priority_Queue pq;
    do
    {
        cout<<"1.Insert\n";
        cout<<"2.Delete\n";
        cout<<"3.Display\n";
        cout<<"4.Quit\n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Input the item value to be added in the queue : ";
            cin>>item;
            cout<<"Enter its priority : ";
            cin>>priority;
            pq.insert(item, priority);
            break;
        case 2:
            pq.del();
            break;
        case 3:
            pq.display();
            break;
        case 4:
            break;
        default :
            cout<<"Wrong choice\n";
        }
    }
    while(choice != 4);
    return 0;
}