class Solution {
    static boolean isPrime(int n) {
        // code here
        if(n <= 1){
            return false;
        }

        int result= 0;

        for(int i = 1; i * i <= n; i++){  // square root n
            if(n % i == 0){
                result++;

                if((n / i) != i){
                    result++;
                }
            }
        }

        if(result == 2){
            return true;
        }else{
            return false;
        }
    }
}
