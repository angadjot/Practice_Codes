//insertion deletion searching union intersection spliting merging 
#include<iostream>
#include<stdio.h>
using namespace std;

void get_array(int *array,int n);
void display(int *array,int n);
void insertion(int *array,int n);
void deletion(int *array,int n);
void search_insert(int *array,int n);
void search_delete(int *array,int n);
void union_array(int *a1,int *a2,int *a3,int n1,int n2);
void intersection(int *a1,int *a2,int *a3,int n1,int n2);
void searching(int *array,int n);
void splitting(int *a1,int *a2,int *a3,int n);
void merging(int *a1,int *a2,int *a3,int n1,int n2);
void printline();

int main(){
	
	int array1[100],array2[100],array3[100],choice,size1,size2;
 	
	do{
		printline();
		cout<<"Select One Option from the List"<<endl;
		printline();
		cout<<"1. Insertion at a paticular Index"<<endl;
		cout<<"2. Deletion at a particular Index"<<endl;
		cout<<"3. Search an element & Insert before it"<<endl;
		cout<<"4. Search & Delete an element"<<endl;
		cout<<"5. Union of 2 arrays"<<endl;
		cout<<"6. Intersection of 2 arrays"<<endl;
		cout<<"7. Searching an element in an array"<<endl;
		cout<<"8. Splitting an array into 2 arrays"<<endl;
		cout<<"9. Merging 2 arrays in 1 array"<<endl;
		printline();
		cout<<"Enter your choice"<<endl;
		printline();
		cin>>choice;
	}while(choice<1||choice>9);

	switch(choice){

		case 1:
			printline();
			cout<<"Enter the size of array"<<endl;
			cin>>size1;
			get_array(array1,size1);
			insertion(array1,size1);
			display(array1,(size1+1));
			break;
			
		case 2:
			printline();
			cout<<"Enter the size of array"<<endl;
			cin>>size1;
			get_array(array1,size1);
			deletion(array1,size1);
			display(array1,(size1-1));
			break;
			
		case 3:
			printline();
			cout<<"Enter the size of array"<<endl;
			cin>>size1;
			get_array(array1,size1);
			search_insert(array1,size1);
			display(array1,(size1+1));
			break;
			
		case 4:
			printline();
			cout<<"Enter the size of array"<<endl;
			cin>>size1;
			get_array(array1,size1);
			search_delete(array1,size1);
			display(array1,(size1-1));
			break;
			
		case 5:
			printline();
			cout<<"Enter the size of 1st array"<<endl;
			cin>>size1;
			get_array(array1,size1);
			cout<<"Enter the size of 2nd array"<<endl;
			cin>>size2;
			get_array(array2,size2);
			union_array(array1,array2,array3,size1,size2);
			break;
			
		case 6:
			printline();
			cout<<"Enter the size of 1st array"<<endl;
			cin>>size1;
			get_array(array1,size1);
			cout<<"Enter the size of 2nd array"<<endl;
			cin>>size2;
			get_array(array2,size2);
			intersection(array1,array2,array3,size1,size2);
			break;
			
		case 7:
			printline();
			cout<<"Enter the size of array"<<endl;
			cin>>size1;
			get_array(array1,size1);
			searching(array1,size1);
			break;
			
		case 8:
			printline();
			cout<<"Enter the size of array"<<endl;
			cin>>size1;
			get_array(array1,size1);
			splitting(array1,array2,array3,size1);
			break;
				
		case 9:
			printline();
			cout<<"Enter the size of 1st array"<<endl;
			cin>>size1;
			get_array(array1,size1);
			cout<<"Enter the size of 2nd array"<<endl;
			cin>>size2;
			get_array(array2,size2);
			merging(array1,array2,array3,size1,size2);
			break;	

	}
	
	return(0);	

}

void get_array(int *array,int n){
	
	printline();
	cout<<"Enter "<<n<<" elemets in the array"<<endl;
	printline();
	for(int i=0;i<n;i++){
		cin>>array[i];
	}

}

void display(int *array,int n){
	
	printline();
	cout<<"Elements of Array :"<<endl;
	printline();
	
	for(int i=0;i<n;i++){
		cout<<array[i]<<"\t";
	}
	
	cout<<endl;
	printline();
}

void insertion(int *array,int n){
	
	int index,element;

	cout<<"Enter the index number to enter new element"<<endl;
	cin>>index;
	cout<<"Enter the New eleemnt to be inserted"<<endl;
	cin>>element;
	
	for(int i=n+1;i>index;i--){
		array[i]=array[i-1];
	}
	
	array[index]=element;
}

void deletion(int *array,int n){

	int index;

	cout<<"Enter the index number to delete an element"<<endl;
	cin>>index;
	
	for(int i=index;i<n-1;i++){
		array[i]=array[i+1];
	}
	
}

void search_insert(int *array,int n){
	
	int index,element,search;
	cout<<"Enter the element before which you want to insert new Element"<<endl;
	cin>>search;
	cout<<"Enter the New eleemnt to be inserted"<<endl;
	cin>>element;
	for(int i=0;i<n;i++){
		if(array[i]==search){
			index=i;
			break;
		}
		else
			continue;
	}
	
	for(int i=n+1;i>index;i--){
		array[i]=array[i-1];
	}
	
	array[index]=element;
}

void search_delete(int *array,int n){
	
	int index,element;
	cout<<"Enter the element  you want to delete"<<endl;
	cin>>element;
	
	for(int i=0;i<n;i++){
		if(array[i]==element){
			index=i;
			break;
		}
		else
			continue;
	}
	
	for(int i=index;i<n-1;i++){
		array[i]=array[i+1];
	}
}

void union_array(int *arr1,int *arr2,int *arr3,int n1,int n2){
	
    int i = 0, j = 0,len=0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
            arr3[len++]=arr1[i++];
        else if (arr2[j] < arr1[i])
            arr3[len++]=arr2[j++];
        else
        {
            arr3[len++]=arr2[j++];
            i++;
        }
    }
    
    while(i < n1)
        arr3[len++]=arr1[i++];
    while(j < n2)
        arr3[len++]=arr2[j++];
    cout<<"Union of Array:"<<endl;
	display(arr3,len);
}

void intersection(int *a1,int *a2,int *a3,int n1,int n2){
	
	int len=0;
	
	for(int i=0;i<n1;i++){
		for(int j=0;j<n2;j++){
			if(a1[i]==a2[j]){
				a3[len++]=a2[j];
			}
		}
	}
	
	printline();
	cout<<"Intersection of Array:"<<endl;
	display(a3,len);
}

void searching(int *array,int n){
	
	int search;
	cout<<"Enter the Element to search in the array"<<endl;
	cin>>search;
	
	for(int i=0;i<n;i++){
		if(array[i]==search){
			printline();
			cout<<"Element Present in the Array"<<endl;
			printline();
			break;
		}
	}

}

void splitting(int *a1,int *a2,int *a3,int n){

	int pos,j=0;
	
	cout<<"Enter the Position to split the array"<<endl;
	cin>>pos;
	
	for(int i=0;i<pos;i++){
		a2[i]=a1[i];
	}
	
	for(int i=pos;i<n;i++){
		a3[j++]=a1[i];
	}
	cout<<"1st Array :"<<endl;
	display(a2,pos);
	cout<<"2nd Array :"<<endl;
	display(a3,j);
	
}

void merging(int *a1,int *a2,int *a3,int n1,int n2){

	int len=0;
	
	for(int i=0;i<n1;i++){
		a3[len++]=a1[i];
	}

	for(int i=0;i<n2;i++){
		a3[len++]=a2[i];
	}
	
	printline();
	cout<<"Merged Array:"<<endl;
	display(a3,len);
	
}

void printline(){
	for(int i=0;i<50;i++){
		cout<<"-";	
	}
	cout<<endl;
}
