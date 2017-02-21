
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <node.h>

#include "neuronengine.h"

using namespace v8;

NeuronEngine myEngine;

  int * toIntArray(char *data,int length) { //字符数组转int数组
      const char * split = ",";
      char *token;
      int *intArray;
      intArray = new int[length];
      int arrayLen = 0;
      token = strtok(data,split);

      while(token!=NULL) {
          intArray[arrayLen] = atoi(token);
          arrayLen++;
          token = strtok(NULL,split);
      }

      for(int i=0;i<arrayLen;i++){
          //std::cout<<"vec"<<intArray[i]<<std::endl;
      }

      return intArray;
  }

Handle<Value> Learn(const Arguments& args) {
    String::Utf8Value utf8Value(args[0]->ToString());
    std::string sourceData = std::string(*utf8Value);
    //std::cout<<" length:"<<sourceData.length()<<std::endl;

    char strData[1024];
    bzero(strData, 1024);
    strcpy(strData, sourceData.c_str());

    int * data;
    data = ::toIntArray(strData,sourceData.length());

    HandleScope scope;

    if (data[0] == 1) {
        std::cout<<"\n--------------Learn-------------"<<std::endl;
        int length = data[1];
        uint8_t vec[length]; //data[1]:length
        int j = 3;
        std::cout<<"vec:"<<std::endl;
        for (int i = 0;i < length;i++) {
            vec[i] =  data[j];
            std::cout<<i<<":"<<data[j]<<std::endl;
            j++;
        }

        int result =  myEngine.Learn(data[2],vec,length); //data[2]:category
        std::cout<<" learn result: (neurons size) "<<result<<std::endl;

        
        Local<Number> num = Number::New(result);
        return scope.Close(num);
    }
    else{
        return scope.Close(String::New("Wrong arguments"));
    }

}

Handle<Value> Classify(const Arguments& args) {

    String::Utf8Value utf8Value(args[0]->ToString());
    std::string sourceData = std::string(*utf8Value);
    //std::cout<<" length:"<<sourceData.length()<<std::endl;

    char strData[1024];
    bzero(strData, 1024);
    strcpy(strData, sourceData.c_str());

    int * data;
    data = ::toIntArray(strData,sourceData.length());

    HandleScope scope;
    if (data[0] == 0) {
        cout<<"\n--------------Classify-------------"<<endl;
        int length = data[1];
        uint8_t vec[length]; //data[1]:length
        int j = 2;
        for (int i = 0;i < data[1];i++) {
            vec[i] =  data[j];
            std::cout<<i<<":"<<data[j]<<std::endl;
            j++;

        }

        int result =  myEngine.Classify(vec,length);
        if(result > 0){
           std::cout<<" Classify result category:"<<result<<std::endl;
        }
        else{
            std::cout<<" nukonw:"<<result<<std::endl;
        }

        HandleScope scope;
        Local<Number> num = Number::New(result);
        return scope.Close(num);

    }
    else{
        return scope.Close(String::New("Wrong arguments"));
    }

}

void Init(Handle<Object> target) {
  target->Set(String::NewSymbol("Learn"),
      FunctionTemplate::New(Learn)->GetFunction());

    target->Set(String::NewSymbol("Classify"),
      FunctionTemplate::New(Classify)->GetFunction());
}



NODE_MODULE(neurons, Init)