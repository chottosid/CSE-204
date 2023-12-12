#include "MyListArr.cpp"    //Change the header file to switch between
#include<fstream>           //array based and ll based implemenation of MyList
using namespace std;

template<typename T>
void print(MyList<T>& lst,ofstream& out){       //helper print function to print the MyList object
    out<<"< ";
    int pos=lst.currPosition();
    lst.setToBegin();
    while(lst.currPosition()<lst.size()-1){
        if(lst.currPosition()!=pos) out<<lst.getValue()<<" ";
        else out<<"|"<<lst.getValue()<<" ";
        lst.next();
    }
    if(lst.currPosition()!=pos) out<<lst.getValue()<<" ";
    else out<<"|"<<lst.getValue()<<" ";
    lst.setToPos(pos);
    out<<">"<<endl;
}

int main()
{
    int k,x;
    ifstream in;
    ofstream out;
    in.open("list_input.txt");
    out.open("list_output.txt");
    in>>k>>x;
    int arr[k];
    for(int i=0;i<k;i++) in>>arr[i];
    MyList<int> ls(arr,k,x);
    ls.setToPos(ls.size()/2);
    int q;
    in>>q;
    print(ls,out);
    while(q--){
        int a,b;
        in>>a>>b;
        if(a==1){
            print(ls,out);
            out<<ls.size()<<endl;
        }
        else if(a==2){
            ls.push(b);
            print(ls,out);
            out<<-1<<endl;
        }
        else if(a==3){
            ls.pushBack(b);
            print(ls,out);
            out<<-1<<endl;
        }
        else if(a==4){
            int ans=ls.erase();
            print(ls,out);
            out<<ans<<endl;
        }
        else if(a==5){
            ls.setToBegin();
            print(ls,out);
            out<<-1<<endl;
        }
        else if(a==6){
            ls.setToEnd();
            print(ls,out);
            out<<-1<<endl;
        }
        else if(a==7){
            ls.prev();
            print(ls,out);
            out<<-1<<endl;
        }
        else if(a==8){
            ls.next();
            print(ls,out);
            out<<-1<<endl;
        }
        else if(a==9){
            print(ls,out);
            out<<ls.currPosition()<<endl;
        }
        else if(a==10){
            ls.setToPos(b);
            print(ls,out);
            out<<-1<<endl;
        }
        else if(a==11){
            print(ls,out);
            out<<ls.getValue()<<endl;
        }
        else if(a==12){
            print(ls,out);
            out<<ls.find(b)<<endl;
        }
        else if(a==13){
            ls.clear();
            print(ls,out);
            out<<-1<<endl;
        }
        else{
            out<<"Error"<<endl;
        }
    }
}
