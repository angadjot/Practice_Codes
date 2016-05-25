//Selection Sort
#include<iostream>
using namespace std;

int main(){
    int array[100],size,min,temp;
    cout<<"Enter the size of the array"<<endl;
    cin>>size;

    cout<<"Enter "<<size<<" Elements in the Array"<<endl;
    for (int i=0; i<size; i++) {
        cin>>array[i];
    }

    for (int i=0; i<size-1; i++) {
        min = i;
        for (int j=i+1; j<size; j++) {
            if (array[j]<array[min]) {
                min=j;
            }
        }
        if (i<min) {
            temp=array[min];
            array[min]=array[i];
            array[i]=temp;
        }
    }

    cout<<"Sorted Array :"<<endl;
    for (int i=0; i<size; i++) {
        cout<<array[i]<<"\t";
    }
    cout<<endl;
    return 0;
}
