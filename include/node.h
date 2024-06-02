class node
{
    int key;
    node *left;
    node *right;

public:
    node(int key) : key(key), left(nullptr), right(nullptr) {}
};