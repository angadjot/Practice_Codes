/*input
11
9
12
6
13
25
4
15
7
1
3
19
*/
#include <iostream>
using namespace std;


void HeapSort(int a[],int size);
void BuildMaxHeap(int a[],int size);
void max_heapify(int i);
void swap(int &x,int &y);

int main(){

    int size,a[100];

    cout<<"Enter the Size of the Array"<<endl;
    cin>>size;

    cout<<"Enter "<<size<<" elements in the array"<<endl;
    for (int i=0; i<size;i++){
        cin>>a[i];
    }

    HeapSort(a,size);
    cout<<endl<<"Sorted elements:\n";
    for(int i=0;i<size;i++){
        cout<<a[i]<<"\t";
    }
}

void max_heapify(int a[],int i,int heapSize){

    int left,right,max;
    left=2*i;
    right=2*i+1;

    if (left <= heapSize && a[left]>a[i]) {
        max=left;
    }
    else
        max=i;
    if (right <= heapSize && a[right]>a[i]) {
        max=right;
    }
    if (max!=i) {
        swap(a[i],a[max]);
        max_heapify(a,max,heapSize);
    }
}

void BuildMaxHeap(int a[],int size){

    int heapSize;
    heapSize=size-1;
    for (int i=size/2; i>=0; i--) {
        max_heapify(a,i,heapSize);
    }
}

void HeapSort(int a[],int size){

    BuildMaxHeap(a,size);
    int heapSize=size-1;
    for (int i = heapSize; i>=0; i--){
        swap(a[1],a[i]);
        heapSize--;
        max_heapify(a,0,heapSize);
    }
}

void swap(int &x,int &y){
    int temp;
    temp = x;
    x=y;
    y=temp;
}