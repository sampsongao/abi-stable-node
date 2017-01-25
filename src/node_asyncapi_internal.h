#ifndef SRC_NODE_ASYNCAPI_INTERNAL_H_
#define SRC_NODE_ASYNCAPI_INTERNAL_H_

#include "node_asyncapi.h"
#include "uv.h"

typedef struct napi_work_impl__ {
  uv_work_t* work;
  void* data;
  void (*execute)(void* data);
  void (*complete)(void* data);
} napi_work_impl;

void napi_work_execute(uv_work_t* req);
void napi_work_complete(uv_work_t* req);


typedef struct napi_async_impl__ {
  uv_async_t* async;
  void* data;
  void (*close)(void* data);
  void (*listener)(void* data);
} napi_async_impl;

void napi_async_listen(uv_async_t* async);


typedef struct napi_handle_impl__ {
  uv_handle_t* handle;
  void* data;
  void (*close)(void* data);
} napi_handle_impl;

void napi_handle_do_close(uv_handle_t* handle);
#endif  // SRC_NODE_ASYNCAPI_INTERNAL_H_
