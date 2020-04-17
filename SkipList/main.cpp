#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct skip_node
{
    int data, lv;
    struct skip_node *left;
    struct skip_node *right;
    struct skip_node *top;
    struct skip_node *bot;

};

class skip_list
{
private:
    skip_node head, *tail;
    int list_size, high_lv;
public:
    skip_list()
    {
        list_size = 0;
        high_lv = 0;
    }
    skip_node searchKey(int n)
    {
        skip_node res = head;
        skip_node temp;
        while(res.bot != nullptr)
        {
            res = *res.bot;
            temp = *res.right;
            while( n >= temp.data)
            {
                temp = *temp.right;
            }
            res = temp;
        }
        return res;
    }

    int coinFlip()
    {
        return rand()%2;
    }

    void insertKey(int n)
    {
        if(head.data == NULL)
        {
            skip_node temp;
            temp.bot = nullptr;
            temp.right = nullptr;
            temp.top = nullptr;
            temp.data = n;
            head = temp;
            return;
        }
        skip_node target = searchKey(n);
        skip_node new_node;
        new_node.data = n;
        new_node.left = &target;
        new_node.right = target.right;

        target.right = *new_node;

        int high = 1;
        while(coinFlip())
        {
            high++;
            if(high >= high_lv)
            {
                high_lv++;
                //CREATE NEW LEVEL
                skip_node new_top = head;
                new_top.bot = head;
                new_top.right = *new_node;
                head = new_top;
            } else
            {
                while(target.top == nullptr)
                    target = target.left;
                skip_node new_top;
                new_top.bot = *new_node;
                new_top.right = target.right;
                target.right = *new_top;
            }
        }
    }
    void printAll()
    {
        skip_node temp = head;
        while(head.bot != nullptr)
        {
            while(temp.next != nullptr)
            {
                cout << temp.data << endl;
                temp = temp.next;
            }
        }
        return;
    }
};

int main()
{
    string line;
    ifstream    file("input-50.txt");
    skip_list my_list;

    while(getline(file, line)) {
        my_list.insertKey(stoi(line));
    }
    my_list.printAll();
    return 0;
}
