#include<iostream>
using namespace std;

class vector{
public:
    int a,b,c;
    void accept(){
        cout<<"Vector Form = ai+bj+ck"<<endl<<"Enter a,b,c"<<endl;
        cin>>a>>b>>c;
    }
    void modify(){
        char ch='y';
        int d,e,f,g;
        while(ch=='y')
        {
            cout<<"Want to Modify a or b or c?"<<endl<<"For a press 1"<<endl<<"For b press 2"<<endl<<"For c press 3"<<endl;
            cin>>d;
            switch(d){
                case 1: cout<<"Enter new value"<<endl;
                    cin>>e;
                    a=e;
                    break;
                case 2:cout<<"Enter new value"<<endl;
                    cin>>f;
                    b=f;
                    break;
                case 3:cout<<"Enter new value"<<endl;
                    cin>>g;
                    c=g;
                    break;
                default :break;
            }
            cout<<"for another change press (y/n)"<<endl;
            cin>>ch;
        }
    }
    void scaler(){
        int t;
        cout<<"enter scaler with which u want to multiply"<<endl;
        cin>>t;
        a=a*t;
        b=b*t;
        c=c*t;
    }
    void display(){
        cout<<"vector="<<a<<"i+"<<b<<"j+"<<c<<"k";
    }
};
int main(){
    
    int c;
    vector ob;
    ob.accept();
    ob.modify();
    ob.scaler();
    ob.display();
    return(0);
}