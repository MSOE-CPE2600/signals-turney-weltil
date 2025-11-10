CFLAGS=-c -g -Wall -Werror
CC=gcc

all: signal_alarm signal_handler signal_segfault signal_sigaction recv_signal send_signal reciever server

recv_signal: recv_signal.o
	$(CC) -o recv_signal recv_signal.o

reciever: reciever.o
	$(CC) -o reciever reciever.o

server: server.o
	$(CC) -o server server.o

send_signal: send_signal.o
	$(CC) -o send_signal send_signal.o

signal_alarm: signal_alarm.o
	$(CC) -o signal_alarm signal_alarm.o

signal_handler: signal_handler.o
	$(CC) -o signal_handler signal_handler.o

signal_segfault: signal_segfault.o
	$(CC) -o signal_segfault signal_segfault.o

signal_sigaction: signal_sigaction.o
	$(CC) -o signal_sigaction signal_sigaction.o

clean:
	rm -f *.o signal_alarm signal_handler signal_segfault signal_sigaction recv_signal send_signal reciever server

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

