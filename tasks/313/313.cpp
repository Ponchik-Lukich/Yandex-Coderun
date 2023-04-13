#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMedian(vector<int>& nums, int num) {
    if (nums.empty()) {
        nums.push_back(num);
        return num;
    }
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == num) {
            left = mid;
            break;
        } else if (nums[mid] < num) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    nums.insert(nums.begin() + left, num);

    long median;
    if (nums.size() % 2 == 0) {
        median = nums[nums.size() / 2 - 1];
    } else {
        median = nums[nums.size() / 2];
    }
    return median;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long medSum = 0;
    cin >> n;
    vector<int> a(n);
    vector<int> b;
    b.reserve(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        medSum += findMedian(b, a[i]);
    }
    cout << medSum << '\n';

    return 0;
}
