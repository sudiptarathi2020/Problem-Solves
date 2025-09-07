#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() : val(false), isLeaf(false), topLeft(nullptr), topRight(nullptr), bottomLeft(nullptr), bottomRight(nullptr) {}
    Node(bool _val, bool _isLeaf) : val(_val), isLeaf(_isLeaf), topLeft(nullptr), topRight(nullptr), bottomLeft(nullptr), bottomRight(nullptr) {}
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight)
        : val(_val), isLeaf(_isLeaf), topLeft(_topLeft), topRight(_topRight), bottomLeft(_bottomLeft), bottomRight(_bottomRight) {}
};

class Solution {
    bool isLeaf(const vector<vector<int>>& grid, int rs, int re, int cs, int ce) {
        int first = grid[rs][cs];
        for (int r = rs; r <= re; ++r) {
            for (int c = cs; c <= ce; ++c) {
                if (grid[r][c] != first) return false;
            }
        }
        return true;
    }

    Node* build(const vector<vector<int>>& grid, int rs, int re, int cs, int ce) {
        if (isLeaf(grid, rs, re, cs, ce)) {
            return new Node(grid[rs][cs] != 0, true);
        }
        int midR = (rs + re) >> 1;
        int midC = (cs + ce) >> 1;

        Node* topLeft     = build(grid, rs,   midR, cs,   midC);
        Node* topRight    = build(grid, rs,   midR, midC + 1, ce);
        Node* bottomLeft  = build(grid, midR + 1, re,   cs,   midC);
        Node* bottomRight = build(grid, midR + 1, re,   midC + 1, ce);

        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }

public:
    Node* construct(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        if (n == 0) return nullptr;
        return build(grid, 0, n - 1, 0, n - 1);
    }
};

void print(Node* root, string path) {
    if (!root) return;
    cout << root->val << ", " << root->isLeaf << ", " << path << endl;
    print(root->topLeft, path + "1");
    print(root->topRight, path + "2");
    print(root->bottomLeft, path + "3");
    print(root->bottomRight, path + "4");
}

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {0,1,1,1,0,0,0,0},
        {0,1,1,1,0,0,0,0},
        {0,0,0,0,1,1,1,1},
        {0,0,0,0,1,1,1,1},
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,0,0,0,0}
    };
    Node* root = sol.construct(grid);
    print(root, "");
    return 0;
}
