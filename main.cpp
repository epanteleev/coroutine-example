#include <windows.h>
#include <iostream>
#include <tchar.h>
#include <stdio.h>
#include <thread>

#include "asm/context.h"

static tb_context_t contexts[3];

static void func1(tb_context_from_t from) {
    contexts[0] = from.ctx;
    std::cout << "hello from coroutine" << std::endl;
    float s = 5;
    std::cout << s;
    tb_context_jump(contexts[0], nullptr);
}

int main(int argc, char** argv) {
    // the stacks
    static char       stacks1[16192];
    static char        stacks2[8192];

    // 通过stack1和func1生成context1
    contexts[1] = tb_context_make(stacks1, sizeof(stacks1), func1);
    float s = sqrt(5);
    tb_context_jump(contexts[1], contexts);

    std::cout <<"here " << s << " " << sqrt(5) << std::endl;
}