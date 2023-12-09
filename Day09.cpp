//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    bool isPrime(int n){
        if(n==2 || n==3)
            return true;
        if(n%2 == 0 || n%3 == 0)
            return false;
        for(int i=5; i*i<=n; i+=6){
            if(n%i==0 || n%(i+2)==0)
                return false;
        }
        return true;
    }
    
    int sumOfDigits(int num) {
        int sum = 0;
        while(num > 0) {
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }
    
    int sumOfPrimeFactor(int num) {
        int sum = 0, flag = 0, i = 2, pro = 1;
        while(num > 1) {
            i++;
            if(!isPrime(i)) continue;
            if(num % i == 0) {
                while(num % i == 0) {
                    sum += sumOfDigits(i);
                    pro += i;
                    num /= i;
                    if(num < 1) break;
                }
            }
            i++;
            if(!isPrime(i)) {
                continue;
            }
        }
        return sum;
    }
    
    int sumOfPrimeFactor2(int n){
        int f = 1;
        int sum = 0;
        while(n > 1){
            ++f;
            if(!isPrime(f))
                continue;
                
            while(n % f == 0){
                sum += sumOfDigits(f);
                n /= f;
            }
        }
        return sum;
    }
    
    int smithNum(long long n) {
        if(isPrime(n)) return 0;
        return (sumOfPrimeFactor2(n) == sumOfDigits(n));
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends
