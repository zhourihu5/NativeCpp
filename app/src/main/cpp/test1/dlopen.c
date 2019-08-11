//
// Created by hu zhou on 2019-08-11.
//

#include <stdio.h>
#include <dlfcn.h>

typedef void(*hello_world)();

int main(int argc, char** argv) {
    void *handle = dlopen(argv[1], RTLD_LAZY);//dlopen 返回了一个handle用于以后的各项dl操作的对象
    if(handle) {
        hello_world hello = (hello_world)dlsym(handle, "hello");//利用返回的handle来找函数地址，并把函数地址转换成函数指针，提供调用
        if(hello) {
            hello();//调用
        } else {
            printf("%s\n", dlerror());
        }
        dlclose(handle);
    } else {
        printf("dlopen %s failed!\n", argv[1]);
    }
    return 0;
}