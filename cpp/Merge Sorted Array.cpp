/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to 
hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
*/
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int index1 = m-1;
        int index2 = n-1;
        int index = m+n-1;
        while (index >= 0) {
            if (index1 >= 0 && (index2 < 0 || A[index1] > B[index2]))
                A[index--] = A[index1--];
            else
                A[index--] = B[index2--];
        }
    }
};