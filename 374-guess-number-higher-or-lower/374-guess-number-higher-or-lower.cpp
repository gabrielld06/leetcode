/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int b = 1, e = n, mid;
        
        while(b < e) {
            mid = b + (e - b) / 2;
            
            if(guess(mid) > 0) b = mid + 1;
            else if(guess(mid) < 0) e = mid;
            else return mid;           
        }
        
        return e;
    }
};