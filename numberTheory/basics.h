#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>
T binpow(T a, T b , const T MOD) { // O(logn) exponentiation 
    T ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

template <typename T >
T lcm( T a , T b){
    return (a/gcd(a,b) * b);

}
template<typename T >
T recursive_ex_gcd(T a ,T b , T&x, T&y){ // recursive implementation 
    if ( b == 0){ // when b = 0 , [x=1 , y =0] 
        x = 1 ;
        y = 0 ;
        return a;
    } 
    T x1 , y1;
    T d = recursive_ex_gcd(b , a % b , x1 , y1); //  get the values of x1 and y1 
    x = y1;  
    y = x1 - y1*(a/b);
    return d ;
}
template<typename T >
T ex_gcd( T a , T b , T &x , T&y){ // iterative implementation 
     x = 1 , y = 0 ;
     T x1 = 0 , y1 = 1 , a1 = a , b1 = b;

     while (b1){
         T q = a1/b1;
         tie(x , x1) = make_pair(x1 , x - q*x1);
         tie(y , y1) = make_pair( y1 , y - q*y1);
        tie(a1 , b1) = make_pair(b1 , a1 - q*b1);
     }
     return(a1);
} 

template<typename  T> 
T modinv ( T a , const T m ){ 
    T x ,y ;
    T g = ex_gcd(a , m, x , y);
    if (g!= 1)return -1;
    return (x % m + m)%m;
}
template <typename  T>
bool hassolution(T a , T b ,T c){
    return (c % gcd(a,b) == 0);
}
    
    




