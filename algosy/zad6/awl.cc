#include <bits/stdc++.h>

using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

class Node
{
public:
    int key;
    Node *right;
    Node *left;
    int height;

    Node(int k)
    {
        key = k;
        right = nullptr;
        left = nullptr;
        height = 1;
    }
};

Node* rightRotate(Node *node)
{
    Node *temp = node->left;
    Node *tempR = temp->right;

    temp->right = node;
    node->left = tempR;

    node->height = max((node->left)->height, (node->right)->height) + 1;
    temp->height = max((temp->left)->height, (temp->right)->height) + 1;

    return temp;
}

Node* leftRotate(Node *node)
{
    Node *temp = node->left;
    Node *tempL = temp->right;

    temp->left = node;
    node->right = tempL;

    node->height = max((node->left)->height, (node->right)->height) + 1;
    temp->height = max((temp->left)->height, (temp->right)->height) + 1;

    return temp;
}

int getBalance(Node *node)
{
    if(node == nullptr) return 0;
    return node->left)->height - (node->right)->height;
}

class Bst
{
private:

    Node *root;

    void find2(Node *node, int x);
    Node* insert2(Node *node, int x);
    Node* remove2(Node *node, int x);

public:

    Bst() { root = nullptr; }

    void find(int x) 
    { 
        if(root != nullptr) find2(root, x);
        else cout << "Drzewo jest puste" << endl;
    }
    void remove(int x) { remove2(root, x); }
    void insert(int x) 
    { 
        if(root == nullptr) root = new Node{x};
        else insert2(root, x); 
    }
};

Node* Bst::insert2(Node *node, int x)
{
    if(node == nullptr) node = new Node{x};
    else if(x <= node->key) node->left = insert2(node->left, x);
    else node->right = insert2(node->right, x);

    node->height = max((node->left)->height, (node->right)->height) + 1;

    int balance = getBalance(node);

    if(balance > 1 && x < (node->left)->key) 
        return rightRotate(node);
        
    if(balance < -1 && x > (node->right)->key) 
        return leftRotate(node);

    if(balance > 1 && x > (node->left)->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if(balance < -1 && x < (node->right)->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void Bst::find2(Node *node, int x)
{
    if(node == nullptr) cout << "Wartosc " << x << " nie zostala znaleziona" << endl;
    else if(node->key == x) cout << "Wartosc " << x << " zostala znaleziona" << endl;
    else if(x <= node->key) find2(node->left, x);
    else find2(node->right, x);  
}

Node* Bst::remove2(Node *node, int x)
{
    if(node == nullptr) cout << "Wartosc " << x << " nie znajduje sie w tym drzewie" << endl;
    else if(x < node->key) node->left = remove2(node->left, x);
    else if(x > node->key) node->right = remove2(node->right, x);
    else
    {
        if(node->left == nullptr && node->right == nullptr)
        {
            delete node;
            node == nullptr;
        }
        else if(node->left == nullptr)
        {
            Node *temp = node;
            node = node->right;
            delete temp;
        }
        else if(node->right == nullptr)
        {
            Node *temp = node;
            node = node->left;
            delete temp;
        }
        else
        {
            Node *temp = node->right;
            Node *tempR = temp->right;
            Node *tempL = temp->left;
            temp = (tempR->key > tempL->key) ? tempR : tempL;
            node->key = temp->key;
            node->right = remove2(node->right, temp->key);
        }
    }
    return node;
}

int main()
{
    Bst tree{};
    tree.find(5);
    tree.remove(4);
    tree.insert(7);
    
    tree.insert(2);
    
    tree.insert(8);
    tree.insert(23);
    tree.insert(5);
    tree.find(5);
    tree.remove(5);
}