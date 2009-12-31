### Solution 1 DFS with memoization for optimization

1. Use `unordered_map<char, int>` to count frequencies of balls in `hand`. Use another `unordered_map<string, int>` to memoization of `steps` needed to empty `board`.
2. Use recursive DFS to try inserting every ball in hand at every position on the board.
3. Decrease freq of ball when inserting it on the board and increase it before trying a new combination.
4. Update the board after inserting a ball on the board and recursively call DFS on the new board with the new hand.
5. Return the minimum steps after trying all combination.

