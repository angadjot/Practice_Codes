/*input
4
2
1
2
1
2
2
0
3
1
3
2
*/
/*input
5
2
1
4
3
2
3
4
1
3
1
4
*/
#include <iostream>
using namespace std;

#define SIZE 10
#define INFINITY 999

struct graphNode{
    int vertex;         //Store Vertex
    char color;         //Color of Node
    int s;              //Start Time
    int f;              //Finish Time
    graphNode* parent;  //Node Parent
};

struct AdjListNode{
    graphNode* node;
    AdjListNode* next;
};

struct AdjList{
    AdjListNode *head;
};

int Time;                       //Universal Time
graphNode* array[SIZE];      //Array for Storing Nodes of Graph

void printline();

class Graph{
private:
    int totNodes;      //Total Number of Vertices/Nodes in the Graph
    AdjList* adj;     //Array for Adjaceny List

public:

    //Graph Constructor
    Graph(int V){
        totNodes = V;
        adj = new AdjList[V];

        for(int i=0;i<V;i++){
            adj[i].head=NULL;
        }
        for(int i=0;i<totNodes;i++){
            array[i]=newGraphNode(i);
        }
    }

    //Create a Node of Graph
    graphNode* newGraphNode(int value){

        graphNode* newNode = new graphNode;
        newNode->vertex = value;
        newNode->color = 'W';       //White Color
        newNode->s = newNode->f = INFINITY;
        newNode->parent = NULL;

        return newNode;
    }

    //Creating New Adjacency List Node
    AdjListNode* newAdjListNode(int value){

        AdjListNode* newAdjNode = new AdjListNode;

        newAdjNode->node = array[value];
        newAdjNode->next = NULL;

        return newAdjNode;
    }

    //Create Graph
    void createGraph(){

        AdjListNode* newNode;
        int neighbours,neighbour_value;

        for(int i=0;i<totNodes-1;i++){

            cout<<endl<<"Enter no. of nodes in the adjacency list of node "<<i<<endl;
            cout<<"--> That is Total Neighbours of "<<i<<" : ";
            cin>>neighbours;

            for(int j=0;j<neighbours;j++){

                cout<<"Enter neighbour #"<<j<<" : ";
                cin>>neighbour_value;

                //Add an edge from src to dest.
                newNode = newAdjListNode(neighbour_value);
                if(adj[i].head==NULL){
                    adj[i].head = newNode;
                }else{
                    AdjListNode* temp;
                    temp=adj[i].head;
                    while(temp->next!=NULL){
                        temp=temp->next;
                    }
                    temp->next=newNode;
                }

            }
        }
    }

    //Print Graph
    void printGraph(){

        AdjListNode* temp;

        for(int i=0;i<totNodes;i++){
            temp=adj[i].head;
            cout<<endl<<"Adjacency list of vertex "<<i<<endl;
            cout<<"Head :";
            while(temp){
                cout<<"-> "<<temp->node->vertex;
                temp=temp->next;
            }
        }
    }

    void DFS_Traveral(){

        graphNode* u;
        Time=0;
        for(int i=0;i<totNodes;i++){
            u=array[i];
            if(u->color == 'W')
                DFS_Visit(u);
        }
    }

    void DFS_Visit(graphNode* u){

        AdjListNode* temp;

        Time = Time + 1;
        u->s = Time;
        u->color = 'G';     //Color Changed to Grey
        cout<<u->vertex<<"\t";
        temp = adj[u->vertex].head;
        while(temp!=NULL){
            if(temp->node->color == 'W'){
                temp->node->parent = u;
                DFS_Visit(temp->node);
            }
            temp=temp->next;
        }
        u->color = 'B';     //Color Changed to Black
        Time = Time + 1;
        u->f = Time;
    }

    void printArray(){

        printline();
        cout<<"Node Details:"<<endl;
        printline();

        for(int i=0;i<totNodes;i++){
            cout<<"Node : "<<array[i]->vertex<<endl;
            cout<<"Color : "<<array[i]->color<<endl;
            cout<<"Start Time :"<<array[i]->s<<endl;
            cout<<"Finish Time :"<<array[i]->f<<endl;
            cout<<"Node Parent :"<<array[i]->parent<<endl;
            cout<<endl;
        }
        cout<<endl;
    }
};
int main(){

    int nodes,start_node;
    cout<<"Enter total nodes in graph : ";
    cin>>nodes;
    Graph gh(nodes);
    cout<<"*****Create a New Graph*****"<<endl;

    gh.createGraph();
    gh.printGraph();
    cout<<endl;
    cout<<endl<<"===DFS traversal is as under==="<<endl;
    gh.DFS_Traveral();
    cout<<endl;
    gh.printArray();
    return 0;
}

void printline(){
    for(int i=0;i<50;i++)
        cout<<"-";
    cout<<endl;
}