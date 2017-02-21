{
  "targets": [
    {
      "target_name": "neurons",
      "sources": [ "neurons.cc","neuronengine.cpp" ],
      "cflags" : [ "-std=c++11"],
        "conditions": [
          [ 'OS=="mac"', {
            "xcode_settings": {
              "OTHER_CPLUSPLUSFLAGS" : [ "-std=c++11"]
            },
          }],
        ]
    }
  ]
}