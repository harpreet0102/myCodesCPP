#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
    /* data */
};

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    int n;
    cout << "hello HARPREET!" << endl;
    cin >> n;
    cout << "the number is: " << n << endl;
}