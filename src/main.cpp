#include "./DemoAsyncWorker.h"

using namespace Napi;

static Value demo(const CallbackInfo& info) {
  Env env = info.Env();

  if (info.Length() != 1) {
    Error::New(env, "arguments.length !== 1").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if (!info[0].IsFunction()) {
    Error::New(env, "typeof arguments[0] !== 'function'").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  Function callback = info[0].As<Function>();
  DemoAsyncWorker *w = new DemoAsyncWorker(callback);
  w->Queue();

  return env.Undefined();
}

Object init(Env env, Object exports) {
  Object global = env.Global();
  Object console = global.Get("console").As<Object>();
  Function log = console.Get("log").As<Function>();
  log.Call(console, { String::New(env, "[C++] Call console.log()") });
  Function module = Function::New(env, demo);
  return module;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, init)
