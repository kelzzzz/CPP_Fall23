#include <iostream>
#include "TreeNode.h"
#include "BinaryTree.h"
enum OPTIONS {
    PRINT, SEARCH, MAX, MIN, INSERT, DELETE, MENU, EXIT
};

OPTIONS takeInput(char in) {
    switch(in) {
        case 'p':
            return PRINT;
        case 's':
            return SEARCH;
        case 'x':
            return MAX;
        case 'n':
            return MIN;
        case 'i':
            return INSERT;
        case 'd':
            return DELETE;
        case 'e':
            return EXIT;
    }
}

void printOptions() {
    std::cout << "OPTIONS ---: \n";
    std::cout << "p -- print the tree in preorder" << std::endl;
    std::cout << "s -- search for node by its data" << std::endl;
    std::cout << "x -- print the maximum data in the tree" << std::endl;
    std::cout << "n -- print the minimum data in the tree" << std::endl;
    std::cout << "i -- insert a new node into the tree" << std::endl;
    std::cout << "d -- delete node from the tree by its data" << std::endl;
    std::cout << "e -- exit" << std::endl;

}

BinaryTree setUpStartingTree() {
    BinaryTree tree(2);
    tree.root->left = tree.createNode(9);
    tree.root->right = tree.createNode(4);
    tree.root->right->right = tree.createNode(7);
    tree.root->left->right = tree.createNode(8);
    return tree;
}

int main()
{
    OPTIONS state = MENU;
    char in = 'b';
    int search = 0;
    int dataInsertion = 0;
    int dataToDelete = 0;

    BinaryTree tree = setUpStartingTree();

    while (state != EXIT) {
        switch (state) {
            case(MENU):
                printOptions();
                std::cin >> in;
                state = takeInput(in);
                break;
            case(PRINT):
                std::cout << "----PRINTING-----" << std::endl;
                tree.recursivelyPrintTreePreorder(tree.root);
                std::cout << std::endl << "-----------------" << std::endl;
                state = MENU;
                break;
            case(SEARCH):
                std::cout << "What data would you like to search for? \n";
                std::cin >> search;
                tree.recursivelySearchTree(tree.root, search);
                state = MENU;
                break;
            case(MAX):
                std::cout << "Highest value is " << tree.recursivelyFindMaximum(tree.root) << std::endl;
                state = MENU;
                break;
            case(MIN):
                std::cout << "Lowest value is " << tree.recursivelyFindMinimum(tree.root) << std::endl;
                state = MENU;
                break;
            case(INSERT):
                std::cout << "What data would you like to insert? \n";
                std::cin >> dataInsertion;
                tree.insertNodeIntoFirstAvailable(tree.root, dataInsertion);
                state = MENU;
                break;
            case(DELETE):
                std::cout << "What data would you like to delete? \n";
                std::cin >> dataToDelete;
                tree.deleteNodeByData(tree.root, dataToDelete);
                state = MENU;
                break;
        }
    } 
}
