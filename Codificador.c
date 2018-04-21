 
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "kiss_fft.h"
#define WIN 64

int main(){

    int nfft = WIN, i, fx;
    int k;
    float abs[64];
	int datos[64];
	int8_t buffer[64];
	int8_t buffer1[64];
	kiss_fft_cfg cfg;
    kiss_fft_cpx cx_in[WIN];
    kiss_fft_cpx cx_out[WIN];
    char filename_Datos[200];
    char filename_real[200];
    char filename_imaginario[200];
    for(k=0;k<1000;k=k+1){
    	sprintf(filename_Datos,"/media/esolera/ExtraDrive1/TEC/cuatri_1/Adquisicion/proyecto2/entregable2/prueba/textfiles/Datos%i.txt", k);
    	sprintf(filename_real,"/media/esolera/ExtraDrive1/TEC/cuatri_1/Adquisicion/proyecto2/entregable2/prueba/Resul_codificador/real%i.txt" , k);
    	sprintf(filename_imaginario, "/media/esolera/ExtraDrive1/TEC/cuatri_1/Adquisicion/proyecto2/entregable2/prueba/Resul_codificador/imaginario%i.txt", k);

		FILE *fptr = fopen(filename_Datos, "r");
		FILE *real = fopen( filename_real , "wb" );
		FILE *imaginario = fopen(filename_imaginario,"wb");

		for (int i = 0;i<64;i++) {
        	fscanf(fptr, "%i\n", &(datos[i]));
        	}

//		for (int i = 0;i<64;i++) {
//        	printf(" %i,",datos[i] );
//       	}
    





 		cfg = kiss_fft_alloc(nfft, 0, 0, 0);
    	for (i = 0;i<WIN;i++) {
            	cx_in[i].i = 0;
            	cx_in[i].r = (int16_t)(datos[i]>>1);
        	}
 

        kiss_fft(cfg, cx_in, cx_out);


		for (int i = 0;i<64;i++) {


   		fwrite(&cx_out[i].r, 1, sizeof(int16_t) ,real);
   		fwrite(&cx_out[i].i, 1, sizeof(int16_t) ,imaginario);
			}

//for (int i = 0;i<64;i++) {
//        printf(" %i,",cx_out[i].r );
  //      }
   		fclose(real);
   		fclose(imaginario);
	}
    free(cfg);


    return 0;
}

	/*if(((cx_out[i].r/4)<=128)&(cx_out[i].r/4)>=-128){
		buffer[i]=(int8_t)(cx_out[i].r>>2);
	}
	else{ 

		if((cx_out[i].r/4)>=128){
		buffer[i]=127;
		}
 		else{
 			buffer[i]=-127;
 		}
	}
	if(((cx_out[i].i/4)<=128)&(cx_out[i].r/4)>=-128){
		buffer1[i]=(int8_t)(cx_out[i].i>>2);
	}
	else{ 

		if((cx_out[i].i/4)>=128){
		buffer1[i]=127;
		}
 		else{
 			buffer1[i]=-127;
 		}
	}
*/



/*printf("\n");
for(int j = 0; j < 64; j++) {
    
    printf("%i, ", buffer[j]);
}




for (i = 0;i<WIN;i++) {
            cx_in[i].i = cx_out[i].i>>1;
            cx_in[i].r = cx_out[i].r>>1;
}


cfg = kiss_fft_alloc(nfft, 1, 0, 0);


kiss_fft(cfg, cx_in, cx_out);


printf("\n");

for(int j = 0; j < 64; j++) {
    abs[j]=((float)((int16_t)(cx_out[j].r)))*pow(2,8);
}
*/






