#include <bits/stdc++.h>

#define int long long

using namespace std;

const int m=1e9+7;

int fast_pow(int b, int pow){
    if(pow==0){return 1;}
    int res = fast_pow(b, pow/2);
    res=(res*res)%m;
    if(pow%2){res*=b;}
    return res%m;
}

vector<int>fac(1e5+1);
int res(int n, int k){
    if(abs(k)>n){return 0;}
    k=(k+n)/2;
    return (((fac[n] * fast_pow(fac[k], m-2))%m)*fast_pow(fac[n-k], m-2))%m;
}

int fast_chocolate(vector<string>a, int n){
    fac[0]=1;
    for (int i = 1;i <= 1e5; ++i) {
        fac[i]=fac[i-1]*i;
        fac[i]%=m;
    }
    int equals = 1;
    vector<int>lon(3);
    for (int i = 0; i < n; ++i) {
        if(a[1][i]==a[2][i]&&a[0][i]==a[1][i]){equals*=2;
            continue;}
        if(a[1][i]==a[2][i]){lon[0]++;}
        if(a[0][i]==a[2][i]){lon[1]++;}
        if(a[0][i]==a[1][i]){lon[2]++;}
        equals%=m;
    }
    if(lon[0]%2!=lon[1]%2||lon[0]%2!=lon[2]%2){
        return 0;
        //cout << 0;
        //exit(0);
    }

    int count=0;
    for (int k = -n/3; k <= n/3; k+=2) {
        int tmpRes=1;
        for (int i = 0; i < 3; ++i) {
            tmpRes*=res(lon[i], k);
            tmpRes%=m;
        }
        count+=tmpRes;
        count%=m;
    }

    return (count*equals)%m;
}

int bruteforce(string a, string b, string c){
    vector<string>ds;
    int count = 0;
    for (int i = 0; i < 1e8; ++i) {
        int curI=i;
        string d="";
        int pow=1;
        while (curI){
            if(curI%(2*pow)||pow==curI){
                d='1'+d;
                curI-=pow;
            } else{
                d='0'+d;
            }
            pow*=2;
        }
        if(d.size()>a.size()){ break;}
        while (d.size()<a.size()){
            d='0'+d;
        }
        int e=0,f=0,g=0;
        for (int i = 0; i < a.size(); ++i) {
            e+=a[i]==d[i];
            f+=b[i]==d[i];
            g+=c[i]==d[i];
        }

        if(e==f&&e==g){
            count++;
            ds.push_back(d);
        }
    }

    return count;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string>a(3);
    for (int i = 0; i < 3; ++i) {
        cin >> a[i];
    }

    cout << /*bruteforce(a[0],a[1], a[2]) << "\n" << */ fast_chocolate(a,n);
/*
    for (int i = 0; i < pow(2, 8); ++i) {
        for (int j = 0; j < pow(2,8); ++j) {
            for (int k = 0; k <= pow(2,8); ++k) {
                vector<int>c={i,j,k};
                vector<string>a(3, "000000");
                for (int x = 0; x < 3; ++x) {
                    for (int y = 0; y < 8; ++y) {
                        if((c[x]>>y)&1){
                            a[x][y]='1';
                        }
                    }
                }
                if(bruteforce(a[0], a[1], a[2])!=fast_chocolate(a,a[0].size())){
                    cout << a[0] << "\n" << a[1] << "\n"<< a[2]<<"\n\n\n";
                }
            }
        }
    }*/
}