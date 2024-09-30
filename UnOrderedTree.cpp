#include<iostream>
using namespace std;
#include <set>


struct Node {
    Node* parent;
    Node* Child;
    int label;
};

struct BinaryTree
{
    Node* root;
    Node* Tree;
};

void InsertChild(struct Node *Tree , Node * leftNode,Node*rightNode,int set m){
    Tree->leftChild=leftNode;
    Tree->leftChild->parent=Tree;
    Tree->rightChild=rightNode;
    Tree->rightChild->parent=Tree;
}
void InsertleftChild(struct Node *Tree , Node * leftNode){
    Tree->leftChild=leftNode;
    Tree->leftChild->parent=Tree;
    Tree->rightChild=NULL;
}
void InsertrightChildBoth(struct Node *Tree ,Node*rightNode){
    Tree->leftChild=NULL;
    Tree->rightChild=rightNode;
    Tree->rightChild->parent=Tree;
}

Node initialiseNode(int label1){
    struct Node *nd=new Node();
    nd->leftChild=NULL;
    nd->rightChild=NULL;
    nd->label=label1;
    return *nd;
}

int main(){
    
    set <int> s;

    struct BinaryTree *bt=new BinaryTree();
    struct Node nd=initialiseNode(81);
    struct Node nd1=initialiseNode(19);
    struct Node nd3=initialiseNode(10);
    struct Node nd4=initialiseNode(99);

    bt->root=&nd;
    bt->Tree=&nd;



    InsertleftChild(bt->Tree,&nd1);
    InsertChildBoth(bt->Tree->leftChild,&nd3,&nd4);

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


}

