#include <iostream>
#include <cmath>
#include <cstring>
#include <ctime>
#include <fstream>
#include <chrono>
#define MAX_LEVEL 4

using namespace std;
using namespace std::chrono;

int random_level()
{
    return rand()%MAX_LEVEL;
}

struct node
{
    int value;
    node **forw;
    node(int level, int &value)
    {
        forw = new node * [level + 1];
        memset(forw, 0, sizeof(node*) * (level + 1));
        this->value = value;
    }
};

struct skiplist
{
    node *header;
    int value;
    int level;
    skiplist()
    {
        header = new node(MAX_LEVEL, value);
        level = 0;
    }
    void display()
    {
        const node *x = header->forw[0];
        while (x != NULL)
        {
            cout << x->value;
            x = x->forw[0];
            if (x != NULL)
                cout << " - ";
        }
        cout << endl;
    }
    bool search_element(int &s_value)
    {
        node *x = header;
        for (int i = level;i >= 0;i--)
        {
            while (x->forw[i] != NULL && x->forw[i]->value < s_value)
            {
                x = x->forw[i];
            }
        }
        x = x->forw[0];
        return x != NULL && x->value == s_value;
    }
    void insert_element(int value)
    {
        node *x = header;
        node *update[MAX_LEVEL + 1];
        memset(update, 0, sizeof(node*) * (MAX_LEVEL + 1));
        for (int i = level;i >= 0;i--)
        {
            while (x->forw[i] != NULL && x->forw[i]->value < value)
            {
                x = x->forw[i];
            }
            update[i] = x;
        }
        x = x->forw[0];
        if (x == NULL || x->value != value)
        {
            int lvl = random_level();
            if (lvl > level)
            {
                for (int i = level + 1;i <= lvl;i++)
                {
                    update[i] = header;
                }
                level = lvl;
            }
            x = new node(lvl, value);
            for (int i = 0;i <= lvl;i++)
            {
                x->forw[i] = update[i]->forw[i];
                update[i]->forw[i] = x;
            }
        }
    }
void delete_element(int &value)
{
    node *x = header;
    node *update[MAX_LEVEL + 1];
    memset (update, 0, sizeof(node*) * (MAX_LEVEL + 1));
    for (int i = level;i >= 0;i--)
    {
        while (x->forw[i] != NULL && x->forw[i]->value < value)
        {
            x = x->forw[i];
        }
        update[i] = x;
    }
    x = x->forw[0];
    if (x->value == value)
    {
        for (int i = 0;i <= level;i++)
        {
            if (update[i]->forw[i] != x)
                break;
            update[i]->forw[i] = x->forw[i];
        }
        delete x;
        while (level > 0 && header->forw[level] == NULL)
        {
            level--;
        }
    }
}
};

int main()
{
    skiplist ss;
    int choice, n;

    string line;
    ifstream in("input-1000.txt");    //CHANGE INPUT DATA HERE
    cout << "Seeding data...." << endl;
    auto start = high_resolution_clock::now();
    while(getline(in, line))
    {
        ss.insert_element(stoi(line));
    }
     auto stop = high_resolution_clock::now();
     auto duration = duration_cast<milliseconds>(stop - start);
     cout << endl << "Operation completed on " << duration.count() << " milliseconds Execution" << endl;
    cout << "Data Seeding completed..." << endl;
    while (1)
    {
        cout << endl << "#############################################" << endl;
        cout << endl << "Enter menu below (enter the number): " << endl;
        cout<<"1.Insert"<<endl;
        cout<<"2.Delete"<<endl;
        cout<<"3.Search"<<endl;
        cout<<"4.Display All"<<endl;
        cout<<"5.Exit "<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            {
             cout<<"Enter new element: ";
             cin>>n;
             auto start = high_resolution_clock::now();
             ss.insert_element(n);
             auto stop = high_resolution_clock::now();
             auto duration = duration_cast<milliseconds>(stop - start);
             cout<<endl<<"Operation completed on "<<duration.count()<<" milliseconds Execution"<<endl;
             break;
            }
        case 2:
        {
             cout<<"Enter the element to be deleted: ";
             cin>>n;
                          auto start = high_resolution_clock::now();
             if(!ss.search_element(n))
             {
                 cout<<"Element not found"<<endl;
                 break;
             }
             ss.delete_element(n);
              auto stop = high_resolution_clock::now();
             auto duration = duration_cast<milliseconds>(stop - start);
             cout<<endl<<"Operation completed on "<<duration.count()<<" milliseconds Execution"<<endl;
             break;
        }
        case 3:
        {
             cout<<"Enter the element to be searched: ";
             cin>>n;
              auto start = high_resolution_clock::now();
             if(ss.search_element(n))
                 cout<<"Element "<<n<<" is in the list"<<endl;
             else
                 cout<<"Element not found"<<endl;
                          auto stop = high_resolution_clock::now();
             auto duration = duration_cast<milliseconds>(stop - start);
             cout<<endl<<"Operation completed on "<<duration.count()<<" milliseconds Execution"<<endl;
             break;
        }
        case 4:
        {
             cout<<"List : ";
             auto start = high_resolution_clock::now();
             ss.display();
             auto stop = high_resolution_clock::now();
             auto duration = duration_cast<milliseconds>(stop - start);
             cout<<endl<<"Operation completed on "<<duration.count()<<" milliseconds Execution"<<endl;
             break;
        }
        case 5:
             exit(1);
             break;
        default:
             cout<<"Wrong Option"<<endl;
        }
    }
    return 0;
}
