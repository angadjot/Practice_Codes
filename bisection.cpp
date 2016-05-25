#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

float function(float x);
float bisection(float a,float b);

int main()
{
	float a,h,root,final;
	a = -10;
	h=0.1;
	
	for(int i=0;;i++){
		if (function(a)*function(a+h)<=0){
			cout<<"Roots of the function Lies in interval ["<<a<<","<<a+h<<"]"<<endl;
			final=a+h;
			root = bisection(a,final);
			cout<<"Root of the Function : "<<root<<endl;
			break;
		}
		else{
			a=a+h;
		}
	}
	
	return(0);
}

float function(float x){
	float result;
	result = (x*x - 4);
	return result;
}

float bisection(float a,float b){
	float mid;
	
	do{
		mid=(a+b)/2;
		if(function(a)*function(mid)<0){
			b=mid;
		}
		else if(function(mid)*function(b)<0){
			a=mid;
		}
		
	}while(function(mid)!=0);
	
	return mid;
}
