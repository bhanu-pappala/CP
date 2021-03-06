#include<bits/stdc++.h>
using namespace std;

int N = 5, V, coins[5] = {1, 5, 10, 25, 50}, memo[6][7500];

int ways(int type, int value) {
	if(value == 0)
		return 1;
	if(value < 0 || type == N) 
		return 0;
	if (memo[type][value] != -1) return memo[type][value];
	return memo[type][value] = ways(type + 1, value) + ways(type, value - coins[type]);
}
int main() {
	memset(memo, -1, sizeof memo);
	while(scanf("%d", &V) != EOF) {
		printf("%d\n", ways(0, V));
	}
	return 0;
}
