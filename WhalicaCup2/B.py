import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    t = int(input_data[0])
    idx = 1
    output = []
    
    for _ in range(t):
        n = int(input_data[idx])
        idx += 1
        

        res = [0] * n
        used = [False] * (n + 1)
        current_sum = n * (n + 1) // 2

        for i in range(n - 1, -1, -1):
            found = False
            for x in range(min(n, i + 5), 0, -1): 
                if not used[x] and current_sum % x == 0:
                    res[i] = x
                    used[x] = True
                    current_sum -= x
                    found = True
                    break
            if not found:
                for x in range(n, 0, -1):
                    if not used[x] and current_sum % x == 0:
                        res[i] = x
                        used[x] = True
                        current_sum -= x
                        break
                        
        output.append("YES")
        output.append(" ".join(map(str, res)))

    sys.stdout.write("\n".join(output) + "\n")

if __name__ == "__main__":
    solve()