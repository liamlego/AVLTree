
#include <memory>
#include <iostream>
#include <vector>

class AVLTree {
private:

struct Node {

    Node(int data) : data{data} {
        left = nullptr;
        right = nullptr;
    }

    ~Node(){}

    int data;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
};



public:

    std::shared_ptr<Node> root;

    // gets height For Node
    int height(std::shared_ptr<Node>,int);

    // inserts a new node
    void insert(int);

    //rotate node left
    std::shared_ptr<Node> balance(std::vector<std::shared_ptr<Node>> &, int);

    std::shared_ptr<Node> rightRotate(std::shared_ptr<Node>);
    std::shared_ptr<Node> leftRotate(std::shared_ptr<Node>);

    void printTree(std::shared_ptr<Node> curr, std::string spaces) {

        if (curr == nullptr) return;

        printTree(curr->right, spaces + "     ");

        std::cout << spaces << curr->data << std::endl;

        printTree(curr->left, spaces + "     ");

    


    }


};