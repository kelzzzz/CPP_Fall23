#pragma once

struct TreeNode {
    int data;
    int idx = 0;
    struct TreeNode* left, * right;
};