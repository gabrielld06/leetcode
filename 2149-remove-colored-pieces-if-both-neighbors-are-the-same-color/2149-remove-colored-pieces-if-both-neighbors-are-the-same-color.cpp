class Solution {
public:
    bool winnerOfGame(string colors) {
        int i = 0, alice = 0, bob = 0;
        while(i < colors.length()) {
            int a = 0;
            while(colors[i] == 'A') {
                a++;
                i++;
            }
            alice += max(a - 2, 0);

            int b = 0;
            while(colors[i] == 'B') {
                b++;
                i++;
            }
            bob += max(b - 2, 0);
        }

        return alice > bob;
    }
};