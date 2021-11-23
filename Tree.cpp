#include <iostream>
#include <string>
#include <fstream>
#include <vector>


using namespace std;

class BinaryTree {

private:
    string key;
    BinaryTree* leftChild;
    BinaryTree* rightChild;
public:
    BinaryTree(string rootObj) {
        this->key = rootObj;
        this->leftChild = NULL;
        this->rightChild = NULL;
    }

    void insertLeft(string newNode) {
        if (this->leftChild == NULL) {
            this->leftChild = new BinaryTree(newNode);
        }
        else {
            BinaryTree* t = new BinaryTree(newNode);
            t->leftChild = this->leftChild;
            this->leftChild = t;
        }
    }

    void insertRight(string newNode) {
        if (this->rightChild == NULL) {
            this->rightChild = new BinaryTree(newNode);
        }
        else {
            BinaryTree* t = new BinaryTree(newNode);
            t->rightChild = this->rightChild;
            this->rightChild = t;
        }
    }

    BinaryTree* getRightChild() {
        return this->rightChild;
    }

    BinaryTree* getLeftChild() {
        return this->leftChild;
    }

    void setRootVal(string obj) {
        this->key = obj;
    }

    string getRootVal() {
        return this->key;
    }
};

void postorder(BinaryTree* tree) {
    if (tree != NULL) {
        postorder(tree->getLeftChild());
        postorder(tree->getRightChild());
        cout << tree->getRootVal() << endl;
    }
}
// going to add primarily to left side of tree both value (operator) value
void add(BinaryTree* tree, BinaryTree* ptr, vector<string> list, int i, bool flag) {

        BinaryTree* temp = ptr->getLeftChild();
        temp->insertLeft(list[i - 1]);
        temp->insertRight(list[i + 1]);
    
}

vector<string> operators = { "=", "-", "+", "*", "/", "<", ">", "<=", ">=" };
vector<string> borders = { "(", ")", "{", "}" };
vector<string> keywords = { "if", "else", "else if", "break", "continue", "for" };

int main() {
    string curr;
    vector<string> list;
    ifstream my_file("text.txt");
    int i, j, k;
    i = j = k = 0;
    bool Init = false; // flag is false until there is actual value into the tree
    bool border = false; // false until it comes across ( or {

    while (!my_file.eof()) {
        getline(my_file, curr);
        if (curr != "")
            list.push_back(curr);
    }
    
 // vector<string>::iterator main_it = list.begin();
    BinaryTree* tree = new BinaryTree("");
    BinaryTree* ptr = tree;

    for (int l = 0; i < list.size(); l++)
    {

        if (find(keywords.begin(), keywords.end(), list[l]) != keywords.end()) {
            if (Init == false) {
                tree->setRootVal(list[l]);
                ptr = tree->getLeftChild();
            }
        }
            
        if (find(borders.begin(), borders.end(), list[l]) != borders.end()) {
            if (border == false) {
                border = true;
            }
        }


        if (find(operators.begin(), operators.end(), list[l]) != operators.end()) {
            if (Init == false) {
                tree->setRootVal(list[l]);
            }
            else if (ptr->getLeftChild() == NULL) {
                ptr->insertLeft(list[l]);

                add(tree, ptr, list, l, border);
            }

        }
            
    }

    return 0;
}
