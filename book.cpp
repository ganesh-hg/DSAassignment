#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node{
public:;
    char label[20];
    int ch_count;
    Node *child[10];
}*root;

class Book{
public:

Book()
{
    root = NULL;
}

void create();
void display(Node *r1);

};

void Book::create()
{
    int chapters, i, j, k;
    root = new Node();
    cout<<"Enter book title : ";
    cin >> root->label;
    cout<<"Enter the Number of Chapters you want to add : ";
    cin >> chapters;
    root->ch_count = chapters;
    for(int i=0; i<chapters; i++)
    {
        root->child[i] = new Node();
        cout<<"Enter Chapter "<<i+1<<" name : ";
        cin >> root->child[i]->label;
        cout<<"Enter the Number of Sections you wan to add : ";
        cin >> root->child[i]->ch_count;
        for(int j=0; j<root->child[i]->ch_count; j++)
        {
            root->child[i]->child[j] = new Node();
            cout<<"Enter Section "<<j+1<<" name : ";
            cin >> root->child[i]->child[j]->label;
            cout<<"Enter the Number of Sub-sections in it : ";
            cin >> root->child[i]->child[j]->ch_count;
            for(int k=0; k<root->child[i]->child[j]->ch_count; k++)
            {
                root->child[i]->child[j]->child[k] = new Node();
                cout<<"Enter the Sub-section "<<k+1<<" name : ";
                cin >> root->child[i]->child[j]->child[k]->label;
            }
        }
    } 
}

void Book::display(Node *r1)
{
    int tchapters, i, j ,k;
    if(r1 != NULL)
    {
    cout<<"================"<<endl;
    cout<<"Book Tree"<<endl;
    cout<<"Book Tite : "<<r1->label;
    tchapters = r1->ch_count;
    for(int i=0; i<tchapters; i++)
    {
        cout<<"\n Chapter : ";
        cout<<" "<<r1->child[i]->label;
        cout<<"\n Section : ";
        for(int j=0 ;j<r1->child[i]->ch_count; j++)
        {
            cout<<"\n "<<r1->child[i]->child[j]->label;
            cout<<"\n Sub-section : ";
            for(int k=0; k<r1->child[i]->child[j]->ch_count ; k++)
            {
                cout<<"\n "<<r1->child[i]->child[j]->child[k]->label;
            }
            cout<<endl;

        }
    }
    }
}
int main()
{
    Book b; int choice;
    while(1)
    {
        cout<<"================"<<endl;
        cout<<"Book Tree"<<endl;
        cout<<"1. Create"<<endl;
        cout<<"2. Display"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1: 
                b.create();
                break;
            case 2: 
                b.display(root);
                break;
            case 3: 
                exit(1);
            default: 
                cout<<"Wrong choice"<<endl;
        }
    }
}