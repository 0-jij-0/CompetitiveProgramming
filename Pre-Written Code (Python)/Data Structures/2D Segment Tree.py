# Handles queries on submatrices in O(log^2(nm))
# O(4nm) space

base = [] # nxm

def resize(l, n, v=0):
    if n < len(l):
        l = l[:-(len(l)-n)]
    elif n > len(l):
        for i in range(n-len(l)):
            l.append(v)
class StVal:
    def __init__(self, v, L=0, R=0):
        self.v = v+int(L)+int(R)
    def __int__(self): # StVal to int
        return self.v
class SegTree2D:
    def __init__(self, n, m):
        self.n = n
        self.m = m
        self.leaves1 = [0]*n
        self.leaves2 = [([0]*m) for i in range(n)]
        self.st = []
        self.init2D(1, 0, n-1)
    def init2D(self, si1, lo, hi):
        if lo == hi:
            if si1 >= int(len(self.st)):
                resize(self.st, si1+1, [])
            self.init(si1, lo, 1, 0, self.m-1)
            self.leaves1[lo] = si1
            return
        lC = si1 << 1
        rC = (si1 << 1) | 1
        mid = (lo+hi) >> 1
        self.init2D(lC, lo, mid)
        self.init2D(rC, mid+1, hi)
        resize(self.st[si1], len(self.st[lC]), StVal(0))
        i = 0
        while i < len(self.st[si1]):
            self.st[si1][i] = StVal(0, self.st[lC][i], self.st[rC][i]) # Merges ALL the nodes of the children segment trees (not only leaves)
            i += 1
    def init(self, si1, prevLo, si2, lo, hi):
        if lo == hi:
            if si2 >= len(self.st[si1]):
                resize(self.st[si1], si2+1, StVal(0))
            self.st[si1][si2] = StVal(base[prevLo][lo]) # Set the actual array here
            self.leaves2[prevLo][lo] = si2
            return
        lC = si2 << 1
        rC = (si2 << 1) | 1
        mid = (lo + hi) >> 1
        self.init(si1, prevLo, lC, lo, mid)
        self.init(si1, prevLo, rC, mid+1, hi)
        self.st[si1][si2] = StVal(0, self.st[si1][lC], self.st[si1][rC])
    # 0-indexed, i is for rows, j for columns
    def query4(self, i1, i2, j1, j2):
        if i1 > i2 or j1 > j2:
            return self.query2D(1, 0, self.n-1, i1, i2, j1, j2)
        return self.query2D(1, 0, self.n-1, i1, i2, j1, j2)
    def query2D(self, si, lo, hi, i1, i2, j1, j2):
        if i1 <= lo and hi <= i2:
            return self.query6(si, 1, j1, j2, 0, self.m-1)
        mid = (lo + hi) >> 1
        if i2 <= mid:
            return self.query2D(si << 1, lo, mid, i1, i2, j1, j2)
        if mid < i1:
            return self.query2D(si << 1 | 1, mid + 1, hi, i1, i2, j1, j2)
        return StVal(0, self.query2D(si << 1, lo, mid, i1, i2, j1, j2), self.query2D(si<<1 | 1, mid + 1, hi, i1, i2, j1, j2))
    def query6(self, si1, si2, l, r, lo, hi):
        if l <= lo and hi <= r:
            return self.st[si1][si2]
        mid = (lo + hi) >> 1
        if r <= mid:
            return self.query6(si1, si2 << 1, l, r, lo, mid)
        if mid < l:
            return self.query6(si1, si2 << 1 | 1, l, r, mid+1, hi)
        return StVal(0, self.query6(si1, si2 << 1, l, r, lo, mid), self.query6(si1, si2 << 1 | 1, l, r, mid+1, hi))
    # Change a leaf and update its ancestors' values
    def update(self, i, j, c):
        si1Init = self.leaves1[i]
        si2Init = self.leaves2[i][j]
        self.st[si1Init][si2Init] = StVal(c)
        si2 = si2Init >> 1
        while si2:
            self.st[si1Init][si2] = StVal(0, self.st[si1Init][si2 << 1], self.st[si1Init][si2<<1|1])
            si2 >>= 1
        si1 = si1Init >> 1
        while si1:
            si2 = si2Init
            while si2:
                self.st[si1][si2] = StVal(0, self.st[si1<<1][si2], self.st[si1 << 1 | 1][si2])
                si2 >>= 1
            si1 >>= 1
