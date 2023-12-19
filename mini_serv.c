#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>

const int BUF_SIZE = 42 * 4096;
typedef struct client {
    int id;
    char msg[110000];
} t_client;

t_client clients[1024];

int max = 0, next_id = 0;
fd_set active, readyWrite, readyRead;
char buf_write[BUF_SIZE], buf_read[BUF_SIZE];

void fetal_error(void) {
  write(2, "Fatal error\n", 12);
  exit (1);
}

void send_all(int es) {
  for(int i = 0; i <= max; i++)
    if (FD_ISSET(i, &readyWrite) && i != es)
      send(i, buf_write, strlen(buf_write), 0);
}

int main (int ac, char **av) {
  if (ac != 2) {
    write(2, "Argument error\n", 16);
    exit(1);
  }
  int port = atoi(av[1]);

  bzero(&clients, sizeof(clients));
  FD_ZERO(&active);

  int serverSocket = socket(AF_INET, SOCK_STREAM, 0); 
  if (serverSocket < 0) 
    fetal_error();

  max = serverSocket;
  FD_SET(serverSocket, &active);

  struct sockaddr_in servaddr;
  socklen_t len = sizeof(servaddr);
  servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(port); 

  if ((bind(serverSocket, (const struct sockaddr *)&servaddr, sizeof(servaddr))) < 0)
    fetal_error();
  if (listen(serverSocket, 128) < 0) 
    fetal_error();

  while (1) {
    readyRead = readyWrite = active;
    if (select(max + 1, &readyRead, &readyWrite, NULL, NULL) < 0)
      continue ;

    for(int s = 0; s <= max; s++) {

      if (FD_ISSET(s, &readyRead) && s == serverSocket) {
        int client = accept(serverSocket, (struct sockaddr *)&servaddr, &len);
        if (client < 0)
          fetal_error();
        max = (client > max) ? client : max;
        clients[client].id = next_id++;
        FD_SET(client, &active);
        sprintf(buf_write, "server : new client %d\n", clients[client].id);
        send_all(client);
        break;
      }
      if (FD_ISSET(s, &readyRead) && s != serverSocket) {
        int res = recv(s, buf_read, BUF_SIZE, 0);
        if (res <= 0) {
          sprintf(buf_write, "server: left client %d\n", clients[s].id);
          send_all(s);
          bzero(&clients[s].msg, strlen(clients[s].msg));
          FD_CLR(s, &active);
          close(s);
          break;
        }
        else {
          for(int i = 0, j = strlen(clients[s].msg); i < res; i++, j++) {
            clients[s].msg[j] = buf_read[i];
            if (clients[s].msg[j] == '\n')
            {
              clients[s].msg[j] = '\0';
              sprintf(buf_write, "client %d: %s\n", clients[s].id, clients[s].msg);
              send_all(s);
              bzero(&clients[s].msg, strlen(clients[s].msg));
              j = -1; 
            }
          }
        break;
        }
      }
    }
  }
}
