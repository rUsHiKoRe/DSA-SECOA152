#include <iostream>
using namespace std;

struct node
{
	bool data;
	node * next;
	node* prev;

};
class theatre
{
	node * hn[10];
	int row,col;
public:
	theatre()
	{
		for(int i=0;i<10;i++)
			hn[i]=NULL;
		create();
	}
	void create()
	{
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<7;j++)
			{
				node * nn;
				nn=new node;
				nn->data=0;
				nn->prev=nn->next=NULL;
				if(hn[i]==NULL)
				{
					hn[i]=nn;nn->prev=nn->next=nn;
				}
				else
				{
					node * cn;
					cn=hn[i];
					while(cn->next!=hn[i])
						cn=cn->next;

					nn->next=cn->next;
					cn->next=nn;
					nn->prev=cn;
					cn->next->prev=nn;
				}
			}
		}
	}

	void book()
	{
		cout<<"\nEnter row number and column number:";
		cin>>row>>col;

		node * cn;
		cn=hn[row-1];
		for(int i=0;i<col;i++)
			cn=cn->next;

		if(cn->data==0)
		{
			cn->data=1;
			cout<<"Your Seat was successfully booked\n";
		}
		else
			cout<<"Seat is already booked by someone else\n";
	}
	void display()
	{
		cout<<"\t\t\t----------------------------\n";
		cout<<"\t\t\t         |SCREEN|\n";
		cout<<"\t\t\t----------------------------\n";
		cout<<"\t\t1\t2\t3\t4\t5\t6\t7\n";
		cout<<"\t==============================================================";

		for(int i=0;i<10;i++)
		{
			cout<<"\n";
			cout<<i+1<<"\t||\t";

			node *cn=hn[i];
			while(cn->next!=hn[i])
			{
				cout<<cn->data;
				cout<<"\t";
				cn=cn->next;
			}
			cout<<cn->data;
		}
		cout<<"\n\t==============================================================";
	}
	void cancel()
	{
		cout<<"\nEnter the row and column:";
		cin>>row>>col;
		node * cn;
		cn=hn[row-1];
		for(int i=0;i<col-1;i++)
			cn=cn->next;
		if(cn->data==1)
		{
			cn->data=0;
			cout<<"Your Seat was successfully cancelled\n";
		}
		else
			cout<<"This seat is already vacant\n";
	}

};
int main()
{
	theatre t;
	int choice;

	while(1)
	{
		cout<<"\nWelcome to Cinema Hall\n";
		cout<<"-------------------------------\n";
		cout<<"1.Book a seat\n";
		cout<<"2.cancel a seat\n";
		cout<<"3.Display Chart\n";
		cout<<"4.Exit\n";
		cout<<"Enter your choice:";
		cin>>choice;

		switch(choice)
		{
			case 1:t.book();t.display();break;
			case 2:t.cancel();t.display();break;
			case 3:t.display();break;
			case 4:return 0;
		}
	}
return 0;
}