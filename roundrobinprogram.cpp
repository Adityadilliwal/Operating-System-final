#include<iostream>
#define max 100
using namespace std;
int main()
{
//number of process
  int n;
  	int wt[max],bt[max],tat[max],quantum=0,t=0,remainingbt[max];
  cout<<"Enter no. of processes\n\n";
  cin>>n;

	cout<<"Enter burst time\n\n";
	for(int i=0;i<n;i++) {
			cin>>bt[i];	
	remainingbt[i]=bt[i];
	}

//time quantum
cout<<"Enter time quantum\n\n";
cin>>quantum;


while(1)
{
	bool done=true;
	for(int i=0;i<n;i++)
	{
		if(remainingbt[i]>0)
		{
			done=false;
			if(remainingbt[i]>quantum)
			{
				 t=t+quantum;
				remainingbt[i]=remainingbt[i]-quantum;
			}
			else
			{
				 t=t+remainingbt[i];
				remainingbt[i]=0;
				wt[i]=t-bt[i];
				tat[i]=t;
			}
		}
	}
	if(done==1)
	break;
}
//Result
	cout<<"turn around time"<<"       "<<"waiting time\n"<<endl;
	for(int i=0;i<n;i++)
	cout<<tat[i]<<"             "<<wt[i]<<endl;
	return 0;
}
