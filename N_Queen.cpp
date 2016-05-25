/*input
4
*/
#include <iostream>
#include <math.h>
using namespace std;

int array[100];

bool place(int k,int i){

    for(int j=1;j<=k-1;j++){
        if (array[j] == i || abs(array[j]-i) == abs(j-k)  ) {
            return false;
        }
    }

    return true;
}

void display(int size){
    for (int i = 1; i <= size; i++) {
        cout<<array[i]<<"\t";
    }
    cout<<endl;
}

void NQueen(int k,int n){
    for(int i=1;i<=n;i++){
        if(place(k,i)){
            display(n);
            cout<<k<<"  "<<i<<endl;
            array[k]=i;
            if(k==n){
                display(n);
            }
            else{
                NQueen(k+1, n);
            }
        }
    }
}

int main() {
    int N;
    cout<<"Enter the Size of the board"<<endl;
    cin>>N;
    NQueen(1 , N);
    return 0;
}
