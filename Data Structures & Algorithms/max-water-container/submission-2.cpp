class Solution {
   public:
    int maxArea(vector<int>& heights) {
        // Guard against 0 and 1 length vectors
        if (heights.size() < 2) {
            return 0;
        }
        // Set 'pointers'
        int l = 0;
        int r = heights.size() - 1;

        // Current water fill max
        int max_l = l;
        int max_r = r;
        int max_vol = 0;

        // Iterate using two pointer alg
        while (l < r) {

            const int min_height = heights[l] < heights[r] ? heights[l] : heights[r];
            const int this_vol = min_height * (r - l);
            
            // New largest water container found!
            if (this_vol > max_vol) {
                cout << l << " " << r << endl;
                max_l = l;
                max_r = r;
                max_vol = this_vol;
            }
            
            // Move shorter bar's pointer inwards
            if (heights[l] < heights[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return max_vol;
    }
};
