#include <iostream>
#include <fstream>

struct TreeNode{
    int key;
    TreeNode *left = NULL;
    TreeNode *right = NULL;
    TreeNode *parent = NULL;
};


struct BST{
    TreeNode *root = NULL;
};


bool CheckDupl(TreeNode *x, int val){
    if(x == NULL)
        return false;
    else if (x->key == val)
        return true;
    else if (val < x->key)
        return CheckDupl(x->left, val);
    else 
        return CheckDupl(x->right, val);
}


void Insert(BST *T, int val){
    TreeNode *cur = new TreeNode;
    TreeNode *parent = new TreeNode;
    TreeNode *x = new TreeNode;
    x->key = val;
    //std::cout << x->key << std::endl;
    parent = NULL;
    if (CheckDupl(T->root, x->key))
        return;

    if (T->root == NULL)
        cur = NULL;
    else
        cur = T->root;
    while (cur != NULL){
        parent = cur;
        if (x->key < cur->key)
            cur = cur->left;
        else 
            cur = cur->right;
    }
    x->parent = parent;
    if (parent == NULL){
        T->root = x;
    }
    else if (x->key < parent->key)
        parent->left = x;
    else 
        parent->right=x;
}


int CountElem(TreeNode *x){
    if(x == NULL)
        return 0;
    else
        return 1 + CountElem(x->left) + CountElem(x->right);
}


int FindMax(TreeNode *x){
    if (x->right == NULL)
        return x->key;
    else return FindMax(x->right);
}


int FindMin(TreeNode *x){
    if (x->left == NULL)
        return x->key;
    else return FindMin(x->left);
}


void Walk(TreeNode *x, std::ofstream &output){
    if(x != NULL){
        Walk(x->left, output);
        output << x->key << std::endl;
        Walk(x->right, output);
    }
}


int main() {
    std::string s = "", com = "";
    BST T;

    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    if(!input or !output){
        std::cout << "Can't open the file" << std::endl;
        return -1;
    }

    getline(input, s);
    for (int i = 0; i <= s.length(); i++){
        if(isspace(s[i])){
            Insert(&T,stoi(com));
            com = "";
        }
        else{
            com += s[i];
        }
    }

    output << CountElem(T.root) << std::endl;
    output << FindMax(T.root) << std::endl;
    output << FindMin(T.root) << std::endl;
    Walk(T.root, output);
    
    input.close();
    output.close();
    return 0;
}