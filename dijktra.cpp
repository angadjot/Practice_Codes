#include <iostream>
using namespace std;

#define INFI 999

class Dijkstra{

private:
    int adjMatrix[100][100],distance[100],predecessor[100];
    bool visited[100];
    int numofVertices;
    int source;

public:
    Dijkstra(int nodes){
        numofVertices=nodes;

        for(int i=0;i<numofVertices;i++){
            distance[i]=INFI;
            visited[i]=false;
            predecessor[i]=-1;
        }
    }

    void read(){
        cout<<"Enter the Adjacency Matrix for the Graph"<<endl;
        cout<<"To Enter INFINITY enter "<<INFI<<endl;

        for(int i=0; i<numofVertices; i++){
            cout<<"Enter the Weights for the row "<<i<<" :"<<endl;
            for (int j=0; j<numofVertices ; j++){
                cin>>adjMatrix[i][j];
            }
        }
    }

    int getClosestUnmarkedNode(){

        int minDistance=INFI;
        int closestUnmarkedNode;

        for (int i = 0; i < numofVertices; ++i){
            if(visited[i]==false && distance[i] <= minDistance){
                minDistance = distance[i];
                closestUnmarkedNode = i;
            }
        }

        return closestUnmarkedNode;

    }

    void calculateDistance(){
        int minDistance=INFI;
        int closestUnmarkedNode;
        int count = 0;
        cout<<"Enter the source Vertex"<<endl;
        cin>>source;

        distance[source]=0;


        while(count < numofVertices) {
            closestUnmarkedNode=getClosestUnmarkedNode();
            visited[closestUnmarkedNode] = true;
            for(int i=0;i< numofVertices;i++){
                if(visited[i]==false && adjMatrix[closestUnmarkedNode][i]>0)
                    if(distance[i] > distance[closestUnmarkedNode]+adjMatrix[closestUnmarkedNode][i]){
                        distance[i] = distance[closestUnmarkedNode] + adjMatrix[closestUnmarkedNode][i];
                        predecessor[i]=closestUnmarkedNode;
                    }
            }
        }
        count++;


    }

    void printPath(int node){

            if(node == source)
                cout<<(char)(node + 97);
            else if(predecessor[node] == -1)
                cout<<"No Path from "<<source<<" to "<<(char)(node + 97)<<endl;
            else{
                printPath(predecessor[node]);
                cout<<" -> "<<(char)(node + 97);
            }
        }

        void output(){

            for(int i=0; i<numofVertices; i++){
                if(i == source)
                    cout<<(char)(source + 97)<<" -> "<<source;
                else
                    printPath(i);
                cout<<" Distance: "<<distance[i]<<endl;
            }
        }
};

int main(){

    return 0;
}