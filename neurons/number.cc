/*
// hello.cc
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <node.h>
#include <v8.h>

#include "neuronengine.h"
using namespace v8; 

namespace smartnode {


   
  Handle<Value> Add(const Arguments& args) {
    HandleScope scope;
    String::Utf8Value utf8Value(args[0]->ToString());
    std::string input = std::string(*utf8Value);
    
    NeuronEngine myEngine;
    uint8_t vec[5] =  {10,11,12,13,14};
    int r =  myEngine.Learn(1,vec,5);
    //std::cout<<input<<std::endl;
    std::string result = input;
    //return scope.Close(String::New("world"));

   // String cstr = ToCString(Utf8Value);  

   // const char* cstr = ToCString(utf8Value);  
        //values[i] = env->NewStringUTF(cstr); 

Local<Number> num = Number::New(args[0]->Value() +
      args[1]->Value());

    return scope.Close(Number::New(num));
  }

  void init(Handle<Object> target) {
    target->Set(String::NewSymbol("Learn"),
        FunctionTemplate::New(Add)->GetFunction());
  }

  NODE_MODULE(neurons, init)

}  // namespace smartnode

*/

#include <node.h>

using namespace v8;

Handle<Value> Add(const Arguments& args) {
  HandleScope scope;

  if (args.Length() < 2) {
    ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
    return scope.Close(Undefined());
  }

  if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
    ThrowException(Exception::TypeError(String::New("Wrong arguments")));
    return scope.Close(Undefined());
  }

  Local<Number> num = Number::New(args[0]->NumberValue() +
      args[1]->NumberValue());
  return scope.Close(num);
}

void Init(Handle<Object> target) {
  target->Set(String::NewSymbol("add"),
      FunctionTemplate::New(Add)->GetFunction());
}

NODE_MODULE(neurons, Init)