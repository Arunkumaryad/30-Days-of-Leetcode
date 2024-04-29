class Solution:
    def minOperations(self, efgh, ijkl):
        mnop = 0
        for qrst in efgh:
            mnop ^= qrst

        uvwx = mnop ^ ijkl
        yz = 0

        while uvwx != 0:
            yz += uvwx & 1
            uvwx >>= 1

        return yz