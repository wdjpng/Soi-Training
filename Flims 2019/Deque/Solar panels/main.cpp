#include <bits/stdc++.h>

#define int long long

using namespace std;
deque<int>q;
int intersec(pair<int,int>a, pair<int, int>b){
    return -(a.second-b.second)/(a.first-b.first);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>>in;
    in.push_back(make_pair(0,0));
    n++;
    for (int i = 1; i < n; ++i) {
        int c, b;
        cin >> c >> b;
        in.push_back(make_pair(b,-c));
    }

    q.push_back(0);
    for (int i = 1; i < n; ++i) {
        int mem=q.back();
        q.pop_back();
        if(q.size()){
            int a = intersec(in[q.back()], in[mem]);
            int b = intersec(in[q.back()], in[i]);
            int c = a+b;
        }
        while (q.size()&&intersec(in[q.back()], in[mem])>intersec(in[q.back()], in[i])){
            mem=q.back();
            q.pop_back();
        }

        q.push_back(mem);
        if(in[i].first>in[mem].first){
            q.push_back(i);
        }
    }

    vector<bool>take(n);
    for (int i = 0; i < q.size(); ++i) {
        take[q[i]]=true;
    }

    int cost = 0;
    int num = 0;
    for (int i = 0; i < n; ++i) {
        cost+=take[i]*in[i].second;
        num=take[i]*in[i].first;
        cost+=num;
    }

    cout << cost;
}