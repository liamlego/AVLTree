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

    nodePath.push_back(curr);

    int leftHeight = height(root->left, 0);
    int rightHeight = height(root->right, 0);

    printTree(root, "");
    std::cout << "---------" << std::endl;

    bool shouldRotate = (abs(leftHeight - rightHeight)) > 1;


    if (shouldRotate) {
        
        root = balance(nodePath, nodePath.size()-1);
        
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


std::shared_ptr<AVLTree::Node> AVLTree::balance(std::vector<std::shared_ptr<Node>> &nodes, int index) {

    if (index-1 < 0) {
        
        int leftHeight = height(root->left, 0);
        int rightHeight = height(root->right, 0);
        
        bool isBalanced = abs(leftHeight - rightHeight) <= 1;
        
        if (!isBalanced) {

            if (leftHeight > rightHeight) {

                if (root->left->right != nullptr && root->left->left == nullptr) {
                    root->left = leftRotate(root->left);
                }

                root = rightRotate(root);
                

            } else {
                
                if (root->right->left != nullptr && root->right->right == nullptr) {
                    root->right = rightRotate(root->right);
                }

                root = leftRotate(root);

            }


        }
        
        return root;
    }

    int leftHeight = height(nodes[index]->left, 0);
    int rightHeight = height(nodes[index]->right, 0);

    bool isBalanced = abs(leftHeight - rightHeight) <= 1;

    std::shared_ptr<Node> curr = nodes[index];
    std::shared_ptr<Node> parent = nodes[index-1];

    if (!isBalanced) {

        int leftHP = height(parent->left, 0);
        int rightHP = height(parent->right, 0);

        if (leftHeight > rightHeight) {
            
            // right rotate

            if (curr->left->right != nullptr && curr->left->left == nullptr) {
                curr->left = leftRotate(curr->left);    
            }

            if (leftHP > rightHP) {
                parent->left = rightRotate(parent->left);
            } else {
                parent->right = rightRotate(parent->left);
            }
            



        } else {

            // left rotate
            if (curr->right->left != nullptr && curr->right->right == nullptr) {
                curr->right = rightRotate(curr->left);    
            }

            if (leftHP > rightHP) {
                
                parent->left = leftRotate(parent->left);
            } else {
                parent->right = leftRotate(parent->right);
            }


        }

    } 

    index--;
    return balance(nodes, index); 
}
/*

*/