#include <iostream>
#include <iomanip>
using namespace std;

struct Node {
    int key;
    int val1;
    int val2;
    Node* left;
    Node* right;
};

// Функция создания новой вершины
Node* newNode(int key, int val1, int val2) {
    Node* node = new Node;
    node->key = key;
    node->val1 = val1;
    node->val2 = val2;
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node* root, int key, int val1, int val2) {
    if (root == NULL) {
        return newNode(key, val1, val2);
    }
    else if (key < root->key) {
        root->left = insert(root->left, key, val1, val2);
    }
    else if (key > root->key) {
        root->right = insert(root->right, key, val1, val2);
    }
    return root;
}

// Функция поиска элемента по ключу
Node* search(Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (root->key < key)
        return search(root->right, key);

    return search(root->left, key);
}

// Функция нахождения максимального элемента в поддереве
Node* findMax(Node* node) {
    while (node->right != NULL)
        node = node->right;
    return node;
}

// Функция удаления элемента по ключу
Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMax(root->left);
        root->key = temp->key;
        root->val1 = temp->val1;
        root->val2 = temp->val2;
        root->left = deleteNode(root->left, temp->key);
    }
    return root;
}

// Функция удаления всех элементов дерева
void clear(Node* root) {
    if (root != NULL) {
        clear(root->left);
        clear(root->right);
        delete root;
    }
}

// Функция вывода всех элементов дерева

// Функция подсчета количества элементов в дереве
int count(Node* root) {
    if (root == NULL)
        return 0;
    return count(root->left) + count(root->right) + 1;
}

// Функция удаления вершины с максимальной суммой 2 целых значений узла
Node* deleteMaxSum(Node* root) {
    if (root == NULL)
        return NULL;

    Node* maxSumNode = root;
    Node* currNode = root;

    while (currNode != NULL) {
        int currSum = currNode->val1 + currNode->val2;
        int maxSum = maxSumNode->val1 + maxSumNode->val2;
        
        if (currSum > maxSum)
            maxSumNode = currNode;
        
        if (currNode->right != NULL) {
            currNode = currNode->right;
        }
        else if (currNode->left != NULL) {
            currNode = currNode->left;
        }
        else {
            break;
        }
    }
    
    int maxSum = maxSumNode->val1 + maxSumNode->val2;
    Node* newRoot = deleteNode(root, maxSumNode->key);
    
    if (maxSumNode->left != NULL) {
        Node* maxLeft = findMax(maxSumNode->left);
        if (maxLeft != NULL && maxLeft->val1 + maxLeft->val2 > maxSum) {
            newRoot = deleteNode(newRoot, maxLeft->key);
            maxSumNode->key = maxLeft->key;
            maxSumNode->val1 = maxLeft->val1;
            maxSumNode->val2 = maxLeft->val2;
        }
    }
    
    return newRoot;
}

void printTreeHelper(Node* root, int indent) {
    if (root == NULL)
        return;
    
    const int INDENTATION_WIDTH = 4;
    
    printTreeHelper(root->right, indent + INDENTATION_WIDTH);
    
    cout << setw(indent) << ' ';
    cout << root->key << endl;
    
    printTreeHelper(root->left, indent + INDENTATION_WIDTH);
}

void printTree(Node* root) {
    printTreeHelper(root, 0);
}


Node *Root = NULL;
int main() {
    Node* root = NULL;
    int choice = -1;
    
    while (choice != 0) {
        cout << endl;
        cout << "Binary Tree Operations:" << endl;
        cout << "-----------------------" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Search Node" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Delete Node with Max Sum" << endl;
        cout << "5. Clear Tree" << endl;
        cout << "6. Print Tree" << endl;
        cout << "7. Count Nodes" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                int key, val1, val2;
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value 1: ";
                cin >> val1;
                cout << "Enter value 2: ";
                cin >> val2;
                root = insert(root, key, val1, val2);
                break;
            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                if (search(root, key) != NULL)
                    cout << "Key found!" << endl;
                else
                    cout << "Key not found" << endl;
                break;
            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                root = deleteNode(root, key);
                break;
            case 4:
                root = deleteMaxSum(root);
                break;
            case 5:
                clear(root);
                root = NULL;
                break;
            case 6:
                printTree(root);
                break;
            case 7:
                cout << "Number of nodes: " << count(root) << endl;
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }
    
    clear(root);
    return 0;
}
