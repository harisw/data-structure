#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct node
{
    int data, lv;
    node *right;
    node *bot;
};

struct skiplist
{
    node *header;
    int value;
    int max_lev;
    void display();
    bool searchVal(int n);
    void insertVal(int elem, node root, int h, int level);
    void deleteVal(int n);
};

void insertVal(int elem, node root, int h, int level)
{
    if(*root.right.data < elem)
    {
        return insertVal(elem, &root.right, h, level);

    } else
    {
        if(level == 0)
        {
            node new_node;
            new_node.right = root.right;
            root.right = &new_node;
        } else
        {
            if(level <= h)
            {
                node new_node;
                new_node.right = root.right;
                root.right = &new_node;
            }
            return insertVal(elem, *root.bot, h, level-1);
        }
    }
}

int main()
{
    string line;
    ifstream    file("input-50.txt");
    skip_list my_list;

    while(getline(file, line)) {
        my_list.insertKey(stoi(line));
        cout << line << endl;
    }
    //my_list.printAll();
    return 0;
}
