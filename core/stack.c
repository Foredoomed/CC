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

#define MAXSTACK 4096
#define EMPTYSTACK 0
#define ITEMSIZE 128

struct item {
  char e[ITEMSIZE];
};

int top = EMPTYSTACK;
struct item stack[MAXSTACK];


void push(const char *item)
{
   if(top >= MAXSTACK){
    return;
   }

   memcpy(stack[top++].e, item, ITEMSIZE);
}

void pop(char dest[])
{
   memcpy(dest, stack[--top].e, ITEMSIZE);
}

int full()
{
   return top == MAXSTACK;
}

int empty()
{
   return top == EMPTYSTACK;
}



