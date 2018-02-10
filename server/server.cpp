/* 
 * 入口程序
 * 
 * created by itsl<itsl@foxmail.com>
 * 2018-2-8
 */
#include <signal.h>
#include <stdlib.h>
#include <iostream>

#include "scheduler/scheduler.hpp"

/* 
 * 处理 ctrl+c 的退出
 */
void my_handler(sig_t s);

int main(int argc, char* args[]) {
    // 注册回调函数
    signal(SIGINT, (__sighandler_t)my_handler);
    std::cout << "Press CTRL+C to exit." << std::endl;
    
    ltrov::scheduler::Scheduler scheduler();
    
    return 0;
}

void my_handler(sig_t s){
    std::cout << "Closing..." << std::endl;
    // exit(1);
}