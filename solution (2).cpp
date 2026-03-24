#include <iostream>
#include <iomanip>
#include <string>
#include <thread>
#include <chrono>
#include <random>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <stdio.h>
#include <climits>

int main()
{
    int N;
    std::cin >> N;

    std::vector<int> h(N);
    for (auto &e : h)
    {
        std::cin >> e;
    }

    std::vector<int> cost(N);
    for (int i = 0; i < N; ++i)
    {
        cost[i] = INT_MAX;
    }

    cost[0] = 0;

    for (int i = 1; i < N; ++i)
    {
        int a, b;

        a = cost[i - 1] + std::abs(h[i] - h[i - 1]);

        if (i >= 2)
        {
            b = cost[i - 2] + std::abs(h[i] - h[i - 2]);
        }
        else
        {
            b = INT_MAX;
        }

        cost[i] = std::min(a, b);
    }

    std::cout << cost[N - 1] << '\n';

}
