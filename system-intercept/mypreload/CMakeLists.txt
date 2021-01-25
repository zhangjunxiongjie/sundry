

add_library(start SHARED start.c intercept_syscall.c syscall_logger.c arithmetic.c)
target_link_libraries(start PRIVATE syscall_intercept)






