#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 500000 // 최대, 최소(-) 크기

using namespace std;

int fixed_index(int index, int max_num) { // -1 -> n - 1
	return index == -1 ? max_num - 1 : index;
}

bool is_dif_x(pair<int, int> a, pair<int, int> b) { // a b의 x좌표가 다르면 true
	return a.first != b.first;
}

void set_dif_arr(vector<int> &arr, int start, int end) { // 차분 배열 채우기
	if(start > end) swap(start, end);
	arr[start + 1] += 1;
	arr[end + 1] -= 1;
}

int set_pfx_arr(vector<int> &pfx_arr, vector<int> &dif_arr) { // 누적합 배열 채우기 & 최댓값 반환
	int ma = 0;

	for(int i = 1; i < MAX * 2 + 1; i++) {
		pfx_arr[i] = pfx_arr[i - 1] + dif_arr[i];
		ma = max(ma, pfx_arr[i]);
	}

	return ma;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; // 꼭짓점 수
	cin >> n;

	pair<vector<int>, vector<int>> arr = {vector<int>(n), vector<int>(n)}; // 꼭짓점 배열 : first -> x, second -> y
	for(int i = 0; i < n; i++) {
		cin >> arr.first[i] >> arr.second[i];
		arr.first[i] += MAX;
		arr.second[i] += MAX;
	}

	pair<vector<int>, vector<int>> dif_arr({vector<int>(MAX * 2 + 1, 0), vector<int>(MAX * 2 + 1, 0)}); //
	for(int i = 0; i < n; i++) {
		int pre_idx = fixed_index(i - 1, n);

		auto pre = make_pair(arr.first[pre_idx], arr.second[pre_idx]);
		auto cur = make_pair(arr.first[i], arr.second[i]);

		if(is_dif_x(pre, cur)) set_dif_arr(dif_arr.first, pre.first, cur.first);
		else set_dif_arr(dif_arr.second, pre.second, cur.second);
	}

	pair<vector<int>, vector<int>> pfx_arr({vector<int>(MAX * 2 + 1, 0), vector<int>(MAX * 2 + 1, 0)});
	
	int h = set_pfx_arr(pfx_arr.first, dif_arr.first);
	int v = set_pfx_arr(pfx_arr.second, dif_arr.second);

	cout << max(h, v) << "\n";
}