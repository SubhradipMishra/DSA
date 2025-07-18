class MyStack {
    private: 
    queue<int> q1;
         queue<int> q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x) ;
    }
    
    int pop() {
        while(q1.size()>1){
            q2.push(q1.front()) ; 
            q1.pop() ;

        }
        int x = q1.front() ; 
        q1.pop() ; 
         swap(q1,q2) ; 
        
        return x ; 
     }
    
    int top() {
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop() ;

        }
        int x = q1.front() ; 
         q2.push(x);
         q1.pop() ; 
        while(!q2.empty())
        
        {
          q1.push(q2.front()) ;
          q2.pop() ; 
        }    


        return x; 
    }
    
    bool empty() {
        return q1.size() == 0 ; 
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */