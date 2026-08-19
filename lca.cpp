#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* leastCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q)
{
    if(root==NULL || root==p || root==q)
        return root;

    TreeNode* res;
    
    TreeNode* l=leastCommonAncestor(root->left,p,q);
    TreeNode* r=leastCommonAncestor(root->right,p,q);
    

    if(l!=NULL && r!=NULL)
        return root;

    if(l!=NULL)
        return l;
    else
        return r;
}
int main()
{
    TreeNode* root=new TreeNode(3);
    TreeNode* l1=new TreeNode(5);
    TreeNode* l11=new TreeNode(6);
    TreeNode* l2=new TreeNode(2);
    TreeNode* l21=new TreeNode(7);
    TreeNode* l22=new TreeNode(4);
    TreeNode* r1=new TreeNode(1);
    TreeNode* r11=new TreeNode(0);
    TreeNode* r12=new TreeNode(8);

    root->left=l1;
    l1->left=l11;
    l2->left=l21;
    l2->right=l22;
    root->right=r1;
    r1->left=r11;
    r1->right=r12;

    TreeNode* ans=leastCommonAncestor(root,l1,r1);
    cout<<ans->val;
    return 0;
}