#include <iostream>
using namespace std;
class sport
{
	int roll_no;
	string name;
public:
	bool badminton[5] , cricket[5];
	void accept();
	void display();
	int Union();
	int Intersection();
	int neither();
};
void sport::accept()
{
	int i,j;
	cout<<"Type 1 if you play badminton or cricket else type 0 \n";
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
		cout<<"Roll_no"<<i+1<<"  Name: ";
		cin>>name[j];
		cout<<"Do you play badminton ";
		cin>>badminton[i];
		cout<<"\tDo you play cricket";
		cin>>cricket[i];
		}
	}
}
void sport::display()
{
	int i;
	cout<<"Student playing badminton\n";
	for(i=0;i<5;i++)
	{
	if (badminton[i]==1)
		{
		cout<<name[j];
		cout<<"Roll_no "<<i+1<<"\t";
		}
	}cout<<endl;
	cout<<"Student playing cricket\n";
	for(i=0;i<5;i++)
	{
	if (cricket[i]==1)
		{
		cout<<name;
		cout<<"Roll_no "<<i+1<<"\t";
		}
	}cout<<endl;
}

int sport::Union()
{
	int i,count=0;
	cout<<"Roll number of students who either play badminton or cricket"<<endl;
	for(i=0;i<5;i++)
	{
		if(badminton[i]==1 || cricket[i]==1)
		{
			count++;
			cout<<name<<"\t";
			cout<<"Roll_no "<<i+1<<"\n";

		}
}
return count;
}
int sport::Intersection()
{
	int i,temp=0;
	cout<<"\nRoll number of students who  play both badminton or cricket"<<endl;
	for(i=0;i<5;i++)
	{
		if(badminton[i]==1 && cricket[i]==1)
		{
			temp++;
			cout<<name<<"\t";
			cout<<"Roll_no "<<i+1<<"\t";
		}
	}

return temp;
}

int sport::neither()
{
	int i,pointer=0;
	cout<<"\nRoll number of students who neither play badminton nor cricket"<<endl;
	for(i=0;i<5;i++)
	{
		if(badminton[i]==0 && cricket[i]==0)
		{
			pointer++;
			cout<<"Roll_no "<<i+1<<"\t";
		}
}
return pointer;
}
int main()
{
sport a;
a.accept();
a.display();
a.Union();
a.Intersection();
a.neither();
return 0;
}