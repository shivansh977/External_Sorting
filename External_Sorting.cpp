#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <bitset>
#include <cmath>
#define ll int long long
#define makearr int arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
#define For(i,j,n) for(int i=j;i<n;i++)
#define pb push_back
#define mp make_pair
#define pi pair<int,int>
#define pll pair<ll,ll>
#define ri(n) int n; cin>>n;
#define rll(n) ll n; cin>>n;
#define di(n) int n;
#define dll(n) ll n;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ri(b);ri(rpp);ri(tr);
    vector<vector<int>> pages;vector<int> tmp;
    For(i,0,tr){
        ri(val);
        if(tmp.size()==rpp){
            pages.pb(tmp);
            tmp.clear();tmp.pb(val);
        }
        else tmp.pb(val);
    }
    if(!tmp.empty()) pages.pb(tmp);
    tmp.clear();
    int n=pages.size();
    int tot=1;
    int po=0;
    while(tot<n){
        tot*=(b-1);po++;
    }
    For(i,0,tot-n) pages.pb(tmp);
    For(i,0,pages.size()){
        sort(pages[i].begin(),pages[i].end());
    }
    For(i,0,po){
        vector<vector<int>> pagest;
        For(j,0,pages.size()){
            For(k,0,pages[j].size()){
                if(tmp.size()==rpp*pow(b-1,i+1)){
                    pagest.pb(tmp);
                    tmp.clear();tmp.pb(pages[j][k]);
                }
                else tmp.pb(pages[j][k]);
            }
        }
        if(!tmp.empty()) pagest.pb(tmp);
        tmp.clear();
        pages=pagest;
        For(k,0,pages.size()){
            sort(pages[k].begin(),pages[k].end());
        }
        int tpp=pages.size();
        For(k,0,(tot/int(pow(b-1,i+1)))-tpp){
            pages.pb(tmp);
        }
    }
    For(i,0,pages[0].size()){
        cout<<pages[0][i]<<"\n";
    }
    return 0;
}