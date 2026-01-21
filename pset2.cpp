import sys

def solve():
    # Read number of test cases
    try:
        line = sys.stdin.readline()
        if not line:
            return
        t = int(line.strip())
    except ValueError:
        return

    for _ in range(t):
        # Read n
        n = int(sys.stdin.readline().strip())
        # Read the array a
        a = list(map(int, sys.stdin.readline().split()))
        
        # The maximum k is the minimum element in the array.
        # This is because we can set each a_i = a_i % a_i = 0.
        # This requires x = a_i, and since x must be >= k, 
        # the largest possible k that satisfies this for all a_i is min(a).
        print(min(a))

if __name__ == "__main__":
    solve()