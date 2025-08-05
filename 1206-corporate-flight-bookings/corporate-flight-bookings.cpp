class Solution {
public:
    void helper(vector<int>& colSum , int first , int last , int seat){
        for(int i = first ; i <= last ; i++){
            colSum[i] += seat ; 
        }
    }

    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int row = bookings.size(); 
        int col = n;

        vector<int> colSum(n, 0); 

        for(int i = 0 ; i < row ; i++ ){
            int first = bookings[i][0] - 1; 
            int last  = bookings[i][1] - 1; 
            int seat  = bookings[i][2];

            helper(colSum, first, last, seat); 
        }

        return colSum; 
    }
};
