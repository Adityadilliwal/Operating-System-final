#include<iostream>
using namespace std;
#define max 10
class process
{ 
   public:
   	int n,pr[max],bt[max],ct;
   	float at[max],tat,wt,avgtat,avgwt,sumtat,sumwt;
   	void getdata()
   	{
   		cout<<"Higher priority is 3"<<endl;
   	   cout<<"Enter the number of processes"<<endl;
	   cin>>n;
	   cout<<"Enter the arrival time of processes"<<endl;
	   for(int i=0;i<=n-1;i++)
	   {
	   cout<<"Process "<<i+1<<" : ";
	   cin>>at[i];
       }
	   cout<<"Enter the burst time of processes"<<endl;
	   for(int i=0;i<=n-1;i++)
	   {
	   cout<<"Process "<<i+1<<" : ";
	   cin>>bt[i];
       }
	   cout<<"Enter the priorities of the processes"<<endl;
	   for(int i=0;i<=n-1;i++)
	   {
	   	cout<<"Process "<<i+1<<" : ";
	    cin>>pr[i];
	   } 	  	
	}
	void timecalcu()
	{
		int temp;
		for (int i=0;i<=n-1;i++) 
		{
      for (int j=i+1;j<=n-1;j++) 
	  {
         if (pr[i]>pr[j]) 
		 {
            temp=pr[j];
            pr[j]=pr[i];
            pr[i]=temp;
			temp=bt[j];
            bt[j]=bt[i];
            bt[i]=temp;
            for(int i=0;i<n;i++)
		{
			if(ct>at[i])
			{
			ct+=bt[i];
			tat=ct-at[i];
			wt=tat-bt[i];
			cout<<"Process "<<i+1 <<" : "<<endl;
			cout<<"Turn around time is : "<< tat<<endl;
			cout<<"Waiting time is     : "<< wt<<endl<<endl<<endl;		
		    }
		else
		{
			ct=at[i]+bt[i];
			tat=ct-at[i];
			wt=tat-bt[i];
			cout<<"Process "<<i+1 <<" : "<<endl;
			cout<<"Turn around time is : "<< tat<<endl;
			cout<<"Waiting time is     : "<< wt<<endl<<endl<<endl;		
		}
		sumtat+=tat;
		sumwt+=wt;
	}
	avgtat=sumtat/n;
	avgwt=sumwt/n;
	cout<<"Average turn around time : "<< avgtat<<endl;
	cout<<"Average waiting time     : "<< avgwt<<endl;
         }
      }
   		}
	}	
};
int main()
{
	process p;
	p.getdata();
	p.timecalcu();
}
