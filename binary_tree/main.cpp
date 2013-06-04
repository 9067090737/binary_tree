#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

struct point
{
int data;///@param data field, contains number
point *left;///@param address of left subtree
point *right;///@param address of right subtree
};

point* Tree(int n, point *p)///@function to construct binary tree
{
point *r;///@param root of the tree
int nl,nr;
if(n==0){p=NULL;return p;}///@brief if element quantity equal to null, then cancel construction
nl=n/2;///@brief element quantity in the left tree
nr=n-nl-1;///@brief element quantity in the right tree
r=new point;
cout<<"element:";
cin>>r->data;///@brief data input
r->left=Tree(nr, r->left);
r->right=Tree(nl, r->right);
p=r;
return p;
}

void Print(point*p, int l) ///@function to print tree
{
if(p)
{
Print(p->left,l+5);
for(int i=0;i<l;i++)
cout<<" ";
cout<<p->data<<"\n";
Print(p->right,l+5);
}
}

void main()
{
int n;
cout<<"Enter element quantity\n";
cin>>n;
point *root;
root=new point;
root=Tree(n, root);
Print(root,1);
getch();
}