#include <bst.hpp>

BSTNode::BSTNode() {
    this->left = this->right = NULL;
    this->height = 0;
}

BSTNode::BSTNode(int key, int height, int meta, BSTNode *left, BSTNode *right) {
    this->key = key;
    this->height = height;
    this->meta = meta;
    this->left = left;
    this->right = right;
}

void BST::destroy(BSTNode* node){
    if (node == nullptr) {
        return;
    }

    destroy(node->left);
    destroy(node->right);
    delete node;
}

BSTNode::~BSTNode() {
    this->left = this->right = NULL;
}

/*
    The constructor of BST initializes the empty BST, the implementation of the constructor is provided.
*/
BST::BST() {
    // YOU DO NOT NEED TO IMPLEMENT THIS ONE
    this->root = NULL;
}

/*
    The deconstructor of BST will deallocate memory of all nodes in the BST.
    You have to implement the deconstructor to release memory of all nodes.
*/
BST::~BST() {
    destroy(this->root);
}

/*
    The find method will find the node that contains the key. 
    You have to implement the find method to return the node containing the given key.
*/
BSTNode* BST::find(int key) {
    BSTNode* currentNode = this->root;
    while(currentNode){
        if (key == currentNode->key) {
            return currentNode;
        } else if (key < currentNode->key) {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
    }
    return nullptr;
}

/*
    The pop maximum method will return the node that contains the maximum value 
    and remove that node out BST but DO NOT release the memory of this maximum node. 
    You have to implement the pop maximum method to return the node containing the maximum value and remove it out of the BST.
*/
BSTNode* BST::popMaximum() {
    if (!this->root) return nullptr; // Empty tree
    
    BSTNode* parentNode = nullptr;
    BSTNode* currentNode = this->root;

    while (currentNode->right != nullptr) {
        parentNode = currentNode;
        currentNode = currentNode->right;
    }
    
    if (currentNode->left != nullptr) {
        parentNode->right = currentNode->left;
    } else {
        parentNode->right = nullptr;
    }

    std::cout << "Popped Node: " << currentNode->key << std::endl;

    return currentNode;
}

/* 
    The pop minimum method will return the node that contains the minimum value 
    and remove that node out BST but DO NOT release the memory of this minimum node. 
    You have to implement the pop minium method to return the node containing the minum value and remove it out of the BST.
*/
BSTNode* BST::popMinimum() {
    if (!this->root) return nullptr; // Empty tree
    
    BSTNode* parentNode = nullptr;
    BSTNode* currentNode = this->root;

    while (currentNode->left != nullptr) {
        parentNode = currentNode;
        currentNode = currentNode->left;
    }
    
    if (parentNode) {
        parentNode->left = currentNode->right;
    } else {
        root = currentNode->right;
    }

    std::cout << "Popped Node: " << currentNode->key << std::endl;
    
    return currentNode;
}

BSTNode* BST::insertR(BSTNode* node, int key, int meta) {
    if (node == nullptr) {
        return new BSTNode(key, 0, meta, nullptr, nullptr);
    }

    if (key < node->key) {
        node->left = insertR(node->left, key, meta);
    } else if (key > node->key) {
        node->right = insertR(node->right, key, meta);
    } else {
        // If the key is the same, insert as a child of the current node
        node->right = insertR(node->right, key, meta);
    }

    int leftHeight = (node->left) ? node->left->height : -1;
    int rightHeight = (node->right) ? node->right->height : -1;
    node->height = 1 + std::max(leftHeight, rightHeight);

    return node;
}

BSTNode* BST::insert(int key, int meta) {
    root = insertR(root, key, meta);
    return root;
}

BSTNode* BST::findMin(BSTNode* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

BSTNode* BST::removeR(BSTNode* node, int key) {
    if (node == nullptr) {
        // Key not found
        return node;
    }

    if (key < node->key) {
        node->left = removeR(node->left, key);
    } else if (key > node->key) {
        node->right = removeR(node->right, key);
    } else {
        // Node with the key is found, handle different cases

        // Case 1: Node with one child or no child
        if (node->left == nullptr) {
            BSTNode* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            BSTNode* temp = node->left;
            delete node;
            return temp;
        }

        BSTNode* successor = findMin(node->right);

        // Copy the in-order successor's data to this node
        node->key = successor->key;

        // Delete the in-order successor
        node->right = removeR(node->right, successor->key);
    }

    return node;
}

BSTNode* BST::remove(int key) {
    root = removeR(root, key);
    return root;
}

void BST::printLevelOrder() {
    if (!root)
        return; // Empty tree

    std::queue<BSTNode*> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty()) {
        BSTNode* currentNode = nodeQueue.front();
        nodeQueue.pop();

        std::cout << "Key: " << currentNode->key << " Meta: " << currentNode->meta << " Height: " << currentNode->height << std::endl;

        if (currentNode->left)
            nodeQueue.push(currentNode->left);
        if (currentNode->right)
            nodeQueue.push(currentNode->right);
    }
}
