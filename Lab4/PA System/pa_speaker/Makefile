all: pa_speaker


pa_speaker: pa_speaker.c
	gcc pa_speaker.c -o pa_speaker -lzmq -L /opt/homebrew/Cellar/zeromq/4.3.5_1/lib -I /opt/homebrew/Cellar/zeromq/4.3.5_1/include

clean:
	rm -rf pa_speaker *.dSYM