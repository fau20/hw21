#include "pipe_networking.h"


int main() {

  int to_client;
  int from_client;

  while(1){
    from_client = server_handshake( &to_client );
    char line[1000];
    while(read(from_client, line, sizeof(line)) != 0){
      int i = 0;
      while(line[i]) {
        if(line[i] >= 'a' && line[i] <= 'z') {
          line[i] = line[i] - 'a' + 'A';
        }
        i++;
      }

      write(to_client, line, sizeof(line));
    }
  }
}
