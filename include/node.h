class node
{
public:
    int key;
    node *left;
    node *right;
    node *root;
    node(int key) : key(key),root(nullptr), left(nullptr), right(nullptr) {}
};