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


#define MAXSTACK 4096
#define EMPTYSTACK -1

int top = EMPTYSTACK;
char *items[MAXSTACK];


void push(char *c)
{
   items[++top] = c;
}

char *pop()
{
   return items[top--];
}

int full()
{
   return top+1 == MAXSTACK;
}

int empty()
{
   return top == EMPTYSTACK;
}



