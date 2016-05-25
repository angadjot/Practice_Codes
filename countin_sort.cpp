#include<iostream>
using namespace std;
void counting(int a[],int len){
	int b[20],k=a[0];
	for(int i=0;i<len;i++){
		if(k<a[i]){
			k=a[i];
		}
	}
	int c[k],sum=0;
	for(int i=0;i<=k;i++){
		c[i]=0;
	}
	for(int i=0;i<=k;i++){
		c[a[i]]++;
	}
	for(int i=0;i<=k;i++){
		if(c[i]>0){
			sum=sum+c[i];
			c[i]=sum;
		}
	}
	for(int i=0;i<len;i++){
		b[c[a[i]]-1]=a[i];
		c[a[i]]--;
	}
	cout<<"-----------------------------------------------------------------"<<endl;
	for(int i=0;i<len;i++){
		cout<<b[i]<<endl;;
	}
}
int main(){
	int a[20],i,len;
	cout<<"enter length"<<endl;
	cin>>len;
	cout<<"enter the numbers"<<endl;
	for(i=0;i<len;i++){
		cin>>a[i];
	}
	counting(a,len);	
	return 0;
}
