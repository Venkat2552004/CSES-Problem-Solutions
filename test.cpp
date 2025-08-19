#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> coins(n);
	for(int i = 0; i < n; i++)
		cin >> coins[i];
	sort(coins.begin(), coins.end());
	
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));
	dp[0][0] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= k; j++){
			if(j < coins[i - 1]) dp[i][j] = dp[i - 1][j];
			else{
				int remSum = j - coins[i - 1];
				if(dp[i - 1][remSum] != INT_MAX){
					dp[i][j] = 1 + dp[i - 1][remSum];
}
}
}
}

int ans = INT_MAX;
for(int i = 1; i <= n; i++){
	ans = min(ans, dp[i][k]);
}

cout << ans;
return 0;
}
