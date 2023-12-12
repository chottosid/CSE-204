#include<iostream>
using namespace std;
template<typename T>
class Node{
    T data;
    Node *next;
    Node *prev;
public:
    Node(){
        data=-1;
        next=prev=NULL;
    }
    Node(T x){
        data=x;
        next=prev=NULL;
    }
    Node* getNext(){return next;}
    void setNext(Node* next){this->next=next;}
    Node* getPrev(){return prev;}
    void setPrev(Node* prev){this->prev=prev;}
    T getData(){return data;}
};
template<typename T>
class MyList
{
    Node<T> *head;
    int listsize;
    Node<T> *current;
public:
    MyList()
    {
        head=current= NULL;
        listsize=0;
    }
    MyList(T *ara, int listsize,int capacity)
    {
        head = new Node<T> (ara[0]);
        Node<T> *prev=head;
        Node<T> *curr;
        for(int i=1;i<listsize;i++){
            curr= new Node<T> (ara[i]);
            prev->setNext(curr);
            curr->setPrev(prev);
            prev=curr;
        }
        this->listsize=listsize;
    }
    int size(){return listsize;}
    void push(T x)
    {
        if(head==NULL){
            head= new Node<T> (x);
            head->setNext(NULL);
            head->setPrev(NULL);
            listsize++;
        }
        else{
            Node<T> *temp = new Node<T> (x);
            current->getPrev()->setNext(temp);
            temp->setPrev(current->getPrev());
            temp->setNext(current);
            current->setPrev(temp);
            current=temp;
            listsize++;
        }
    }
    void pushBack(T x)
    {
        if(head==NULL){
            head= new Node<T> (x);
            head->setNext(NULL);
            head->setPrev(NULL);
            listsize++;
        }
        else{
            Node<T> * temp=head;
            while(temp->getNext()!=NULL){
                temp=temp->getNext();
            }
            Node<T> *n = new Node<T> (x);
            temp->setNext(n);
            n->setPrev(temp);
            n->setNext(NULL);
            listsize++;
        }
    }
    T erase()
    {
        if(current==NULL) current=head;
        if(current->getPrev()!=NULL){
            current->getPrev()->setNext(current->getNext());
            //current->getNext()->setPrev(current->getPrev());
        }
        else{
            head=current->getNext();
            //head->setPrev(NULL);
        }
        if(current->getNext()!=NULL){
            current->getNext()->setPrev(current->getPrev());
        }
        Node<T> *temp=current->getNext();
        T ans = current->getData();
        delete current;
        current=temp;
        listsize--;
        return ans;
    }
    void setToBegin(){current=head;}
    void setToEnd()
    {
        current=head;
        while (current->getNext()!=NULL)
        {
            current=current->getNext();
            //cout<<current->getData()<<endl;
        }
    }
    void prev(){
        if(current->getPrev()!=NULL) current=current->getPrev();
    }
    void next(){
        if(current->getNext()!=NULL) current=current->getNext();
    }
    int currPosition(){
        Node<T> *temp=head;
        int cnt=0;
        while(temp!=current){
            temp=temp->getNext();
            cnt++;
        }
        return cnt;
    }
    void setToPos(int pos)
    {
        Node<T> *temp=head;
        while(pos--){
            temp=temp->getNext();
        }
        current=temp;
    }
    T getValue(){return current->getData();}
    int find(T x){
        int index=0;
        Node<T> *temp=head;
        while(temp->getData()!=x and temp->getNext()!=NULL){
            temp=temp->getNext();
            index++;
        }
        if(temp->getNext()==NULL) return -1;
        return index;
    }
    void clear(){
        while(head!=NULL){
            Node<T> * temp=head->getNext();
            delete head;
            head=temp;
        }
    }
};
// int main()
// {
//     MyList<int> l;
//     l.setToBegin();
// }