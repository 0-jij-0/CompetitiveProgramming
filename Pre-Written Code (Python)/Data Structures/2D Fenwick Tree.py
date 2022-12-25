# Queries take O(log^2 n) time
class FT2D:
    def __init__(self, n, m):
        self.n = n
        self.m = m
        self.vals = [[0]*(m+1) for i in range(n+1)]
    # Adds val to (i,j) 0-indexed
    def update(self, i, j, val):
        i += 1
        j += 1
        while i<=self.n:
            _j = j
            while _j <= self.m:
                self.vals[i][_j] += val
                _j += _j & -j
            i += i & -i                
    def query(self, i, j, i2='', j2=''):
        if isinstance(i2, str):
            # Sum of the rectangle (0,0),(i,j) 0-indexed
            sum = 0
            i += 1
            j += 1
            while i:
                _j = j
                while _j:
                    sum += self.vals[i][_j]
                    _j -= _j & -_j
                i -= i & -i
            return sum
        else:
            # Sum of the rectangle (i1, j1, i2, j2)
            return self.query(i2, j2) - self.query(i2,j-1) - self.query(i-1, j2) + self.query(i - 1, j - 1)
