//Merge Sort
#include<iostream>
using namespace std;

void merge_sort(int array[],int first,int last);
void merge(int array[],int first,int last,int mid);

int main(){
    int array[100],size;
    cout<<"Enter the size of the array"<<endl;
    cin>>size;

    cout<<"Enter "<<size<<" Elements in the Array"<<endl;
    for (int i=0; i<size; i++) {
        cin>>array[i];
    }

    merge_sort(array,0,size-1);

    cout<<"Sorted Array :"<<endl;
    for (int i=0; i<size; i++) {
        cout<<array[i]<<"\t";
    }
    cout<<endl;
	return 0;
}

void merge_sort(int array[],int first,int last){
	int mid;


	if(first<last){

		mid=(first+last)/2;
        merge_sort(array,first,mid);
        merge_sort(array,mid+1,last);
        merge(array,first,last,mid);
	}

}
void merge(int array[],int first,int last,int mid){
    int temp[100];
    int i,j,k;
    i=first;
    j=mid+1;
    k=first;

    while (i<=mid && j<=last) {
        if (array[i]<array[j]) {
            temp[k++]=array[i++];
        }
        else{
           temp[k++]=array[j++];
        }
    }

    while (i<=mid) {
        temp[k++]=array[i++];
    }

    while (j<=last) {
        temp[k++]=array[j++];
    }

    for (int i=first; i<k; i++) {
        array[i]=temp[i];
    }
}
