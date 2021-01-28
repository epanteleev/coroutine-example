#pragma once

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void* tb_context_t;

/*! the context-from type
 *
 * @ctx    the from-context
 * @priv   the passed user private data
 */
struct tb_context_from_t {
    tb_context_t ctx;
    const void* priv;
} ;

/*! the context entry function type
 *
 * @param from          the from-context
 */
typedef void (*tb_context_func_t)(tb_context_from_t from);

/*! make context from the given the stack space and the callback function
 *
 * @param stackdata     the stack data
 * @param stacksize     the stack size
 * @param func          the entry function
 *
 * @return              the context pointer
 */
tb_context_t tb_context_make(char* stackdata, size_t stacksize, tb_context_func_t func);

/*! jump to the given context
 *
 * @param ctx           the to-context
 * @param priv          the passed user private data
 *
 * @return              the from-context
 */
tb_context_from_t tb_context_jump(tb_context_t ctx, const void* priv);

#ifdef __cplusplus
}
#endif
