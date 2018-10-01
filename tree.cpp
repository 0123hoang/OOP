#include<iostream>
#include"tree.h"
#include<cstdlib>
using namespace std;

int main(){
    tree test;
    int data;
    for(int i=1;i<10;i++){
            cin>>data;
        test.Order(data);
    }
    // cout<<test.CalcuTreeHeight();
    // cout<<endl;
    // test.Print();
    // cout<<endl;
    // test.PostOrder();
    // cout<<endl;
    // test.PreOrder();
    //cout<<(test.find(10));
    //test.InsertData(11);
    //test.PostOrder();
    test.Delete(9);
    test.PostOrder();
     return 0;
}
