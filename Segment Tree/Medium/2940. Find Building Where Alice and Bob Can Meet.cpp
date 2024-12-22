class SGTree {
    vector<int> seg;

public:
    SGTree(int n) {
        seg.resize(4 * n + 1);
    }

    void build(int idx, int low, int high, vector<int>& arr) {
        if (low == high) {
            seg[idx] = arr[low];
            return;
        }
        int mid = low + (high - low) / 2;
        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);
        seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    int query(int idx, int low, int high, int l, int r) {
        if (high < l || low > r)
            return -1;
        if (low >= l && high <= r) {
            return seg[idx];
        }
        int mid = low + ((high - low) / 2);
        int left = query(2 * idx + 1, low, mid, l, r);
        int right = query(2 * idx + 2, mid + 1, high, l, r);
        return max(left, right);
    }

    
};

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& h, vector<vector<int>>& queries) {
        int q = queries.size();
        int n = h.size();
        SGTree seg(n);
        seg.build(0, 0, n - 1, h);
        vector<int>ans;
        for(int i=0;i<q;i++){
            int h1 = queries[i][0];
            int h2 = queries[i][1];
            if(h1==h2||h[max(h1,h2)]>h[min(h1,h2)]){
                ans.push_back(max(h1,h2));
            }else{
                int maxHeight = max(h[h1],h[h2]);
                int l =max(h1,h2)+1;
                int r = n-1;
                int curr= -1;
                while(l<=r){
                    int mid = l+(r-l)/2;
                    int mx = seg.query(0,0,n-1,l,mid);
                    if(mx>maxHeight){
                        curr  = mid;
                        r = mid-1;
                    }else{
                        l=mid+1;
                    }
                }
                ans.push_back(curr);
            }
        }
        return ans;
    }
};