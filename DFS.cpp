// #include <iostream>
// using namespace std ;
// struct Node {
//     int data;
//     // Node* parent;
//     bool Visited;
//     // int level;
//     // int cmpID;
//     // int dist;
// };
// struct Stack
// {
//     int size ;
//     int top ;
//     Node *arr;
// };
// Node initialiseNode(int label1){
//     struct Node *nd=new Node();
//     nd->data=label1;
//     // nd->parent=nullptr;

//     nd->Visited=false;
//     return *nd;
// }
// bool isEmpty(struct Stack * sp){
//     if (sp-> top == -1){
//         return true;

//     }
//     return false ;
// }

// bool isFull(struct Stack *sp){
//     if(sp -> top == sp->size -1){
//         return true;
//     }
//     return false ;
// }

// void push(struct Stack *sp , Node* element){
//     if (isFull(sp)){
//         // cout << "Stack overflow !!";
//     }
//     else {
//         (sp -> top) ++;
//         sp ->arr[sp -> top] =*element;


//     }
// }
// Node* pop (struct Stack * sp ){
//     if(isEmpty(sp)){
//         cout << "Stack is Empty ";
//         return nullptr;
 
//     }
//     else {
//         Node* val =&sp -> arr[sp ->top ] ;
//         sp -> top --;
//         return val ;
//     }
// }
// int peek (struct Stack *sp , int indx ){
//     if (sp->top +1 -indx <0){
//         return -1;
//     }
//     else{
//         return sp -> arr[sp->top +1-indx].data;
//     }
// }
// int stackButton(struct Stack * sp ){
//     return sp-> arr[0].data;
// }

// int stackTop(struct Stack *sp ){
//     return sp -> arr[sp -> top].data;
// }

// int main (){
//     struct Stack myStack;
//     myStack.size=20;
//     myStack.top =-1;
//     myStack.arr = new Node[myStack.size];
//     Node nd1=initialiseNode(0);
//     Node nd2=initialiseNode(1);
//     Node nd3=initialiseNode(2);
//     Node nd4=initialiseNode(3);
//     Node nd5=initialiseNode(4);
//     Node nd6=initialiseNode(5);
//     Node nd7=initialiseNode(6);
     
//     // cout <<"The value at the index 1 is "<<peek(&myStack,1)<<endl;

//     // if(isFull(&myStack)){
//     //     cout << "Stack created is Full";
//     // }
//     // cout << myStack.size<<endl;
//     // cout << myStack.top<<endl;
//     Node *AllNode[7]={&nd1,&nd2,&nd3,&nd4,&nd5,&nd6,&nd7};
//     // int visited[7]={0,0,0,0,0,0,0};
//     int adjacencyMatrix[7][7]={
//         {0,1,1,1,0,0,0},
//         {1,0,1,0,0,0,0},
//         {1,1,0,1,1,0,0},
//         {1,0,1,0,1,0,0},
//         {0,0,1,1,0,1,1},
//         {0,0,0,0,1,0,0},
//         {0,0,0,0,1,0,0}
//     };
//     push(&myStack,&nd1);

//     while(!isEmpty(&myStack)){
//         Node* nd=pop(&myStack);
//         if(!nd->Visited){
//             cout<<nd->data<<endl;
//             nd->Visited=true;
//             for(int i=0;i<7;i++){
//                 // cout<<nd->data<<endl;
//                 if(adjacencyMatrix[nd->data][i]==1 &&  !AllNode[i]->Visited){
//                     push(&myStack,AllNode[i]);
//                     // cout<<"Nd data is :"<<nd->data<<endl;
//                     // cout<<"The top element is : "<<i<<myStack.top<<endl;
//                 }
//             }
//         }
//         // else{
//         //     continue;
//         // }

//     }

//     delete[] myStack.arr;
//     return 0;

// }


#include <iostream>
using namespace std;

struct Node {
    int data;
    bool Visited;
    int arrival_time1 ;
    int departure_time1; 
    Node * parent;
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



// Function to initialize a stack
void initializeStack(Stack &stack, int size) {
    stack.size = size;
    stack.top = -1;
    stack.arr = new Node*[size];
}

// Function to push an element to the stack
void push(Stack *stack, Node *node) {
    if (stack->top < stack->size - 1) {
        stack->arr[++stack->top] = node;
    } else {
        cout << "Stack Overflow" << endl;
    }
}

// Function to pop an element from the stack
Node* pop(Stack *stack) {
    if (stack->top >= 0) {
        return stack->arr[stack->top--];
    } else {
        cout << "Stack Underflow" << endl;
        return nullptr;
    }
}

// Function to check if the stack is empty
bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
bool isFull(Stack *stack) {
    return stack->top == stack->size - 1;
}
void DFS(Graph *G , Node *r){
    struct Stack myStack;
    myStack.size=20;
    myStack.top =-1;
    myStack.arr = new Node*[myStack.size];
    push(&myStack,r);
    while(!isEmpty(&myStack)){
        Node* nd=pop(&myStack);
        cout<<nd->data<<endl;
        if(nd->Visited==false){
            nd->Visited=true;
            for (int j=0;j<7;j++){
                if(G->adjacencyMatrix[nd->data][j]==1){
                    push(&myStack,G->AllNode[j]);
                }
            }
        }
    }
    delete[] myStack.arr;
}
int time1 =0;

void DFSRec(Graph *G , Node *nd){
    nd->Visited=true;
    nd->arrival_time1=time1++;
    for (int j=0;j<7;j++){
        if(G->adjacencyMatrix[nd->data][j]==1  && G->AllNode[j]!=nd->parent){
            if(G->AllNode[j]->Visited==false){
                G->AllNode[j]->parent=nd;
                DFSRec(G,G->AllNode[j]);
            }
            else{
                cout<<"Found Cycle !\n";
                return;
            }

        }
    }
    nd->departure_time1=time1++;
    cout<<nd->data<<" "<<nd->arrival_time1<<" "<<nd->departure_time1<<endl;
    
}

// void DFSRec(Graph *G , Node *nd){
//     nd->Visited=true;
//     nd->arrival_time1=time1++;
//     for (int j=0;j<7;j++){
//         if(G->adjacencyMatrix[nd->data][j]==1 ){
//             if(G->AllNode[j]->Visited==false){
//                 G->AllNode[j]->parent=nd;
//                 DFSRec(G,G->AllNode[j]);
//             }
//             else{
//                 if( G->AllNode[j]!=nd->parent){
//                     cout<<"Found Cycle !\n";
//                     return;
//                 }
//             }

//         }
//     }
//     nd->departure_time1=time1++;
//     cout<<nd->data<<" "<<nd->arrival_time1<<" "<<nd->departure_time1<<endl;
    
// }
void DFS2(Graph *G,Node *nd){
    
    cout<<nd->data<<endl;
    DFSRec(G,nd);
}

int min1(int a ,int b ){
    if(a>b){
        return b;
    }
    return a;
}

int Two_Edge(Graph *G,Node *nd){
    nd->Visited=true;
    nd->arrival_time1=time1++;
    int deepest=nd->arrival_time1;
    int deepest1;
    for (int j=0;j<7;j++){
        if(G->adjacencyMatrix[nd->data][j]==1  && G->AllNode[j]!=nd->parent){
            if(G->AllNode[j]->Visited==false){
                G->AllNode[j]->parent=nd;
                deepest=Two_Edge(G,G->AllNode[j]);
            }
            else{
                deepest1=G->AllNode[j]->arrival_time1;
            }
            deepest=min1(deepest,deepest1);
        }
    }
    nd->departure_time1=time1++;
    if(nd->parent!=nullptr && nd->arrival_time1==deepest){
        cout<<"Bridgefound\n";
        cout<<nd->data<<endl;
    }
    return deepest;
}
bool HasCycle(Graph * G){
    DFS2(G,&G->nd1);
    for(Node *nd:G->AllNode ){
        for (int j=0;j<7;j++){
            if(G->adjacencyMatrix[nd->data][j]==1 && nd->departure_time1 <= G->AllNode[j]->departure_time1){
                return true;
            }
        }
    }
    return false;
}


int Strongly_Connected(Graph *G,Node *nd){
    nd->Visited=true;
    nd->arrival_time1=time1++;
    int earliest=nd->arrival_time1;
    int earliest1;
    for (int j=0;j<7;j++){
        if(G->adjacencyMatrix[nd->data][j]==1 ){
            if(G->AllNode[j]->Visited==false){
                G->AllNode[j]->parent=nd;
                earliest1=Strongly_Connected(G,G->AllNode[j]);
            }
            else{
                earliest1=G->AllNode[j]->arrival_time1;
            }
            earliest=min1(earliest,earliest1);
        }
    }
    nd->departure_time1=time1++;
    if(nd->parent!=nullptr && nd->arrival_time1==earliest){
        cout<<"Not Strongly Connected .\n";
        cout<<nd->data<<endl;
    }
    return earliest;
}

int main (){
    Graph G;
    Strongly_Connected(&G,&G.nd1);



    // if(HasCycle(&G)){
    //     cout <<"The graph has a cycle ."<<endl;

    // }
    // else{
    //     cout<<"The Graph has no Cycle.\n";
    // }

    // // Node nd1=initialiseNode(0);
    // // Node nd2=initialiseNode(1);
    // // Node nd3=initialiseNode(2);
    // // Node nd4=initialiseNode(3);
    // // Node nd5=initialiseNode(4);
    // // Node nd6=initialiseNode(5);
    // // Node nd7=initialiseNode(6);
     
    // // // cout <<"The value at the index 1 is "<<peek(&myStack,1)<<endl;

    // // // if(isFull(&myStack)){
    // // //     cout << "Stack created is Full";
    // // // }
    // // // cout << myStack.size<<endl;
    // // // cout << myStack.top<<endl;
    // // Node *AllNode[7]={&nd1,&nd2,&nd3,&nd4,&nd5,&nd6,&nd7};
    // // // int visited[7]={0,0,0,0,0,0,0};
    // // int adjacencyMatrix[7][7]={
    // //     {0,1,1,1,0,0,0},
    // //     {1,0,1,0,0,0,0},
    // //     {1,1,0,1,1,0,0},
    // //     {1,0,1,0,1,0,0},
    // //     {0,0,1,1,0,1,1},
    // //     {0,0,0,0,1,0,0},
    // //     {0,0,0,0,1,0,0}
    // // };
    // push(&myStack,&nd1);

    // while(!isEmpty(&myStack)){
    //     Node* nd=pop(&myStack);
    //     if(!nd->Visited){
    //         cout<<nd->data<<endl;
    //         nd->Visited=true;
    //         for(int i=0;i<7;i++){
    //             // cout<<nd->data<<endl;
    //             if(adjacencyMatrix[nd->data][i]==1 &&  !AllNode[i]->Visited){
    //                 push(&myStack,AllNode[i]);
    //                 // cout<<"Nd data is :"<<nd->data<<endl;
    //                 // cout<<"The top element is : "<<i<<myStack.top<<endl;
    //             }
    //         }
    //     }
    //     // else{
    //     //     continue;
    //     // }

    // }

    // delete[] myStack.arr;
    return 0;

}
