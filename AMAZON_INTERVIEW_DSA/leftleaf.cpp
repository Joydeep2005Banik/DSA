#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};
bool isLeaf(TreeNode* node)
{
    return node->left==NULL && node->right==NULL;
}
int sumLeaf(TreeNode* root)
{
    if(root==NULL)
        return 0;
    int sum=0;
    if(root->left!=NULL)
    {
        if(isLeaf(root->left))
            sum+=root->left->val;
        else
            sum+=sumLeaf(root->left);
    }
    sum+=sumLeaf(root->right);
    return sum;
}
int main()
{
    TreeNode* root=new TreeNode(3);
    TreeNode* n1=new TreeNode(9);
    TreeNode* n2=new TreeNode(20);
    TreeNode* n3=new TreeNode(15);
    TreeNode* n4=new TreeNode(7);
    root->left=n1;
    root->right=n2;
    n2->left=n3;
    n2->right=n4;
    cout<<sumLeaf(root)<<endl;
    return 0;
}