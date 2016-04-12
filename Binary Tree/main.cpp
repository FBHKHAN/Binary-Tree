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
    
    //
    //  Constructor used for copying/cloning another tree.
    //
    Node(int value, Node* newLeft, Node* newRight) {
        
        this->value = value;
        left = newLeft;
        right = newRight;
        
    }
    
};

class Tree {
    
public:
    
    Node* root = nullptr;
    
    Tree();
    Tree(const int );
    
    Node* createNode(int value);
    void insert(int value);
    void insert(int value, Node*);      //  Insert new value to tree
    void postTraversal(Node*);          //  Output in Post Traversal Form
    void preTraversal(Node*);           //  Output in Pre Traversal Form
    void inTraversal(Node*);            //  Output in In Traversal Form
    void countNodes(Node*, int&);       //  Count the total number of Nodes in the tree
    void countLeaf(Node*, int&);        //  Count the total number of leaves in the tree
    int depth(Node*);                   //  Calculate the depth of the tree
    Node* copyTree(Node*);              //  Clones/copies another tree and returns the root
    void deleteTree(Node*);             //  Deletes the entire tree to free up the memory.

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
//  insert - Overloaded function.
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
    else if(value > leaf->value)
    {
        if(leaf->right!=NULL)
            insert(value, leaf->right);
        else
        {
            leaf->right = new Node(value);
        }
    }
    else if(value == leaf -> value) {
        cout << "ATTENTION! Duplicate value inserted: " << value << endl;
        return;
    }
}

//
//  Prints out the tree in In-Order Traversal
//
void Tree::inTraversal(Node* root){
    
    if (root != NULL) {
        inTraversal(root->left);        //  Descend Left
        cout << root->value << " ";     //  Print the value
        inTraversal(root->right);       //  Descend Right
    }
    
}

//
//  Prints out the tree in Pre-Order Traversal
//
void Tree::preTraversal(Node* root){
    
    if (root != NULL) {
        cout << root->value << " ";     //  Print the value
        preTraversal(root -> left);     //  Descend Left
        preTraversal(root -> right);    //  Descend Right
    }
    
}

//
//  Prints out the tree in Post-Order Traversal
//
void Tree::postTraversal(Node* root){
    if (root != NULL) {
        postTraversal(root->left);      //  Descend Left
        postTraversal(root->right);     //  Descend Right
        cout << root -> value << " ";   //  Print the value
    }
}

void Tree::countNodes(Node* root, int& count) {
    
    if (root != NULL) {
        countNodes(root -> left, count);    //  Descend Left
        countNodes(root -> right, count);   //  Descend Right
        count++;
    }
    
}

void Tree::countLeaf(Node* root, int& count){
    
    if (root != NULL) {
        
        //  Check if root is a leaf, if so increment the count
        if (root->right == NULL && root ->left == NULL)
            count++;
        
        countLeaf(root->left, count);   //  Descend Left
        countLeaf(root->right, count);  //  Descend Right
        
    }
    
}

int Tree::depth(Node* root) {
    
    int depthLeft, depthRight, depthVal;
    
    if (root == NULL) {
        
        //  Depth of an empty tree is -1
        depthVal = -1;
    }
    else {
        // find the depth of the left subtree of t
        depthLeft = depth(root -> left);
        
        // find the depth of the right subtree of t
        depthRight = depth(root -> right);
        
        // Depth of the tree with root is 1 + Maximum
        // of the depths of the two subtrees
        depthVal = 1 + (depthLeft > depthRight ? depthLeft : depthRight);
    }
    
    return depthVal;
}

Node* Tree::copyTree(Node* root) {
    
    Node* newLeft,* newRight,* newNode;
    
    if(root == NULL)
        return NULL;
    
    newLeft = copyTree(root->left);
    newRight = copyTree(root->right);
    
    newNode = new Node(root->value, newLeft, newRight);
    
    return newNode;
}

void Tree::deleteTree(Node* root) {
    
    if (root != NULL) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete(root);
    }
    
}

int main() {
    
    const int MAX_NUM = 12;
    int nodeCount = 0, leafCount = 0;
    
    int numbers[MAX_NUM] ={ 51, 45, 47, 65, 34, 23, 80, 85, 32, 33, 10, 34 };
    
    Tree* treeOne;
    treeOne = new Tree();
    
    Tree* treeTwo;
    treeTwo = new Tree();
    
    for (int i = 0; i < MAX_NUM; i++) {
        treeOne->insert(numbers[i]);
    }
    
    cout << "In Order Output: " << endl;
    treeOne->inTraversal(treeOne->root);
    
    cout << "\n\nPre Order Output: " << endl;
    treeOne -> preTraversal(treeOne->root);
    
    cout << "\n\nPost Order Output: " << endl;
    treeOne -> postTraversal(treeOne->root);
    
    treeOne->countNodes(treeOne->root, nodeCount);
    cout << "Total Nodes: " << nodeCount << endl;
    
    treeOne->countLeaf(treeOne->root, leafCount);
    cout << "Total Leaves: " << leafCount << endl;
    
    
    cout << "\nDepth of the tree: " << treeOne->depth(treeOne->root) << endl;
    
    //
    // copying treeOne to treeTwo
    //
    treeTwo->root = treeOne->copyTree(treeOne->root);
    
    cout << "\nNew Tree's Pre Order Output: " << endl;
    treeTwo -> preTraversal(treeTwo->root);
    
    cout << endl <<endl;
    
    return 0;
}
