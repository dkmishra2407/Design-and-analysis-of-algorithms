#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void subseq(vector<ll>&arr,ll fsum,ll i,ll sum,vector<ll> &ans){
    if(sum == fsum){
        for(auto it:ans){
            cout << it << " ";
        }
        cout << endl;

        return;
    }

    if(i >= arr.size() -1  || sum > fsum){
        return;
    }

    ans.push_back(arr[i]);
    subseq(arr,fsum,i+1,sum + arr[i],ans);
    
    ans.pop_back();
    subseq(arr,fsum,i+1,sum,ans);
}
int main() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll sum = 0;
    cin>>sum;
    vector<ll> ans;
    subseq(arr,sum,0,0,ans);
    return 0;
}
