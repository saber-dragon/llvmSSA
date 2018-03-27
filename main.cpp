int main(int argc, char *argv[]) {

    int a = argc;
    int b = 10;
    int c, d, e = 1;


    goto L1;

    L1: {
        c = a + b;
        d = c - a;
        if (d) goto L2;
        d = b * d;
        e = e + 1;
    }

    L2: {
        b = a + b;
        e = c - a;
        if (e) goto L1;
    }
}