#include<iostream>
using namespace std;

struct Node {
    Node* leftChild;
    Node* parent;
    Node* rightChild;
    int label;
    int depth;
    char op;
    int NoOfchildren;
};
struct Queue{
    int N;
    int head;
    int tail;
    Node *arr;
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
void enqueue(struct Queue *qe, struct Node nd){
    // if (isFull(qe)){
    //     cout << "Queue is Full !"<<endl;
    // }
    // else {
    qe->arr[qe->tail]=nd;
    qe->tail =(qe -> tail+1) % qe -> N;
    // }
}

int dequeue(struct Queue * qe){
    struct Node *Tree =&qe->arr[qe->head];
    if(Tree->leftChild != NULL && Tree->rightChild != NULL){
        enqueue(qe,*Tree->leftChild);
        enqueue(qe,*Tree->rightChild);
    }
    else if(Tree->leftChild !=NULL){
        enqueue(qe,*Tree->leftChild);
    }
    else if(Tree->rightChild !=NULL){
        enqueue(qe,*Tree->rightChild);
    }
    if(isEmpty(qe)){
        cout<< "Queue is Empty !"<<endl;
        return -1;
    }
    else {
        int val =qe-> arr[qe-> head].label;
        qe->head =(qe ->head +1) % qe -> N;
        return val;

    }
}

void dequeue1(struct Queue * qe , struct Queue *myQueue){
    struct Node *Tree =&qe->arr[qe->head];
    if(Tree->leftChild != NULL && Tree->rightChild != NULL){
        enqueue(qe,*Tree->leftChild);
        enqueue(qe,*Tree->rightChild);
    }
    else if(Tree->leftChild !=NULL){
        enqueue(qe,*Tree->leftChild);
    }
    else if(Tree->rightChild !=NULL){
        enqueue(qe,*Tree->rightChild);
    }
    

    enqueue(myQueue,qe->arr[qe->head]);
    
    qe->head =(qe ->head +1) % qe -> N;

    
}

void printQueue(struct Queue* qe) {
    if (isEmpty(qe)) {
        cout << "Queue is Empty!" << endl;
        return;
    }
    int i = qe->head;
    while (i != qe->tail) {
        cout << qe->arr[i].label << endl;
        i = (i + 1) % qe->N;
    }
}

struct BinaryTree
{
    Node* root;
    Node* Tree;
};

void InsertChildBoth(struct Node *Tree , Node * leftNode,Node*rightNode){
    Tree->NoOfchildren=2;
    Tree->leftChild=leftNode;
    Tree->leftChild->depth=Tree->depth+1;
    Tree->leftChild->parent=Tree;
    Tree->rightChild=rightNode;
    Tree->rightChild->depth=Tree->depth+1;
    Tree->rightChild->parent=Tree;
}
void InsertleftChild(struct Node *Tree , Node * leftNode){
    Tree->NoOfchildren=1;
    Tree->leftChild=leftNode;
    Tree->leftChild->parent=Tree;
    Tree->leftChild->depth=Tree->depth+1;
    Tree->rightChild=NULL;
}
void InsertrightChildBoth(struct Node *Tree ,Node*rightNode){
    Tree->NoOfchildren=1;
    Tree->leftChild=NULL;
    Tree->rightChild=rightNode;
    Tree->rightChild->parent=Tree;
    Tree->rightChild->depth=Tree->depth+1;

}

Node initialiseNode(int label1){
    struct Node *nd=new Node();
    nd->leftChild=NULL;
    nd->rightChild=NULL;
    nd->label=label1;
    nd->NoOfchildren=0;
    return *nd;
}
Node initialiseNode1(char label1){
    struct Node *nd=new Node();
    nd->leftChild=NULL;
    nd->rightChild=NULL;
    nd->op=label1;
    nd->NoOfchildren=0;
    return *nd;
}

bool CheckAncestor(struct BinaryTree *bt, struct Node *child1, struct Node *ancestor) {
    // If child1 is the root, it cannot have an ancestor
    if (child1 == bt->root) {
        return false;
    }

    // Traverse up the tree from child1 to the root
    struct Node *child = child1;
    while (child != NULL && child != bt->root) {
        if (child == ancestor) {
            return true;
        }
        child = child->parent;
    }

    // Finally, check if the root is the ancestor
    return (child == ancestor);
}


bool checkSibling(struct BinaryTree *bt, struct Node *child1,struct Node* child2){
    if(child1 ==bt->root || child2 ==bt->root){
        return false ;
    }
    if(child1->parent ==child2->parent){
        return true;

    }
    else {
        return false ;
    }
}

int level_depth(struct BinaryTree *bt,struct Node *nd){
    if(nd==bt->root){

        return 0;

    }
    else {
        Node *nd_1 = nd->parent;
        return 1+ level_depth(bt,nd_1);
    }
}
int max1(int a, int b){
    if(a>=b){
        return a;
    }
    return b;
}
int min1(int a, int b){
    if(a<=b){
        return a;
    }
    return b;
}
Node LowestCommonAncestor(struct Node* n1,struct Node *n2,struct BinaryTree *bt){
    int depth1=level_depth(bt,n1);
    int depth2=level_depth(bt,n2);

    if(min1(depth1,depth2)==depth1){
        Node*resultNode=n1;
        while (!CheckAncestor(bt,n2,resultNode))
        {
            resultNode=resultNode->parent;
        }
        return *resultNode;
        
    }
    else{
        Node*resultNode=n2;
        while (!CheckAncestor(bt,n1,resultNode))
        {
            resultNode=resultNode->parent;
        }
        return *resultNode;

    }
}
int NumberOfChild(Node *nd){
    if(nd->leftChild==nullptr && nd->rightChild==nullptr){
        return 0;
    }
    else if(nd->leftChild==nullptr || nd->rightChild==nullptr){
        return 1;
    }
    else{
        return 2;
    }
}
int NumberOfNodesAtDepth_i_fromNodeN(Node * nd, int depth){
    if(depth==1){
        return NumberOfChild(nd);
    }
    else{
        int val1=0;
        int val2=0;
        if(nd->leftChild !=nullptr){
            val1=NumberOfNodesAtDepth_i_fromNodeN(nd->leftChild,depth-1);
        }
        if(nd->rightChild != nullptr){
            val2=NumberOfNodesAtDepth_i_fromNodeN(nd->rightChild,depth-1);
        }
        return val1+val2;
    }
}

int height(struct BinaryTree *bt,struct Node *nd){
    Node *n1=nd->leftChild;
    Node *n2=nd->rightChild;
    if(n1==NULL && n2== NULL){
        return 0;
    }
    if(n1==NULL){
        return max1(height(bt,n2)+1,0);
    }
    else if(n2==NULL){
        return max1(height(bt,n1)+1,0);
    }
    else {
        return max1(height(bt,n1)+1,height(bt,n2)+1);
    }
}


void TransverseBinaryTree(struct Node *Tree ,int*arr){

    arr[Tree->depth]++;

    cout<<Tree->label<<endl;
    if(Tree->leftChild==NULL && Tree->rightChild==NULL){
    }
    else if(Tree->leftChild==NULL){
        TransverseBinaryTree(Tree->rightChild,arr);
    }
    else if (Tree->rightChild==NULL)
    {
        TransverseBinaryTree(Tree->leftChild,arr);
    }
    else{
        TransverseBinaryTree(Tree->leftChild,arr);
        TransverseBinaryTree(Tree->rightChild,arr);
    }
    
}
void BubbleSort(int* arr,int size) {
    int n = size;
    bool swapped;
    
    // Outer loop for each pass
    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        // Inner loop for comparing adjacent elements
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements if they are in the wrong order
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

bool AllEqual(int *arr, int size){
    int n=size-1;
    while (n>=0){
        if(arr[n--]!=0){
            return false;
        }
    }
    return true;
}

int power(int base, int exponent){
    int result=1;
    for(int i=0;i<exponent;i++){
        result *=base;
    }
    return result;
}

bool CheckTheSequenceasBT(int* arr,int size){

    int i=size-1;
    BubbleSort(arr,size);
    // for(int i=k;i>=0;i--){
        while(arr[i-1]!=0){
        if(arr[i]==arr[i-1]){
            arr[i]=0;
            arr[i-1]--;
            BubbleSort(arr,size);

        }
        else{
            arr[i]=arr[i-1];
            if(arr[i]==arr[i-1]){
                arr[i]=0;
                arr[i-1]--;
                BubbleSort(arr,size);
            }
        }
        }
        for (int i=0;i<5;i++){
            cout<<arr[i]<<endl;
        }
        if(AllEqual(arr,size)){
            return true;
        }
        return false;
    

}

void PreorderWalk(struct Node *Tree){
    if(Tree==NULL){
        return;
    }
    cout<<Tree->label<<"\t";
    PreorderWalk(Tree->leftChild);
    PreorderWalk(Tree->rightChild);
}

void PostOrderWalk(struct Node *Tree){
    if(Tree==NULL){
        return;
    }
    PostOrderWalk(Tree->leftChild);
    PostOrderWalk(Tree->rightChild);
    cout<<Tree->label<<"\t";
}

void InOrderWalk(struct Node *Tree){
    if(Tree==NULL){
        return;
    }
    InOrderWalk(Tree->leftChild);
    cout<<Tree->label<<"\t";
    InOrderWalk(Tree->rightChild);
}
bool is_BST(struct Node *Tree){
    // if(Tree == NULL){
    //     return true;
    // }
    // cout<<"hii\n";
    if(Tree->leftChild!= NULL){
        is_BST(Tree->leftChild);
    }else{
        return true;
    }
    if(Tree->leftChild->label<Tree->label && Tree->label<=Tree->rightChild->label){
        return true;
    }
    else{
        return false;
    }
    if(Tree->rightChild!= NULL){
        is_BST(Tree->leftChild);
    }else{
        return true;
    }
}
bool isRightLeaf(struct Node *nd){
    if(nd->leftChild==NULL && nd->rightChild==NULL && nd->parent->rightChild==nd){
        return true;
    }
    else {
        return false ;
    }
}
bool isLeaf(struct Node *nd){
    if(nd->leftChild==NULL && nd->rightChild==NULL){
        return true;
    }
    else {
        return false ;
    }
}

void PrintinExpression(struct Node *Tree){
    if(Tree->leftChild==NULL && Tree->rightChild==NULL){
        cout<<Tree->label;
        return ;
    }
    // if(Tree==NULL){
    //     return;
    // }
    cout<<" ( ";
    PrintinExpression(Tree->leftChild);
    if(Tree->label == 0){
    cout<<Tree->op;
    }
    else{
        cout<<Tree->label;
    }

    PrintinExpression(Tree->rightChild);
    cout<<" ) ";
}
Node prev1Print1(struct BinaryTree *bt, struct Node *Tree){
    if(isRightLeaf(Tree)){
        return *(Tree->parent);
    }
    else if(!isLeaf(Tree)){
        if(Tree->leftChild==NULL){
            return *Tree;
        }
        else {
            Node *crt=Tree->leftChild;
            while (crt->rightChild !=NULL){
                crt =crt->rightChild;
            }
            return *crt;
        }
    }
    else{
        Node *crt=Tree->parent;
        while (crt->parent->leftChild==crt)
        {
            /* code */
            crt =crt->parent;
        }
        return *crt;
    }
}

void LevelOrderTransversal(struct Node *Tree){
    
    struct Queue myQueue;
    myQueue.N=20;
    myQueue.head =0;
    myQueue.tail =0;
    myQueue.arr = new Node[myQueue.N];

    enqueue(&myQueue,*Tree);
    while(!isEmpty(&myQueue)){
        cout<<dequeue(&myQueue)<<endl;

    }
}

void HeightOrderTransversal(struct Node *Tree , struct Queue myQueue){
    struct Queue qe;
    qe.N=100;
    qe.head =0;
    qe.tail =0;
    qe.arr = new Node[qe.N];


    enqueue(&qe,*Tree);
    while(!isEmpty(&qe)){
        dequeue1(&qe,&myQueue);
    }
}

Node* searchBST(Node* root, int key) {
    Node* current = root;  // Start with the root node

    while (current != NULL) {
        if (current->label == key) {
            return current;  // Node found, return the pointer to the node
        } else if (current->label < key) {
            current = current->rightChild;  // Move to the right child
        } else {
            current = current->leftChild;   // Move to the left child
        }
    }

    return NULL;  // Node not found, return NULL
}


Node* SearchinBST(struct Node *Tree1, struct Node *nd){
    Node *Tree = Tree1;
    
    if(nd->label==Tree->label){
        return Tree;
    }
    else if(nd->label<Tree->label){
        if(Tree->leftChild==NULL){
            return NULL;
        }
        return SearchinBST(Tree->leftChild,nd);
    }
    else{
        if(Tree->rightChild==NULL){
            return NULL;
        }
        return SearchinBST(Tree->rightChild,nd);
    }
    
}
Node* SearchinPostOrderSearchTree(struct Node *Tree1, struct Node *nd){
    // cout<<"hello";
    Node *Tree = Tree1;
    if(nd->label==Tree->label){
        return Tree;
    }
    if(nd->label > Tree->label){
        // cout<<"Hii";
        return NULL;
    }
    else if(nd->label >= Tree->leftChild->label && Tree->rightChild != NULL &&  nd->leftChild != NULL){
        // cout<<"he\n";

        return SearchinPostOrderSearchTree(Tree->rightChild,nd);
    }
    else if(nd->label <= Tree->leftChild->label &&Tree->leftChild!=NULL){
        // cout<<"he\n";

        return SearchinPostOrderSearchTree(Tree->leftChild,nd);
    }
    else if(nd->label <= Tree->rightChild->label && Tree->rightChild != NULL &&  nd->leftChild == NULL){
        // cout<<"he\n";

        return SearchinPostOrderSearchTree(Tree->rightChild,nd);
    }
    else if (nd->label <= Tree->leftChild->label && Tree->leftChild != NULL &&  nd->rightChild == NULL){
        // cout<<"he\n";

        return SearchinPostOrderSearchTree(Tree->leftChild,nd);
    }
    else if(Tree->label != nd->label && Tree->leftChild == NULL &&  nd->rightChild == NULL ){
        // cout<<"he\n";
        return NULL;

    }else{
        // cout <<"my\n";
        return NULL;
    }
}

Node MinKeyNode(struct Node *Tree){
    Node *crt = Tree;
    while (crt->leftChild != NULL){
        crt =crt ->leftChild;
    }
    return *crt;
}

Node* Successor(struct Node * nd ){
    Node *crt = nd;
    if(nd->rightChild != NULL){
        return nd->rightChild;
    }
    else{
        while (crt->parent->leftChild != crt && crt->parent!= NULL){
            crt=crt->parent;
        }
        return crt->parent;
    }
}
Node* Predecessor(struct Node * nd ){
    Node *crt = nd;
    if(nd->leftChild != NULL){
        return nd->leftChild;
    }
    else{
        while (crt->parent->rightChild != crt && crt->parent!= NULL){
            crt=crt->parent;
        }
        return crt->parent;
    }
}

void Insertion(struct BinaryTree *BT,struct Node *nd){
    Node *x= BT->root;
    Node *y=NULL;
    while (x!= NULL){
        y=x;
        if(x->label > nd->label){
            x=x->leftChild;
        }
        else{
            x=x->rightChild;
        }
    }
    if(y==NULL){
        BT->root=nd;
    }
    if(y->label > nd->label){
        y->leftChild=nd;
    }
    else{
        y->rightChild=nd;
    }
    nd->parent=y;
}

void InsertionInPST(struct BinaryTree *BT,struct Node *root,struct Node *nd){
    // Node *y=NULL;
    if(BT->root->label < nd->label){

        nd->leftChild=BT->root;
        BT->root->parent=nd;
        BT->root=nd;
        return ;
    }
    else if(isLeaf(root)){
        root->leftChild=nd;
        nd->parent=root;
        return ;
    }
    else if(BT->root->leftChild->label >= nd->label){
        return InsertionInPST(BT,root->leftChild,nd);
    }
    else if(BT->root->leftChild->label < nd->label && nd->label < BT->root->rightChild->label){
        return InsertionInPST(BT,root->rightChild,nd);
    }
    else if(BT->root->rightChild->label<nd->label){
            nd->leftChild=BT->root->rightChild;
            BT->root->rightChild->parent=nd;
            BT->root->rightChild=nd;
            nd->parent=BT->root;
            return ;
    }
}



void Deletion(struct BinaryTree *BT,struct Node *nd){
    Node *y = (nd->leftChild==NULL || nd->rightChild==NULL)? nd : Successor(nd);
    if (y != nd){
        nd->label=y->label;
    }
    Node *x = (nd->leftChild==NULL )? nd->rightChild : nd->leftChild;
    if(x!=NULL){
        x->parent=y->parent;
    }
    if(y->parent==NULL){
        BT->root=x;
    }
    else{
        if (y->parent->leftChild==y){
            y->parent->leftChild=x;
        }
        else{
            y->parent->rightChild=x;
        }
    }
    // delete y;
}


void DeletionFromPostOrder(struct BinaryTree *BT,struct Node *nd){

    // delete y;
    if(isLeaf(nd)){
        if(nd->parent->leftChild==nd){
            nd->parent->leftChild=NULL;
        }
        else{
            nd->parent->rightChild=NULL;
        }
        nd->parent=NULL;
    }
    else if(nd->leftChild == NULL){
        if(nd->parent->rightChild==nd){
        nd->parent->rightChild=nd->rightChild;}
        else{
            nd->parent->leftChild=nd->rightChild;
        }
        nd->rightChild->parent=nd->parent;
    }
    else if(nd->rightChild==NULL){
        if(nd->parent->leftChild==nd){
        nd->parent->leftChild=nd->leftChild;}
        else{
            nd->parent->rightChild=nd->leftChild;
        }
        nd->leftChild->parent=nd->parent;
    }
    else if(nd->label==BT->root->label){
        Node *crt =nd->rightChild;
        while(!isLeaf(crt) ){
            if(crt->leftChild!=NULL){
                crt=crt->leftChild;
            }
            else{
                crt=crt->rightChild;
            }
        }
        crt->leftChild=nd->leftChild;
        BT->root=nd->rightChild;
        nd->rightChild->parent=NULL;
        crt->leftChild->parent=crt;
        nd->rightChild=NULL;
        nd->leftChild=NULL;
    }
    else{
        Node *crt =nd->rightChild;

        while(!isLeaf(crt) ){
            if(crt->leftChild!=NULL){
                crt=crt->leftChild;
            }
            else{
                crt=crt->rightChild;
            }
        }
        crt->leftChild=nd->leftChild;
        // crt->parent=nd->parent;
        // BT->root=nd->rightChild;
        nd->rightChild->parent=nd->parent;
        if(nd->parent->leftChild==nd){
            nd->parent->leftChild=nd->rightChild;
        }
        else{
            nd->parent->rightChild=nd->rightChild;
        }
        crt->leftChild->parent=crt;
        nd->rightChild=NULL;
        nd->leftChild=NULL;
        nd->parent=NULL;
    }
}

void leftMostandRightMost(struct BinaryTree *BT,struct Node *nd){
    Node *nd1=SearchinBST(BT->Tree,nd);
    Node *nd2=SearchinBST(BT->Tree,nd);

    while(Predecessor(nd1)->label==nd1->label){
        nd1=Predecessor(nd1);
    }
    while(Successor(nd2)->label==nd2->label){
        nd2=Successor(nd2);
    }
    cout<<endl;
    cout<<"Left Most : "<<nd1->label<<endl;
    cout<<Predecessor(nd1)->label<<endl;
    cout<<"Right Most : "<<nd2->label<<endl;
    cout<<Successor(nd2)->label<<endl;
}
int main(){

    
    struct BinaryTree *bt=new BinaryTree();
    struct Node nd=initialiseNode(81);
    struct Node nd1=initialiseNode(19);
    struct Node nd3=initialiseNode(10);
    struct Node nd4=initialiseNode(99);
    struct Node nd5=initialiseNode(100);
    struct Node nd6=initialiseNode(101);
    
    bt->root=&nd;
    bt->root->depth=0;
    bt->Tree=&nd;
    bt->Tree->depth=0;

    struct BinaryTree *btpo=new BinaryTree();
    struct Node n=initialiseNode(6);
    struct Node n1=initialiseNode(3);
    struct Node n3=initialiseNode(5);
    struct Node n4=initialiseNode(0);
    struct Node n5=initialiseNode(1);
    struct Node n6=initialiseNode(4);
    struct Node n7=initialiseNode(-1);

    
    btpo->root=&n;
    btpo->root->depth=0;
    btpo->Tree=&n;
    btpo->Tree->depth=0;
    InsertChildBoth(btpo->Tree,&n1,&n3);
    InsertChildBoth(btpo->Tree->leftChild,&n4,&n5);
    InsertleftChild(btpo->Tree->rightChild,&n6);
    cout<<btpo->root->leftChild->label<<endl;
    int i=2;
    cout<<"The number of nodes at depth "<<i<<" is "<<NumberOfNodesAtDepth_i_fromNodeN(btpo->root,i)<<endl;

    Node *ft=SearchinPostOrderSearchTree(btpo->root,&n6);
    if(ft != NULL){
        cout<<"This is present.\n";
    }
    else{
        cout<<"This is not present \n";
    }
    cout<<"The minimum key node is "<<MinKeyNode(btpo->Tree).label<<endl;
    cout<<"The Maximum key node is "<<btpo->root->label<<endl;

    InsertionInPST(btpo ,btpo->root,&n7);
    DeletionFromPostOrder(btpo ,&n7);
    DeletionFromPostOrder(btpo,&n1);
    DeletionFromPostOrder(btpo,&n3);

    PostOrderWalk(btpo->root);

    cout<<endl;

    struct BinaryTree *bst=new BinaryTree();
    struct Node nd12=initialiseNode(4);
    struct Node nd13=initialiseNode(3);
    struct Node nd14=initialiseNode(2);
    struct Node nd15=initialiseNode(1);
    struct Node nd16=initialiseNode(5);
    struct Node nd17=initialiseNode(6);
    struct Node nd18=initialiseNode(7);

    struct BinaryTree *bst1=new BinaryTree();
    struct Node nd112=initialiseNode(4);
    struct Node nd113=initialiseNode(3);
    // struct Node nd114=initialiseNode(2);
    // struct Node nd115=initialiseNode(1);
    struct Node nd116=initialiseNode(5);
    struct Node nd117=initialiseNode(6);
    struct Node nd121=initialiseNode(6);
    struct Node nd120=initialiseNode(6);
    struct Node nd119=initialiseNode(6);
    struct Node nd118=initialiseNode(7);

    bst1->root=&nd15;
    bst1->Tree=&nd15;
    Insertion(bst1,&nd112);
    Insertion(bst1,&nd113);
    Insertion(bst1,&nd118);
    Insertion(bst1,&nd116);
    Insertion(bst1,&nd117);
    Insertion(bst1,&nd119);
    Insertion(bst1,&nd120);
    Insertion(bst1,&nd121);

    InOrderWalk(bst1->Tree);
    leftMostandRightMost(bst1,&nd117);
    cout<<endl;

    bst->root=&nd12;
    bst->root->depth=0;
    bst->Tree=&nd12;
    bst->Tree->depth=0;


    InsertChildBoth(bst->Tree,&nd14,&nd16);
    InsertChildBoth(bst->Tree->leftChild,&nd15,&nd13);
    InsertrightChildBoth(bst->Tree->rightChild,&nd17);
    Deletion(bst,&nd16);
    Insertion(bst,&nd18);
    cout<<Successor(&nd17)->label<<endl;

    int key = 6;
    Node* result = SearchinBST(bst->root,&nd16);
    if (result != NULL) {
        cout << "Node with key " << key << " found." << std::endl;
    } else {
        cout << "Node with key " << key << " not found." << std::endl;
    }

    Node result1 =MinKeyNode(bst->root);
    cout<<"The minimum value in the BST is "<<result1.label<<endl;

    Node *scr=Successor(&nd12);
    cout<<"The next element after " <<nd12.label<<" in the In Order walk is "<<scr->label<<endl; 

    PostOrderWalk(bst->Tree);
    cout<<endl;
    InOrderWalk(bst->Tree);
    cout<<endl;

    if(is_BST(bst->Tree)){
        cout<<"The input given is Binary search Tree\n";
    }
    else{
        cout<<"The input given is not a Binary search Tree\n";
    }






    InsertleftChild(bt->Tree,&nd1);
    InsertChildBoth(bt->Tree->leftChild,&nd3,&nd4);
    InsertChildBoth(bt->Tree->leftChild->rightChild,&nd5,&nd6);
    

    if(CheckAncestor(bt,&nd4,&nd3)){
        cout<<"The root Node is the ancestor of the node4 \n";
    }
    else{
        cout<<"The Root node is not the ancestor of the node 4\n";
    }

    cout <<bt->root->label<<endl;
    cout<<bt->Tree->leftChild->label<<endl;
    if(bt->Tree->rightChild==NULL){
        cout<<"No RightChild .\n";
    }
    else{
    cout<<bt->Tree->rightChild->label<<endl;
    }
    cout<<bt->Tree->leftChild->leftChild->label<<endl;
    cout<<bt->Tree->leftChild->rightChild->label<<endl;

    if(checkSibling(bt,&nd3,&nd4)){
        cout<< "Nd4 and nd3 are siblings .\n";

    }
    else {
        cout<< " Nd4 and nd3 are not siblings. \n " ;
        
    }
    cout<<"The level/depth of the Tree is " << level_depth(bt,&nd4)<<endl;
    Node Node1=LowestCommonAncestor(&nd3,&nd6,bt);
    int data=Node1.label;
    cout <<data<<endl;

    cout<< "The height of the Root node is : "<<height(bt,&nd)<<endl;
    int arr[10];
    for (int i=0;i<10;i++){
        arr[i]=0;
    }
    int depth=level_depth(bt,&nd6);

    cout<<"The node's label which appear just befor is " <<prev1Print1(bt,&nd).label<<endl;
    
    TransverseBinaryTree(bt->root,arr);
    int Total=0;
    float count=0;
    for (int i=0;i<=depth;i++){
        Total += i*arr[i];
        count +=arr[i];
    }
    cout<<"The depth is "<<depth<<endl;
    cout<<"Total :"<<Total<<endl;
    cout<<"The mean depth is : "<<Total/count<<endl;

    int arr1[5] ={1,2,2,3,3};
    int size1=5;
    if(CheckTheSequenceasBT(arr1,size1)){
        cout<<"This sequence is possible .\n";
    }
    else {
        cout<<"The sequence is not possible .\n";
    }

    cout<<"This is the PreOrderWalk"<<endl;
    PreorderWalk(bt->Tree);
    cout<<endl;
    cout<<"This is the InOrderWalk"<<endl;
    InOrderWalk(bt->Tree);
    cout<<endl;

    cout<<"This is the PostOrderWalk"<<endl;
    PostOrderWalk(bt->Tree);
    cout<<endl;


    struct BinaryTree *bt1=new BinaryTree();
    struct Node p0=initialiseNode1('+');
    struct Node p11=initialiseNode1('*');
    struct Node p12=initialiseNode1('/');
    struct Node p21=initialiseNode(5);
    struct Node p22=initialiseNode(4);
    struct Node p23=initialiseNode(6);
    struct Node p24=initialiseNode(3);



    bt1->root=&p0;
    bt1->root->depth=0;
    bt1->Tree=&p0;
    bt1->Tree->depth=0;
    InsertChildBoth(bt1->Tree,&p11,&p12);
    InsertChildBoth(bt1->Tree->leftChild,&p21,&p22);
    InsertChildBoth(bt1->Tree->rightChild,&p23,&p24);
    PrintinExpression(bt1->Tree);
    cout<<endl;

    LevelOrderTransversal(bt->Tree);
    struct Queue myQueue;
    myQueue.N=100;
    myQueue.head =0;
    myQueue.tail =0;
    myQueue.arr = new Node[myQueue.N];

    HeightOrderTransversal(bt->Tree , myQueue);

    for (int i=5;i>=0;i--){
        cout << myQueue.arr[myQueue.head +i].label <<endl;
    }



    return 0;

}

