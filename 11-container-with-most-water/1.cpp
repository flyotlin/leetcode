class Solution {
public:
    int maxArea(vector<int>& height) {
        int x = 0, y = height.size() - 1;
        int max_area = 0;
        while (x < y) {
            int current_area = (y - x) * min(height[x], height[y]);
            max_area = max(max_area, current_area);

            if (height[x] < height[y]) {
                x++;
            } else {
                y--;
            }
        }
        return max_area;
    }
};