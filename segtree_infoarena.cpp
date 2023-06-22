#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class aint{
private:

    vector<int> tree;
    int n;

    void build(int node, int l, int r, const vector<int> &data){
        if (l == r){
            tree[node] = data[l];
        } else {
            int m = (l + r) / 2;

            build(2 * node, l, m, data);
            build(2 * node + 1, m + 1, r, data);

            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(int node, int l, int r, int p, int value){
        if (l == r){
            tree[node] = value;
        } else {
            int m = (l + r) / 2;

            if (p <= m){
                update(2 * node, l, m, p, value);
            } else {
                update(2 * node + 1, m + 1, r, p, value);
            }

            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int node, int l, int r, int x, int y){
        if (x <= l && r <= y){
            return tree[node];
        } else {
            int m = (l + r) / 2;
            int answer = numeric_limits<int>::min();

            if (x <= m){
                answer = max(answer, query(2 * node, l, m, x, y));
            }

            if (m < y){
                answer = max(answer, query(2 * node + 1, m + 1, r, x, y));
            }

            return answer;
        }
    }

public:

    aint(const vector<int> &data) {
        this->n = data.size();
        this->tree.resize(4 * n);
        build(1, 0, n - 1, data);
    }

    void update(int p, int v){
        update(1, 0, n - 1, p - 1, v);
    }

    int query(int x, int y){
        return query(1, 0, n - 1, x - 1, y - 1);
    }
};

int main()
{
    ifstream in("arbint.in");
    ofstream out("arbint.out");

    int n, m;
    in >> n >> m;

    vector<int> data(n);

    for (int &x: data)
        in >> x;

    aint a_int(data);

    while (m--){
        int t, x, y;
        in >> t >> x >> y;

        if (t == 0){
            out << a_int.query(x, y) << "\n";
        } else {
            a_int.update(x, y);
        }
    }

    in.close();
    out.close();

    return 0;
}
