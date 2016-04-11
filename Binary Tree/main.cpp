//
//  main.cpp
//  Binary Tree
//
//  Created by Farooq Khan on 4/9/16.
//  Copyright © 2016 Farooq Khan. All rights reserved.
//

#include <iostream>

using namespace std;

struct Node {
    
    int value;
    Node* left;
    Node* right;
    
    //  Constructors
    Node();
    Node(int value) {
        left = nullptr;
        right = nullptr;
        this->value = value;
    }
    
}* root = nullptr;

class Tree {
public:
    
    Tree();
    Tree(const int );
    
    Node* createNode(int value);
    void insert(int value);
    void insert(int value, Node* leaf);
    void postOrderOutput(Node* root);
    void preOrderOutput(Node* root);
    void inOrderOutput(Node* root);

};

Tree::Tree() { }

void Tree::insert(int value) {
    
    if (root != nullptr) {
        insert(value, root);
    }
    else {
        root = new Node(value);
    }
    
}

//
//  Overloaded function.
//
//  Inserts new value in the tree.
//
void Tree::insert(int value, Node *leaf)
{
    if(value < leaf->value)
    {
        if(leaf->left!=NULL)
            insert(value, leaf->left);
        else
        {
            leaf->left=new Node(value);
        }
    }
    else if(value >= leaf->value)
    {
        if(leaf->right!=NULL)
            insert(value, leaf->right);
        else
        {
            leaf->right = new Node(value);
        }
    }
}

void Tree::inOrderOutput(Node* root){
    
    if (root != NULL) {
        inOrderOutput(root->left);
        cout << root->value << " ";
        inOrderOutput(root->right);
    }
    
}

void Tree::preOrderOutput(Node* root){
    
    if (root != NULL) {
        cout << root->value << " ";
        preOrderOutput(root -> left);
        preOrderOutput(root -> right);
    }
    
}

int main() {
    
    const int MAX_NUM = 10;
    
    int numbers[MAX_NUM] ={ 51, 45, 65, 34, 23, 80, 85, 32, 33, 10 };
    
    Tree* tree;
    tree = new Tree();
    for (int i = 0; i < MAX_NUM; i++) {
        tree->insert(numbers[i]);
    }
    
    cout << "In Order Output: " << endl;
    tree->inOrderOutput(root);
    
    cout << "Post Order Output: " << endl;
    tree -> preOrderOutput(root);
    
    return 0;
}
