class PrefSum2D:
    def __init__(self, v):
        self.n = len(v)
        self.pref = v
        j = 1
        while j < self.n:
            self.pref[0][j] += self.pref[0][j-1]
            j += 1
        i = 1
        while i < self.n:
            self.pref[i][0] += self.pref[i-1][0]
            i += 1
        i = 1
        while i < self.n:
            j = 1
            while j < self.n:
                self.pref[i][j] += self.pref[i-1][j] + self.pref[i][j-1] - self.pref[i-1][j-1]
                j += 1
            i += 1
    def query(self, xTL, yTL, xBR, yBR):
        res = self.pref[xBR][yBR]
        if xTL:
            res -= self.pref[xTL-1][yBR]
        if yTL:
            res -= self.pref[xBR][yTL-1]
        if xTL and yTL:
            res += self.pref[xTL-1][yTL-1]
        return res
        
