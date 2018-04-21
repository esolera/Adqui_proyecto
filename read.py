import numpy as np
import matplotlib.pyplot as plt
from scipy.io import wavfile
from scipy.fftpack import fft, ifft,rfft,irfft
import struct as st
import os

list = os.listdir('/media/esolera/ExtraDrive1/TEC/cuatri_1/Adquisicion/proyecto2/entregable2/prueba/audio_files') # dir is your directory path
number_files = len(list)


for i in range(0,number_files-1):
	fs, data = wavfile.read('/media/esolera/ExtraDrive1/TEC/cuatri_1/Adquisicion/proyecto2/entregable1/audio_files/chunk%i.wav'%i)
	k = data.T[0] # hay dos canales

	we=np.int16(k)
	print(we)

	with open('/media/esolera/ExtraDrive1/TEC/cuatri_1/Adquisicion/proyecto2/entregable2/prueba/textfiles/Datos%i.txt'%i, 'w') as file:
		for a in range(64):
			file.write("%i\n" %k[a])


