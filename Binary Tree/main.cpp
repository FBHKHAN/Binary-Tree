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
    void insert(int value, Node*);
    void postTraversal(Node*);
    void preTraversal(Node*);
    void inTraversal(Node*);
    int countNodes(Node*, int);

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

//
//  Prints out the tree in In-Order Traversal
//
void Tree::inTraversal(Node* root){
    
    if (root != NULL) {
        inTraversal(root->left);
        cout << root->value << " ";
        inTraversal(root->right);
    }
    
}

//
//  Prints out the tree in Pre-Order Traversal
//

void Tree::preTraversal(Node* root){
    
    if (root != NULL) {
        cout << root->value << " ";
        preTraversal(root -> left);
        preTraversal(root -> right);
    }
    
}

//
//  Prints out the tree in Post-Order Traversal
//

void Tree::postTraversal(Node* root){
    if (root != NULL) {
        postTraversal(root->left);
        postTraversal(root->right);
        cout << root -> value << " ";
    }
}

int Tree::countNodes(Node* root, int count = 0) {
    
    if (root != NULL) {
        count += countNodes(root -> left);
        count += countNodes(root -> right);
        count++;
        return count;
    }
    
    return 0;
}

int main() {
    
    const int MAX_NUM = 11;
    
    int numbers[MAX_NUM] ={ 51, 45, 65, 34, 23, 80, 85, 32, 33, 10, 34 };
    
    Tree* tree;
    tree = new Tree();
    for (int i = 0; i < MAX_NUM; i++) {
        tree->insert(numbers[i]);
    }
    
    cout << "In Order Output: " << endl;
    tree->inTraversal(root);
    
    cout << "\n\nPre Order Output: " << endl;
    tree -> preTraversal(root);
    
    cout << "\n\nPost Order Output: " << endl;
    tree -> postTraversal(root);
    
    cout << "Total Nodes: " << tree->countNodes(root) << endl;
    
    return 0;
}
