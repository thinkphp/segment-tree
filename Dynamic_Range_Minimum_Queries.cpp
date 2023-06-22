#include <bits/stdc++.h>
 
#define LL long long
 
using namespace std;
 
const int N = 200200;
 
int n,m;
int a[N],t[4 * N];
 
void build( int x, int l, int r )
{
    if( l == r ){
        t[x] = a[l];
        return;
    }
    int k = ( l + r ) / 2;
    build( x * 2, l , k );
    build( x * 2 + 1 , k + 1, r );
    t[x] = min( t[x*2] , t[x*2+1] );
}
 
int get( int x,int l , int r , int tl , int tr )
{
    if( tl > tr ){
        return 2e9;
    }
    if( tl == l && tr == r ){
        return t[x];
    }
    int k = ( l + r ) / 2;
    return min( get( x * 2, l , k , tl , min(k,tr) ) , get( x * 2 + 1 , k + 1, r , max(k+1,tl) , tr ) );
}
 
void upd( int x ,int l ,int r , int g , int y )
{
    if( l == r ){
        t[x] = y;
        return;
    }
    int k = ( l + r ) / 2;
    if( k >= g ){
        upd( x * 2 , l , k , g , y );
    }
    else{
        upd( x * 2 + 1, k + 1, r , g , y );
    }
    t[x] = min( t[x*2] , t[x*2+1] );
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    //freopen( "input.txt" , "r" , stdin );
    //freopen( "output.txt" , "w" , stdout );
 
    cin>>n>>m;
    for( int i=1; i<=n; i++ ){
        cin>>a[i];
    }
    build(1,1,n);
    for( int i=1; i<=m; i++ ){
        int x,y,z;
        cin>>x>>y>>z;
        if( x == 1 ){
            upd( 1 , 1 , n , y, z );
        }
        else{
            cout<<get( 1 , 1 , n , y , z )<<endl;
        }
    }
}
