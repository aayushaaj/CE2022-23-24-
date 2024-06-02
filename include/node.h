class node
{
public:
    node(int key) : key(key), left(nullptr), right(nullptr), value(0) {}
    int key;
    node *left;
    node *right;
    int value;
};