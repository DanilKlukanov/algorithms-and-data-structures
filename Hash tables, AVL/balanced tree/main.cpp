#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node{
    long long data;
    Node* left;
    Node* right;
    int height;
    Node(long long value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

int height(Node* root) {
    if (root == NULL)
        return 0;
    else
        return root->height;
}

int balance(Node* root){
    if (root == NULL)
        return 0;
    else
        return height(root->right) - height(root->left);
}

void height_veri(Node* root){
    if (root != NULL)
        root->height = max(height(root->left), height(root->right)) + 1;
}

Node* left_rota(Node* root){
    Node* new_root = root->right;
    root->right = new_root->left;
    new_root->left = root;
    height_veri(root);
    height_veri(new_root);
    return new_root;

}

Node* right_rota(Node* root){
    Node* new_root = root->left;
    root->left = new_root->right;
    new_root->right = root;
    height_veri(root);
    height_veri(new_root);
    return new_root;
}

Node* balanced_veri(Node* root){
    height_veri(root);
    if (balance(root) == 2) {
        if (balance(root->right) == 1)
            return left_rota(root);
        else if (balance(root->right) == -1) {
            root->right = right_rota(root->right);
            return left_rota(root);
        }
    }
    if (balance(root) == -2) {
        if (balance(root->left) == -1)
            return right_rota(root);
        else if (balance(root->left) == 1) {
            root->left = left_rota(root->left);
            return right_rota(root);
        }
    }
    return root;
}

Node* push (Node* root, long long key){
    if (root == NULL){
        return new Node(key);
    }
    else {
        if (key > root->data) root->right = push(root->right, key);
        if (key < root->data) root->left = push(root->left, key);
        return balanced_veri(root);
    }
}

Node* mini(Node* root){
    if (root == NULL)
        return 0;
    if (root->left != NULL)
        return mini(root->left);
    else return root;
}

Node* pop(Node* root, long long key){
    if (root == NULL) {
        return root;
    }
    Node * sup = root;

    if (key < root->data) {
        root->left = pop(root->left, key);
    } else if (key > root->data) {
        root->right = pop(root->right, key);
    } else {
        if (root->right == NULL && root->left == NULL) {
            free(sup);
            return NULL;
        }
        if (root->left != NULL && root->right != NULL) {
            root->data = mini(root->right)->data;
            root->right = pop(root->right, mini(root->right)->data);
        }
        if (root->left != NULL && root->right == NULL){
            root = root->left;
            free(sup);
        }
        if (root->right != NULL && root->left == NULL) {
            root = root->right;
            free(sup);
        }
    }
    return balanced_veri(root);
}

int size(Node* root) {
    int l_size = 0;
    int r_size = 0;

    if (root == NULL) {
        return 0;
    } else {
        if (root->left != NULL)
            l_size = size(root->left);
        if (root->right != NULL)
            r_size = size(root->right);
        return l_size + r_size + 1;
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    long long num;
    Node* tree(0);

    while (fin >> num){
        if (num > 0) tree = push(tree, num);
        if (num < 0) tree = pop(tree, -num);
        if (num == 0) break;
    }

    int siz = size(tree);
    for (int i = 0; i < siz; i++){
        num = mini(tree)->data;
        fout << num << " ";
        tree = pop(tree, num);
    }
    cout << siz;
    return 0;
}