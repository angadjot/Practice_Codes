#include <iostream>
using namespace std;

bool isBinarySearchtree(node *tree,int minValue,int maxValue);
void printline();

int main(){

    int choice,option,val;

    for (int i = 1; i > 0; )
    {
        do
        {
            printline();
            cout<<"Select One Option"<<endl;
            printline();
            cout<<"1. Insert an Element in the Tree"<<endl;
            cout<<"2. Check "<<endl;
            cout<<"8. Display Tree"<<endl;
            cout<<"9. Exit"<<endl;
            printline();
            cout<<"Enter the Choice"<<endl;
            cin>>choice;
        } while (choice > 0 && choice < 10);

        switch(choice){
            case 1:
                option = 1;
                while(option == 1){
                    cout<<"Enter the Element to Insert in the Tree"<<endl;
                    cin>>val;
                    insert(root,val);
                    cout<<"Press 1 to Continue"<<endl;
                    cin>>option;
                }
                break;
            case 2:
                isBinarySearchtree(root,-2147483648,2147483648);
                break;
            case 3:
                display(root,1);
                break;
            case 9:
                return 0;
        }
    }
}
bool isBinarySearchtree(node *tree,int minValue,int maxValue){
    
    if (tree == NULL)
    {
        return true;
    }
    
    if(tree->value > minValue && tree->value < maxValue && isBinarySearchtree(tree->left,minValue,tree->value) && isBinarySearchtree(tree->right,tree->value,maxValue)){
        return true;
    }
    else
        return false;
}

void printline(){
    for (int i = 0; i < 50; ++i)
    {
        cout<<"-";
    }
    cout<<endl;
}