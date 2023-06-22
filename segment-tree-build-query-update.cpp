/*
 *  Selected Topic:  Segment Tree Data Structure
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> segtree;

void build(int node, int lo, int hi, const vector<int> &source) {

             if(lo == hi) {

                segtree[node] =  source[lo];

                return;

             }

             int middle = (lo+hi)/2;

             build(2 * node, lo, middle, source);

             build(2 * node + 1, middle + 1, hi, source);

             segtree[node] = segtree[2 * node] + segtree[2 * node + 1];
}

void update(int node, int lo, int hi, int pos, int value) {

  if(pos > hi || pos < lo) return;

  if(lo == hi) {

     segtree[node] = value;

     return;

  }

  int middle = (lo+hi)/2;

  update(2 * node, lo, middle, pos, value);

  update(2 * node + 1, middle + 1, hi, pos, value);

  segtree[node] = segtree[2 * node] + segtree[2 * node + 1];

}

int query(int node, int lo, int hi, int left, int right) {

           if(lo >= left && hi <= right) {

              return segtree[node];
           }

           if(lo > right || hi < left) return 0;

           int middle = ( lo + hi ) / 2;

           return query(2 * node, lo, middle, left, right) +

                  query(2 * node + 1, middle + 1, hi, left, right);
}

//function main
int main(int argc, char const *argv[]) {

  //declare an vector container
  vector<int> data;

  //assign an array of elements
  data = {0,1,2,3,4,5,6,7,8,9,10};

  //get the size of the source data
  int n = data.size()-1;

  //resize the segment tree
  segtree.resize(4 * n);

  //construct the Segment Tree in the memory
  build(1, 1, n, data);

  //display the array
  for(vector<int>::iterator it = data.begin()+1; it!=data.end(); it++) cout<<*it<<" ";

  int x = 1, y = 10;

  cout<<"Sum["<<x<<","<<y<<"]="<<query(1, 1, n, x, y)<<endl;

  update(1, 1, n, 10, 0);
  
  update(1, 1, n, 9, 0);

  cout<<"Sum["<<x<<","<<y<<"]="<<query(1, 1, n, x, y)<<endl;

  return 0;
}
