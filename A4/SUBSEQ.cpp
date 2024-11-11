#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool subseq(vector<int> &ans,int n,int sum,int fsum,int i){
    if(sum == fsum){
        return true;
    }

    if(i >= n){
        return false;
    }

    bool take = false;

    if(ans[i] + sum < fsum ){
        take = subseq(ans,n,sum + ans[i],fsum,i+1);
    }    

    bool non_take = subseq(ans,n,sum ,fsum,i+1);

    return take | non_take;
}
int main() {
    
    int n;
    vector<int> ans(n);

    for(int i=0;i<ans.size();++i){
        cin>>ans[i];
    }

    int fsum =0 ;
    cin>>fsum;
    cout<<subseq(ans,n,0,fsum,0);

    return 0;
}