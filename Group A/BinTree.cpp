#include<iostream>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};
class BinTree
{
    TreeNode *root,Temp;
    public:
        TreeNode* create();
        TreeNode* insert(TreeNode *);
        void Inorder(TreeNode *);
        void PostOrder(TreeNode *);
        void PreOrder(TreeNode *);
        void Display(TreeNode *);
};
TreeNode* BinTree::create()
{
    TreeNode *p;
    cout<<"\nEnter the Data For Root Node";
    p = new TreeNode;
    cin>>p->data;
    p->left=NULL;
    p->right=NULL;
    root=p;
    cout<<"Node Has Been Inserted "<<root->data;
    return root;
}
TreeNode* BinTree::insert(TreeNode *root)
{
    int db;
    char ans,ans2;
    TreeNode *node;
    node = new TreeNode;
do{
    cout<<"\nEnter the Data";
    cin>>db;
    if(db==-1)
    {
        return NULL;
    }
    else
    {
        node->data=db;
        node->left=NULL;
        node->right=NULL;
            cout<<"Do You wana Insert This Node at Left";
            cin>>ans;
            if(ans=='y')
            {
                root->left=node;
                cout<<"\nInserted at Left";
            }
            else if(root->right==NULL)
            {
                cout<<"\nDo You Wana Insert This Node At Right";
                cin>>ans;
                if(ans=='y')
                    root->right=node; cout<<"\nInserted at Right";
                    
            }    
    }
    cout<<"\nCountinue??";
    cin>>ans2;
 }while(ans2=='y');
    return root;
}
void BinTree::PreOrder(TreeNode *root)
{
    if(root)
    {
        cout<<"\t"<<root->data;
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
void BinTree::Inorder(TreeNode *root)
{
    if(root)
    {
        Inorder(root->left);
        cout<<"\t"<<root->data;
        Inorder(root->right);
    }
}
void BinTree::PostOrder(TreeNode *root)
{
    if(root)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        cout<<"\t"<<root->data;
    }
}
void BinTree::Display(TreeNode *root)
{
    TreeNode *temp=NULL;
    temp=root;
    while(temp)
    {
        if(temp->left!=NULL)
        {
            cout<<temp->data;
            temp=temp->left;
        }
        else if(temp->right!=NULL){
            cout<<temp->data;
            temp=temp->right;
        }
    }
}
int main()
{
    BinTree B1;
    TreeNode *root;
    int in; char b;
    do
    {
        cout<<"\n1.Create\n2.Insert\n3.Preorder\n4.Inorder\n5.Postorder\n6.Display\nEnter Tour choice";
        cin>>in;
        switch(in)
        {
            case 1: root=B1.create();
                    break;
            case 2: B1.insert(root);
                    break;
            case 3: B1.PreOrder(root);
                    break;
            case 4: B1.Inorder(root);
                    break;
            case 5: B1.PostOrder(root);
                    break;
            case 6: B1.Display(root);
                    break;
            
        }
        cout<<"\nDo You Want to Perform any other Operations ??";
        cin>>b;
    } while (b=='y');
    return 0;
}