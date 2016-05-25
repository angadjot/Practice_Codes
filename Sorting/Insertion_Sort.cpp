//Insertion Sort
#include<iostream>
using namespace std;

int main(){
	
	int array[100],size,temp,j;
	
	cout<<"Enter the Size of the array"<<endl;
	cin>>size;
	
	cout<<"Enter "<<size<<" elements in the array"<<endl;
	
	for(int i=0i;i<size;i++)
		cin>>array[i];
    
    for (int i=1; i<size; i++) {
        temp=array[i];
        j=i-1;
        while (j>=0 && array[j]>temp) {
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=temp;
    }
	
	cout<<"Sorted Array: ";
	for(int i=0;i<size;i++){
		cout<<array[i]<<"\t";
	
	}
	cout<<endl;
	
	return 0;
}
