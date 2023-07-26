#include <iostream>
#include <vector>
using namespace std;

struct Item {
    int peso;
    int valor;
};

int knapsack(int capacidad, const vector<Item>& items) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacidad + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacidad; ++w) {
            if (items[i - 1].peso <= w) {
                dp[i][w] = max(items[i - 1].valor + dp[i - 1][w - items[i -1].peso], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacidad];
}

int main() {
    int capacidad_mochila = 10;
    vector<Item> items = {
        {2, 6},
        {2, 10},
        {3, 12},
        {4, 8},
        {5, 10}
    };

    int max_valor = knapsack(capacidad_mochila, items);

    cout << "El valor maximo que se puede llevar en la mochila es: " << max_valor << endl;

    return 0;
}
