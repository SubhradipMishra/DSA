class Solution {
public:

    int calculateGCD(int a , int b){
        while(b!=0){
            int temp = b ; 
            b =  a%b ;  
            a = temp ; 
        }

        return a;
    }
    int gcdOfOddEvenSums(int n) {
        int evenSum = 2 ; 
        int digit = 2; 
        int count = 1 ; 
        while(count <= n ){
         digit +=2 ;
         evenSum+=digit ; 
         count++ ; 
            
        }

        int oddSum = 1 ;
         digit = 1 ;
        count = 1 ;
        while(count <= n ){
            digit += 2 ;
            oddSum += digit;
            count++; 

        }

        int gcd =  calculateGCD(evenSum  , oddSum);

        return gcd-1 ; 
    }
};