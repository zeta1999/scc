char gc[3];
int gi[2];

char str1[] = "Test";
unsigned char str2[] = "Xy\x81";

int g2[2][3];

void main(void)
{
    char a[2], b[3];
    a[0] = 42;
    b[2] = 55;

    assert_eq(a[0], 42);
    assert_eq(b[2], 55);
    assert_eq(sizeof(a), 2);
    assert_eq(sizeof(b), 3);

    int i[3];

    i[0] = 1;
    i[1] = 2;
    i[2] = 3;

    assert_eq(i[0], 1);
    assert_eq(i[1], 2);
    assert_eq(i[2], 3);
    assert_eq(sizeof(i), 6);

    struct S {
        int x, y;
    } ss[2];
    ss[0].x = 1; ss[0].y = 2;
    ss[1].x = 3; ss[1].y = 4;

    assert_eq(ss[0].x, 1);
    assert_eq(ss[0].y, 2);
    assert_eq(ss[1].x, 3);
    assert_eq(ss[1].y, 4);
    assert_eq(sizeof(ss[0]), 4);
    assert_eq(sizeof(ss), 8);

    struct SA {
        int a[3];
    } sa;
    sa.a[0] = -1;
    sa.a[1] = -2;
    sa.a[2] = -3;
    assert_eq(sa.a[0], -1);
    assert_eq(sa.a[1], -2);
    assert_eq(sa.a[2], -3);
    assert_eq(sizeof(sa.a), 6);
    assert_eq(sizeof(sa), 6);

    char* pc = &gc[2];
    *pc = 'X';

    *(gi+1) = 666;

    assert_eq(gc[0], 0);
    assert_eq(gc[1], 0);
    assert_eq(gc[2], 'X');

    assert_eq(gi[0], 0);
    assert_eq(gi[1], 666);

    assert_eq(sizeof(gc), 3);
    assert_eq(sizeof(gi), 4);

    assert_eq(sizeof(int[4]), 8);

    char large[512];
    large[1] = 60;
    large[511] = 42;
    assert_eq(large[1], 60);
    assert_eq(large[511], 42);

    assert_eq(sizeof(str1), 5);
    assert_eq(str1[0], 'T');
    assert_eq(str1[1], 'e');
    assert_eq(str1[2], 's');
    assert_eq(str1[3], 't');
    assert_eq(str1[4], 0);

    assert_eq(sizeof(g2), 12);
    assert_eq(sizeof(g2[0]), 6);
    assert_eq(sizeof(g2[0][0]), 2);
    assert_eq(g2[0][0], 0);
    g2[0][1] = 50;
    g2[1][2] = 42;
    assert_eq(g2[0][0], 0);
    assert_eq(g2[0][1], 50);
    assert_eq(g2[0][2], 0);
    assert_eq(g2[1][0], 0);
    assert_eq(g2[1][1], 0);
    assert_eq(g2[1][2], 42);
    assert_eq(&g2[0][0], (int*)g2);

    char sm[3][4];
    assert_eq(sizeof(sm), 12);
    sm[2][1] = 42;
    assert_eq(sm[2][1], 42);

    int arr3[4][5][6];
    assert_eq(sizeof(arr3), 4*5*6*sizeof(int));
    assert_eq(sizeof(arr3[0]), 5*6*sizeof(int));
    assert_eq(sizeof(arr3[0][0]), 6*sizeof(int));
    assert_eq(sizeof(arr3[0][0][0]), sizeof(int));
    arr3[1][1][1] = 123;
    assert_eq(arr3[1][1][1], 123);

    assert_eq(sizeof(str2), 4);
    assert_eq(str2[0], 'X');
    assert_eq(str2[1], 'y');
    assert_eq(str2[2], 0x81);
    assert_eq(str2[3], 0);
}
