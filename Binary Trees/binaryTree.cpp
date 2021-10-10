#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left = NULL;
    TreeNode *right = NULL;
    TreeNode(int data)
    {
        this->data = data;
    }
};


void insert(TreeNode* &root, int data)
{
    if(!root){
        root = new TreeNode(data);
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* front = q.front();
        q.pop();
        if(front->left){
            q.push(root->left);
        }else{
            front->left = new TreeNode(data);
            return;
        }
        if(front->right){
            q.push(root->right);
        }else{
            front->right = new TreeNode(data);
            return;
        }
    }
}

void inorder(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

//My functions

int calcHeight(TreeNode* root){
    if(!root) return 0;
    int left = calcHeight(root->left);
    int right = calcHeight(root->right);
    return max(left, right) + 1;
}

int main()
{
    TreeNode* root = NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        insert(root,data);
    }
    inorder(root);
    cout<<"\n"<<calcHeight(root);
    return 0;
}