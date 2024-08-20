class Solution {
public:
    int partition(vector<int>& nums, int l, int r) {

        int pivo = nums[r];
        int i = l;

        for (int j = l; j < r; ++j) {
            if (nums[j] >= pivo) {
                swap(nums[i], nums[j]);
                ++i;
            }
        }
        swap(nums[i], nums[r]);
        return i;
    }

    int quickselect(vector<int>& nums, int l, int r, int k) {

        if (l == r) return nums[l];

        int pivo = partition(nums, l, r);

        if (pivo == k) {
            return nums[pivo];
        } else if (pivo < k) {
            return quickselect(nums, pivo + 1, r, k);
        } else {
            return quickselect(nums, l, pivo - 1, k);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        
        int n = nums.size();
        return quickselect(nums, 0, n - 1, k - 1);
    }
};