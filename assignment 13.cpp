#include <iostream>
using namespace std;

class sorting
{
	int n;
	float arr[10];
public:
	void accept()
	{
		cout<<"\nNO.Of Students:";
		cin>>n;
		cout<<"\nEnter the elements:";
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
	}
	void display()
	{
		for(int i=n-1;i>=n-5;i--)
				{
					cout<<arr[i]<<"\t";
				}
		cout<<"\n";
	}
	void bubble()
	{
		for(int pass=0;pass<n-1;pass++)
		{
			for(int comp=0;comp<n-1-pass;comp++)
			{
				if(arr[comp]>arr[comp+1])
				{
					float temp=arr[comp];
					arr[comp]=arr[comp+1];
					arr[comp+1]=temp;
				}
			}
		}
		cout<<"\nBubble sorted array:";
		display();
	}
	void selection()
	{
		int pos;
		for(int i=0;i<n;i++)
		{
			pos=i;
			for(int j=i+1;j<n;j++)
			{
				if(arr[pos]>arr[j])
				{
					pos=j;
				}
			}
			float temp=arr[i];
			arr[i]=arr[pos];
			arr[pos]=temp;
		}
		cout<<"\nSelection sorted array:";
		display();

	}
};
int main() {
	sorting obj;
	cout<<"\nSelection sort";
	obj.accept();
	obj.selection();
	cout<<"\nBubble Sort";
	obj.accept();
	obj.bubble();
	return 0;
}