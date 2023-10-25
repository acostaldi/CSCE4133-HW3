#pragma once

#include <iostream>
#include <bst.hpp>

class AVL: public BST {
    public:
        AVL();
        ~AVL();

        int balanceFactor(BSTNode *node);
        void update(BSTNode *node);
        BSTNode* rotateRight(BSTNode *node);
        BSTNode* rotateLeft(BSTNode *node);
        BSTNode* balance(BSTNode *node);
        
        BSTNode* insertHelper(int key, int meta, BSTNode *node);
        BSTNode* insert(int key, int meta = 0);

        BSTNode* findMinimum(BSTNode *node);
        BSTNode* removeMinimum(BSTNode *node);
        BSTNode* removeHelper(BSTNode *node, int key);
        BSTNode* remove(int key);
};
