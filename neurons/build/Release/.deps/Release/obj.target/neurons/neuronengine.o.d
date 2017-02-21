cmd_Release/obj.target/neurons/neuronengine.o := c++ '-DNODE_GYP_MODULE_NAME=neurons' '-DUSING_UV_SHARED=1' '-DUSING_V8_SHARED=1' '-DV8_DEPRECATION_WARNINGS=1' '-D_DARWIN_USE_64_BIT_INODE=1' '-D_LARGEFILE_SOURCE' '-D_FILE_OFFSET_BITS=64' '-DBUILDING_NODE_EXTENSION' -I/Users/guozhong/.node-gyp/0.10.48/include/node -I/Users/guozhong/.node-gyp/0.10.48/src -I/Users/guozhong/.node-gyp/0.10.48/deps/uv/include -I/Users/guozhong/.node-gyp/0.10.48/deps/v8/include  -Os -gdwarf-2 -mmacosx-version-min=10.5 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -fno-rtti -fno-exceptions -fno-threadsafe-statics -std=c++11 -MMD -MF ./Release/.deps/Release/obj.target/neurons/neuronengine.o.d.raw   -c -o Release/obj.target/neurons/neuronengine.o ../neuronengine.cpp
Release/obj.target/neurons/neuronengine.o: ../neuronengine.cpp \
  ../neuronengine.h
../neuronengine.cpp:
../neuronengine.h:
