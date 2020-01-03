#include "./inc/libft.h"

#include <limits.h>
#include <float.h>

# define ADD_TEST_RESULT(__t, __v) { *__t += (long long)(1ll << (sizeof(int) * 8) | __v); }
# define GET_COUNT(__t) ((__t & 0xFFFFFFFF00000000) >> (sizeof(int) * 8))
# define GET_ERROR(__t) (__t & 0x00000000FFFFFFFF)

int verbose = 0;

void test_double(unsigned long long *errcnt, double d, int id);

t_buf *read_all(int fd)
{
    t_buf *buf;
    int ret;
    char c;

    buf = buf_new();
    while ((ret = read(fd, &c, 1)) > 0)
    {
        buf_push_one(buf, c);
    }
    return buf;
}

int test(int id, const char *fmt, ...)
{
    va_list ap;
    va_list ft_ap;
    int fds[2];
    int ft_fds[2];
    t_buf *buf;
    t_buf *ft_buf;
    int ret;
    int ft_ret;

    va_start(ap, fmt);
    va_copy(ft_ap, ap);
    pipe(fds);
    pipe(ft_fds);
    ret = vdprintf(fds[1], fmt, ap);
    ft_ret = ft_vdprintf(ft_fds[1], fmt, ft_ap);
    close(fds[1]);
    close(ft_fds[1]);
    buf = read_all(fds[0]);
    ft_buf = read_all(ft_fds[0]);
    close(fds[0]);
    close(ft_fds[0]);
    if (ret != ft_ret)
    {
        dprintf(
            STDERR_FILENO,
            "\033[31m[ERROR]\033[0m: test %s (#%d): ret(s) are different:\n\
printf    (%3d): '%.*s'\n\
ft_printf (%3d): '%.*s'\n\
\n",
            fmt, id,
            ret, (int)buf->len, buf->content,
            ft_ret, (int)ft_buf->len, ft_buf->content);
        return (1);
    } else if (buf->len != ft_buf->len)
    {
        dprintf(
            STDERR_FILENO,
            "\033[31m[ERROR]\033[0m: test %s (#%4d): outs are not of same length.\n\
printf   : %-3zd: '%.*s'\n\
ft_printf: %-3zd: '%.*s'\n\
",
            fmt, id,
            buf->len, (int)buf->len, buf->content,
            ft_buf->len, (int)ft_buf->len, ft_buf->content);
        return (1);
    }
    else if (strncmp(buf->content, ft_buf->content, buf->len) != 0)
    {
        dprintf(
            STDERR_FILENO,
            "\033[31m[ERROR]\033[0m: test %s (#%4d): outs are different:\n\
printf   : '%.*s'\n\
ft_printf: '%.*s'\n\
\n",
            fmt, id,
            (int)buf->len, buf->content,
            (int)ft_buf->len, ft_buf->content);
        return (1);
    }
    if (verbose)
        printf("\033[32m[SUCCESS]\033[0m: TEST (#%4d) '%s'\n",id, fmt);
    if (verbose == 2) {
        printf("\
printf   : '%.*s'\n\
ft_printf: '%.*s'\n\
",
        (int)buf->len,
        buf->content,
        (int)ft_buf->len,
        ft_buf->content);
    }
    return (0);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        if (ft_strcmp(argv[1], "-v") == 0)
            verbose = 1;
        else if (ft_strcmp(argv[1], "-vv") == 0)
            verbose = 2;
        else
        {
            dprintf(STDERR_FILENO, "invalid flag %s\n", argv[1]);
            exit(1);
        }
    }
    unsigned long long err_count;

    err_count = 0;
    ft_printf("no conv\n");
    ADD_TEST_RESULT(&err_count, test(900, ""));
    ADD_TEST_RESULT(&err_count, test(901, "a"));
    ADD_TEST_RESULT(&err_count, test(902, "%"));
    ADD_TEST_RESULT(&err_count, test(903, "%, qwe%"));
    ADD_TEST_RESULT(&err_count, test(993, "%, Qwe%"));
    ADD_TEST_RESULT(&err_count, test(904, "% Qwe%"));
    ADD_TEST_RESULT(&err_count, test(905, "%,,, qwe%"));
    ADD_TEST_RESULT(&err_count, test(906, "%,,, %qwe%"));
    // ADD_TEST_RESULT(&err_count, test(907, "%,,, 9qwe%"));
    ADD_TEST_RESULT(&err_count, test(908, "%,,, .9qwe%"));
    ADD_TEST_RESULT(&err_count, test(909, "%9.3,,, qwe%"));
    ADD_TEST_RESULT(&err_count, test(910, "%9.3,,,0 Qwe%"));
    ADD_TEST_RESULT(&err_count, test(913, "%,,,,s", NULL));
    ADD_TEST_RESULT(&err_count, test(914, "%.5-10.2s", "SALE MOCHE"));
    ADD_TEST_RESULT(&err_count, test(3, "%,,,,,s", NULL));
    ADD_TEST_RESULT(&err_count, test(122, "%ll37u", 400));
    // return (0);

    /* s */
    ft_printf("conversion s\n");
    ADD_TEST_RESULT(&err_count, test(0, "%-10.5s", "SALE MOCHE"));
    ADD_TEST_RESULT(&err_count, test(0, "%-5.10s", "SALE MOCHE"));
    ADD_TEST_RESULT(&err_count, test(1, "%10.10s", "SALE MOCHE"));
    ADD_TEST_RESULT(&err_count, test(2, "%10.5s", "SALE MOCHE"));
    ADD_TEST_RESULT(&err_count, test(3, "%s", NULL));
    ADD_TEST_RESULT(&err_count, test(4, "%.2s", NULL));
    ADD_TEST_RESULT(&err_count, test(5, "%-42.6s", NULL));
    ADD_TEST_RESULT(&err_count, test(6, "%.7s", NULL));
    ADD_TEST_RESULT(&err_count, test(61, "%.09s", NULL));

    // /* d */
    int d = 123456;
    ft_printf("conversion d\n");
    ADD_TEST_RESULT(&err_count, test(7, "%d", d));
    ADD_TEST_RESULT(&err_count, test(8, "%+d", d));
    ADD_TEST_RESULT(&err_count, test(9, "%-d", -d));
    ADD_TEST_RESULT(&err_count, test(10, "% d", d));
    ADD_TEST_RESULT(&err_count, test(11, "%8d", d));
    ADD_TEST_RESULT(&err_count, test(18, "%010d", d));
    ADD_TEST_RESULT(&err_count, test(12, "%.10d", d));
    ADD_TEST_RESULT(&err_count, test(13, "%12.10d", d));
    ADD_TEST_RESULT(&err_count, test(113, "%012.10d", d));
    ADD_TEST_RESULT(&err_count, test(114, "%012d", d));
    ADD_TEST_RESULT(&err_count, test(14, "%-12.10d", d));
    ADD_TEST_RESULT(&err_count, test(15, "%-+12.10d", d));
    ADD_TEST_RESULT(&err_count, test(16, "%-+5.10d", d));
    ADD_TEST_RESULT(&err_count, test(17, "%.1d", d));
    ADD_TEST_RESULT(&err_count, test(117, "%0-10d", d));
    ADD_TEST_RESULT(&err_count, test(118, "%.0d", d));
    ADD_TEST_RESULT(&err_count, test(119, "%+-5.0d", d));
    ADD_TEST_RESULT(&err_count, test(120, "%5.0d %5.d", 0, 0));
    ADD_TEST_RESULT(&err_count, test(121, "%.d %.0d", d, d));
    ADD_TEST_RESULT(&err_count, test(122, "{%+03d}", d));
    ADD_TEST_RESULT(&err_count, test(123, "{%+3d}", d));
    ADD_TEST_RESULT(&err_count, test(4000, "%+.0i", 0));
    ADD_TEST_RESULT(&err_count, test(4001, "%+.i", 0));
    ADD_TEST_RESULT(&err_count, test(4002, "%+.0d", 0));
    ADD_TEST_RESULT(&err_count, test(4003, "%+.d", 0));

    ft_printf("conversion unsigned\n");
    unsigned char uc = 25;
    ADD_TEST_RESULT(&err_count, test(121, "%hhu", uc));
    ADD_TEST_RESULT(&err_count, test(1210, "%08.3u", uc));
    ADD_TEST_RESULT(&err_count, test(1210, "%08.3d", uc));

    ft_printf("conversion ull\n");
    unsigned long long ull = 522337203685470ull;
    ADD_TEST_RESULT(&err_count, test(122, "%37llu", ull));
    ADD_TEST_RESULT(&err_count, test(123, "this %#x number", 0));
    
    ft_printf("conversion o\n");
    unsigned long long o = 42;
    ADD_TEST_RESULT(&err_count, test(122, "%#08o", o));
    ADD_TEST_RESULT(&err_count, test(122, "%#.3o", o));
    ADD_TEST_RESULT(&err_count, test(122, "@moulitest: %#.o %#.0o", 0, 0));
    ADD_TEST_RESULT(&err_count, test(122, "@moulitest: %#.o %#.0o", o, o));
    ADD_TEST_RESULT(&err_count, test(123, "this %#o number", 0));
    ADD_TEST_RESULT(&err_count, test(125, "%#.5o", 1));

    ft_printf("conversion x\n");
    unsigned long long x = 42;
    ADD_TEST_RESULT(&err_count, test(122, "%#08x", x));
    ADD_TEST_RESULT(&err_count, test(123, "this %#x number", 0));
    ADD_TEST_RESULT(&err_count, test(124, "@moulitest: %#.x %#.0x", x, x));
    ADD_TEST_RESULT(&err_count, test(125, "@moulitest: %#.x %#.0x", 0, 0));
    ADD_TEST_RESULT(&err_count, test(126, "%#.5x", 1));
    ADD_TEST_RESULT(&err_count, test(3027, "%#8x", 42));
    ADD_TEST_RESULT(&err_count, test(3028, "%#-08x", 42));
    
    ft_printf("conversion p\n");
    unsigned long long *p = NULL;
    ADD_TEST_RESULT(&err_count, test(122, "%p", p));
    ADD_TEST_RESULT(&err_count, test(122, "%5p", p));
    ADD_TEST_RESULT(&err_count, test(122, "%.5p", p));
    ADD_TEST_RESULT(&err_count, test(122, "%.p, %.0p", p, p));
    ADD_TEST_RESULT(&err_count, test(122, "%.p, %.0p", 0, 0));

    ft_printf("conversion pct\n");
    ADD_TEST_RESULT(&err_count, test(2000, "%%"));
    ADD_TEST_RESULT(&err_count, test(2001, "%0+- #10%"));
    ADD_TEST_RESULT(&err_count, test(2002, "%0+- #.10%"));
    ADD_TEST_RESULT(&err_count, test(2003, "%0+- #10.10%"));
    ADD_TEST_RESULT(&err_count, test(2004, "%10%"));
    ADD_TEST_RESULT(&err_count, test(2005, "%-10%"));
    ADD_TEST_RESULT(&err_count, test(2006, "%.10%"));
    ADD_TEST_RESULT(&err_count, test(2007, "%-.10%"));
    ADD_TEST_RESULT(&err_count, test(2008, "%.0%"));
    ADD_TEST_RESULT(&err_count, test(2009, "%.2%"));

    ft_printf("conversion char\n");
    char c = 'z';
    ADD_TEST_RESULT(&err_count, test(2100, "%c", c));
    ADD_TEST_RESULT(&err_count, test(2101, "%10c", c));
    ADD_TEST_RESULT(&err_count, test(2102, "%-10c", c));
    ADD_TEST_RESULT(&err_count, test(2103, "%.10c", c));
    ADD_TEST_RESULT(&err_count, test(2104, "%-.10c", c));

    {
        ft_printf("conversion float\n");
        double
            d1 = 123456789.5876565,
            d2 = 123456789,
            d3 = -123456789.1,
            d4 = 0;

        test_double(&err_count, d1, 2500);
        test_double(&err_count, d2, 2600);
        test_double(&err_count, d3, 2700);
        test_double(&err_count, d4, 2800);
        test_double(&err_count, UINT32_MAX, 2900);

        ADD_TEST_RESULT(&err_count, test(2900, "%f", 3.9999999));
        ADD_TEST_RESULT(&err_count, test(2901, "%f", -5.9999999));
        ADD_TEST_RESULT(&err_count, test(2902, "this %.0f float", 1.6));
        ADD_TEST_RESULT(&err_count, test(2903, "%.0f", -3.85));
        ADD_TEST_RESULT(&err_count, test(2904, "%.1f", -3.85));
        ADD_TEST_RESULT(&err_count, test(2905, "%#.0f", 7.4));
        ADD_TEST_RESULT(&err_count, test(2906, "%#.0f", -7.4));
    }

    {
        int id = 3000;
        ADD_TEST_RESULT(&err_count, test(id + 0, "%Lf",  23.375094499l));
        ADD_TEST_RESULT(&err_count, test(id + 1, "%Lf",  -985.765426499l));
        ADD_TEST_RESULT(&err_count, test(id + 2, "%Lf",  0.08942555l));
        ADD_TEST_RESULT(&err_count, test(id + 3, "%Lf",  -56.2012685l));
        ADD_TEST_RESULT(&err_count, test(id + 4, "%Lf",  43.4399999l));
        ADD_TEST_RESULT(&err_count, test(id + 5, "%Lf",  -5.0299999l));
        ADD_TEST_RESULT(&err_count, test(id + 6, "%Lf",  43.43999949l));
        ADD_TEST_RESULT(&err_count, test(id + 7, "%Lf",  -5.02999949l));
        ADD_TEST_RESULT(&err_count, test(id + 8, "%Lf",  1.99999949l));
        ADD_TEST_RESULT(&err_count, test(id + 9, "%Lf",  -0.99999949l));
        ADD_TEST_RESULT(&err_count, test(id + 10, "%Lf",  3.9999999l));
        ADD_TEST_RESULT(&err_count, test(id + 11, "%Lf",  -5.9999999l));
        ADD_TEST_RESULT(&err_count, test(id + 12, "this %.7Lf float",  1.5l));
        ADD_TEST_RESULT(&err_count, test(id + 13, "%.7Lf",  7.5l));
        ADD_TEST_RESULT(&err_count, test(id + 14, "%.7Lf",  1.0l));
        ADD_TEST_RESULT(&err_count, test(id + 15, "%.7Lf",  -3.85l));
        ADD_TEST_RESULT(&err_count, test(id + 16, "%.7Lf",  573.924l));
        ADD_TEST_RESULT(&err_count, test(id + 17, "%.7Lf",  -958.125l));
        ADD_TEST_RESULT(&err_count, test(id + 18, "%.7Lf",  23.00041l));
        ADD_TEST_RESULT(&err_count, test(id + 19, "%.7Lf",  0.0000039l));
        ADD_TEST_RESULT(&err_count, test(id + 20, "%.7Lf",  -7.00036l));
        ADD_TEST_RESULT(&err_count, test(id + 21, "%.7Lf",  -0.000032l));
        ADD_TEST_RESULT(&err_count, test(id + 22, "%.7Lf",  0.0000001l));
        ADD_TEST_RESULT(&err_count, test(id + 23, "%.7Lf",  -0.0000001l));
        ADD_TEST_RESULT(&err_count, test(id + 24, "%.7Lf",  9873.000001l));
        ADD_TEST_RESULT(&err_count, test(id + 25, "%.7Lf",  -875.000001l));
        ADD_TEST_RESULT(&err_count, test(id + 26, "%.7Lf",  999.9999999l));
        ADD_TEST_RESULT(&err_count, test(id + 27, "%.7Lf",  -99.9999999l));
        ADD_TEST_RESULT(&err_count, test(id + 28, "%.7Lf",  0.999999l));
        ADD_TEST_RESULT(&err_count, test(id + 29, "%.7Lf",  -0.999999l));
        ADD_TEST_RESULT(&err_count, test(id + 30, "%.7Lf",  23.375094499l));
        ADD_TEST_RESULT(&err_count, test(id + 31, "%.7Lf",  -985.765426499l));
        ADD_TEST_RESULT(&err_count, test(id + 32, "%.7Lf",  0.0894255l));
        ADD_TEST_RESULT(&err_count, test(id + 33, "%.7Lf",  -56.2012685l));
        ADD_TEST_RESULT(&err_count, test(id + 34, "%.7Lf",  43.4399999l));
        ADD_TEST_RESULT(&err_count, test(id + 35, "%.7Lf",  -5.0299999l));
        ADD_TEST_RESULT(&err_count, test(id + 36, "%.7Lf",  43.43999949l));
        ADD_TEST_RESULT(&err_count, test(id + 37, "%.7Lf",  -5.02999949l));
        ADD_TEST_RESULT(&err_count, test(id + 38, "%.7Lf",  1.99999949l));
        ADD_TEST_RESULT(&err_count, test(id + 39, "%.7Lf",  -0.99999949l));
        ADD_TEST_RESULT(&err_count, test(id + 40, "%.7Lf",  3.9999999l));
        ADD_TEST_RESULT(&err_count, test(id + 41, "this %.8Lf float",  1.5l));
        ADD_TEST_RESULT(&err_count, test(id + 42, "%.8Lf",  7.5l));
        ADD_TEST_RESULT(&err_count, test(id + 43, "%.8Lf",  1.0l));
        ADD_TEST_RESULT(&err_count, test(id + 44, "%.8Lf",  -3.85l));
        ADD_TEST_RESULT(&err_count, test(id + 45, "%.8Lf",  573.924l));
        ADD_TEST_RESULT(&err_count, test(id + 46, "%.8Lf",  -958.125l));
        ADD_TEST_RESULT(&err_count, test(id + 47, "%.8Lf",  23.00041l));
        ADD_TEST_RESULT(&err_count, test(id + 48, "%.8Lf",  0.00000039l));
        ADD_TEST_RESULT(&err_count, test(id + 49, "%.8Lf",  -7.00036l));
        ADD_TEST_RESULT(&err_count, test(id + 50, "%.8Lf",  -0.0000032l));
        ADD_TEST_RESULT(&err_count, test(id + 51, "%.8Lf",  0.00000001l));
        ADD_TEST_RESULT(&err_count, test(id + 52, "%.8Lf",  -0.00000001l));
        ADD_TEST_RESULT(&err_count, test(id + 53, "%.8Lf",  9873.000001l));
        ADD_TEST_RESULT(&err_count, test(id + 54, "%.8Lf",  -875.000001l));
        ADD_TEST_RESULT(&err_count, test(id + 55, "%.8Lf",  999.9999999l));
        ADD_TEST_RESULT(&err_count, test(id + 56, "%.8Lf",  -99.99999999l));
        ADD_TEST_RESULT(&err_count, test(id + 57, "%.8Lf",  0.999999l));
        ADD_TEST_RESULT(&err_count, test(id + 58, "%.8Lf",  -0.999999l));
        ADD_TEST_RESULT(&err_count, test(id + 59, "%.8Lf",  23.375094499l));
        ADD_TEST_RESULT(&err_count, test(id + 60, "%.8Lf",  -985.765426499l));
        ADD_TEST_RESULT(&err_count, test(id + 61, "%.8Lf",  0.0894255l));
        ADD_TEST_RESULT(&err_count, test(id + 62, "%.8Lf",  -56.2012685l));
        ADD_TEST_RESULT(&err_count, test(id + 63, "%.8Lf",  43.4399999l));
        ADD_TEST_RESULT(&err_count, test(id + 64, "%.8Lf",  -5.0299999l));
        ADD_TEST_RESULT(&err_count, test(id + 65, "%.8Lf",  43.43999949l));
        ADD_TEST_RESULT(&err_count, test(id + 66, "%.8Lf",  -5.02999949l));
        ADD_TEST_RESULT(&err_count, test(id + 67, "%.8Lf",  1.99999949l));
        ADD_TEST_RESULT(&err_count, test(id + 68, "%.8Lf",  -0.99999949l));
        ADD_TEST_RESULT(&err_count, test(id + 69, "%.8Lf",  3.9999999l));
        ADD_TEST_RESULT(&err_count, test(id + 70, "%.0Lf",  LDBL_MIN));
        ADD_TEST_RESULT(&err_count, test(id + 71, "%.0Lf",  -LDBL_MIN));
        ADD_TEST_RESULT(&err_count, test(id + 72, "%.3Lf",  -LDBL_MIN));
        ADD_TEST_RESULT(&err_count, test(id + 73, "%Lf",  -LDBL_MIN));
        ADD_TEST_RESULT(&err_count, test(id + 74, "%.8Lf",  -LDBL_MIN));
    }

    (void)argc;
    (void)argv;
    ft_printf("\n");
    int errors = GET_ERROR(err_count);
    int count = GET_COUNT(err_count);
    if (errors > 0)
        dprintf(STDERR_FILENO, "\033[31mERROR COUNT\033[0m: %d / %d (%.2f%%)\n", errors, count, (double)errors / count * 100);
    else
        printf("\033[32mAll %d tests OK\n\033[0m", count);

    return (0);
}

void test_double(unsigned long long *errcnt, double d, int id)
{
    ADD_TEST_RESULT(errcnt, test(id + 0, "%f", d));
    ADD_TEST_RESULT(errcnt, test(id + 1, "%.f", d));
    ADD_TEST_RESULT(errcnt, test(id + 2, "%.0f", d));
    ADD_TEST_RESULT(errcnt, test(id + 3, "%.2f", d));
    ADD_TEST_RESULT(errcnt, test(id + 4, "%.10f", d));
    ADD_TEST_RESULT(errcnt, test(id + 5, "%.20f", d));
    ADD_TEST_RESULT(errcnt, test(id + 6, "%20f", d));
    ADD_TEST_RESULT(errcnt, test(id + 7, "%-20f", d));
    ADD_TEST_RESULT(errcnt, test(id + 8, "%10f", d));
    ADD_TEST_RESULT(errcnt, test(id + 9, "%-10f", d));
    ADD_TEST_RESULT(errcnt, test(id + 10, "%20.5f", d));
    ADD_TEST_RESULT(errcnt, test(id + 11, "%-20.5f", d));
    ADD_TEST_RESULT(errcnt, test(id + 12, "%20.10f", d));
    ADD_TEST_RESULT(errcnt, test(id + 13, "%-20.10f", d));
    ADD_TEST_RESULT(errcnt, test(id + 14, "%0+20f", d));
    ADD_TEST_RESULT(errcnt, test(id + 15, "%0 20f", d));
}