#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    vector<bool> check;
    check.resize(n + 1, true);

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    for (int i = 0; i < lost.size(); i++) {
        check[lost[i]] = false;
    }

    for (int i = 0; i < reserve.size(); i++) {
        if (!check[reserve[i]]) {
            check[i] = true;
        }
        else if (!check[reserve[i] - 1]) {
            check[reserve[i] - 1] = true;
        }
        else if (reserve[i] + 1 <= n && !check[reserve[i] + 1]) {
            check[reserve[i] + 1] = true;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (check[i]) answer++;
    }

    return answer;
}

int main() {
	init();


    cout << solution("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}) << "\n";
}
