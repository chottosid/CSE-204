#include<iostream>
using namespace std;
template<typename T>
class NodeBST{
    T key;
    T data;
    NodeBST *right;
    NodeBST *left;
    NodeBST *parent;
public:
    NodeBST(){
        key=data=-1;
        left=right=parent=NULL;
    }
    NodeBST(T k,T v){
        key=k;
        data=v;
        left=right=parent=NULL;
    }
    NodeBST(NodeBST<T> &n){
        key=n.key;
        data=n.data;
        right=n.right;
        left=n.left;
    }
    ~NodeBST(){
        key=-1;
        right=left=parent=NULL;
    }
    NodeBST* getParent(){return parent;}
    void setParent(NodeBST* par){parent=par;}
    NodeBST* getRight(){return right;}
    void setRight(NodeBST* right){this->right=right;}
    NodeBST* getLeft(){return left;}
    void setLeft(NodeBST* left){this->left=left;}
    T getKey(){return key;}
    T getData(){return data;}
};