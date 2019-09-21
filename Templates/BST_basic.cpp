//

#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node *leftchild;
    struct node *rightchild;
};

void outorder(struct node*root, int *temp)
{
    if(root)
    {
        outorder(root->rightchild, temp);//Go to left subtree
        *temp = *temp + root->data;
        root->data = *temp-root->data;
        printf("%d ",root->data);    //Printf root->data
        outorder(root->leftchild, temp);     //Go to right subtree
    }
}

struct node* find(int data, struct node* root){
    if(root==NULL){
        cout<<"not found";
        return root;
    }
    cout<<root->data<<endl;
    if(data<root->data){
        
        find(data, root->leftchild);
    }
    else if(data == root->data){
        return root;
    }
    else{
        find(data, root->rightchild);
    }
    return root;
}

struct node* insert(int data, struct node* root){
    struct node* tempnode = (struct node*)malloc(sizeof(struct node));
    struct node* current = (struct node*)malloc(sizeof(struct node));
    struct node* parent = (struct node*)malloc(sizeof(struct node));
    tempnode -> data = data;
    tempnode -> leftchild = NULL;
    tempnode -> rightchild = NULL;
    if(root==NULL){
        root = tempnode;
    }
    else{
        current = root;
        parent = NULL;
    }
    
    while(1){
        parent=current;
        if(data<parent->data){
            current = parent->leftchild;
            if(current==NULL){
                parent->leftchild = tempnode;
                return root;
        
            }
        }
        else{
            current = parent->rightchild;
            if(current ==NULL){
                parent->rightchild = tempnode;
                return root;
            }
        }
    }
    return root;
}

void deletenode(struct node* root, int data){
    
    struct node* prev = (struct node*)malloc(sizeof(struct node));
    prev = root;
    
    if(data<root->data){
        deletenode(data, root->leftchild);
    }
    else if(data == root->data){
        return root;
    }
    else{
        find(data, root->rightchild);
    }
    return;
    
}

int main() {
    
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root = NULL;
    int data = 5;
    
    root = insert(data, root);
    data = 10;
    root = insert(data, root);
    data = 11;
    insert(data, root);
    data = 2;
    insert(data, root);
    data = 3;
    insert(data, root);
    int temp = 0;
    outorder(root, &temp);
    
    return 0;
}
