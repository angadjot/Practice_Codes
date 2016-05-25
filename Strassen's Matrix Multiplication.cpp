/**
 UCS-406 (Data Structure)
 Lab Assignment

 Question: Implement Strassen's Matrix Multiplication problem using Divide & Conquer approach.

 Name : Angadjot Singh Bhasin
 Roll No. : 101403037
 Group : COE2

 */
#include<iostream>
using namespace std;

void printline();
void insert_array(int a[100][100],int num);
void display(int a[100][100],int num);
void Strassen_mul(a[100][100],b[100][100],size);

int main(){

    int arrayA[100][100],arrayB[100][100],size;

    printline();
    cout<<"Enter the Size of the two arrays"<<endl;
    cin>>size;

    insert_array(arrayA,size);
    insert_array(arrayB,size);

    display(arrayA,size);
    display(arrayA,size);

    Strassen_mul(arrayA,arrayB,size);


    return 0;

}

void Strassen_mul(a[100][100],b[100][100],size){

    int c[4][4],s[10],p[7];

    if (size==1) {
        cout<<"Array :"<<endl;
        cout<<a[0][0]*b[0][0];
    }
    else{
        s[0]=b[0][1]-b[1][1];
        s[1]=a[0][0]+a[0][1];
        s[2]=a[1][0]+a[1][1];
        s[3]=b[1][0]-b[0][0];
        s[4]=a[0][0]
    }

    cout<<"After Matrix Multiplication :"<<endl;
    display(c,size);
}

void insert_array(int a[100][100],int num){

    cout<<"Enter "<<size*size<<" elements in the array in rowise manner"<<endl;

    for (int i=0; i<num; i++) {
        for (int j=0; j<num; j++) {
            cin>>a[i][j];
        }
    }

}

void display(int a[100][100],int num){

    printline();
    cout<<"Array : "<<endl;
    printline();

    for (int i=0; i<num; i++) {
        for (int j=0; j<num; j++) {
            cout<<a[i][j]<<"  ";
        }
        cout<<endl;
    }

}

void printline(){

    for (int i=0; i<50; i++) {
        cout<<"-";
    }
    cout<<endl;
}