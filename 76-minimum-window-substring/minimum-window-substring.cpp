class Solution {
public:
    string minWindow(string s, string t) {
        
        //find the length of the both string
         
         int n = s.size() ; 
         int m = t.size() ; 

         // create all the needed variables and data structure

         int i  =  0; // for shrinking the window
         int j  = 0 ; // for expand the window 
         int count = 0 ; // it store how much character of 't' is found in the substring of 's' .
         int minLen = INT_MAX ; // it stores the length of the minimum substring
         int sIdx = -1 ; // it indicates the starting index of substring

         map<char,int>mp ; // we use it to maintain the frequency

         // store all the character's frequency of 't' string
         for(char ch : t){
             mp[ch]++;
         }

         while(j < n ){
           // check the frequncy of s[j]  in map if it is positve(> 0 ) means it is a element of 't' string -> so we increae the count by 1 and decease the frequency by one  because we take it  and we find it

           if(mp[s[j]] > 0 ){ 
            count++ ;
             }
           mp[s[j]]-- ; 

           // if count == m (t.size())  means all the element of 't' is find in the substring of 's' . so we need to check a) if the length of  the current substring is less then previous length so we need to upadate the minLen and starting point(sIdx) 
    

    // b) in question we need to find the minimum length substring so we need to shrink the window for this we would increase the freqency ofs[i] (mp[s[i]]++) because we exclude it and if the frequency becomme positive(>0 ) means we exclude the all freqncy of a  character of 't' 
    


           while(count == m ){
             if(minLen > j -i +1) 
             {  sIdx = i ; 
                minLen = j - i +1 ;
               
             }

             // shrink the window
             mp[s[i]]++;
             if(mp[s[i]] > 0 ) { 
                count --; 
            }
             
             i++ ;
             
           }


           // expand the window

           j++ ;
            

         }

         // if the sIdx == -1 meanse no substring present in 's' which contains all the character of 't' so return a empty string and if not then return the substrig from starting index to sIdx + minLen ; 

         return sIdx == -1 ? "" : s.substr(sIdx,minLen) ; 
    }
};