#include<iostream>
using namespace std;

struct node
{
	bool data;
	node *next, *prev;
};

class Binary
{
		node * hn;
	public:
		Binary() { hn=NULL;}
		void accept();
		void display();
		void one_c();
		void two_c();
friend		void binaryAddition(Binary b1,Binary b2);
};

void binaryAddition(Binary b1,Binary b2)
{
	node * cn1=b1.hn;
	node* cn2=b2.hn;

}




void Binary :: accept()
{
	node * nn;
	nn= new node;
	cout<<"\nEnter bit";
	cin>>nn->data;
	nn->next=nn->prev=NULL;

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
		nn->prev=cn;
	}
}

void Binary :: display()
{
	node * cn;
	cn=hn;
	while(cn!=NULL)
	{
		cout<<cn->data<<"\t";
		cn=cn->next;
	}
}

void Binary ::one_c()
{
	node * cn;
	cn=hn;
	while(cn!=NULL)
	{
		if(cn->data==1)
			cout<<"0";
		else
			cout<<"1";
		cn=cn->next;
	}
}

void Binary ::two_c()
{
	node * cn;
	bool num[4];
	cn=hn;
	while(cn->next!=NULL)
		cn=cn->next;
		int i=0;
		while(cn->data!=1)
		{
			num[i]=cn->data;
			i++;

			cn=cn->prev;
		}

		num[i]=1;
		i++;
		cn=cn->prev;
		while(cn!=NULL)
		{
			if(cn->data==1)
			{
				num[i]=0;
				i++;

			}
			else
			{

				num[i]=1;
				i++;
			}
			cn=cn->prev;
		}

		i--;
		while(i>=0)
		{
			cout<<num[i];
			i--;
		}
		cout<<"\n\n***********\n";
}


int main()
{
	Binary b;

	while(1)
	{
		cout<<"\n1:Accept binary No";
		cout<<"\n2: Display";
		cout<<"\n3: 1's compliment";
		cout<<"\n4: 2's Compliment";
		cout<<"\n5:Exit";
		int ch;
		cout<<"\nEnter Choice";
		cin>>ch;
		switch(ch)
		{
			case 1: b.accept();
					break;
			case 2: b.display();
					break;
			case 3: b.one_c();
					break;
			case 4: b.two_c();
					break;
			case 5: return 0;
		}
	}
	return 0;
}