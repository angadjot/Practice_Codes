#include <iostream>

using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long num,a[1000000],max_diff,min;
    cin>>num;
    for(int i=0;i<num;i++){
        cin>>a[i];
    }
    max_diff=a[1]-a[0];
    min=a[0];
    for(int i=1;i<num;i++){
        if(a[i]-min>max_diff){
            max_diff=a[i]-min;
        }
        if(a[i]<min){
            min=a[i];
        }
    }
    
    if(max_diff==0){
        cout<<-1;
    }
    else
    cout<<max_diff;
    
    return(0);
}