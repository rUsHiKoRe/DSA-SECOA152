#include<iostream>
using namespace std;
class search
{
	int Roll_no[100],n;
public:
	void accept();
	void display();
	void binary_search();
	void linear_search();
	void sentinal_search();
	int fibonacci_search();
	int fibo(int k);

};

void search::accept()
{
	cout<<"enter how many student attended program:"<<endl;
	cin>>n;
	cout<<"enter roll numbers in sorted order:"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>Roll_no[i];
	}
}

void search::display()
{
	cout<<"Roll numbers of student:"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<Roll_no[i]<<endl;
	}
}

void search::linear_search()
{
	int R,i;
	int flag=0;
	cout<<"enter roll number to search:"<<endl;
	cin>>R;
	for(i=0;i<n;i++)
	{

		if(R==Roll_no[i])
		{

			flag=1;
			break;
		}
	}

	if(flag==1)
	{
		cout<<"Roll number "<<R<<" attended the program"<<endl;
	}
	else
	{
		cout<<"Roll number "<<R<<" not attended the program"<<endl;
	}
}

void search::binary_search()
{
	int R;
	int flag=0;
	int low,high,mid;
	cout<<"enter roll number to search:"<<endl;
	cin>>R;
	low=0;high=n-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(Roll_no[mid]==R)
		{
			flag=1;
			break;
		}
		else
		{
			if(R>Roll_no[mid])
			{
				low=mid+1;
			}
			else
			{
				high=mid-1;
			}
		}
	}
	if(flag==1)
	{
		cout<<"Roll number "<<R<<" attended the program"<<endl;
	}
	else
	{
		cout<<"Roll number "<<R<<" not attended the program"<<endl;
	}

}

void search::sentinal_search()
{
	int R,i;
	cout<<"enter number to search:"<<endl;
	cin>>R;
	Roll_no[n]=R;
	for( i=0;i<=n;i++)
	{
		if(R==Roll_no[i])
		{
			break;
		}
	}

	if(i==n)
	{
		cout<<"Roll number "<<R<<" not attended the program"<<endl;
	}

	else
	{
		cout<<"Roll number "<<R<<" attended the program"<<endl;
	}


}

int search::fibo(int k)
{
	if(k==0)
		return 0;
	else if(k==1)
		return 1;
	else
		return(fibo(k-1)+fibo(k-2));
}

int search::fibonacci_search()
{
	int f1,f2,t,mid,j,f,R;
	j=1;
	cout<<"enter number to search"<<endl;
	cin>>R;
	while(fibo(j)<=n)
	{
		j++;
	}
	f=fibo(j);
	f1=fibo(j-2);
	f2=fibo(j-3);
	mid=n-f1+1;
	while(R!=Roll_no[mid])
	{
		if(mid<0 || R>Roll_no[mid])
		{
			if(f1==1)
				return -1;
			mid=mid+f2;
			f1=f1-f2;
			f2=f2-f1;
		}
		else
		{
			if(f2==0)
				return -1;
			mid=mid-f2;
			t=f1-f2;
			f1=f2;
			f2=t;
		}
	}
		return mid;
}





int main()
{
	int c,R;
	char ch;
	search s;
	do
	{	cout<<"\t MENU"<<endl;
		cout<<"enter 1 for accept roll_number:"<<endl;
		cout<<"enter 2 for display roll_number:"<<endl;
		cout<<"enter 3 for linear search:"<<endl;
		cout<<"enter 4 for binary search:"<<endl;
		cout<<"enter 5 for sentinal search:"<<endl;
		cout<<"enter 6 for fibonacci search:"<<endl;
		cout<<"enter your choice:"<<endl;
		cin>>c;
		switch(c)
		{
		case 1:
			s.accept();
			break;
		case 2:
			s.display();
			break;
		case 3:
			s.linear_search();
			break;
		case 4:
			s.binary_search();
			break;
		case 5:
			s.sentinal_search();
			break;
		case 6:
			R=s.fibonacci_search();
			    if(R!=-1)
				{
					cout<<"Roll number "<<R<<" attended the program"<<endl;
				}

				else
				{
					cout<<"Roll number "<<R<<" not attended the program"<<endl;
				}


			break;
		default:
			cout<<"invalid choice:"<<endl;
			break;
		}

		cout<<"do you want to continue:"<<endl;
		cin>>ch;

	}while(ch=='y' || ch=='Y');

	return 0;
}