class Solution {
public:
    int returnDays(vector<int>& weights, int cap) {
        int days = 1, load = 0;

        for (int w : weights) {
            if (load + w > cap) {
                days++;
                load = w;
            } else {
                load += w;
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int D) {
        int mx = *max_element(weights.begin(), weights.end());
        int sum = accumulate(weights.begin(), weights.end(), 0);

        int low = mx;
        int high = sum;

        while (low < high) {
            int mid = low + (high - low) / 2;

            int requiredDays = returnDays(weights, mid);

            if (requiredDays <= D)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};