#ifndef __DEMO_ASYNC_WORKER_H__
#define __DEMO_ASYNC_WORKER_H__

#include <napi.h>

class DemoAsyncWorker : public Napi::AsyncWorker {
  public:
    DemoAsyncWorker(Napi::Function& callback);

    ~DemoAsyncWorker();

    void Execute();

    void OnOK();
};

#endif // ! __DEMO_ASYNC_WORKER_H__
