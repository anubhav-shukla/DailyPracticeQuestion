#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int data){
        this -> data = data;
        this -> left = this->right = nullptr;
    }
};

void preorder (Node* root){
    if(root == nullptr){
        return;
    }

    cout<< root->data << " ";
    preorder(root->left);
    preorder(root->right);


}

void postorder (Node* root){
    if(root == nullptr){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    
    cout<< root->data << " ";


}
void Inorder (Node* root){
    if(root == nullptr){
        return;
    }

    Inorder(root->left);
    
    cout<< root->data << " ";

    Inorder(root->right);


}

void invertBinaryT(Node* root){
    if(root == nullptr){
        return;
    }

    swap(root -> left, root->right);
    invertBinaryT(root->left);
    invertBinaryT(root->right);
}

int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    invertBinaryT(root);
    // preorder(root);
    // Inorder(root);
    postorder(root);
    

    return 0;
    
}
