#pragma once
#include <iostream>
using namespace std;

struct Node {
    int key;
    int val1;
    int val2;
    Node* left;
    Node* right;
};

struct Tree {
    Node* node {};
    int counter;
    void AddNode(int k);
    void PrintTree(Node* temp, int l);
    void Delete(int k);
    bool Balance(Node* temp);
    void DirectBypass(Node* temp);
    void ReverseBypass(Node* temp);
    void DownScan(Node* temp);
    void FindMaxSumNode(Node* temp, Node*& maxNode, int& maxSum); // ??????? ??????? ? ???????????? ??????
};

void Tree::FindMaxSumNode(Node* temp, Node*& maxNode, int& maxSum)
{
    if (temp)
    {
        int sum = temp->val1 + temp->val2;
        if (sum > maxSum)
        {
            maxSum = sum;
            maxNode = temp;
        }

        FindMaxSumNode(temp->left, maxNode, maxSum);
        FindMaxSumNode(temp->right, maxNode, maxSum);
    }
}
