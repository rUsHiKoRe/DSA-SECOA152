#include <iostream>
using namespace std;

struct node
{
	int prn;
	node * next;
};

class Club
{
	node * hn, *hn1;
public:
	Club(){ hn=NULL; hn1=NULL;}
	void add_member();
	void add_member1();
	void display();
	void display1();
	void merge();
	void remove();
};

void Club :: add_member()
{
	node *nn;
	nn= new node;
	nn->next=NULL;

	cout<<"\nEnter PRN";
	cin>>nn->prn;

	if(hn==NULL)
	{
		hn=nn;
	}

	else
	{
		node * cn;
		cn=hn;

		while(cn->next!=NULL)
			cn=cn->next;

		cn->next=nn;
	}
}

void Club :: add_member1()
{
	node *nn;
	nn= new node;
	nn->next=NULL;

	cout<<"\nEnter PRN";
	cin>>nn->prn;

	if(hn1==NULL)
	{
		hn1=nn;
	}

	else
	{
		node * cn;
		cn=hn1;

		while(cn->next!=NULL)
			cn=cn->next;

		cn->next=nn;
	}
}
void Club :: display()
{
	node * cn;
	cn=hn;

	cout<<"\nPosition: President";
	cout<<"\tPRN="<<cn->prn;
	cn=cn->next;
	while(cn->next!=NULL)
	{
		cout<<"\nPosition: Member";
		cout<<"\tPRN="<<cn->prn;
		cn=cn->next;
	}

	cout<<"\nPosition: Secretary";
	cout<<"\tPRN="<<cn->prn;
}
void Club :: display1()
{
	node * cn;
	cn=hn1;

	cout<<"\nPosition: President";
	cout<<"\tPRN="<<cn->prn;
	cn=cn->next;
	while(cn->next!=NULL)
	{
		cout<<"\nPosition: Member";
		cout<<"\tPRN="<<cn->prn;
		cn=cn->next;
	}

	cout<<"\nPosition: Secretary";
	cout<<"\tPRN="<<cn->prn;
}

void Club :: merge()
{
	node * cn;
	cn=hn;
	while(cn->next!=NULL)
		cn=cn->next;
	cn->next=hn1;
	hn1=hn;

}
void Club :: remove()
{
	cout<<"\n1: Remove President";
	cout<<"\n2: Remove Member";
	cout<<"\n3: Remove Secretary";

	cout<<"\nEnter Choice";
	int ch;
	cin>>ch;
	if(ch==1)
	{
		hn=hn->next;
		cout<<"\nNew president is: "<<hn->prn;
	}
	else
	if(ch==2)
	{
		cout<<"\nEnter PRN";
		int no;
		cin>>no;

		node * cn;
		cn=hn;
		node * prev;
		while(cn->prn!=no)
		{
			prev=cn;
			cn=cn->next;
		}
		prev->next=cn->next;
		delete cn;
	}
	else
	if(ch==3)
	{
		node *cn;
		cn=hn;
		while(cn->next->next!=NULL)
			cn=cn->next;

		cn->next=NULL;
	}
}

int main()
{
	Club C;

	while(1)
	{
		cout<<"\n1: Add Member";
		cout<<"\n2: Display";
		cout<<"\n3: Remove";
		cout<<"\n4: Add Member- List2";
		cout<<"\n5: Display - List 2";
		cout<<"\n6. Merge";
		cout<<"\n7.Exit";
		cout<<"\nEnter Choice";
		int ch;
		cin>>ch;
		switch(ch)
		{
		case 1: C.add_member();
				break;
		case 2: C.display();
				break;
		case 3: C.remove();
				break;
		case 4: C.add_member1();
				break;
		case 5: C.display1();
				break;
		case 6: C.merge();
				break;
		case 7: return 0;
		}
	}
	return 0;
}
