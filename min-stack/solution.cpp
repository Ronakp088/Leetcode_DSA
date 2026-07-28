class MinStack {
public:
    stack<long long> st;
    long long mini;
    MinStack() {
    }
    
    void push(long long value) {
        if(st.empty()){
            st.push(value);
            mini = value;
        }
        else {
            if(value >= mini) st.push(value);
            else{
                long long y = (2*(long long)value) - mini;
                st.push(y);
                mini = value;
            }
        }
    }
    
    void pop() {
        long long x= st.top();
        st.pop();
        if(x < mini) mini = 2*mini - x;
    }
    
    long long top() {
        if(mini < st.top()) return st.top();
        else return mini;

    }
    
    long long getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */