class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq ;
        for(int ele : stones){
            pq.push(ele);
        }
        while(pq.size() >1 ){
            int x = pq.top() ;
            pq.pop() ;
            int y = pq.top();
            pq.pop() ; 

            if(x!=y){
                int dis = abs(x-y) ; 
                pq.push(dis) ;
            }
        }

        return pq.size() == 1 ?  pq.top() :  0  ;
    }
};