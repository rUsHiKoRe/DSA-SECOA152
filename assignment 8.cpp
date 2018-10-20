#include<iostream>
#define max 30
using namespace std;
class stac
{
	char s[max];
	int top;
	char s1[30];
public:
	stac()
{
		top=-1;
}
	int is_stack_empty();
	int is_stack_full();
	void accept();
	void display();
	void push_element(char x);
	int pop_element();
	void check();
};

int stac::is_stack_empty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

int stac::is_stack_full()
{
	if(top==max-1)
		return 1;
	else
		return 0;
}

int stac::pop_element()
{
	int temp;
	if(is_stack_empty())
	{
		cout<<"stack is empty"<<endl;
	}
	else
	{
		temp=s[top];
		top--;

	}
	return temp;
}

void stac::push_element(char x)
{
	if(is_stack_full())
	{
		cout<<"stack is full"<<endl;
	}
	else
	{
		top++;
		s[top]=x;
	}
}

void stac::accept()
{
	cout<<"enter elements:"<<endl;
	cin>>s1;

}

void stac::display()
{
	cout<<"Expression is:"<<s1<<endl;
}

void stac::check()
{
	char a,token;
	for(int i=0;s1[i]!='\0';i++)
	{
		token=s1[i];
		if(token=='(' || token=='{' || token=='[')
		{
			push_element(token);
		}

		if(token==')' || token=='}' || token==']')
		{
			if(!is_stack_empty())
			{
				a=pop_element();
				if(a=='(' && token==')' || a=='{' && token=='}' || a=='[' && token==']')
				{

				}
				else
				{
					cout<<"mismatch"<<endl;
				}

			}
			else
			{
				cout<<"more no of brackets"<<endl;
			}


		}
	}
	if(is_stack_empty())
	{
		cout<<"expression is balanced"<<endl;
	}
	else
	{
		cout<<"expression is not balanced"<<endl;
	}
}

int main()
{
	stac o1;
	o1.accept();
	o1.display();
	o1.check();
	return 0;
}
