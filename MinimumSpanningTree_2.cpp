#include <iostream>
#include<queue>
using namespace std ;

struct Node {
    int data;
    bool Visited;
    int arrival_time1 ;
    int departure_time1; 
    Node * parent;
};
struct Heap{
    Node *arr;
};

// Function to initialize a node
Node initialiseNode(int data) {
    Node newNode;
    newNode.data = data;
    newNode.parent=nullptr;
    newNode.Visited = false;
    return newNode;
}

struct Stack {
    int size;
    int top;
    Node** arr;
};
struct Graph {
    Node nd1=initialiseNode(0);
    Node nd2=initialiseNode(1);
    Node nd3=initialiseNode(2);
    Node nd4=initialiseNode(3);
    Node nd5=initialiseNode(4);
    Node nd6=initialiseNode(5);
    Node nd7=initialiseNode(6);
    Node* AllNode[7]={&nd1,&nd2,&nd3,&nd4,&nd5,&nd6,&nd7};
    int adjacencyMatrix[7][7]={
        {0,1,0,0,0,0,0},
        {0,0,1,0,0,0,0},
        {0,0,0,1,0,0,0},
        {0,0,0,0,1,0,0},
        {0,0,0,0,0,1,0},
        {0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0}
    };
};



void MST(Graph *G,Node* r){
    priority_queue<Node> unvisited;
    for(Node * nd : G->AllNode){
        nd->Visited=false;
        // unvisited.push(*nd,100);
    }
}

int main(){
    priority_queue<int >pq;
    pq.push(4);
    pq.push(3);
    pq.push(1);
    pq.push(6);
    pq.push(2);
    pq.push(5);
    while (!pq.empty())
    {
        cout<<pq.top()<<endl;
        pq.pop();
    }
}