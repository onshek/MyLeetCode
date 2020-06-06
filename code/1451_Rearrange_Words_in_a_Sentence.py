class Solution(object):
    def arrangeWords(self, text):
        """
        :type text: str
        :rtype: str
        """
        if (len(text) == 0):
            return text;
        text = text[0].lower() + text[1:]
        res = sorted(text.split(" "), key=lambda x: len(x))
        res = " ".join(res)
        res = res[0].upper() + res[1:]
        return res