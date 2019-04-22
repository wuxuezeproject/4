#include "stdlib.h"
#include<iostream>
using namespace std;
typedef struct Binode
{
	int date;
	struct Binode *lchild,*rchild;
}Binode,*Bitree;
void create(Bitree &T)
{
	int t;
	char ch;
	cin>>t>>ch;
	if(t==-1)T=NULL;
	else
	{
		T=(Bitree)malloc(sizeof(Binode));
		if(!T)return;
		T->date=t;
		create(T->lchild);
		create(T->rchild);
	}
}
int seek(Bitree &T)
{
	if(!T)
		return 1;
	else if(!(T->lchild)&&!(T->rchild))//����������û
		return 1;
	else if((T->lchild)&&!(T->rchild))
	{//����������������
		if(T->lchild->date>T->date)
			return 0;
		else
			return seek(T->lchild);
	}
	else if(!(T->lchild)&&(T->rchild))
	{//����������������
		if(T->rchild->date<T->date)
			return 0;
		else
			return seek(T->rchild);
	}
	else
	{//������������
		if((T->lchild->date>T->date)||(T->rchild->date<T->date))
	      return 0;
		else
			return (seek(T->lchild)&&seek(T->rchild));
	}
}
int main()
{
	Bitree T;
	int flag=0;
	create(T);
	flag=seek(T);
	if(flag)
		cout<<"YES";
	else
		cout<<"NO";
	system("pause");
	return 0;
}