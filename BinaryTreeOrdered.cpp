#include<iostream>
using namespace std;

struct Node {
    Node* firstChild;
    Node* parent;
    Node* nextSibling;
    int label;
};

struct BinaryTree
{
    Node* root;
    Node* Tree;
};


void InsertfirstChild(struct Node *Tree , Node * firstChildNode){
    Tree->firstChild=firstChildNode;
    Tree->firstChild->parent=Tree;
    Tree->firstChild->nextSibling=NULL;
}
void Insertnextsibling(struct Node *Tree ,Node* nextSiblingNode){
    Node *currentChild= Tree->firstChild;
    while (currentChild->nextSibling != NULL){
        currentChild =currentChild->nextSibling;
    }
    currentChild->nextSibling=nextSiblingNode;
    currentChild->nextSibling->parent=Tree;
    currentChild->nextSibling->nextSibling=NULL;

}

Node initialiseNode(int label1){
    struct Node *nd=new Node();
    nd->firstChild=NULL;
    nd->nextSibling=NULL;
    nd->label=label1;
    return *nd;
}

int main(){
    struct BinaryTree *bt=new BinaryTree();
    struct Node nd=initialiseNode(81);
    struct Node nd1=initialiseNode(19);
    struct Node nd3=initialiseNode(10);
    struct Node nd4=initialiseNode(99);

    bt->root=&nd;
    bt->Tree=&nd;

    InsertfirstChild(bt->Tree,&nd1);
    InsertfirstChild(bt->Tree->firstChild,&nd3);
    Insertnextsibling(bt->Tree->firstChild,&nd4);

    cout<<bt->root->label<<endl;
    cout<<bt->Tree->firstChild->label<<endl;
    cout<<bt->Tree->firstChild->firstChild->label<<endl;
    cout<<bt->Tree->firstChild->firstChild->nextSibling->label<<endl;
    



}

