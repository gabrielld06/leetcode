class Solution {
public:
    int binSearch(int n, int k, int x, int b, int e) {
        if(n == 1) return x;

        int m = (b + e - 1) / 2;
        if(x == 0) {
            // 0 1
            // if(b == k) return 0; 
            // if(e == k) return 1; 
            if(k > m) {
                return binSearch(n-1, k, 1, m+1, e);
            } else {
                return binSearch(n-1, k, 0, b, m);
            }
        } else {
            // 1 0
            // if(b == k) return 1; 
            // if(e == k) return 0;
            if(k > m) {
                return binSearch(n-1, k, 0, m+1, e);
            } else {
                return binSearch(n-1, k, 1, b, m);
            }
        }
    }

    int kthGrammar(int n, int k) {
        int e = pow(2, n-1);

        return binSearch(n, k, 0, 1, e);
    }
};