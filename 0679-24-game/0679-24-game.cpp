class Solution {
    const double EPS = 1e-6;
    const double TARGET = 24.0;
    bool found = false;
    char ops[4] = {'+', '-', '*', '/'};

public:
    bool judgePoint24(vector<int>& cards) {
        int perm[4];
        bool used[4] = {false};
        permute(cards, perm, used, 0);
        return found;
    }

    void permute(vector<int>& cards, int perm[], bool used[], int idx) {
        if (found) return;
        if (idx == 4) {
            char chosen[3];
            chooseOps(perm, chosen, 0);
            return;
        }
        for (int i = 0; i < 4; ++i) {
            if (!used[i]) {
                used[i] = true;
                perm[idx] = cards[i];
                permute(cards, perm, used, idx + 1);
                used[i] = false;
            }
        }
    }

    void chooseOps(int perm[], char chosen[], int idx) {
        if (found) return;
        if (idx == 3) {
            checkBrackets(perm, chosen);
            return;
        }
        for (int i = 0; i < 4; ++i) {
            chosen[idx] = ops[i];
            chooseOps(perm, chosen, idx + 1);
        }
    }

    bool apply(double x, double y, char op, double &out) {
        if (op == '+') { out = x + y; return true; }
        if (op == '-') { out = x - y; return true; }
        if (op == '*') { out = x * y; return true; }
        if (op == '/') {
            if (fabs(y) < EPS) return false;
            out = x / y; return true;
        }
        return false;
    }

    void checkBrackets(int p[], char o[]) {
        double a = p[0], b = p[1], c = p[2], d = p[3];
        char op1 = o[0], op2 = o[1], op3 = o[2];

        double r1;
        if (apply(a, b, op1, r1)) {
            double r12;
            if (apply(r1, c, op2, r12)) {
                double r123;
                if (apply(r12, d, op3, r123) && fabs(r123 - TARGET) < EPS) { found = true; return; }
            }
        }

        double r2;
        if (apply(b, c, op2, r2)) {
            double r21;
            if (apply(a, r2, op1, r21)) {
                double r213;
                if (apply(r21, d, op3, r213) && fabs(r213 - TARGET) < EPS) { found = true; return; }
            }
        }

        double r23;
        if (apply(b, c, op2, r2) && apply(r2, d, op3, r23)) {
            double r3;
            if (apply(a, r23, op1, r3) && fabs(r3 - TARGET) < EPS) { found = true; return; }
        }

        double r4;
        if (apply(c, d, op3, r4)) {
            double r42;
            if (apply(b, r4, op2, r42)) {
                double r421;
                if (apply(a, r42, op1, r421) && fabs(r421 - TARGET) < EPS) { found = true; return; }
            }
        }

        double left;
        if (apply(a, b, op1, left) && apply(c, d, op3, r4)) {
            double rFinal;
            if (apply(left, r4, op2, rFinal) && fabs(rFinal - TARGET) < EPS) { found = true; return; }
        }
    }
};