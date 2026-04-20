class NumArray {
public:
    vector<int>st; 
    vector<int>arr;
    int len ;
    NumArray(vector<int>& nums) {
        int n = nums.size() ;
        len = n ;  
        st.resize(4*n) ; 
        arr = nums;

        build(0 ,  0 , n-1) ; 
    }

    void build(int node , int left , int right){
        if(left == right){
            st[node] = arr[left] ;
            return ; 

        }

        int mid = (left +  right)/2;
        build(2*node+1 , left , mid) ;
        build(2*node+2 , mid + 1 , right) ; 

        st[node] = st[2*node+1] + st[2*node+2] ; 
    }
    void solve_update(int node , int left  ,int right , int idx , int val){
     if(left == right){
        st[node] = val ; 
        arr[idx] = val ; 

        return ; 
     }

     int mid = (left + right)/ 2; 
     if( idx <= mid)
        solve_update(2*node+1  , left , mid , idx , val) ;
     else
         solve_update(2*node+2  ,mid+1 , right , idx , val) ;

    st[node] = st[2*node+ 1 ] + st[2*node+2] ;
     
     
    }
    void update(int index, int val) {
     solve_update(0 ,   0 , len-1 , index ,val) ;    
    }
    
    int solve_sum(int node , int left , int right , int l , int r){
       // no overlap [ (l,r)  [left ,right] , (l,r)] 
       if(r < left  or right < l ) return  0 ;
       // complete overlap [ [left (l rright ) r] ]
        if(l <= left && right <= r) return st[node];

        int mid = (left +  right) /2  ;

        return solve_sum(2*node+1 , left ,  mid ,  l , r) 
         +   solve_sum(2*node+2 , mid+1 ,  right ,  l , r)  ; 

       
    }
    int sumRange(int left, int right) {
        return solve_sum(0 ,  0 , len-1  , left, right ) ; 
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */