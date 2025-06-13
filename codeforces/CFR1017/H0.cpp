function f(k, a, l, r):
   ans := 0
      for i from l to r (inclusive):
            while k is divisible by a[i]:
                     k := k/a[i]
                    ans := ans + k   
                    return ans