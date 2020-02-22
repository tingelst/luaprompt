/* Copyright (C) 2012-2015 Papavasileiou Dimitris
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef _PROMPT_H_
#define _PROMPT_H_

#if defined(__cplusplus)
extern "C" {
#endif

#include <lauxlib.h>
#include <lualib.h>

#include "luaprompt/visibility_control.h"

#define LUAP_VERSION "0.7"

LUAPROMPT_PUBLIC
void luap_setprompts(lua_State *L, const char *single, const char *multi);
LUAPROMPT_PUBLIC
void luap_sethistory(lua_State *L, const char *file);
LUAPROMPT_PUBLIC
void luap_setname(lua_State *L, const char *name);
LUAPROMPT_PUBLIC
void luap_setcolor(lua_State *L, int enable);

LUAPROMPT_PUBLIC
void luap_getprompts(lua_State *L, const char **single, const char **multi);
LUAPROMPT_PUBLIC
void luap_gethistory(lua_State *L, const char **file);
LUAPROMPT_PUBLIC
void luap_getcolor(lua_State *L, int *enabled);
LUAPROMPT_PUBLIC
void luap_getname(lua_State *L, const char **name);

LUAPROMPT_PUBLIC
void luap_enter(lua_State *L);
LUAPROMPT_PUBLIC
char *luap_describe(lua_State *L, int index);
LUAPROMPT_PUBLIC
int luap_call(lua_State *L, int n);


#if defined(__cplusplus)
}
#endif

#endif
