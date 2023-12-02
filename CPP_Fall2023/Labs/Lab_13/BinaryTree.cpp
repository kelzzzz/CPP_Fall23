#include "BinaryTree.h"
#include <iostream>
#include "TreeNode.h"
#include <queue>

BinaryTree::BinaryTree(int root)
{
    this->root = createNode(root);
}

TreeNode* BinaryTree::createNode(int data)
{
    TreeNode* out = new TreeNode;
    out->data = data;
    out->idx += incrementingIdx;
    out->left = out->right = nullptr;
    incrementingIdx++;
    return out;
}

void BinaryTree::recursivelyPrintTreePreorder(struct TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    else {
        std::cout << node->data << " -> ";

        recursivelyPrintTreePreorder(node->left);
        recursivelyPrintTreePreorder(node->right);
    }
}

void BinaryTree::recursivelySearchTree(struct TreeNode* node, int searchFor) {
    if (node == nullptr) {
        return;
    }
    if (node->data == searchFor) {
        std::cout << "Search term " << searchFor << " found at index: " << node->idx << "\n";
    }
    recursivelySearchTree(node->left, searchFor);
    recursivelySearchTree(node->right, searchFor);
}

void BinaryTree::insertNodeIntoFirstAvailable(TreeNode* root, int data)
{
    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* top = q.front();
        q.pop();

        if (top->left != nullptr)
            q.push(top->left);
        else {
            top->left = createNode(data);
            std::cout << "Inserted " << data << " into tree index " << top->left->idx << "\n";
            break;
        }

        if (top->right != nullptr)
            q.push(top->right);
        else {
            top->right = createNode(data);
            std::cout << "Inserted " << data << " into tree index " << top->right->idx << "\n";
            break;
        }
    }    
}

int BinaryTree::recursivelyFindMaximum(struct TreeNode* node) {
    if (node == nullptr) {
        return INT_MIN;
    }

    int highestSoFar = node->data;
    int leftChild = recursivelyFindMaximum(node->left);
    int rightChild = recursivelyFindMaximum(node->right);
    if (leftChild > highestSoFar) {
        highestSoFar = leftChild;
    }
    if (rightChild > highestSoFar) {
        highestSoFar = rightChild;
    }
    return highestSoFar;
}

int BinaryTree::recursivelyFindMinimum(struct TreeNode* node) {
    if (node == nullptr) {
        return INT_MAX;
    }
    int lowestSoFar = node->data;
    int leftChild = recursivelyFindMinimum(node->left);
    int rightChild = recursivelyFindMinimum(node->right);
    if (leftChild < lowestSoFar) {
        lowestSoFar = leftChild;
    }
    if (rightChild < lowestSoFar) {
        lowestSoFar = rightChild;
    }
    return lowestSoFar;
}

void BinaryTree::deleteNodeByData(TreeNode* node, int searchFor)
{
    std::queue<TreeNode*> q;
    q.push(node);

    while (!q.empty()) {
        TreeNode* top = q.front();
        q.pop();

        if (top->left != nullptr) {
            if (top->left->data != searchFor) {
                q.push(top->left);
            }
            else {
                std::cout << "Deleting node with data: " << top->left->data << "\n";
                top->left = popDeepestRightMostNode(node);
                std::cout << "Replaced node with node that has data: " << top->left->data << "\n";
                break;
            }
        }
        if (top->right != nullptr) {
            if (top->right->data != searchFor) {
                q.push(top->right);
            }
            else {
                std::cout << "Deleting node with data: " << top->right->data << "\n";
                top->right = popDeepestRightMostNode(node);
                std::cout << "Replaced node with node that has data: " << top->right->data << "\n";
                break;
            }
        }
    }

}

void BinaryTree::deleteNodeByIdx(TreeNode* node, int idx)
{
    //Did not have time to implement this! :(
}

TreeNode* BinaryTree::popDeepestRightMostNode(TreeNode* root)
{
    std::queue<TreeNode*> q;
    q.push(root);
    TreeNode* parent{};

    while (!q.empty()) {
        TreeNode* top = q.front();
        if (top->right == nullptr) {
            TreeNode* rightmost = createNode(top->data);
            if (top->left != nullptr) {
                top = top->left;
                top->right = nullptr;
            }
            else {
                if (parent != nullptr) {
                    parent->right = nullptr;
                }
                delete top;
            }
            return rightmost;
        }
        else {
            q.push(top->right);
            parent = q.front();
            q.pop();
        }
    }
    return nullptr;
}

