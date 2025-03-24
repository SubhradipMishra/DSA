class Solution {
public:
    int fib(int n) {
        int  p2 =  0 ;
        int  p1 =  1;
        if(n )
        for(int i  =  2 ; i <=  n ;i++){
            int curri = p2 + p1  ; 
            p2 = p1 ;
            p1 = curri ; 
        }


        return (n == 0  )? p2 :p1 ; 
     }
};