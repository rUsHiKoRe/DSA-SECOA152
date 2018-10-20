#include<iostream>

using namespace std;

class Str_Opr
{
	string str1;
	string str2;

public:
	void accept();
	void display();
	void s_len();
	void merge();
	void substring();
	void reverse();


};
void Str_Opr::substring()
{
	int i,j,counter=0;
	string sbs;
	cout<<"\nEnter the substring to be searched";
	cin>>sbs;
	for(i=0;sbs[i]!='\0';i++);

	for(j=0;str1[j]!='\0';j++)
	{
		if(counter!=i)
		{
		for(int l=j,k=0;l<(j+i),k<i;l++,k++)
		{
			if(sbs[k]==str1[l])
			{
				counter++;
			}
			else{
				break;
			}

		}
		}else
			break;
	}
if(counter==i){
	cout<<"Found";
}else
	cout<<"Not found";

}
void Str_Opr::reverse()
{
	cout<<"\n";

	int i;
	for(i=0;str1[i]!='\0';i++);

	for(int j=i-1;j>=0;j--)
		cout<<str1[j];
}
void Str_Opr::merge()
{
	int i,j,k;

	for(i=0;str1[i]!='\0';i++);
	for(j=i,k=0;str2[k]!='\0';k++,j++)
		{
		str1[j]=str2[k];
		}
	cout<<"\n";
	for(i=0;str1[i]!='\0';i++)
	cout<<str1[i];

}
void Str_Opr :: accept()
{
	cout<<"\nEnter String 1";
	cin>>str1;
	cout<<"\nEnter String 2";
	cin>>str2;
}

void Str_Opr :: display()
{
	cout<<"\nString 1 is:"<<str1;
	cout<<"\nString 2 is:"<<str2;
}

void Str_Opr :: s_len()
{
	int i;
	for(i=0;str1[i]!='\0';i++);
	cout<<"\nLength of String1 is:"<<i;
	for(i=0;str2[i]!='\0';i++);
		cout<<"\nLength of String2 is:"<<i;
}


int main()
{
	int choice;
	Str_Opr s1;
	s1.accept();
	do
	{
		cout<<"\n1.Display the string"<<endl;
		cout<<"2.merge the string"<<endl;
		cout<<"3.length of the string"<<endl;
		cout<<"4.reverse the string"<<endl;
		cout<<"5.search the string"<<endl;
		cout<<"enter your choice:";
		cin>>choice;
		switch(choice){
		case 1:s1.display();break;
		case 2:s1.merge();break;
		case 3:s1.s_len();break;
		case 4:s1.reverse();break;
		case 5:s1.substring();break;
		}
	}while(choice>0&&choice<5);
	return 0;
}