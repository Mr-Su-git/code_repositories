#include <bits/stdc++.h>

using namespace std ;

bool is_prime(long long i){
    for(long long j = 2 ; j *j <= i ; j++){
        if(i % j == 0)return false ;
    }
    return true ;
} ;

int main(){
    long long n = 0 ;
    vector<long long>s(n+1 , 0) ;
    scanf("%lld" , &n) ;
    for(long long i = 1 ; i <= n ; i++){
        scanf("%lld" , &s[i]) ;
        s[i] = s[i-1] + s[i] ;
    }

    long long ans = INT_MIN ;
    for(long long length = 2 ; length <= n ; length++){
        if(is_prime(length)){
            for(long long i = length ; i <= n ; i++){
                ans = max(ans , s[i] - s[i - length]) ;
            }
        }
    }

    printf("%lld" , ans) ;
    return 0 ;
}