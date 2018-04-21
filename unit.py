
from pydub import AudioSegment
from pydub.utils import make_chunks
import os

#list = os.listdir('/media/esolera/ExtraDrive1/TEC/cuatri_1/Adquisicion/proyecto2/entregable2/prueba/wav/audio_files') # dir is your directory path
#number_files = len(list)

sound1 = AudioSegment.from_wav("/media/esolera/ExtraDrive1/TEC/cuatri_1/Adquisicion/proyecto2/entregable2/prueba/wav/test0.wav")
sound2 = AudioSegment.from_wav("/media/esolera/ExtraDrive1/TEC/cuatri_1/Adquisicion/proyecto2/entregable2/prueba/wav/test1.wav")
combined_sounds = sound1 + sound2
combined_sounds.export("testac.wav", format="wav")

for i in range(0,1000):
	sound1 = AudioSegment.from_wav("testac.wav")
	sound2 = AudioSegment.from_wav("/media/esolera/ExtraDrive1/TEC/cuatri_1/Adquisicion/proyecto2/entregable2/prueba/wav/test%i.wav"%i)
	combined_sounds = sound1 + sound2
	combined_sounds.export("testac.wav", format="wav")