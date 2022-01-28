#include "AVLTree.h"


int AVLTree::height(std::shared_ptr<Node> node, int curr) {
    

    if (node == nullptr) {
        return curr;
    }

    int leftHeight = height(node->left, curr + 1);
    int rightHeight = height(node->right, curr + 1);

    if (leftHeight > rightHeight) {
        return leftHeight;
    } else {
        return rightHeight;
    }

}


void AVLTree::insert(int data) {

    if (root == nullptr) {

        root = std::make_shared<Node>(data);
        return;
    }

    std::shared_ptr<Node> curr = root;

    std::shared_ptr<Node> currP = root;

    std::vector<std::shared_ptr<Node>> nodePath;

    while (curr != nullptr) {
        currP = curr;
        nodePath.push_back(curr);
        if (data > curr->data) { 
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }

    if (data > currP->data) {
        currP->right = std::make_shared<Node>(data);
        curr = currP->right;
    } else {
        currP->left = std::make_shared<Node>(data);
        curr = currP->left;
    }

    int leftHeight = height(root->left, 0);
    int rightHeight = height(root->right, 0);

    std::cout << "Left: " << leftHeight << std::endl;
    std::cout << "Right: " << rightHeight << std::endl;

    printTree(root, "");

    bool shouldRotate = (abs(leftHeight - rightHeight)) > 1;


    if (shouldRotate) {
        root = balance(nodePath, curr);
    }

}

std::shared_ptr<AVLTree::Node> AVLTree::rightRotate(std::shared_ptr<Node> node) {

    std::shared_ptr<Node> temp = node;

    node = node->left;
    temp->left = node->right;
    node->right = temp;

    return node;
}

std::shared_ptr<AVLTree::Node> AVLTree::leftRotate(std::shared_ptr<Node> node) {

    std::shared_ptr<Node> temp = node;

    node = node->right;
    temp->right = node->left;
    node->left = temp;

    return node;
}


std::shared_ptr<AVLTree::Node> AVLTree::balance(std::vector<std::shared_ptr<Node>> &nodes, std::shared_ptr<Node> node) {

    if (node == nullptr) {
        return nullptr;
    }

    int leftHeight = height(node->left, 0);
    int rightHeight = height(node->right, 0);

    



    return node;
}
/*

*/