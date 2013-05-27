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
#include "utils.h"
#include "code.h"
#include "type.h"
#include "stack.h"


int parse(FILE *file)
{
  int head = read_header(file);

  if(head == 0){
    printf("Invalid Clean C compiled file");
    return 1;
  }

  while(has_next(file)){
    CODE code = read_code(file);

    switch(code){
      case PUSH : {
        char type = read_constant_type(file);
        if(type == 'S'){
          char *litteral = read_litteral(file);
          push(litteral);
        }
        break;
      }
      case PRINT :
        printf("%s\n", pop());
        break;
      case END :
        return 0;
    }
  }

  return 0;
}

int execute(char *file)
{
  printf("Executing : %s", file);

  long start = get_time();

  FILE *src = fopen(file, "r");

  if(NULL == src){
    printf("Unable to open %s", file);
    return 1;
  }

  int result = parse(src);

  long end = get_time();

  long t = elapsed(start, end);

  printf("Finished in %ld", t);

  fclose(src);

  return result;

}
