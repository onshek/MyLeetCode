class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ""
        return self.longestCommonPrefix2(strs, 0, len(strs) - 1)

    def longestCommonPrefix2(self, strs: List[str], l: int,r: int) -> str:
        if l == r:
            return strs[l]
        else:
            mid = int((l + r)/2)
            lcpLeft = self.longestCommonPrefix2(strs, l, mid)
            lcpRight = self.longestCommonPrefix2(strs, mid + 1, r)
            return self.commonPrefix(lcpLeft, lcpRight)

    @staticmethod
    def commonPrefix(left: str, right: str) -> str:
        min_len = min(len(left), len(right))
        for i in range(min_len):
            if left[i] != right[i]:
                return left[:i]
        return left[:min_len]