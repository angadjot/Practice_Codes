#include<iostream>
using namespace std;

void printline();
void display(int array[100][100],int size);
void uppertriangle(int array[100][100],int size);

int main(){
	
    int size,array[100][100];
    cout<<"Enter the Size of the Square Matrix"<<endl;
    cin>>size;
    
    cout<<"Enter the Elements of the matrix in row-wise fashion"<<endl;
    
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            cin>>array[i][j];
        }
    }
	
    display(array,size);
    uppertriangle(array,size);
    display(array,size);
    
	return 0;
}

void display(int array[100][100],int size){
    
    printline();
    cout<<"Elements of Matrix are : "<<endl;
    printline();
    
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            cout<<array[i][j]<<"\t";
        }
        cout<<endl;
    }
    
    printline();
}

void uppertriangle(int array[100][100],int size){
    
    int temp[size],h,count=1;
    
    for (int i=0; i<size; i++) {
        for (int j=count; j<size; j++) {
            h=array[j][i];
            for (int k=0; k<size; k++) {
                array[j][k]=array[j][k]-(h * array[i][k]/array[i][i]);
            }
            
        }
        count++;
    }
    
}

void printline(){
    for (int i=0; i<50; i++) {
        cout<<"-";
    }
    cout<<endl;
}