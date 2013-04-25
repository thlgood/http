#ifndef HTTP_HEAD_STRUCT_H
#define HTTP_HEAD_STRUCT_H
#include <linux/limits.h>

#define HOST_MAX_LEN    64
#define URI_MAX_LEN     PATH_MAX
#define UA_MAX_LEN      64
#define COOKIE_MAX_LEN  4096
typedef enum {
    HTTP_REQ_METHOD_GET, 
    HTTP_REQ_METHOD_POST,
    HTTP_REQ_METHOD_HEAD, 
    HTTP_REQ_METHOD_PUT, 
    HTTP_REQ_METHOD_DELETE, 
    HTTP_REQ_METHOD_TRACE, 
    HTTP_REQ_METHOD_CONNECT, 
    HTTP_REQ_METHOD_OPTIONS, 
    HTTP_REQ_METHOD_UNKNOW
}req_method_e;

typedef enum {
    HTTP_1_0,
    HTTP_1_1
}http_version_e;

typedef enum {
    KEEP_ALIVE,
    CLOSE
}connection_type_e;

typedef struct {
    req_method_e        method;
    char                URI[URI_MAX_LEN];
    char                host[HOST_MAX_LEN];
    char                user_agent[UA_MAX_LEN];
    char                cookie[COOKIE_MAX_LEN];
    http_version_e      http_version;
    connection_type_e   connection;
}http_request_head_s;

#endif
