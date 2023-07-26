#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;//(double)(1000000000.0)

int minCoins(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> dp(amount + 1, INF);

    dp[0] = 0; 
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                int subproblem = dp[i - coins[j]];
                if (subproblem != INF && subproblem + 1 < dp[i])
                    dp[i] = subproblem + 1;
            }
        }
    }

    return dp[amount] == INF ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {1, 5, 10, 25, 50};
    int amount = 73;

    int result = minCoins(coins, amount);
    if (result == -1)
        cout << "No es posible dar cambio para el monto dado." << endl;
    else
        cout << "El número minimo de monedas necesarias es: " << result << endl;

    return 0;
}
