#include<iostream>
#define m 100
using namespace std;
class Bankers
{
	public:
		int process,resource,allocation[m][m],max[m][m],available[m],need[m][m],finish[m],work[m];
		void getdata()
		{
			cout<<"Enter number of processes"<<endl;
			cin>>process; 
			cout<<"Enter number of resources"<<endl;
			cin>>resource; 
			cout<<"Enter Allocation Matrix:\n";
			for(int i=0;i<process;i++)
			{
				for(int j=0;j<resource;j++)
					cin>>allocation[i][j];
			}
			
			cout<<"Enter Max Matrix"<<endl;
			for(int i=0;i<process;i++)
			{
				for(int j=0;j<resource;j++)
					cin>>max[i][j];
			}
			
			cout<<"Enter Availability "<<endl;
			for(int j=0;j<resource;j++)
				cin>>available[j];
		}
		void bankersalgo()
		{
			
			for(int i=0;i<process;i++)
				finish[i]=0;
			
			for(int i=0;i<process;i++)
			{
				for(int j=0;j<resource;j++)
				{
					need[i][j]=max[i][j]-allocation[i][j];	
				}
			} 
			int counter=0;
    		for (int k=0;k<resource;k++)
			{ 
        		for(int i=0;i<process;i++)
				{ 
            		if(finish[i]==0)
					{ 
                		int flag=0; 
                		for (int j=0;j<m;j++)
						{ 
                    		if(need[i][j]>available[j]) 
                        		flag=1; 
                    		break;
						} 
                		if (flag==0)
						{ 
                			work[counter++]=i; 
                			for(int y=0;y<m;y++) 
                				available[y]+=allocation[i][y]; 
                    		finish[i]=1; 
               			} 
            		} 
        		} 
    		}	
		for(int i=0;i<process;i++)
		{
			if(finish[i]==1)
				cout<<"It is a Safe Sequence"<<endl;
			break;
			if(finish[i]==0)	
				cout<<"It is not a Safe Sequence"<<endl;
			break;	
		}			
	}
	void printwork()
	{
		int sumalloc=0,sumwork=0;
		for(int i=0;i<resource;i++)
		{
			for(int j=0;j<process;j++)
			{
				sumalloc=sumalloc+allocation[j][i];
				sumalloc=sumalloc+available[i];
			}
			cout<<sumalloc;
		}
		
	}
};
int main()
{
	Bankers b;
	b.getdata();
	b.bankersalgo();
	b.printwork();
	return 0;
}
