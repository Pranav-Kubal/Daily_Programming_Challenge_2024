#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int minCoins(const vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0; // Base case: 0 coins needed to make amount 0

    for (int i = 1; i <= amount; ++i) {
        for (const int& coin : coins) {
            if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    int n, amount;
    
    cout << "Enter the number of coin denominations: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter the coin denominations: ";
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    cout << "Enter the total amount: ";
    cin >> amount;

    int result = minCoins(coins, amount);
    if (result == -1) {
        cout << "Cannot make the amount with the given coins." << endl;
    } else {
        cout << "Minimum number of coins needed: " << result << endl;
    }

    return 0;
}
