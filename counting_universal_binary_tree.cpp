#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data){
    struct Node* temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int isTrue(struct Node* root, int &count){
    if(root==NULL){
        return 1;
    }
    if((isTrue(root->left, count) == isTrue(root->right, count)) == 1){
        if(root->left ==NULL && root->right == NULL){
            count+=1;
            return 1;
        }
        else if(root->left!=NULL && root->data==root->left->data && root->right==NULL){
            count+=1;
            return 1;
        }
        else if(root->right!=NULL && root->data==root->right->data && root->left==NULL){
            count+=1;
            return 1;
        }
        else if(root->left != NULL && root->right != NULL){
            if(root->left->data==root->right->data && root->left->data==root->data){
                count+=1;
                return 1;
            }
            else
                return 0;
        }
        else{
            return 0;
        }
    }
    return 1;
}

int main() {
    struct Node* a = newNode(1);
    a->left = newNode(1);
    a->right = newNode(1);
    a->left->left = newNode(1);
    a->left->right = newNode(1);
    a->left->left->left = newNode(1);
    a->left->left->right = newNode(1);
    int count = 0;
    int par_data = a->data;
    isTrue(a, count);
    cout<<count<<endl;
    return 0;
}