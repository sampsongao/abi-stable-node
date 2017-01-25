#include "node_asyncapi_internal.h"

napi_work napi_create_work() {
  napi_work_impl* worker = (napi_work_impl*) malloc(sizeof(napi_work_impl));
  uv_work_t* req = (uv_work_t*) malloc(sizeof(uv_work_t));
  req->data = worker;
  worker->work = req;
  return reinterpret_cast<napi_work>(worker);
}

void napi_delete_work(napi_work w) {
  napi_work_impl* worker = reinterpret_cast<napi_work_impl*>(w);
  if (worker != NULL) {
    if (worker->work != NULL) {
      delete worker->work;
    }
    delete worker;
  }
}

void* napi_work_get_data(napi_work w) {
  napi_work_impl* worker = reinterpret_cast<napi_work_impl*>(w);
  return worker->data;
}

void napi_work_set_data(napi_work w, void* data) {
  napi_work_impl* worker = reinterpret_cast<napi_work_impl*>(w);
  worker->data = data;
}

void napi_work_set_execute(napi_work w, void (*execute)(void* data)) {
  napi_work_impl* worker = reinterpret_cast<napi_work_impl*>(w);
  worker->execute = execute;
}

void napi_work_set_complete(napi_work w, void (*complete)(void* data)) {
  napi_work_impl* worker = reinterpret_cast<napi_work_impl*>(w);
  worker->complete = complete;
}

void napi_work_execute(uv_work_t* req) {
  napi_work_impl* worker = static_cast<napi_work_impl*>(req->data);
  worker->execute(worker->data);
}

void napi_work_complete(uv_work_t* req) {
  napi_work_impl* worker = static_cast<napi_work_impl*>(req->data);
  worker->complete(worker->data);
}

int napi_work_queue_worker(napi_work w) {
  napi_work_impl* worker = reinterpret_cast<napi_work_impl*>(w);
  return uv_queue_work(
             uv_default_loop(),
             worker->work,
             napi_work_execute,
             reinterpret_cast<uv_after_work_cb>(
                 napi_work_complete));
}


napi_async napi_create_async() {
  napi_async_impl* watcher = (napi_async_impl*) malloc(sizeof(napi_async_impl));
  uv_async_t* async = (uv_async_t*) malloc(sizeof(uv_async_t));
  watcher->async = async;
  async->data = watcher;
  return reinterpret_cast<napi_async>(watcher);
}

void napi_delete_async(napi_async w) {
  napi_async_impl* watcher = reinterpret_cast<napi_async_impl*>(w);
  if (watcher != NULL) {
    if (watcher->async != NULL) {
      delete watcher->async;
    }
    delete watcher;
  }
}

void napi_async_init(napi_async w) {
  napi_async_impl* watcher = reinterpret_cast<napi_async_impl*>(w);
  uv_async_init(uv_default_loop(), watcher->async,
      reinterpret_cast<uv_async_cb>(napi_async_listen));
}

void napi_async_set_data(napi_async w, void* data) {
  napi_async_impl* watcher = reinterpret_cast<napi_async_impl*>(w);
  watcher->data = data;
}

void* napi_async_get_data(napi_async w) {
  napi_async_impl* watcher = reinterpret_cast<napi_async_impl*>(w);
  return watcher->data;
}

napi_handle napi_async_get_handle(napi_async w) {
  return reinterpret_cast<napi_handle>(w);
}

void napi_async_set_listener(napi_async w, void (*listener)(void* data)) {
  napi_async_impl* watcher = reinterpret_cast<napi_async_impl*>(w);
  watcher->listener = listener;
}

int napi_async_send(napi_async w) {
  napi_async_impl* watcher = reinterpret_cast<napi_async_impl*>(w);
  return uv_async_send(watcher->async);
}

void napi_async_listen(uv_async_t* async) {
  napi_async_impl* watcher = static_cast<napi_async_impl*>(async->data);
  watcher->listener(watcher->data);
}


napi_handle napi_create_handle() {
  napi_handle_impl* handler = (napi_handle_impl*) malloc(sizeof(napi_handle_impl));
  uv_handle_t* handle = (uv_handle_t*) malloc(sizeof(uv_handle_t));
  handler->handle = handle;
  handle->data = handler;
  return reinterpret_cast<napi_handle>(handler);
}

void napi_delete_handle(napi_handle h) {
  napi_handle_impl* handler = reinterpret_cast<napi_handle_impl*>(h);
  if (handler != NULL) {
    if (handler->handle != NULL) {
      delete handler->handle;
    }
    delete handler;
  }
}

void napi_handle_set_data(napi_handle h, void* data) {
  napi_handle_impl* handler = reinterpret_cast<napi_handle_impl*>(h);
  handler->data = data;
}

void* napi_handle_get_data(napi_handle h) {
  napi_handle_impl* handler = reinterpret_cast<napi_handle_impl*>(h);
  return handler->data;
}

void napi_handle_ref(napi_handle h) {
  napi_handle_impl* handler = reinterpret_cast<napi_handle_impl*>(h);
  uv_ref(handler->handle);
}

void napi_handle_unref(napi_handle h) {
  napi_handle_impl* handler = reinterpret_cast<napi_handle_impl*>(h);
  uv_unref(handler->handle);
}

void napi_handle_set_close(napi_handle h, void (*close)(void* data)) {
  napi_handle_impl* handler = reinterpret_cast<napi_handle_impl*>(h);
  handler->close = close;
}

void napi_handle_do_close(uv_handle_t* handle) {
  napi_handle_impl* handler = static_cast<napi_handle_impl*>(handle->data);
  handler->close(handler->data);
}

void napi_handle_close(napi_handle h) {
  napi_handle_impl* handler = reinterpret_cast<napi_handle_impl*>(h);
  uv_close(handler->handle, reinterpret_cast<uv_close_cb>(napi_handle_do_close));
}
