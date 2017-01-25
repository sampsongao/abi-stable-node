#ifndef SRC_NODE_ASYNCAPI_H_
#define SRC_NODE_ASYNCAPI_H_

#include "node_asyncapi_types.h"
#include <stdlib.h>

#ifndef NODE_EXTERN
# ifdef _WIN32
#   ifndef BUILDING_NODE_EXTENSION
#     define NODE_EXTERN __declspec(dllexport)
#   else
#     define NODE_EXTERN __declspec(dllimport)
#   endif
# else
#   define NODE_EXTERN /* nothing */
# endif
#endif

extern "C" {
NODE_EXTERN napi_work napi_create_work();
NODE_EXTERN void napi_delete_work(napi_work w);
NODE_EXTERN void* napi_work_get_data(napi_work w);
NODE_EXTERN void napi_work_set_data(napi_work w, void* data);
NODE_EXTERN void napi_work_set_execute(napi_work w, void (*execute)(void*));
NODE_EXTERN void napi_work_set_complete(napi_work w, void (*complete)(void*));
NODE_EXTERN int napi_work_queue_worker(napi_work w);

NODE_EXTERN napi_async napi_create_async();
NODE_EXTERN void napi_delete_async(napi_async watcher);
NODE_EXTERN void napi_async_set_data(napi_async w, void* data);
NODE_EXTERN void* napi_async_get_data(napi_async w);
NODE_EXTERN napi_handle napi_async_get_handle(napi_async w);
NODE_EXTERN void napi_async_set_listener(napi_async w, void (*listen)(void* data));
NODE_EXTERN void napi_async_init(napi_async w);
NODE_EXTERN int napi_async_send(napi_async w);

NODE_EXTERN napi_handle napi_create_handle();
NODE_EXTERN void napi_handle_set_data(napi_handle h, void* data);
NODE_EXTERN void* napi_handle_get_data(napi_handle h);
NODE_EXTERN void napi_handle_ref(napi_handle h);
NODE_EXTERN void napi_handle_unref(napi_handle h);
NODE_EXTERN void napi_handle_set_close(napi_handle h, void (*close)(void* data));
NODE_EXTERN void napi_handle_close(napi_handle h);
} // extern "C"

#endif // SRC_NODE_ASYNCAPI_H_
