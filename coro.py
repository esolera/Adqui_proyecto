import numpy as np
import matplotlib.pyplot as plt
from scipy.io import wavfile
from scipy.io.wavfile import write
from scipy.fftpack import fft, ifft,rfft,irfft
import struct as st
import os

for i in range(1000):
	f = open("/media/esolera/ExtraDrive1/TEC/cuatri_1/Adquisicion/proyecto2/entregable2/prueba/resultados_decodificador/resultado%i.txt"%i, "r")
	b = np.fromfile(f, dtype=np.int16)
	write('/media/esolera/ExtraDrive1/TEC/cuatri_1/Adquisicion/proyecto2/entregable2/prueba/wav/test%i.wav'%i, 8000, b)









#e=(a/(2**15))
#w=b
#t=np.arange(0,64)

#y=fft(a)
#print(abs(a))
#plt.plot(t,a,color='red')
#plt.plot(t,w)
#plt.show()