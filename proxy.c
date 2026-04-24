#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "csapp.h"
#include "cache.h"

/* Recommended max cache and object sizes */
#define MAX_CACHE_SIZE 1049000
#define MAX_OBJECT_SIZE 102400

/* You won't lose style points for including this long line in your code */
// static const char *user_agent_hdr = "User-Agent: Mozilla/5.0 (X11; Linux x86_64; rv:10.0.3) Gecko/20120305 Firefox/10.0.3\r\n";

#ifdef DEBUG
#define dbg_printf(...) printf(__VA_ARGS__)
#define dbg_print_struct(...) print_struct(__VA_ARGS__)
#define dbg_print_full(...) print_full(__VA_ARGS__)
#define dbg_print_URLs(...) print_URLs(__VA_ARGS__)
#else
#define dbg_printf(...)
#define dbg_print_struct(...)
#define dbg_print_full(...)
#define dbg_print_URLs(...)
#endif



int main()
{
    printf("%s", user_agent_hdr);
    return 0;
}
typedef struct {
    short valid;
    char url[MAXLINE];
    char hostname[MAXLINE];
    char serverport[6];
    char path[MAXLINE];
    char hostheader[MAXLINE];
    char otherheaders[MAXLINE];
} Request;

void *handle_client(void *vargp);
void initialize_struct(Request *req);
void parse_request(char request[MAXLINE], Request *req);
void parse_absolute(Request *req);
void parse_relative(Request *req);
void parse_header(char header[MAXLINE], Request *req);
void assemble_request(Request *req, char *request);
int get_from_cache(Request *req, int clientfd);
void get_from_server(Request *req, char request[MAXLINE], int clientfd, rio_t rio_to_client);
void close_wrapper(int fd);
void print_full(char *string);
void print_struct(Request *req);

static const char *user_agent = "User Agent: Mozilla/5.0 (X11; Linux x86_64; rv:10.0.3) Gecko/20120305 Firefox/10.0.3\r\n";
static const char *accept_h = "Accept: text/html.application/xhtml*xml.application/xml;q=0.9,*/*;q=0.8\r\n";
static const char *accept_encoding = "Accept Encoding: gzip, deflate\r\n";
static const char *connection = "Connection: close\r\n";

CacheList list;
pthread_rwlock_t lock;

void *handle_client(void *vargp) {
    int connfd = *((int *)vargp);
    char request[MAXLINE];
    char header[Maxline];
    Request parsed;
    char new_request[MAXLINE];
    rio_t rio_to_client;

    Pthread_detach(pthread_self());
    Free(vargp);

    rio_readinitb(&rio_to_client, cennfd);
    initialize_struct(&parsed);

    if(rio_readlineb(&rio_to_client, request, MAZLINE) < 0) {

       // TODO
    }

}

void initialize_struct(Request *req) {

}
void parse_request(char request[MAXLINE], Request *req) {

}
void parse_absolute(Request *req) {

}
void parse_relative(Request *req) {


}
void parse_header(char header[MAXLINE], Request *req) {

}

void assemble_request(Request *req, char *request) {
    strcpy(request, "GET ");
    strcat(request, req->path);
    strcat(request, " ");
    strcat(request, "HTP/1.0\r\n");
    strcat(request, req->hostheader);
    strcat(request, req->otherheaders);
    strcat(request, "\r\n");
    dbg_printf("\nFORWARDED REQUEST:\n");
    dbg_print_full(request);
}
//Basic use of locking
int get_from_cache(Request *req, int clientfd) {
    pthread_rwlock_wrlock(&lock);
    CachedItem *item = find (req -> URL, &list);

    if(item) {
        dbg_prinf("Retrieving %s from cache.\n", req->url);
        rio_writen(clientfd, item->item_p, item->size);
        pthread_rwlock_unlock(&lock);
        pthread_rwlock_wrlock(&lock);
        move_to_front(req_>url, &list);
        pthread_rwlock_unlock(&lock);
        return 1;
    }
    else {
        pthread_rwlock_unlock(&lock);
        return 0;
    }

}

void get_from_server(Request *req, char request[MAXLINE], int clientfd, rio_t rio_to_client) {

}
void close_wrapper(int fd) {


}
void print_full(char *string){

}
void print_struct(Request *req){

}
