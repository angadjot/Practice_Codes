#include <iostream>
using namespace std;

#define INFINITY 999
class Prim{
private:
  int totnodes;
  int adjMatrix[50][50];

public:


  Prim(int V){
    totnodes=V;
  }

  //Read the Adjancecy Matrix
  void read(){

    cout<<"Enter the Adjacency Matrix for the Graph"<<endl;
    cout<<"To Enter INFINITY enter "<<INFINITY<<endl;

    for(int i=0; i<totnodes; i++){
      cout<<"Enter the Weights for the row "<<i<<" :"<<endl;
      for (int j=0; j<totnodes ; j++){
        cin>>adjMatrix[i][j];
      }
    }
  }

        int minKey(int *key,bool *mstSet){
          int min=INFINITY,min_index;

          for(int i=0;i<totnodes;i++){
            if(mstSet[i]==false && key[i]<min){
              min=key[i];
              min_index=i;
            }
          }

          return min_index;
        }

        void printMST(int parent[]){
          cout<<"Edge   Weight\n";
          for (int i = 1; i < totnodes; i++)
            cout<<parent[i]<<" - "<<i<<"\t"<<adjMatrix[i][parent[i]]<<endl;
        }

        void primMST(){

          int parent[totnodes],key[totnodes];
          bool mstSet[totnodes];

          for (int i = 0; i < totnodes; ++i){
            mstSet[i]=false;
            key[i]=INFINITY;
          }

          key[0]=0;
          parent[0]=-1;

          int u = minKey(key,mstSet);

          mstSet[u]=true;

          for(int v=0;v<totnodes;v++){
            if(adjMatrix[u][v]>0 && mstSet[v]==false && adjMatrix[u][v]<key[v]){
              parent[v]=u;
              key[v]=adjMatrix[u][v];
            }
          }

          printMST(parent);

        }
};
int main(){


  return 0;
}