#include <node.h>
#include <unistd.h>

int numberOfCalls = 0;

void Fork(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    auto pid = fork();

    args.GetReturnValue().Set(pid);
}

void Initialize(v8::Local<v8::Object> exports)
{
    NODE_SET_METHOD(exports, "fork", Fork);
}

NODE_MODULE(module_name, Initialize)
