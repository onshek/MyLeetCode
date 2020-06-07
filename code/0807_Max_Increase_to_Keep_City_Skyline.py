class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        res = 0
        idxMax = [max(grid[i]) for i in range(len(grid))]
        colMax = [max([grid[j][i] for j in range(len(grid))]) for i in range(len(grid[0]))]
        for i in range(len(grid)):
            for j  in range(len(grid[0])):
                res += min(idxMax[i], colMax[j]) - grid[i][j]
        return res