#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

template<typename T>
class minheap{
    public:
    T *arr;
    int maxsiz;
    int siz;
    minheap(int si)
    {
        maxsiz=si;
        arr= new T[maxsiz];
        siz=0;
    }
    int parent(int n){return (n-1)/2;}
    int leftchild(int n){return 2*n+1;}
    int rightchild(int n){return 2*n+2;}
    T FindMin(){ return arr[0];}
    T ExtractMin(){
        if(siz==1){
            siz--;
            return arr[0];
        }
        swap(arr[0],arr[siz-1]);
        siz--;
        if(siz!=0){ shift(0);}
        return arr[siz];
    }
    void Insert(T key){
        if(siz==maxsiz){
            T *temp= new T[2*siz+1];
            for(int i=0;i<siz;i++){
                temp[i]=arr[i];
            }
            delete arr;
            arr=temp;
            maxsiz=2*siz+1;
        }
        siz++;
        int temp=siz-1;
        arr[temp]=key;
        while(temp!=0 and arr[parent(temp)]>arr[temp]){
            swap(arr[temp],arr[parent(temp)]);
            temp=parent(temp);
        }
    }
    void DecreaseKey(T prev, T next){
        int index=find(prev);
        if(index<0) return;
        arr[index]=next;
        while (index!=0 and arr[parent(index)]>arr[index]) {
            swap(arr[index],arr[parent(index)]);
            index=parent(index);
        }
    }
    int find(T n){
        for(int i=0;i<siz;i++){
            if(arr[i]==n) return i;
        }
        return -1;
    }
    void Print(){
        int level=0;
        //int i;
        cout<<"Printing the Binary Heap: "<<endl<<endl;
        while((((1<<(level))-1)<siz)){
            int i=(1<<level)-1;
            int j=(1<<(level+1))-1;
            cout<<"LEVEL "<<level<<" :"<<endl;
            while(i<siz and i<j){
                cout<<arr[i]<<" ";
                i++;
            }
            cout<<endl;
            level++;
        }
        //cout<<"hey"<<arr[0]<<arr[1]<<arr[2]<<endl;
        cout<<endl;
    }
    void shift(int n){
        while(!checkLeaf(n)){
            int lc=leftchild(n);
            int rc=rightchild(n);
            int index=lc;
            if(rc<siz and arr[lc]>arr[rc]) index=rc;
            if(arr[n]<arr[index]) return;
            else swap(arr[n],arr[index]);
            n=index;
        }
    }
    bool checkLeaf(int n){
        if(n>=siz/2 and n<siz) return true;
        return false;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    minheap<int> heap(10);
    char s[100];
    while (scanf("%s",s)!=EOF)   
    {
        if(strcmp(s,"INS")==0){
            int a;scanf("%d",&a);
            heap.Insert(a);
            printf("INSERTED %d\n",a);
        }
        else if(strcmp(s,"PRI")==0){
           heap.Print(); 
        }
        else if(strcmp(s,"DEC")==0){
            int a,b;
            scanf("%d %d",&a,&b);
            heap.DecreaseKey(a,b);
            printf("%d decreased to %d\n",a,b);
        }
        else if(strcmp(s,"FIN")==0){
            int ans=heap.FindMin();
            printf("FindMin returned %d\n",ans);
        }
        else if(strcmp(s,"EXT")==0){
            int ans=heap.ExtractMin();
            printf("ExtractMin returned %d\n",ans);
        }
    }
    
}