class Solution {
public:
    void mergersort(vector<int> &a,int l,int r,int mid){
        vector<int> tmp(r-l+1);
        int s=mid+1,i=l,k=0;
        while(i<=mid && s<=r){
            if(a[i]<a[s]){
                tmp[k++]=a[i++];
            }
            else tmp[k++]=a[s++];
        }
        while(i<=mid){
            tmp[k++]=a[i++];
        }
        while(s<=r){
            tmp[k++]=a[s++];
        }
        for(int i=l;i<=r;i++){
            a[i]=tmp[i-l];
        }
    }
    void merge(vector<int> &a,int l,int r){
        if(l>=r) return;
        int mid=(l+r)/2;
        merge(a,l,mid);
        merge(a,mid+1,r);
        mergersort(a,l,r,mid);
    }
    vector<int> sortArray(vector<int>& a) {
        merge(a,0,a.size()-1);
        return a;
    }
};