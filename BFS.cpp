#include <iostream>
using namespace std ;



struct Node {
    int data;
    Node* parent;
    bool Visited;
    int level;
    int cmpID;
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
    return *nd;
}
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
        {0,1,1,0,0,0,0},
        {1,0,0,1,1,0,0},
        {1,0,0,0,0,1,1},
        {0,1,0,0,0,0,0},
        {0,1,0,0,0,0,0},
        {0,0,1,0,0,0,0},
        {0,0,1,0,0,0,0}
    };
};
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
void enqueue(struct Queue *qe, Node nd){
    if (isFull(qe)){
        cout << "Queue is Full !"<<endl;
    }
    else {
        qe->arr[qe->tail]=nd;
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
void BFSConnected(Graph *G,Node *r,int cID){
    struct Queue myQueue;
    myQueue.N=50;
    myQueue.head =0;
    myQueue.tail =0;
    myQueue.arr = new Node[myQueue.N];

    Node *node =r;
    r->Visited=true;
    r->level=0;
    r->cmpID=cID;
    // int x=6;
    enqueue(&myQueue,*node);
    while(!isEmpty(&myQueue)){
        Node *nd=dequeue(&myQueue);
        // if(nd->data==x){
        //     cout<<nd->data<<" This is all we wanted !\n";
        //     break;
        // }
        cout<<nd->data<<"  "<<nd->level<<"  "<<nd->cmpID<<endl;
        for (int j=0;j<7;j++){
            if(G->adjacencyMatrix[nd->data][j]==1 &&  G->AllNode[j]->Visited==false){
                G->AllNode[j]->Visited=true;
                G->AllNode[j]->parent=nd;
                G->AllNode[j]->level=nd->level+1;
                G->AllNode[j]->cmpID=r->cmpID;
                enqueue(&myQueue,*G->AllNode[j]);
            }
        }
    }
    delete[] myQueue.arr;
}
int BFSConnectedMAx(Graph *G,Node *r,int cID){
    int result =0;
    struct Queue myQueue;
    myQueue.N=50;
    myQueue.head =0;
    myQueue.tail =0;
    myQueue.arr = new Node[myQueue.N];

    Node *node =r;
    r->Visited=true;
    r->level=0;
    r->cmpID=cID;
    // int x=6;
    enqueue(&myQueue,*node);
    while(!isEmpty(&myQueue)){
        Node *nd=dequeue(&myQueue);
        // if(nd->data==x){
        //     cout<<nd->data<<" This is all we wanted !\n";
        //     break;
        // }
        cout<<nd->data<<"  "<<nd->level<<"  "<<nd->cmpID<<endl;
        for (int j=0;j<7;j++){
            if(G->adjacencyMatrix[nd->data][j]==1 &&  G->AllNode[j]->Visited==false){
                G->AllNode[j]->Visited=true;
                G->AllNode[j]->parent=nd;
                G->AllNode[j]->level=nd->level+1;
                G->AllNode[j]->cmpID=r->cmpID;
                result=G->AllNode[j]->level;
                enqueue(&myQueue,*G->AllNode[j]);
            }
        }
    }
    for (Node * nd : G->AllNode){
        nd->Visited=false ;
    }
    delete[] myQueue.arr;
    return result;
}
void CC (Graph *G){
    for (int i=0;i<7;i++){
        G->AllNode[i]->cmpID=0;

    }
    int cID=1;
    for (Node* r : G->AllNode){
        if(r->cmpID==0){
            BFSConnected(G,r,cID);
            cID++;
        }
    }

}

bool IsBiPartite(Graph* G ){
    Node* r=&G->nd1;
    BFSConnected(G,r,123);
    for (Node * nd : G->AllNode){
        for (int j=0;j<7;j++){
            if(G->adjacencyMatrix[nd->data][j]==1){
                if(nd->level == G->AllNode[j]->level){
                    return false   ;
                }
            }
        }
    }
    return true;
}

int Diameter (Graph * G ){
    int maxlevel=0; 
    for (Node *r : G->AllNode){
        int maxlevel1=BFSConnectedMAx(G,r,123);
        maxlevel=max(maxlevel,maxlevel1);
    }
    return maxlevel;
}
int main(){
    // struct Queue myQueue;
    // myQueue.N=50;
    // myQueue.head =0;
    // myQueue.tail =0;
    // myQueue.arr = new Node[myQueue.N];

    // Node nd1=initialiseNode(0);
    // Node nd2=initialiseNode(1);
    // Node nd3=initialiseNode(2);
    // Node nd4=initialiseNode(3);
    // Node nd5=initialiseNode(4);
    // Node nd6=initialiseNode(5);
    // Node nd7=initialiseNode(6);
    // Node *AllNode[7]={&nd1,&nd2,&nd3,&nd4,&nd5,&nd6,&nd7};
    // int adjacencyMatrix[7][7]={
    //     {0,1,1,1,0,0,0},
    //     {1,0,1,0,0,0,0},
    //     {1,1,0,0,1,0,0},
    //     {1,0,1,0,1,0,0},
    //     {0,0,1,1,0,1,0},
    //     {0,0,0,0,1,0,0},
    //     {0,0,0,0,0,0,0}
    // };
    struct Graph G;
    int dia=Diameter(&G);
    cout << "The diamter is "<< dia <<endl;
    

    // if(IsBiPartite(&G)){
    //     cout << "G is Bipartite graph !\n";
    // }
    // else {
    //     cout << "G is not a Bipartitre Graph !\n";
    // }
    

    // // visited [i]=1;
    // Node *node =&nd7;
    // nd7.Visited=true;
    // nd7.level=0;
    // nd7.cmpID=11;
    // // int x=6;
    // enqueue(&myQueue,*node);
    // while(!isEmpty(&myQueue)){
    //     Node *nd=dequeue(&myQueue);
    //     // if(nd->data==x){
    //     //     cout<<nd->data<<" This is all we wanted !\n";
    //     //     break;
    //     // }
    //     cout<<nd->data<<"  "<<nd->level<<"  "<<nd->cmpID<<endl;
    //     for (int j=0;j<7;j++){
    //         if(adjacencyMatrix[nd->data][j]==1 &&  AllNode[j]->Visited==false){
    //             AllNode[j]->Visited=true;
    //             AllNode[j]->parent=nd;
    //             AllNode[j]->level=nd->level+1;
    //             AllNode[j]->cmpID=nd1.cmpID;
    //             enqueue(&myQueue,*AllNode[j]);
    //         }
    //     }
    // }
    // Node *crt=nd1.parent;
    // cout<<nd1.data<<endl;
    // while (crt != nullptr){
    //     cout<<crt->data<<endl;
    //     crt=crt->parent;
    // }



    // delete[] myQueue.arr;
}