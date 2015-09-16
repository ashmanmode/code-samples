#include <math.h>
#include <bits/stdc++.h>
using namespace std;
double A[1000];
int ones[1000];
int main()
{
	freopen("B-large (1).in","r",stdin);
	int t;
	cin>>t;
	for(int test=1;test<=t;test++)
	{
		int N,M;
		cin>>N>>M;
		double s=0.0;
		int o=0;
		for(int i=0;i<N;i++)
		{
			int x;
			cin>>x;
			if(x==1)
			{
				o++;
			}
			ones[i]=o;
			double X=x;
			double a=log10(X);
			s+=a;
			A[i]=s;
		}
		printf("Case #%d: \n",test);
		while(M--)
		{
			int l,r;
			cin>>l>>r;
			double ans;
			if(l>0)
			{
				int uu=ones[r]-ones[l-1];
				if(uu==r-l+1)
				{
					ans=1.0;
				}
				else
				{
					ans=A[r]-A[l-1];
					double nn=r-l+1;
					ans/=nn;
					ans=pow(10.0,ans);
				}
			}
			else
			{
				int uu=ones[r];
				if(uu==r+1)
				{
					ans=1.0;
				}
				else
				{
					ans=A[r];
					// cout<<ans<<endl;
					double nn=r+1;
					// printf("%lf\n%lf\n",nn,ans);
					ans/=nn;
					ans=pow(10.0,ans);
				}
			}
			printf("%.9lf\n",ans);
		}
	}
	return 0;
}