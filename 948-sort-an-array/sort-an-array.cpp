class Solution {
public:
    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && nums[left] > nums[largest])
            largest = left;
        if (right < n && nums[right] > nums[largest])
            largest = right;

        if (largest != i) {
            swap(nums[i], nums[largest]);
            heapify(nums, n, largest);
        }
    }

    void heapSort(vector<int>& nums) {
        int n = nums.size();

        // Build max heap
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(nums, n, i);

        // One by one extract elements from heap
        for (int i = n - 1; i >= 0; i--) {
            swap(nums[0], nums[i]);    // Move current root to end
            heapify(nums, i, 0);       // Heapify reduced heap
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }
};