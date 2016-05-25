//Bubble Sort
#include<iostream>
using namespace std;

int main(){
    int array[100],size,flag,temp;
    cout<<"Enter the size of the array"<<endl;
    cin>>size;

    cout<<"Enter "<<size<<" Elements in the Array"<<endl;
    for (int i=0; i<size; i++) {
        cin>>array[i];
    }

    for (int i=0; i<size; i++) {
        flag=0;
        for (int j=0; j<size-i-1; j++) {
            if (array[j]>array[j+1]) {
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
                flag++;
            }
        }
        if (flag == 0) {
            break;
        }
    }

    cout<<"Sorted Array :"<<endl;
    for (int i=0; i<size; i++) {
        cout<<array[i]<<"\t";
    }
    cout<<endl;
	return 0;
}
