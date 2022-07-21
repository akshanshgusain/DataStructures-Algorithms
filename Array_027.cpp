//
// Created by Akshansh Gusain on 12/07/21.
//
#include<stdc++.h>
using namespace std;

// Time: O(N), Space: O(N)
// Buy and sell stocks at most two times, Divide and conquer
// tut: https://www.youtube.com/watch?v=37s1_xBiqH0&t=8s, https://www.youtube.com/watch?v=_VV93iZR7lE
// tut DP Approach: https://www.youtube.com/watch?v=wuzTpONbd-0&t=2265s


int maxProfit(vector<int>& prices){
    int n = prices.size();

    if(n == 0) return 0;

    vector<int> left(n), right(n);

    //Fill the first Transaction (LEFT TO RIGHT)
    //Max profit that can be made up to ith day i.e., if buy-sell before ith day (from 0th day to i-1th day)
    int leftMin = prices[0];
    for(int i = 1; i < n; i++){
        left[i] = max(left[i-1], prices[i] - leftMin);
        leftMin = min(left[i], leftMin);
    }

    //Fill the second Transaction (RIGHT TO LEFT)
    //Max profit that can be made from ith day i.e., if you buy-sell after ith day (from ith day to nth day)
    int rightMax = prices[n-1];
    for(int i = n-2; i >= 0; i--){
        right[i] = max(right[i+1], rightMax - prices[i]);
        rightMax = max(rightMax, prices[i]);
    }

    //Find the max profit value
    int profit = 0;
    for(int i =0 ; i< n; i++){
        profit = max(profit, left[i-1] + right[i]);
    }

    return profit;
}

int main(){
    vector<int> arr = {10, 22, 5, 75, 65, 80};
    cout<<maxProfit(arr);
    return 0;
}

