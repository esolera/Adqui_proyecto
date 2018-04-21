#define DFIXED_POINT 16

#include <stdio.h>
#include <math.h>
#include "kiss_fft.h"

#define WIN 64

int main()
{
    int nfft = WIN, i, fx;
    float f[64];
    float abs[64];
    kiss_fft_cfg cfg;
    kiss_fft_cpx cx_in[WIN];
    kiss_fft_cpx cx_out[WIN];
    int16_t a[64] = {-4831, -3466, -5133, -4747,  -980, -4661,   946,   338,   135,  3515,  3332,  2529,
  4317,  3418,  4481,  5662,  1552,  5209,   -14,  3062,   831, -2886,  2676, -4108,
 -1429,   295, -2114,  -877,  -146, -2218, -2027,   388, -2050,  1918,  2735,  4677,
  6164,  5558,  5829,  5527,  4683,  3051,    92, -1361,  -919, -4917,   715, -3533,
 -1795,   -87, -3816,   284, -2277, -1770, -1186,  -170, -1287,  2915,  2813,  3280,
  6580,  4164,  5758,  6356}
 ;


    cfg = kiss_fft_alloc(nfft, 0, 0, 0);
    for (i = 0;i<WIN;i++) {
            cx_in[i].i = 0;
            cx_in[i].r = (a[i]);
        }
 

   printf("\n");

        kiss_fft(cfg, cx_in, cx_out);

    printf("\n");




for (i = 0;i<WIN;i++) {
            cx_in[i].i = cx_out[i].i;
            cx_in[i].r = cx_out[i].r;
}


cfg = kiss_fft_alloc(nfft, 1, 0, 0);


kiss_fft(cfg, cx_in, cx_out);




for(int j = 0; j < 64; j++) {
    abs[j]=((float)((int16_t)(cx_out[j].r)))*pow(2,6);
    printf("%f, ", abs[j]);
}


    free(cfg);


    return 0;
}
