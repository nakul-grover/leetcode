class MinStack {
public:
    stack<long long int>st;
    long long int minVal = INT_MAX;
    MinStack() {
    }
    
    void push(int val) {
       if (st.empty()) {
            st.push(val);
            minVal = val;
        } else {
            if (val < minVal) {
                st.push((long long int)2 * val - minVal);
                minVal = val;
            } else
                st.push(val);
        }
    }
    
    void pop() {
        if(minVal>st.top()){
         minVal =  ((2*(long long int)minVal) - st.top());
        }
        st.pop();
    }
    
    int top() {
        if(minVal > st.top()){
            return minVal;
        }
        return st.top();
    }
    
    int getMin() {
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */