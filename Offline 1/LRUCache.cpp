#include "MyListLL.cpp"
#include<iostream>
#include<fstream>
using namespace std;
class Data{
    int key,value;
public:
    Data(){key=value=0;}
    Data(int k,int v){key=k;value=v;}
    int getKey(){return key;}
    int getvalue(){return value;}
    void setValue(int value){this->value=value;}
    void display(){cout<<"key and value "<<key<<" "<<value<<endl;}
};
class LRUCache{
    int capacity;
    MyList<Data> cache;
public:
    LRUCache(int c){capacity=c;}
    int get(int x){
        cache.setToBegin();
        for(int i=0;i<cache.size();i++){
            cache.setToPos(i);
            Data temp=cache.getValue();
            if(temp.getKey()==x){
                int ans=temp.getvalue();
                cache.erase();
                cache.pushBack(Data(x,ans));
                return ans;
            }
        }
        return -1;
    }
    void put(int x,int y){
        cache.setToBegin();
        bool found =false;
        for(int i=0;i<cache.size();i++){
            cache.setToPos(i);
            Data temp=cache.getValue();
            if(temp.getKey()==x){
                cache.erase();
                cache.pushBack(Data(x,y));
                found=true;
                break;
            }
        }
        if(!found){
            if(cache.size()<capacity){
                //cache.setToBegin();
                //cache.erase();
                cache.pushBack(Data(x,y));
            }
            else{
                cache.setToBegin();
                cache.erase();
                cache.pushBack(Data(x,y));
            }
        }
    }
    void display(){
        for(int i=0;i<cache.size();i++){
            cache.setToPos(i);
            cout<<cache.getValue().getKey()<<" "<<cache.getValue().getvalue()<<endl;
       }
    }
};
int main()
{
    ifstream in;
    ofstream out;
    in.open("lru_input.txt");
    out.open("lru_output.txt");
    int c,q;
    in>>c>>q;
    LRUCache cache(c);
    while(q--){
        int a;in>>a;
        if(a==1){
            int b;
            in>>b;
            out<<cache.get(b)<<endl;
        }
        else{
            int b,c;
            in>>b>>c;
            cache.put(b,c);
        }
    }
}
