#ifndef TREE_H
#define TREE_H
#include<cstdlib>
#include<iostream>
using namespace std;
class tree{
    private:
        int data=0;
        tree *left;
        tree *right;
    public:
        tree(){
             left=NULL;
             right=NULL;
        }
        int CalcuTreeHeight(){
                if(this->left==NULL&&this->right==NULL)
                    return 0;
                return max(this->left->CalcuTreeHeight()+1,this->right->CalcuTreeHeight()+1);
        }
        void Order(int data){
            if(this->data==NULL){
                    this->data=data;
                    this->left=new tree();
                    this->right=new tree();
            }
            else{
                    if(this->data>data){
                            this->left->Order(data);
                    }
                    else{
                            this->right->Order(data);
                    }
            }
            return;
        };
        void PreOrder(){
                if(this->data!=NULL)
                        cout<<this->data<<" ";
                if(this->left!=NULL){
                        this->left->PreOrder();
                }
                if(this->right!=NULL){
                        this->right->PreOrder();
                }
                return ;
        }
        void PostOrder(){
                if(this->left!=NULL){
                    this->left->PostOrder();
                    if(this->right!=NULL){
                        this->right->PostOrder();
                    }
                }
                if(this->data!=NULL)
                        cout<<this->data<<" ";
                return ;
        }
        void Print(){
                if(this->data==NULL)return;
                else{
                        if(this->left!=NULL){
                                this->left->Print();
                        }
                        cout<<this->data<<" ";
                        if(this->right!=NULL){
                                this->right->Print();
                        }
                }
        }
        bool Find(int data){
                if(this->data==NULL){
                        cout<<data<<" not found"<<endl;
                        return false;
                }
                if(this->data==data){
                        cout<<data<<" has in tree"<<endl;
                        return true;
                }
                else if(this->data>data){
                        this->left->Find(data);
                }
                else
                        this->right->Find(data);
        }
        void InsertData(int data){
                tree *curr=this;
                for(;(curr->left->data!=NULL)||(curr->right->data!=NULL);){
                    cout<<(curr->left->data!=NULL)<<" "<<(curr->right->data!=NULL)<<" "<<(curr->left!=NULL)<<" "<<(curr->right!=NULL)<<endl;
                        if(curr->data < data){
                                curr=curr->right;
                        }
                        else curr=curr->left;
                }
                tree *temp=new tree();
                temp->data=data;
                if(curr->data>data){
                        curr->left=temp;
                }
                else{
                        curr->right=temp;
                }

        }
        void Delete(int data){
                if(!this->Find(data)){
                        return;
                }
                tree *curr=this;
                while(curr->data!=data){
                        if(curr->data < data){
                                curr=curr->right;
                        }
                        else curr=curr->left;
                }
                        while(curr->right->data!=NULL){
                                swap(curr->data,curr->right->data);
                                curr=curr->right;
                        }
                curr->data=NULL;
        }
};


#endif
