#include <iostream>
#include <list>

using namespace std;

class queue
{
	list <int> l;
public:
	void enqueue()
	{
		cout<<"Enter the element to be added";
		int e;
		cin>>e;
		l.push_back(e);

	}
	void dequeue()
	{
		if(!isEmpty())
		{
			l.pop_front();
		}
		else
			cout<<"Empty List..Cannot dequeue"<<endl;

	}
	bool isEmpty()
	{
		if(l.begin()==l.end())
			return 1;
		else
			return 0;
	}

	void getFront()
		{
		if(!isEmpty())
			cout<<l.front()<<endl;
		else
			cout<<"Empty Queue"<<endl;

		}
	void getRear()
			{
		if(!isEmpty())
				cout<<l.back()<<endl;
			else
				cout<<"Empty Queue"<<endl;


			}
	void display()
	{
		list <int>:: iterator i;
		for(i=l.begin();i!=l.end();i++)
		{
			cout<<" "<<*i;

		}
		cout<<"\n";
	}

};

int main() {
	queue s;
	int choice;
	while(1)
	{
		cout<<"MENU"<<endl;
		cout<<"1.Enqueue"<<endl;
		cout<<"2.Dequeue"<<endl;
		cout<<"3.Get Front"<<endl;
		cout<<"4.Get Rear"<<endl;
		cout<<"5.Display"<<endl;
		cout<<"6.Empty?"<<endl;
		cout<<"Enter your choice";
		cin>>choice;
		switch(choice)
		{
		case 1:s.enqueue();break;
		case 2:s.dequeue();break;
		case 3:s.getFront();break;
		case 4:s.getRear();break;
		case 5:s.display();break;
		case 6:if(s.isEmpty())
			cout<<"Empty"<<endl;
		else
			cout<<"Not Empty"<<endl;
		break;
		default:return 0;

		}
	}
	return 0;
}