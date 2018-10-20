#include<iostream>
using namespace std;
#define size 10
class PizzaQue
{
     int que[size];//queue
     int front, rear;
   public:
     PizzaQue()
      {
        front=-1;
        rear=-1;
      }
     int Qfull();
     int Qempty();
     int Accept(int);
     int Ready();
     void Display();
};
 int PizzaQue::Qfull()
   {
     if(front==(rear+1)%size)
         return 1;
     else
         return 0;
   }

int PizzaQue::Qempty()
   {
     if(front==-1)
        return 1;
     else
        return 0;
   }

int PizzaQue::Accept(int item)
   {
	     if(front==-1)
	         front=rear=0;
	     else
	    	 rear=(rear+1)%size;

	     que[rear]=item;
	     return rear;

   }

int PizzaQue::Ready()
   {
		cout<<"\n The order no : "<<que[front]<<" is Ready";
		if(rear==front)
				rear=front=-1;
		else
			    front=(front+1)%size;
   }

void PizzaQue:: Display()
   {
    int i;
    i=front;
     while(i!=rear)
     {
         cout<<" "<<que[i];
         i=(i+1)%size;
     }
     cout<<" "<<que[i];
   }

int main()
{
  int choice,item;
  PizzaQue obj;
  do
  {
     cout<<"\n Main Menu";
     cout<<"\n 1.ADD Order \n 2.Ready Order \n 3. Display Order Queue";
     cout<<"\n Enter Your Choice";
     cin>>choice;
     switch(choice)
     {
        case 1: if(obj.Qfull())
                    cout<<"\n Can not accept order";
                else
                 {
                   cout<<"\n Enter The order number: ";
                   cin>>item;
                   obj.Accept(item);
                 }
                break;
        case 2: if(obj.Qempty())
                    cout<<"\n No Order Ready";
                else
                   obj.Ready();
                break;

        case 3: if(obj.Qempty())
                    cout<<"\n Order queue is empty";
                else
                   obj.Display();
                break;
        default : cout<<"\n wrong choice";
      }

  }while(choice<=3);
}