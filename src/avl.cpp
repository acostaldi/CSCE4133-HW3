#include <avl.hpp>

/*
    The constructor of AVL initializes the empty AVL, the implementation of the constructor is provided.
 */
AVL::AVL() : BST() {
    // The AVL constructor will initialize the empty AVL tree via the BST constructor
}

/*
    The deconstructor of AVL will deallocate memory of all nodes in the BST. 
    You do not need to implement this method since since it will use the deconstructor of BST.
*/
AVL::~AVL() {
    // The AVL deconstructor will deallocate memory of all nodes in AVL via the BST deconstructor
}

/*
    The balance factor method will calculate the height difference between right and left children nodes of the given node, 
    i.e., height of right node – height of left node. You need to implement the balance factor method to return the height difference 
    between right and left nodes. We assume that the NULL pointer has the height of 0.
*/ 
int AVL::balanceFactor(BSTNode *node) {
    // YOUR CODE HERE
}

/*
    The update method will update the height of the given node, i.e., height of the given node = max(height of left node, height of right node) + 1. 
    You need to implement the update method to update the height of the given node. We assume that the NULL pointer has the height of 0.
*/
void AVL::update(BSTNode *node) {
    // YOUR CODE HERE
}

/*
    The rotate right method will rotate a given node to the right. 
    You need to implement the rotate right method to rotate the node into the right and return the new root of the subtree. 
*/
BSTNode* AVL::rotateRight(BSTNode *node) {
    // YOUR CODE HERE
}

/*
    The rotate left method will rotate a given node to the left. 
    You need to implement the rotate left method to rotate the node into the left and return the new root of the subtree. 
*/
BSTNode* AVL::rotateLeft(BSTNode *node) {
    // YOUR CODE HERE
}

 

/*
    The balance method will balance the current subtree that satisfy the rules of AVL. 
    You have to implement the balance method to balance the current subtree where node is the root of the subtree. 
*/
BSTNode *AVL::balance(BSTNode *node) {
    // YOUR CODE HERE
}

/*
    The insert helper method is the support method that will help to insert a given key and meta 
    into the current AVL subtree where node is the root of the subtree. This one is optional.
*/
BSTNode* AVL::insertHelper(int key, int meta, BSTNode *node) {
    // YOU CAN IGNORE THIS FUNCTION IF YOU DO NOT WANT TO THIS FUNCTION
    // YOUR CODE HERE
}

/*
    The insert method will insert a new node with a given key and meta data. 
    You have to implement this method to insert a new node into AVL and return the new root of AVL. 
    However, if you implement the insertHelper function, this function can simply call the insertHelper, 
    i.e., return this->root = this->insertHelper(key, meta, this->root)
*/
BSTNode *AVL::insert(int key, int meta) {
    // YOUR CODE HERE
    //return this->root = this->insertHelper(key, meta, this->root); // Uncomment this one if you implement the insertHelper to insert a node into AVL.
}

/*
    The find minimum method will find the node containing the minimum value in the current subtree of node. 
    This method is used to support the remove method, if you will not use this method in your remove method, you can ignore this one.
*/
BSTNode* AVL::findMinimum(BSTNode *node) {
    // YOU CAN IGNORE THIS FUNCTION IF YOU DO NOT WANT TO THIS FUNCTION
    // YOUR CODE HERE
}

/*
    The remove minimum method will remove the node containing the minimum value in the current subtree of node. 
    This method is used to support the remove method, if you will not use this method in your remove method, you can ignore this one.
*/
BSTNode* AVL::removeMinimum(BSTNode *node) {
    // YOU CAN IGNORE THIS FUNCTION IF YOU DO NOT WANT TO THIS FUNCTION
    // YOUR CODE HERE
}

/*
    The remove helper method will remove the node containing the given key in the current subtree of node. 
    This method is used to support the remove method, if you will not use this method in your remove method, you can ignore this one.
*/
BSTNode* AVL::removeHelper(BSTNode *node, int key) {
    // YOU CAN IGNORE THIS FUNCTION IF YOU DO NOT WANT TO THIS FUNCTION
    // YOUR CODE HERE
}

/*
    The remove method will remove a node containing the given key. 
    You have to implement this method to remove the node containing the key and return the new root of AVL. 
    However, if you implement the removeHelper function, this function can simply call the removeHelper, 
    i.e., return this->root = this->removeHelper(this->root, key).
*/
BSTNode *AVL::remove(int key) {
    // YOUR CODE HERE
    // return this->root = this->removeHelper(this->root, key); // Uncomment this one if you implement the removeHelper to remove a node out of AVL.
}
