/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int head = 0;
        int tail = height.size() - 1;
        int water = 0;
        while (head < tail) {
            if (height[head] < height[tail]) {
                water = height[head] * (tail - head);
                head++;
            }
            else {
                water = height[tail] * (tail - head);
                tail--;
            }
            if (water > maxWater) maxWater = water;
        }
        return maxWater;
    }
};