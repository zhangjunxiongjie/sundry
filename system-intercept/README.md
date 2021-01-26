基于 Linux glibc 的一个系统 hook 使用到了 [syscall_intercept](https://github.com/pmem/syscall_intercept)

- mypreload/   对两个接口函数的重载，需要使用环境变量 LD_PRELOAD（局部有效） 或 /etc/ld.so.preload（全局有效） 设置生成后的共享库路径方可生效；
- user-interface/   接口层工具，用于配置策略查看日志；

使用前需要正确编译安装 syscall_intercept，另策略配置文件和日志文件均未上传，编译好共享库（mypreload/ 编译后是一个共享库文件）和接口工具并启动运行后配置文件和日志文件会自动生成，生成路径可查看 ./mypreload/config.h。

代码多有瑕疵，且涉及系统调用，建议先使用 LD_PRELOAD 进行局部测试。

