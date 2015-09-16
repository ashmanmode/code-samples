
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{

int t,n,a,sum=0,flag,i,temp,mn,fg;
vector<int> v,ans;
cin>>t;
while(t--)
{ 
flag=0;sum=0,fg=0;
cin>>n;
for(i=0;i<n;i++)
{
cin>>a;
if(a==n || a<0 || n==1)
flag=1;
sum=sum+a;
v.push_back(a);


}

if(sum>n)
flag=1;

if(flag==1)
cout<<-1<<endl;
else
{

for(i=0;i<n;i++)
{
a=v[i];

while(a--)
{

ans.push_back(i+1);
}
if(ans.size()==n)
break;



}

reverse(ans.begin(),ans.end());
mn=n-1;
for(i=n-1;i>=0;i--)
{

if(ans[i]==i+1)
{
if(ans[i]!=ans[mn]){
temp=ans[mn];
ans[mn]=ans[i];
ans[i]=temp;

mn=i;
}
else
{
fg=i;
}

}

}
if(fg>0)
{ temp=ans[0];
ans[0]=ans[fg];
ans[fg]=temp;}

for(i=0;i<n;i++)
cout<<ans[i]<<" ";
cout<<endl;




}

v.clear();
ans.clear();
}

return 0;

}