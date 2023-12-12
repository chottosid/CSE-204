#include<iostream>
#include<string>
#include "NodeBST.cpp"
#include "MyListArr.cpp"
using namespace std;
template<typename T>
class BST
{
    NodeBST<T>* root;
    int cnt;
public:
    BST(){
        cnt=0;
        root=NULL;
    }
    void inorder(NodeBST<T>* x){
        if(x!=NULL){
            inorder(x->getLeft());
            cout<<x->getKey()<<" ";
            inorder(x->getRight());
        }
    }
    MyList<T> preorder(NodeBST<T>* x){
        MyList<T> list;
        if(x!=NULL){
            list.pushBack(x->getKey());
            cout<<x->getKey()<<" ";
            preorder(x->getLeft());
            preorder(x->getRight());
        }
        return list;
    }
    void postorder(NodeBST<T> * x){
        if(x!=NULL){
            postorder(x->getLeft());
            postorder(x->getRight());
            cout<<x->getKey()<<" ";
        }
    }
    void insert(T key){
        NodeBST<T>* node= new NodeBST<T>(key,key);
        NodeBST<T>* y=NULL;
        NodeBST<T>* x=root;
        while (x!=NULL)
        {
            y=x;
            if(node->getKey()< x->getKey()){
                x=x->getLeft();
            }
            else x=x->getRight();
        }
        node->setParent(y);
        if(y==NULL){
            root=node;
        }
        else if(node->getKey()<y->getKey()) y->setLeft(node);
        else y->setRight(node);
        cnt++;
    }
    bool delt(T val){
        NodeBST<T>* node=root;
        while(node!=NULL){
            if(node->getKey()==val){
                if(node->getRight()==NULL and node->getLeft()==NULL){
                    NodeBST<T>* papa=node->getParent();
                    if(papa->getLeft()==node) papa->setLeft(NULL);
                    else papa->setRight(NULL);
                    delete node;
                    node=NULL;
                    cnt--;
                    return true;
                }
                else return false;
            }
            else if(val<node->getKey()) node=node->getLeft();
            else node=node->getRight();
        }
        cnt--;
        return false;
    }
    bool find(T k){
        NodeBST<T>* node=root;
        while(node!=NULL){
            if(node->getKey()==k) return true;
            if(k<node->getKey()) node=node->getLeft();
            else node=node->getRight();
        }
        return false;
    }
    void show(NodeBST<T> * node,string & s)
    {
        if(node==NULL) return;
        s=s+(to_string(node->getKey()));
        //cout<<"key here:"<<node->getKey()+'0';
        if(node->getLeft()==NULL and node->getRight()==NULL) return;
        s.push_back('(');
        show(node->getLeft(),s);
        s.push_back(')');
        s.push_back('(');
        show(node->getRight(),s);
        s.push_back(')');
        // if(node!=NULL){
        //     cout<<"(";
        //     cout<<node->getKey();
        //     show(node->getLeft());
        //     //cout<<' ';
        //     show(node->getRight());
        //     cout<<")";
        // }
    }
    void show2(NodeBST<T>* node){
        cout<<node->getKey();
        show(node->getLeft());
        show(node->getRight());
    }
    NodeBST<T>* getRoot(){return root;}
};
