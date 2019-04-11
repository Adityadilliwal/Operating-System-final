#include<iostream>
#define max 2000
using namespace std;
class FirstFit
{
	public:
		int p,block,blocksize[max],psize[max];
		void getData()
		{
			cout<<"Enter number of blocks ";
			cin>>block;
			cout<<"Enter  Block Size"<<endl;
			for(int i=0;i<block;i++)
				cin>>blocksize[i];
			cout<<"Enter number of process"<<endl;
			cin>>p;
			cout<<"Enter Process size"<<endl;
   			for(int i=0;i<p;i++)
				cin>>psize[i];
		}
		void firstFit()
		{
			for(int i=0;i<p;i++)
			{
				int flag=1;
	 			for(int j=0;j<block;j++)
				 {
	   				if(psize[i]<=blocksize[j]){
	   				flag=0;
	   				cout<<" process number="<<i+1<<endl;
	   				cout<<"Space allocated in Block number="<<j+1<<endl;
					blocksize[j]=psize[i];		
					break;
				}	
	  		}
	  		if(flag==1)
	  		cout<<"Process "<<i+1<<" is not allocatd"<<endl;
			}			
		}	
};
int main()
{
FirstFit obj;
obj.getData();
obj.firstFit();
return 0;		
}
