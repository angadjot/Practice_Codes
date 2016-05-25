#include<iostream>
using namespace std;

void counting_sort(int a[],int size,int range);

int main(){
    int array[100],size,range=0;
    cout<<"Enter the size of the array"<<endl;
    cin>>size;
    
    cout<<"Enter "<<size<<" Elements in the Array"<<endl;
    for (int i=0; i<size; i++) {
        cin>>array[i];
        if (range<array[i]) {
            range=array[i];
        }
    }
    range++;
    cout<<range<<endl;
    counting_sort(array,size,range);
    
    
	return 0;
}

void counting_sort(int a[],int size,int range){

    int c[100]={0},b[100],sum=0;
    for (int i=0; i<range; i++) {
        c[a[i]]=c[a[i]]+1;
    }
    
    for (int i=0; i<range; i++) {
        cout<<c[i]<<"\t";
    }
    cout<<endl;
    
    for (int i=1; i<range; i++) {
        c[i]=c[i]+c[i-1];
    }
    
    for (int i=0; i<range; i++) {
        cout<<c[i]<<"\t";
    }
    cout<<endl;
    
    for (int i=0; i<size; i++) {
        b[c[a[i]]]=a[i];
        c[a[i]]=c[a[i]]-1;
    }
    
    cout<<"Sorted Array :"<<endl;
    for (int i=0; i<size; i++) {
        cout<<b[i]<<"\t";
    }
    cout<<endl;
    
}