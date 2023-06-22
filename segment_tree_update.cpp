#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int N = (int)2e5 + 7;
int n,q;
ll t[4*N];
 
void upd(int nod,int tl,int tr,int p,int val)
{
        if(tr<p || p<tl) return;
        if(tl==tr)
        {
                t[nod]=val;
        }
        else
        {
                int tm=(tl+tr)/2;
                upd(2*nod,tl,tm,p,val);
                upd(2*nod+1,tm+1,tr,p,val);
                t[nod]=t[2*nod]+t[2*nod+1];
        }
}
 
ll get(int nod,int tl,int tr,int l,int r)
{
        if(tr<l||r<tl)return 0;
        if(l<=tl && tr<=r)
        {
                return t[nod];
        }
        else
        {
                int tm=(tl+tr)/2;
                return get(2*nod,tl,tm,l,r)+get(2*nod+1,tm+1,tr,l,r);
        }
}
 
int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
 
        cin>>n>>q;
        for(int i=1;i<=n;i++)
        {
                int x;
                cin>>x;
                upd(1,1,n,i,x);
        }
        for(int i=1;i<=q;i++)
        {
                int t;
                cin>>t;
                if(t==2)
                {
                        int l,r;
                        cin>>l>>r;
                        cout<<get(1,1,n,l,r)<<"\n";
                }
                else
                {
                        int p,x;
                        cin>>p>>x;
                        upd(1,1,n,p,x);
                }
        }
 
}
