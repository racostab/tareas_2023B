
/*
 * Alumno: Daniel Montes Guerrero
 * Compilar: gcc queue_write_v2.c -o write
 */

#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<string.h>

struct msg_buffer {
	long msg_type;
	char msg_text[100];
};

struct msg_buffer message;

int main(int argc, char** argv){
	key_t key;
	int msgid;
	if(argc < 2){
		printf("Syntaxis: queue_write <mensaje>\n");
		return -1;
	}
	key = ftok("prgfile", 65);
	msgid = msgget(key, 0666 | IPC_CREAT);
	strcpy(message.msg_text, argv[1]);
	message.msg_type = 1;
	printf("El mensaje a enviar es: %s\n", message.msg_text);
	msgsnd(msgid, &message, sizeof(message), 0);
	return 0;
}
