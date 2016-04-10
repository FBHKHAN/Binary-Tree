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
    Node* Left;
    Node* Right;
    
    Node(int value) {
        Left = nullptr;
        Right = nullptr;
        this->value = value;
    }
}* root = nullptr;

class Tree {
public:
    
    Tree();
    Tree(const int );
    
    Node* createNode(int value);
    void treeInsert(int value, Node* leaf);
};

Tree::Tree() { }

Tree::Tree(const int value) {
    
    
}

void Tree::treeInsert(int value, Node* leaf){
    
    if (root == nullptr) {
        root = new Node(value);         // Base Case
    }
    else if (value == root->value){
        return;
    }
    else if(value < root-> value) {
        treeInsert(value, leaf);        // Recursive
    }
    else{
        
    }
    
}

int main() {
    
    int numbers[10] ={51,45, 65, 34, 23, 80, 85, 32, 33, 10};
    
    
    
    return 0;
}
