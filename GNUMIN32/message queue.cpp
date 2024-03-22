#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#define MSG_SIZE 128
struct msg_buffer {
    long msg_type;
    char msg_text[MSG_SIZE];
};
int main() {
    key_t key;
    int msgid;
    struct msg_buffer message;
    key = ftok("msg_queue_program", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (fork() > 0) {
        message.msg_type = 1;
        printf(" message: ");
        fgets(message.msg_text, MSG_SIZE, stdin);
        msgsnd(msgid, &message, sizeof(message), 0);
        printf("Message sent by parent process: %s", message.msg_text);
    }
    else {
        msgrcv(msgid, &message, sizeof(message), 1, 0);
        printf("Child process received message: %s", message.msg_text);
    }
    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}
