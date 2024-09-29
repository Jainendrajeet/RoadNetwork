#include <bits/stdc++.h>
using namespace std ;

struct Node {
    int data;
    Node* parent;
    bool Visited;
    int level;
    int cmpID;
    int dist;
    int noOfShortestPath;
};
struct Queue{
    int N;
    int head;
    int tail;
    Node *arr;
};
Node initialiseNode(int label1){
    struct Node *nd=new Node();
    nd->data=label1;
    nd->parent=nullptr;
    nd->Visited=false;
    nd->dist=INT_MAX;
    nd->noOfShortestPath=0;
    return *nd;
}
bool isEmpty(struct Queue * qe){
    if (qe -> head == qe->tail ){
        return true;
    }
    return false ;

}
bool isFull(struct Queue * qe){
    if (qe->head -qe->tail ==1 || qe->tail -qe->head ==qe->N-1){
        return true;
    }
    return false ;

}

int size (struct Queue *qe){
    return (qe->tail -qe->head +qe->N)%qe->N ;
}
void enqueue(struct Queue *qe, Node nd,int dis){
    if (isFull(qe)){
        cout << "Queue is Full !"<<endl;
    }
    else {
        qe->arr[qe->tail]=nd;
        qe->arr[qe->tail].dist=dis;
        qe->tail =(qe -> tail+1) % qe -> N;
    }
}

Node* dequeue(struct Queue * qe){
    if(isEmpty(qe)){
        // Node nd=initialiseNode(-1);
        cout<< "Queue is Empty !"<<endl;
        return nullptr;
    }
    else {
        Node* val =&qe-> arr[qe-> head];
        qe->head =(qe ->head +1) % qe -> N;
        return val;

    }
}

void printQueue(struct Queue* qe) {
    if (isEmpty(qe)) {
        cout << "Queue is Empty!" << endl;
        return;
    }
    int i = qe->head;
    while (i != qe->tail) {
        cout << qe->arr[i].data << endl;
        i = (i + 1) % qe->N;
    }
}
int main(){
    struct Queue myQueue;
    myQueue.N=50;
    myQueue.head =0;
    myQueue.tail =0;
    myQueue.arr = new Node[myQueue.N];
    Node nd1=initialiseNode(0);
    Node nd2=initialiseNode(1);
    Node nd3=initialiseNode(2);
    Node nd4=initialiseNode(3);
    Node nd5=initialiseNode(4);
    Node nd6=initialiseNode(5);
    Node nd7=initialiseNode(6);
    Node *AllNode[7]={&nd1,&nd2,&nd3,&nd4,&nd5,&nd6,&nd7};
    int adjacencyMatrix[7][7]={
        {0,1,2,3,4,5,1},
        {0,0,2,3,4,5,0},
        {0,0,0,3,4,1,0},
        {0,0,0,0,1,1,0},
        {0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0},
        {1,1,1,1,1,1,0}
    };
    Node *node =&nd1;
    nd1.cmpID=123;
    nd1.dist=0;
    nd1.noOfShortestPath=1;
    enqueue(&myQueue,*node,0);
    while(!isEmpty(&myQueue)){
        Node *nd=dequeue(&myQueue);
        for (int j = 0; j < 7; j++) {
            if (adjacencyMatrix[nd->data][j] != 0) {
                int newDist = nd->dist + adjacencyMatrix[nd->data][j];
                if(newDist== AllNode[j]->dist){
                    AllNode[j]->noOfShortestPath++;
                }
                else if (newDist < AllNode[j]->dist) {
                    AllNode[j]->noOfShortestPath=nd->noOfShortestPath;
                    AllNode[j]->dist = newDist;
                    AllNode[j]->parent = nd;
                    AllNode[j]->cmpID = nd->cmpID;
                    // cout << nd -> data<<" " << j << endl;
                    enqueue(&myQueue, *AllNode[j], newDist);
                }
            }
        }
    }
    cout<< " The shortest distance from the given node to the node 1 is "<<nd1.dist<<" and no. of shortest path is "<<nd1.noOfShortestPath<<endl;
    cout<< " The shortest distance from the given node to the node 2 is "<<nd2.dist<<" and no. of shortest path is "<<nd2.noOfShortestPath<<endl;
    cout<< " The shortest distance from the given node to the node 3 is "<<nd3.dist<<" and no. of shortest path is "<<nd3.noOfShortestPath<<endl;
    cout<< " The shortest distance from the given node to the node 4 is "<<nd4.dist<<" and no. of shortest path is "<<nd4.noOfShortestPath<<endl;
    cout<< " The shortest distance from the given node to the node 5 is "<<nd5.dist<<" and no. of shortest path is "<<nd5.noOfShortestPath<<endl;
    cout<< " The shortest distance from the given node to the node 6 is "<<nd6.dist<<" and no. of shortest path is "<<nd6.noOfShortestPath<<endl;
    cout<< " The shortest distance from the given node to the node 7 is "<<nd7.dist<<" and no. of shortest path is "<<nd7.noOfShortestPath<<endl;
    delete[] myQueue.arr;
}