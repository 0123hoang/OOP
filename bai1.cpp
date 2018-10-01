#include<iostream>
#include<cstring>
using namespace std;

    void Union(int a[],int n){
        int root=-1;
        for(int i=0;i<n;i++){
            if(a[i]==-1){
                if(root==-1)
                    root=i;
                else{
                    a[i]=root;
                    cout<<"Union 2 trees succeed!";
                    return;
                }
            }
        }
    }
    void Print(int a[],int n){
        cout<<endl;
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    void Find(int a[],int n,int num){
        if(a[num]==-1){
            cout<<num;
            return;
        }
        Find(a,10,a[num]);
        return;
    }
    void Delete(int a[],int n,int root){
        a[root]=-2;
        for(int i=0;i<n;i++){
            if(a[i]==root){
                Delete(a,n,i);
            }
        }
    }

int main(){
    int a[10];
    for(int i=0;i<10;i++)
        a[i]=-2;
    int tree;
    cout<<"nhap so cay: ";
    cin>>tree;
    cout<<endl;
    int node,root;
    for(int j=0;j<tree;j++){
        int C_node;
        cout<<"nhap so node cua cay "<<j+1<<endl;
        cin>>C_node;
        cout<<"nhap du lieu theo thu tu node->root"<<endl;
        for(int i=0;i<C_node;i++){
            cin>>node>>root;
            a[node]=root;
        }
    }
    Print(a,10);
    Union(a,10);
    Print(a,10);
    cout<<"root of "<< 6<<" is ";
    Find(a,10,6);
    Delete(a,10,8);
    Print(a,10);
    return 0;
}
