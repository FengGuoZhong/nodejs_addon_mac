# nodejs_addon_mac

# Install

```bash
1、安装nodejs,本例使用的版本为 nodejs-v0.10.48
2、安装node-gyp
   执行sudo npm install -g node-gyp@3.4.0(用root身份)
3、安装Python2.7.x,本例安装的是v2.7.10
4、安装Xcode(mac下需要c++编译器)
4、编译：
   进入示例目录（hello），
   可以分开执行：先执行node-gyp configure，再执行 node-gyp build
   也可以执行node-gyp configure build，完成编译。
