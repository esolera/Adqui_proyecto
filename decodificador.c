#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "kiss_fft.h"
#define WIN 64


int main(){


	int nfft = WIN, i, k;
    float f[64];
    int16_t abs[64];
	int16_t datos[64];
	kiss_fft_cfg cfg;
    kiss_fft_cpx cx_in[WIN];
    kiss_fft_cpx cx_out[WIN];
    int16_t buffer[64];
    int16_t buffer1[64];
    char filename_resil[200];
    char filename_real[200];
    char filename_imaginario[200];



    for(k=0;k<1000;k=k+1){
    	sprintf(filename_resil,"/media/esolera/ExtraDrive1/TEC/cuatri_1/Adquisicion/proyecto2/entregable2/prueba/resultados_decodificador/resultado%i.txt", k);
    	sprintf(filename_real,"/media/esolera/ExtraDrive1/TEC/cuatri_1/Adquisicion/proyecto2/entregable2/prueba/Resul_codificador/real%i.txt" , k);
    	sprintf(filename_imaginario, "/media/esolera/ExtraDrive1/TEC/cuatri_1/Adquisicion/proyecto2/entregable2/prueba/Resul_codificador/imaginario%i.txt", k);


		FILE *real = fopen( filename_real , "rb" );
		FILE *imaginario = fopen(filename_imaginario,"rb");
		FILE *resil = fopen(filename_resil,"wb");

		for (int i = 0;i<64;i++) {
        	fread(&buffer[i], 1, sizeof(int16_t) ,real);
        	fread(&buffer1[i], 1, sizeof(int16_t) ,imaginario);
        	cx_in[i].r=((int16_t)buffer[i])>>1;
        	cx_in[i].i=((int16_t)buffer1[i])>>1;
		}
		cfg = kiss_fft_alloc(nfft, 1, 0, 0);

		kiss_fft(cfg, cx_in, cx_out);



		for(i=0; i<64;i++){
			abs[i]=(((int16_t)(cx_out[i].r)))*pow(2,8);
			fwrite(&abs[i], 1,sizeof(int16_t) ,resil);

		
		}

		fclose(resil);
		fclose(imaginario);
		fclose(real);
	}
    free(cfg);
}