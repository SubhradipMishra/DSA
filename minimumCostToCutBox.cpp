#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;  

bool cmp(int x , int y){
    return x >  y; 
}
int findMinimumCost(int n   ,  int m ,vector<int> verticle , vector<int>horizontal){
  sort(verticle.begin() ,  verticle.end() , cmp) ; 
  sort(horizontal.begin() , horizontal.end()  , cmp) ; 
  int hz = 1; // horizontal cut count 
  int vr = 1 ;  // verticle cut count  

  int h  =  0  ; 
  int v = 0 ; 

  int totalCost =  0 ;
  while(h  < horizontal.size()  && v  < verticle.size() ){
     if(verticle[v] > horizontal[h]){
        totalCost+= verticle[v]*vr ; 
        hz++ ; 
        v++ ; 
     }
     else{
      totalCost+= horizontal[h]*hz ; 
      vr++;
      h++ ; 
     }
  }

  while(h < horizontal.size() ) {
    totalCost+= horizontal[h]*hz ; 
    vr++;
    h++ ; 
  }

  while(v <  verticle.size()){
    totalCost+= verticle[v]*vr ; 
    hz++ ; 
    v++ ; 
  }


  return  totalCost ; 
} 



int main(){
    int n ; 
    cin >> n ;  
    vector<int>verticle(n);  
    int m ;
    cin >> m ; 
    vector<int>horizontal(m) ;


    // verticle array

    for(int i   = 0 ;  i  <  n - 1  ; i++){
        cin >> verticle[i] ; 
    }


    // horizontal array 

    for(int i  =  0  ; i  < m -1  ; i++) {
        cin >> horizontal[i] ; 

        
    }


    // find the minimum  cost

    cout << findMinimumCost(n , m  , verticle, horizontal)  ; 



    
    


}