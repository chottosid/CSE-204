#include<iostream>
using namespace std;
template<typename T>
class MyList
{
    T *arr;
    int capacity;
    int listsize;
    int currPos;
public:
    MyList()
    {
        arr= new T[10];
        capacity=10;
        listsize=currPos=0;
    }
    MyList(T *ara, int listsize,int capacity)
    {
        //T temp;
        arr=new T[capacity];
        for(int i=0;i<listsize;i++) arr[i]=ara[i];
        this->listsize=listsize;
        this->capacity=capacity;
    }
    ~MyList()
    {
        delete[] arr;
    }
    int size(){return listsize;}
    void push(T x)
    {
        if(listsize+1<=capacity){
            for(int i=listsize;i>=currPos+1;i--){
                arr[i]=arr[i-1];
            }
            arr[currPos]=x;
            listsize++;
        }
        else{
            T *arr2= new T[2*capacity];
            for(int i=0;i<listsize;i++){
                arr2[i]=arr[i];
            }
            for(int i=listsize;i>=currPos+1;i--){
                arr[i]=arr[i-1];
            }
            arr[currPos]=x;
            listsize++;
            capacity=2*capacity;
            delete[] arr;
            arr=arr2;
        }

    }
    void pushBack(T x)
    {
        if(listsize+1<=capacity){
            arr[listsize]=x;
            listsize++;
                    //cout<<"here";
        }
        else{
            T *arr2= new T[2*capacity];
            for(int i=0;i<listsize;i++){
                arr2[i]=arr[i];
            }
            capacity=2*capacity;
            delete[] arr;
            arr=arr2;
            listsize++;
        }
    }
    T erase()
    {
        T temp=arr[currPos];
        for(int i=currPos;i<listsize-1;i++){
            arr[i]=arr[i+1];
        }
        listsize--;
        if(listsize<=capacity/2){
            T *arr2=new T[listsize];
            for(int i=0;i<listsize;i++){
                arr2[i]=arr[i];
            }
            delete[] arr;
            arr=arr2;
        }
        if(currPos==listsize) currPos--;
        return temp;
    }
    void setToBegin(){currPos=0;}
    void setToEnd(){currPos=listsize-1;}
    void prev(){
        if(currPos>0) currPos--;
    }
    void next(){
        if(currPos<listsize-1) currPos++;
    }
    int currPosition(){
        return currPos;
    }
    void setToPos(int pos){if(pos<=listsize-1 and pos>=0) currPos=pos;}
    T getValue(){return arr[currPos];}
    int find(T x){
        for(int i=0;i<listsize;i++){
            if(arr[i]==x) return i;
        }
        return -1;
    }
    void clear(){
        delete[] arr;
        capacity=0;
        listsize=0;
        currPos=0;
    }
};
