#include <iostream>
using namespace std;

class student
{
	int roll,marks;
	string name;
	bool result;

public:

	void accept();
	void display();
	static float tot_count,ab_count,max_marks,min_marks,total,pass_count,fail_count;
	static float avg;
	static int frequency[31];
	student(){
			tot_count++;
		}

};
int student::frequency[31];
float student::tot_count=0;
float student::total=0;
float  student::pass_count=0;
float  student::fail_count=0;
float  student::ab_count=0;
float  student::max_marks=0;
float  student::min_marks=30;
float student::avg=0;

void student:: accept(){
	cout<<"Enter name:";
	cin>>name;
	cout<<"Enter roll number:";
	cin>>roll;
	label:
	cout<<"Enter marks between 0 to 30(Enter -1 if absent):";
	cin>>marks;
	if(marks>=0&&marks<=30){
		if(marks>max_marks)
			max_marks=marks;

		if(marks<min_marks)
			min_marks=marks;
		total=total+marks;
		avg=total/tot_count;
		if(marks<(0.33*30)){
			result=0;fail_count++;
		}
		else
			{result=1;pass_count++;}
		frequency[marks]++;
	}
	else if(marks==-1)
		{ab_count++;result=0;fail_count++;}
	else
		{cout<<"Invalid marks!!!!"<<endl;
		goto label;
		}

}
void student::display(){
	cout<<"\n"<<roll;
	cout<<"\tName:"<<name;
	if(marks>-1){
	cout<<"\tMarks:"<<marks;
	}
	else
	{
		cout<<"\tAbsent";}
	}

void report()
{
	cout<<"\n\n\n************Report**************";
	cout<<"\nTotal strength of the class:"<<student::tot_count;
	cout<<"\nNumber of students absent for the test:"<<student::ab_count;
	cout<<"\nNumber of students present for the test:"<<(student::tot_count-student::ab_count);
	cout<<"\nHighest score:"<<student::max_marks;
	cout<<"\nLowest score:"<<student::min_marks;
	cout<<"\nAverage marks scored by students:"<<student::avg;
	cout<<"\nPassed students:"<<student::pass_count;
	cout<<"\nFailed students:"<<student::fail_count;
	cout<<"\nPassing percentage with absentees:"<<(student::pass_count/student::tot_count)*100<<"%";
	cout<<"\nFailing percentage with absentees:"<<100-((student::pass_count/student::tot_count)*100)<<"%";
	cout<<"\nPassing percentage without absentees:"<<(student::pass_count/(student::tot_count-student::ab_count))*100<<"%";
	cout<<"\nFailing percentage without absentees:"<<100-((student::pass_count/(student::tot_count-student::ab_count))*100)<<"%";

	int temp_max=0;

	for(int i=0;i<31;i++){
		if(student::frequency[i]>temp_max)
			{temp_max=student::frequency[i];}
		}
	for(int i=0;i<31;i++){
		if(student::frequency[i]==temp_max)
			cout<<"\n"<<temp_max<<" students scored"<<i<<" marks";

	}

}
int main()
{
	int n;
	cout<<"Number of students:";
	cin>>n;
	student s[n];



	for(int i=0;i<n;i++)
				s[i].accept();



	for(int i=0;i<n;i++)
				s[i].display();

	report();

}