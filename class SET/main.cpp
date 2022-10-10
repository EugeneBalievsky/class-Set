#include<iostream>

//Класс "уникальное множество строк" (сортированное)
class Set {
private:
    struct Node {
        std::string key;
        Node* left;
        Node* right;
        Node(std::string key) : key(key), left(nullptr), right(nullptr) {}
    } *root;
    void copy_helper(Node* original, Node* result);
    void delete_helper(Node* cur);
    void insert_helper(Node* cur, std::string key);
public:
    Set() : root(nullptr) {}
    Set(const Set& other);
    ~Set();

    Set& operator=(const Set& right);
    void insert(std::string key);

    friend Set operator+(const Set& left, const Set& right);        //Объединение множеств
    friend Set operator*(const Set& left, const Set& right);        //Пересечение множеств

    bool is_empty() { return !root; }

    Set& operator+=(const Set& right);
    Set& operator*=(const Set& right);
};
Set::Set(const Set& other) : root(nullptr) {
    copy_helper(other.root, root);
}
void Set::copy_helper(Node* original, Node* result) {
    if (!original) {
        return;
    }
    result = new Node(original->key);
    copy_helper(original->left, result->left);
    copy_helper(original->right, result->right);
}
Set::~Set() {
    delete_helper(root);
}
void Set::delete_helper(Node* cur) {
    if (!cur) {
        return;
    }
    delete_helper(cur->left);
    delete_helper(cur->right);
    delete cur;
}
Set& Set::operator=(const Set& right) {

}
void Set::insert(std::string key) {
    insert_helper(root, key);
}
void Set::insert_helper(Node* cur, std::string key) {
    if (!cur) {
        cur->key = key;
    }
}
int main() {

    return 0;
}