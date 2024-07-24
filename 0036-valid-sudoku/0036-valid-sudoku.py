class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        sub_boxes = [set() for _ in range(9)]

        for i in range(9):
            for j in range(9):
                num = board[i][j]
                if num == '.':
                    continue
                if num in rows[i]:
                    return False
                if num in cols[j]:
                    return False
                if num in sub_boxes[3 * (i // 3) + (j // 3)]:
                    return False

                rows[i].add(num)
                cols[j].add(num)
                sub_boxes[3 * (i // 3) + (j // 3)].add(num)

        return True
