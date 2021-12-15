// Best time to buy and sell Stock - II

// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
// Find and return the maximum profit you can achieve.

// 1. RECURSIVE - TLE

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        return maxprofit(prices, INT_MIN, 0);
    }
    int maxprofit(vector<int> prices, int cp, int n)
    {
        if (n == prices.size())
            return 0;
        if (prices[n] < cp)
            return maxprofit(prices, prices[n], n + 1);
        else
        {
            if (cp > INT_MIN)
                return max(prices[n] - cp + maxprofit(prices, INT_MIN, n + 1), maxprofit(prices, cp, n + 1));
            else
                return max(maxprofit(prices, prices[n], n + 1), maxprofit(prices, cp, n + 1));
        }
    }
};
