/*
There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int start1 = 0;
        int end1 = (int)(nums1.size()) - 1;
        int start2 = 0;
        int end2 = (int)(nums2.size()) - 1;
        int len = (nums1.size() + nums2.size() + 1) / 2;
        int s = 0;
        int e = 0;
        for (int i = 0; i < len; i++) {
            if (start1 >= nums1.size())
                s = nums2[start2++];
            else if (start2 >= nums2.size())
                s = nums1[start1++];
            else if (nums1[start1] < nums2[start2])
                s = nums1[start1++];
            else
                s = nums2[start2++];
            if (end1 < 0)
                e = nums2[end2--];
            else if (end2 < 0)
                e = nums1[end1--];
            else if (nums1[end1] > nums2[end2])
                e = nums1[end1--];
            else
                e = nums2[end2--];
        }
        return (s + e) * 0.5;
    }
};