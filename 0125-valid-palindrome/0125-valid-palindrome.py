class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = "".join(e for e in s if e.isalnum()).lower()
        front, back = 0, len(s) - 1
        
        while front <= back:
            if s[front] != s[back]:
                return False
            front += 1
            back -= 1
        
        return True