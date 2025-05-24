#include<bits/stdc++.h>
using namespace std;

class info{
    public:
    int open,close,full;
    info(int _open,int _close,int _full){
        open=_open;
        close=_close;
        full=_full;
    }
    info(){
        open=0;
        close=0;
        full=0;
    }
};

info merge(info left,info right){
    info ans= info(0,0,0);
    ans.open=left.open+ right.open - min(left.open, right.close);
    ans.close=left.close+ right.close - min(left.open, right.close);
    ans.full=left.full+ right.full + min(left.open, right.close);
    return ans;
}

void build(int ind,int low,int high,vector<info> &seg, string &s){
    if(low==high){
        seg[ind]= info(s[low]=='(' , s[low]==')',0);
        return;
    }
    int mid=(low+high)/2;
    build(2*ind+1,low,mid,seg,s);
    build(2*ind+2,mid+1,high,seg,s);
    seg[ind]=merge(seg[2*ind+1],seg[2*ind+2]);
}

info query(int ind,int low,int high,vector<info> &seg, int l, int r){
    if(low>r || high<l) return  info(0,0,0);
    else if(low>=l && high<=r) return seg[ind];
    int mid=(low+high)/2;
    info leftquery=query(2*ind+1,low,mid,seg,l,r);
    info rightquery=query(2*ind+2,mid+1,high,seg,l,r);
    return merge(leftquery,rightquery);
}

int main(){
    string s;
    cin>>s;
    int m;
    cin>>m;
    int n=s.size();
    vector<info> seg(4*n);
    build(0,0,n-1,seg,s);
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        info ans=query(0,0,n-1,seg,l-1,r-1);
        cout<<ans.full*2;
        cout<<endl;
    }
    return 0;
}