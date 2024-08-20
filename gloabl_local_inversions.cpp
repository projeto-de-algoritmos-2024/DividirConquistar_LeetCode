using namespace std;
#include <vector>

int merge(vector<int>& nums, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = 0, cont = 0;
    vector<int> temp(right - left + 1);

    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
            cont += (mid - i + 1);
        }
    }

    while (i <= mid) {
        temp[k++] = nums[i++];
    }

    while (j <= right) {
        temp[k++] = nums[j++];
    }

    for (i = left, k = 0; i <= right; i++, k++) {
        nums[i] = temp[k];
    }

    return cont;
}

int contagem_inversoes(vector<int>& nums, int left, int right) {
    long int cont = 0;

    if (left >= right) return cont;

    int mid = (left + right) / 2;

    cont += contagem_inversoes(nums, left, mid);
    cont += contagem_inversoes(nums, mid + 1, right);
    cont += merge(nums, left, mid, right);

    return cont;
}

bool isIdealPermutation(vector<int>& nums) {
    int global = 0;
    int local = 0;

    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            local++;
        }
    }

    global = contagem_inversoes(nums, 0, nums.size() - 1);

    return global == local;
}