#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>
#include "kiss_fft.h"

#define WIN 64

int main()
{
    int nfft = WIN, i, fx,j;
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
            cx_in[i].i = 0.0;
            cx_in[i].r = (float)(a[i]/pow(2,15));
        }
    
    

  

        kiss_fft(cfg, cx_in, cx_out);
         for(j = 0; j < 64; j++) {
        printf("%f,", cx_out[j].r);
    }
    printf("\n");

        //Display all values
        /*
        for (i = 0;i<WIN;i++) {
            //printf("Joe: cx_out[i].r:%f\n", cx_out[i].r);
            //printf("Joe: cx_out[i].i:%f\n", cx_out[i].i);
            intensity = sqrt(pow(cx_out[i].r,2) + pow(cx_out[i].i,2));
            printf("%d - %9.4f\n", i, intensity);
        }
        */
    free(cfg);


    return 0;
}
