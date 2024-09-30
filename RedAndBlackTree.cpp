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
void Rotation(struct Node *A,struct Node * B){
    if(A->rightChild==NULL){
        A->rightChild=B->leftChild;
        B->parent=A->parent;
        B->leftChild=A;
        A->parent=B;

    }
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
    return 0;
}