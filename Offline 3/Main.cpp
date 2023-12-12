#include<iostream>
#include "BST.cpp"
#include<fstream>
using namespace std;
int makeint(string s)
{
    int ans=0;
    for(int i=2;i<s.size();i++){
        ans=10*ans+s[i]-'0';
    }
    return ans;
}
int main()
{
    BST<int> bst;
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    std::cin.rdbuf(cin.rdbuf());
    std::cout.rdbuf(cout.rdbuf());
    string line;
    while (getline(cin,line))
    {
        if(line.size()<1) break;
        if(line[0]=='I'){
            bst.insert(makeint(line));
            string s="";
            bst.show(bst.getRoot(),s);
            cout<<s<<endl;
        }
        else if(line[0]=='F'){
            if(bst.find(makeint(line))){
                cout<<"True\n";
            }
            else cout<<"False\n";
        }
        else if(line[0]=='D'){
            if(bst.delt(makeint(line))){
                //cout<<"int from line is"<<makeint(line);
                string s="";
                bst.show(bst.getRoot(),s);
                cout<<s<<endl;
            }
            else{
                cout<<"Invalid Operation\n";
            }
        }
        else if(line[0]=='T'){
            if(line.size()==4){
                bst.inorder(bst.getRoot());
                cout<<endl;
            }
            else if(line.size()==5){
                bst.preorder(bst.getRoot());
                cout<<endl;
            }
            else {bst.postorder(bst.getRoot());cout<<endl;}
        }
    }
}