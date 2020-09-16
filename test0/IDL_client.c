/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "IDL.h"
#include <stdio.h>
#include <iostream>


void trpc_6(char* host, char* cmd, int value) {
  CLIENT *clnt;
  float  *result_1;
  args  gotemp_6_arg;
  float  *result_2;
  args  gohumi_6_arg;
  clnt = clnt_create(host, TRPC, TRPC_VERS, "udp");
  if (clnt == NULL) {
    clnt_pcreateerror(host);
    exit(1);
  }
  if (!strcmp(cmd, "gotemp")) {
    gotemp_6_arg.value = value;
    gotemp_6_arg.operation = 'a';
    result_1 = gotemp_6(&gotemp_6_arg, clnt);
    if (result_1 == NULL) {
      clnt_perror(clnt, "call gotemp_6_arg failed:");
    }
  }
  if (!strcmp(cmd, "gohumi")) {
    gohumi_6_arg.value = value;
    gohumi_6_arg.operation = 'b';
    result_2 = gohumi_6(&gohumi_6_arg, clnt);
    if (result_2 == NULL) {
      clnt_perror(clnt, "call gohumi_6_arg failed:");
    }
  }
  clnt_destroy( clnt );
}


// ----------------------------------------------------------------------
int main(int argc, char* argv[]) {

  char *host = argv[1];

  if(argc < 2) {
    printf("usage: %s server_host gotemp [T] \n", argv[0]);
    exit(1);
  }

  char *cmd = argv[2];
  float t;
  sscanf(argv[3], "%f", &t);

  trpc_6(host, cmd, t);
}
