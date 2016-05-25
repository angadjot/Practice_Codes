//Shell sort
#include<iostream>
using namespace std;

void get_array(int *arr,int num);
void display(int *arr,int num);
void shell_sort(int *arr,int num);

int main(){

	int array[100],size;
	cout<<"Enter the size of the array"<<endl;
	cin>>size;

	get_array(array,size);
	shell_sort(array,size);
	display(array,size);

	return(0);

}

void get_array(int *arr,int num){

	cout<<"Enter "<<num<<" elements in the array"<<endl;
	for(int i=0;i<num;i++){
		cin>>arr[i];
	}

}

void display(int *arr,int num){
	cout<<"Elements of array :"<<endl;
	for(int i=0;i<num;i++){
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
}

void shell_sort(int *arr,int num){
	int temp;

	for(int i=num/2;i>0;i=i/2){
		for(int j=i;j<num;j++){
			for(int k=j-i;k>=0;k=k-i){
                if(arr[k+i]<arr[k]){
					temp=arr[k+i];
					arr[k+i]=arr[k];
					arr[k]=temp;
				}
			}
		}
	}
}
