class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        const int n = dist.size();
        vector<int> bucket(100001, 0);

        for(int i = 0;i < n;i++) {
            int t = ceil((float) dist[i] / (float) speed[i]);
            bucket[t]++;
        }

        int kills = 0, shots = 1;
        for(int i = 0;i < bucket.size() && kills < n;i++) {
            if(bucket[i] > shots) {
                return kills + shots;
            }

            if(bucket[i] != 0) {
                shots -= bucket[i];
                kills += bucket[i];
            }

            if(i != 0) shots++;
        }

        return n;
    }
};