#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct node{
    int value;
    node *next;
};

node *start;
int len=0;

node *Create_Node(int val){
    node *temp;
    temp = new node;
    
    temp->value=val;
    temp->next=NULL;
    
    return temp;
}

void insert(){
    int num;
    cin>>num;
    
    node *t,*s;
    t=Create_Node(num);
    
    if(start==NULL){
        start = t;
    }
    
    else{
        s=start;
        while(s->next!=NULL){
            s=s->next;
        }
        s->next=t;
        t->next=NULL;
        len++;
    }
}

void make_cyclic(){
    node *s;
    s=start;
    while(s->next!=NULL){
        s=s->next;
    }
    s->next=start;
}

void check_cyclic(){
    
    node *s;
    s=start;
    
    for(int i=0;i<len;i++){
        s=s->next;
    }
    
    if(s->next!=NULL){
    	cout<<"Cyclic"<<endl;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int choice;
    for(int i=1;i>0;){
        do{
            cin>>choice;
        }while(choice<0 || choice >4);
        
        switch(choice){
            case 1:
                insert();
                break;
            case 2:
                make_cyclic();
                break;
            case 3:
                check_cyclic();
                break;
            case 4:
                return 0;
        }
    }
    return 0;
}