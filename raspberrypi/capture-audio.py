import pyaudio
from match_file_acrcloud import recognize
import wave

# ACRCloud wants PCM 16 bit, mono 8000 Hz

form_1 = pyaudio.paInt16  # 16-bit resolution
chans = 1  # 1 channel
samp_rate = 44100  # 44.1kHz sampling rate
chunk = 4096  # 2^12 samples for buffer
record_secs = 30  # seconds to record

audio = pyaudio.PyAudio()  # create pyaudio instantiation

dev_index = 0
for ii in range(audio.get_device_count()):
    if "USB" in audio.get_device_info_by_index(ii).get('name'):
        dev_index = ii

print("capturing from audio device %s" % dev_index)

# create pyaudio stream
stream = audio.open(format=form_1, rate=samp_rate, channels=chans,
                    input_device_index=dev_index, input=True,
                    frames_per_buffer=chunk)
print("recording...")
frames = []

# loop through stream and append audio chunks to frame array
for ii in range(0, int((samp_rate/chunk)*record_secs)):
    data = stream.read(chunk)
    frames.append(data)

print("finished recording")

# stop the stream, close it, and terminate the pyaudio instantiation
stream.stop_stream()
stream.close()
audio.terminate()

# TODO: don't fingerprint if it's quiet

wf = wave.open('tmp.wav', 'wb')
wf.setnchannels(chans)
wf.setsampwidth(audio.get_sample_size(form_1))
wf.setframerate(samp_rate)
wf.writeframes(b''.join(frames))
wf.close()

recognize('tmp.wav')
