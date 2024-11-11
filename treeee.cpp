#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int data ;

    Node* left;
    Node* right;

    Node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }

};

Node* binatree(Node* root)
{
    cout<<"enter the data: ";
    int data; cin>>data;

    root=new Node(data);


    if(data==-1)
    {
        return NULL;
    }

    cout<<"Enter data for inserting in the left of data: "<<data<<endl;

    root->left=binatree(root->left);

    cout<<"Enter data for inserting in the right of data: "<<data<<endl;
    root->right=binatree(root->right);

    return root;
}
void laveltraversal(Node*root)
{
    queue<Node*>q;

    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* temp=q.front();
        

        q.pop();

        if(temp==NULL)
        {
            cout<<endl;

            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";

            if(temp->left)
            {
                q.push(temp->left);
            }

            if(temp->right)
            {
                q.push(temp->right);
            }
        }

    }
}

void preodr(Node* root)
{
    if(root==NULL)
    {
        return ;
    }
    
    cout<<root->data<<" ";
    preodr(root->left);
    preodr(root->right);


}

void inord(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    inord(root->left);
    cout<<root->data<<" ";
    inord(root->right);
}

void postord(Node* root)
{
    if(root==NULL)
    return;
    postord(root->left);
    postord(root->right);
    cout<<root->data<<" ";
}
int main()
{
    Node* root=NULL;

   root = binatree(root);

    laveltraversal(root);

    cout<<"Preorder traversal of the tree"<<endl;

    preodr(root);
    cout<<"Inorder traversal of the tree"<<endl;
    inord(root);

    cout<<"Post order traversal of the tree"<<endl;
    postord(root);

    return 0;
}