#ifndef SRC_NODE_ASYNCAPI_TYPES_H_
#define SRC_NODE_ASYNCAPI_TYPES_H_

// LIBUV API types are all opaque pointers for ABI stability
// typedef undefined structs instead of void* for compile time type safety
typedef struct napi_uv_work_t__ *napi_work;
typedef void (*napi_work_cb)(void*);

typedef struct napi_uv_async_t__ *napi_async;
typedef void (*napi_async_cb)(void*);

typedef struct napi_uv_handle_t__ *napi_handle;
typedef void (*napi_handle_cb)(void*);
#endif  // SRC_NODE_ASYNCAPI_TYPES_H_
