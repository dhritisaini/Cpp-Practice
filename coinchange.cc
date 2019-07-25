#include<iostream>
#include<climits>
using namespace std;

int change(int* coins,int n, int amt)  //by recursion
{
	if(amt==0)
		return 0;
	int ans=INT_MAX;

	for(int i=0;i<n;i++)
	{
		if(amt-coins[i]>=0)
		{
			int smallAns=change(coins,n,amt-coins[i]);
			if(smallAns!=INT_MAX)
			{
				ans=min(ans, smallAns+1);
			}
		}
	}
	return ans;
}

int coinsdp(int* coins, int amt, int n)   //by DP
{
	int* dp=new int[amt+1];
	dp[0]=0;

	for(int i=0;i<=amt;i++)
	{
		dp[i]=INT_MAX;
	}

	for(int rupay=1;rupay<=amt;rupay++)
	{
	for(int i=0;i<=n;i++)
	{
		if(rupay-coins[i]>=0)
		{
			int smallans=dp[rupay-coins[i]];
			if(smallans!=INT_MAX)
			{
				dp[rupay]=min(dp[rupay],smallans+1);
			}
		}

	}
}

}



int main()
{
	int coins[]={1,2,5,10,50};
	int n=5;
	int amt=39;
	cout<<coinsdp(coins,n, amt);
}


