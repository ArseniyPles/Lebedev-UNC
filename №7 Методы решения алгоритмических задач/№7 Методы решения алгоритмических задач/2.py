# вместимость рюкзака
M = 15

# массы слитков
weights = [3, 8, 1, 2, 5]

def knapsack_max_weight(M, weights):

    dp = [0] * (M + 1)

    for w in weights:
        # идём с конца, чтобы не использовать слиток повторно
        for j in range(M, w - 1, -1):
            dp[j] = max(dp[j], dp[j - w] + w)

    return dp[M]


result = knapsack_max_weight(M, weights)

print("Максимальная масса:", result)