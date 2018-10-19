#include "./DemoAsyncWorker.h"
#include <thread>
#include <chrono>

using namespace Napi;

DemoAsyncWorker::DemoAsyncWorker(Function& callback): AsyncWorker(callback) {}
DemoAsyncWorker::~DemoAsyncWorker() {}

void DemoAsyncWorker::Execute() {
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void DemoAsyncWorker::OnOK() {
  Callback().Call({ String::New(Env(), "callbcak.") });
}
