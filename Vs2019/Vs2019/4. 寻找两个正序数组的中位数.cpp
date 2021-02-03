#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	vector<int> nums1, nums2;
	nums1 = { 1 };
	nums2 = { 2,3,4 };
	int l1 = nums1.size(), l2 = nums2.size();
	int l = l1 + l2;
	int mid = l / 2, mid1, mid2;
	int temp;
	int n1, n2, m1, m2;
	int start = 0, end = l1;

	while (start <= end) {
		mid1 = (start + end) / 2;
		mid2 = mid - mid1;

		n1 = mid1 > 0 ? nums1[mid1 - 1] : -100000000;
		n2 = mid1 < l1 ? nums1[mid1] : 100000000;

		m1 = mid2 > 0 ? nums2[mid2 - 1] : -100000000;
		m2 = mid2 < l2 ? nums2[mid2] : 100000000;


		if (n1 > m2) {
			end = mid1 - 1;
		}
		else if (m1 > n2) {
			start = mid1 + 1;
		}
		else {
			break;
		}
	}

	vector<int>bound(4);
	bound[0] = n1;
	bound[1] = n2;
	bound[2] = m1;
	bound[3] = m2;

	sort(bound.begin(), bound.end());
	if (l % 2 == 1) {
		return bound[2];
	}
	else {
		return (bound[1] + bound[2]) / 2.0;
	}

	return 0;
}