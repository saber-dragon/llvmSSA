int foo(int a, int b){
    int x, y, z, w, q;
    x = a + b;

    if (x) {
        y = a + b;
        if (a * a + b * b >= 25) {
            B4:
            {
                z = a + b;
                goto EXIT;
            }
        } else {
            goto B3;
        }
    } else {
        q = a + b;
        if (q * q > q) {
            a = 2 * a + b;
            b = 2 * b + a;
            goto B3;
        } else {
            goto B4;
        }
    }

    B3: {
        w = a + b;
        q = w * w - x;
    }
    EXIT: {
        return q;
    }
}