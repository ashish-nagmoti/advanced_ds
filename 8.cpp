#include<iostream>
#include<string.h>
using namespace std;
class dict
{
public: dict *root, *node, *left, *right, *tree1;
		string s1, s2;
		int flag, flag1, flag2, flag3, cmp;
		   
dict()
{
    flag=0,flag1=0,flag2=0,flag3=0,cmp=0;
    root=NULL;
}

void input()
{
    node=new dict;
    cout<<"Enter keyword : ";
    cin>>node->s1;
    cout<<"Enter its meaning : ";
    cin>>node->s2;
    create_root(root, node);
}

void create_root(dict *tree,dict *node1)
{
	int i=0,result;
	char a[20],b[20];
	if(root==NULL)
	{
		root=new dict;
		root=node1;
		root->left=NULL;
		root->right=NULL;
		cout<<"\nRoot node created successfully."<<endl;
		return;
 	}
	for(i=0;node1->s1[i]!='\0';i++)
	{
    	a[i]=node1->s1[i];
   	}
   
	for(i=0;tree->s1[i]!='\0';i++)
	{
    	b[i]=tree->s1[i];
   	}
	result=strcmp(b,a);
	check_same(tree,node1);
	if(flag==1)
	{
        cout<<"The word you entered already exists.\n";
		flag=0;
	}
	else
	{
		if(result>0)
		{
       		if(tree->left!=NULL)
       		{
           		create_root(tree->left,node1);
       		}
       		else
       		{
           		tree->left=node1;
           		(tree->left)->left=NULL;
               	(tree->left)->right=NULL;
            	cout<<"Node added to left of "<<tree->s1<<"\n";
            	return;
         	}
       }
       else if(result<0)
       {
        	if(tree->right!=NULL)
        	{
            	create_root(tree->right,node1);
        	}
        	else
        	{
            	tree->right=node1;
            	(tree->right)->left=NULL;
            	(tree->right)->right=NULL;
            	cout<<"Node added to right of "<<tree->s1<<"\n";
           	 	return;
        	}
       }
	}
}  

void check_same(dict *tree,dict *node1)
{
	if(tree->s1==node1->s1)
	{
		flag=1;
		return;
    }
	else if(tree->s1>node1->s1)
	{
		if(tree->left!=NULL)
		{
    		check_same(tree->left,node1);
    	}
    }
    else if(tree->s1<node1->s1)
    {
    	if(tree->right!=NULL)
    	{
    		check_same(tree->right,node1);
    	}
    }
}


void input_displayasc()
{
	if(root!=NULL)
	{
    	cout<<"The words entered in the dictionary are : \n\n";
    	displayasc(root);
	}
	else
	{
       cout<<"\nThere are no words in the dictionary.\n";
	}
}

void displayasc(dict *tree)
{
    if(tree->left==NULL&&tree->right==NULL)
    {
    	cout<<tree->s1<<" : "<<tree->s2<<"\n\n";
    }
    else
    {
       if(tree->left!=NULL)
       {
           displayasc(tree->left);
       }
       cout<<tree->s1<<" : "<<tree->s2<<"\n\n";
       if(tree->right!=NULL)
       {
           displayasc(tree->right);
       }
    }
}

void input_displaydesc()
{
	if(root!=NULL)
	{
    	cout<<"The words entered in the dictionary are : \n\n";
    	displaydesc(root);
	}
	else
	{
       cout<<"\nThere are no words in the dictionary.\n";
	}
}

void displaydesc(dict *tree)
{
    if(tree->left==NULL&&tree->right==NULL)
    {
    	cout<<tree->s1<<" : "<<tree->s2<<"\n\n";
    }
    else
    {
       if(tree->right!=NULL)
       {
           displaydesc(tree->right);
       }
       cout<<tree->s1<<" : "<<tree->s2<<"\n\n";
       if(tree->left!=NULL)
       {
           displaydesc(tree->left);
       }
    }
}

void input_find()
{
	flag2=0,cmp=0;
	if(root!=NULL)
	{
       cout<<"\nEnter the keyword to be searched : \n";
       cin>>s1;
       find(root,s1);
       if(flag2==0)
       {
           cout<<"Number of comparisons needed : "<<cmp<<"\n";
           cmp=0;
       }
	}
	else
	{
       cout<<"\nThere are no words in the dictionary.\n";
	}
}

dict* find(dict *tree,string s3)
{
	if(tree==NULL)
	{
		cout<<"\nWord not found.\n";
		flag2=1;
		flag3=1;
		cmp=0;
	}
	else
	{
		if(tree->s1==s3)
		{
			cmp++;
			cout<<"\nWord found.\n";
			cout<<tree->s1<<": "<<tree->s2<<"\n";
			tree1=tree;
			return tree;
		}
		else if(tree->s1>s3)
		{
			cmp++;
			find(tree->left,s3);
		}
		else if(tree->s1<s3)
		{
			cmp++;
			find(tree->right,s3);
		}
	}
	return tree;
}

void input_remove()
{
	char t;
	if(root!=NULL)
	{
 		cout<<"\nEnter a keyword to be deleted :\n";
 		cin>>s1;
 		remove(root,s1);
 		if(flag1==0)
 		{
    		cout<<"\nThe word '"<<s1<<"' has been deleted.\n";
 		}
	 	flag1=0;
	}
	else
	{
		cout<<"\nThere are no words in the dictionary.\n";
	}
}

dict* remove(dict *tree,string s3)
{
	dict *temp;
   	if(tree==NULL)
   	{
    	cout<<"\nWord not found.\n";
	 	flag1=1;
    	return tree;
   	}
   	else if(tree->s1>s3)
   	{
    	tree->left=remove(tree->left,s3);
    	return tree;
   	}
   	else if(tree->s1<s3)
   	{
    	tree->right=remove(tree->right,s3);
    	return tree;
   	}
   	else
   	{
    	if(tree->left==NULL&&tree->right==NULL)
    	{
    		delete tree;
    		tree=NULL;
    	}
    	else if(tree->left==NULL)
    	{
    		temp=tree;
    		tree=tree->right;
    		delete temp;
    	}
    	else if(tree->right==NULL)
    	{
    		temp=tree;
    		tree=tree->left;
    		delete temp;
    	}
    	else
    	{
    		temp=findmin(tree->right);
    		tree=temp;
    		tree->right=remove(tree->right,temp->s1);
    	}
	}
    return tree;
}

dict* findmin(dict *tree)
{
	while(tree->left!=NULL)
	{
		tree=tree->left;
	}
	return tree;
}
};

int main()
{
int ch;
dict d;

cout<<"\n\t\t-----Welcome to Dictionary-----\n\n1. Insert (word, meaning)\n2. Find a word.\n3. Delete word.\n4. Display dictionary (Ascending order)\n5. Display dictionary (Descending order)\n6. Exit.\n"<<endl;
do{
cout<<"Enter your choice : ";
cin>>ch;

switch(ch){

case 1: d.input();
        break;
       
case 2: d.input_find();
        break;
       
case 3: d.input_remove();
        break;
       
case 4: d.input_displayasc();
        break;
       
case 5: d.input_displaydesc();
        break;
       
default:cout<<"Thank you!"<<endl;
        break;
}
}while(ch!=6);
return 0;
}
