//adding two n-bit binary integers
#include<iostream>
using namespace std;

int main(){

	int size,temp,carry=0;
	
	cout<<"Enter the number of bits in the binary number"<<endl;
	cin>>size;
	
	int num1[size],num2[size],result[size+1];
	
	cout<<"Enter the 1st "<<size<<"-bit binary integer"<<endl;
	for(int i=0;i<size;i++){
		cin>>num1[i];
	}
	
	cout<<"Enter the 2nd "<<size<<"-bit binary integer"<<endl;
	for(int i=0;i<size;i++){
		cin>>num2[i];
	}
	
	for(int i=size;i>=0;i--){
		
		temp=num1[i-1]+num2[i-1]+carry;
		if(temp==0 || temp ==1){
			result[i]=temp;
		}
		else if(temp ==2){
			result[i]=0;
			carry=1;
		}
		else if(temp ==3){
			result[i]=1;
			carry=1;
		}
	}
	cout<<"Sum : ";
	for(int i=0;i<size+1;i++){
		cout<<result[i];
	}
	cout<<endl;
}