class CustomStack {
public:
    stack<int>st;
    int K;
    int currCount =0;
    CustomStack(int maxSize) {
        K  = maxSize;
    }
    
    void push(int x) {
        if(currCount==K){
            return;
        }
        st.push(x);
        currCount++;
    }
    
    int pop() {
        if(st.empty()){
            return -1;
        }
        int x = st.top();
        st.pop();
    
        currCount--;
        return x;
    }
    
    void increment(int k, int val) {
        vector<int>v;
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<k&& i<v.size();i++){
            v[i]+=val;
        }
        for(int i=0;i<v.size();i++){
            st.push(v[i]);
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */