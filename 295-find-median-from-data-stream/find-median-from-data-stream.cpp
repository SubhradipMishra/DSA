class MedianFinder {
public:
        priority_queue<int>left ; 
        priority_queue<int,vector<int>,greater<int>>right ;
    
    void addNum(int num) {
       

        if(left.size() == 0 || left.top() > num) left.push(num);
        else right.push(num) ;

        if(left.size() >  right.size() +1)
        {
            right.push(left.top());
            left.pop() ; 
        }
        
        if(right.size() >  left.size() +1)
        {
            left.push(right.top());
            right.pop() ; 
        }


    }
    
    double findMedian() {
        if(left.size() == right.size() ){
            return (left.top() + right.top())/2.0 ; 
        }
        else{
            if(left.size() >  right.size()) return left.top() ; 
            else return right.top() ;
        }
    }
};

