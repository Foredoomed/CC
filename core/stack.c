/***********************************************************************
**
**  Clean C
**
**  Licensed under the Apache License, Version 2.0 (the "License");
**  you may not use this file except in compliance with the License.
**  You may obtain a copy of the License at
**
**  http://www.apache.org/licenses/LICENSE-2.0
**
**  Unless required by applicable law or agreed to in writing, software
**  distributed under the License is distributed on an "AS IS" BASIS,
**  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
**  See the License for the specific language governing permissions and
**  limitations under the License.
**
************************************************************************/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

#define MAXSTACK 1024*1024*4
#define EMPTYSTACK 0

typedef struct item_t {
  char *value;
} item_t;

int top = EMPTYSTACK;
item_t *stack[MAXSTACK];


void push(const char *data)
{
  if(top >= MAXSTACK){
    return;
  }
  item_t *item = malloc(sizeof(item_t));
  item->value=malloc(sizeof(data));
  memcpy(item->value, data, strlen(data));
  stack[top++] = item;
}

char * pop()
{
  return stack[--top]->value;
}

int full()
{
  return top == MAXSTACK;
}

int empty()
{
  return top == EMPTYSTACK;
}



