#include <iostream>
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int size,a[1000],temp;
    cin>>size;
    for(int i=0;i<size;i++){
        cin>>a[i];
    }
    
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(int i=0;i<size;i++){
        if(a[i]==a[i+1]){
            continue;
        }
        else{
            cout<<size-i<<endl;
        }
    }
    return(0);
}