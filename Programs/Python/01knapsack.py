from sys import stdin

def knapsack(weights, values, n, maxWeight) :
    dp = [[0 for i in range(maxWeight+1)] for j in range(len(weights)+1)]
    
    for i in range(1,len(weights)+1):
        for j in range(maxWeight+1):
            if j < weights[i-1]:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = max(values[i-1]+dp[i-1][j-weights[i-1]],dp[i-1][j])
    return dp[len(weights)][maxWeight]


def takeInput() :
    n = int(input())

    if n == 0 :
        return list(), list(), n, 0

    weights = list(map(int, input().split(" ")))
    values = list(map(int,  input().split(" ")))
    maxWeight = int(input())

    return weights, values, n, maxWeight


#main
weights, values, n, maxWeight = takeInput()

print(knapsack(weights, values, n, maxWeight))
