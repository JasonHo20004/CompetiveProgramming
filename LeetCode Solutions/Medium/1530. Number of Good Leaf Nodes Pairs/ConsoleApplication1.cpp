// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;


struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : value(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : value(x), left(left), right(right){}  
};

vector<int> isLeaf(TreeNode* root) {
    //return an array of isLeaf nodes from root
    if (!root) return { };
    
    if (!root->left && !root->right)
        return { root->value };

    vector<int> leftLeaves = isLeaf(root->left);
    vector<int> rightLeaves = isLeaf(root->right);

    leftLeaves.insert(leftLeaves.end(), rightLeaves.begin(), rightLeaves.end());
    return leftLeaves;

}

int countPairs(TreeNode* root, int distance) {

    int count = 0;

    function<vector<int>(TreeNode*)> dfs = [&](TreeNode* node) {
        if (!node) return vector<int>();
        if (!node->left && !node->right) return vector<int>{0};

        vector<int> left = dfs(node->left);
        vector<int> right = dfs(node->right);

        // Check pairs between left and right children
        for (int l : left) {
            for (int r : right) {
                if (l + r + 2 <= distance) {
                    count++;
                }
            }
        }
        vector<int> result;
        for (int l : left) result.push_back(l + 1);
        for (int r : right) result.push_back(r + 1);
        return result;
    };
    dfs(root);
    return count;
}


int main()
{

}