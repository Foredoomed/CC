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

  int ch = fgetc(file);
  while(ch != EOF){
    CODE code = ch - '0';
    switch(code){
      case PUSH : {
        char type = read_type(file);
        if(type == 'S'){
          int length;
          fscanf(file, "%d", &length);
          char litteral[length];
          fgets(litteral, length + 1, file);
          push(litteral);
        }
        break;
      }
      case PRINT : {
        char output[128];
        pop(output);
        printf("%s\n", output);
        break;
      }
      case END :
        return 0;
    }
    ch = fgetc(file);
  }

  return 0;
}

int execute(char *file)
{
  printf("Executing : %s", file);

  long start = get_time();

  FILE *src = fopen(file, "r");

  if(NULL == src){
    printf("Error opening %s", file);
    return 1;
  }

  int result = parse(src);

  long end = get_time();

  double t = elapsed(start, end);

  printf("Finished in %lf\n", t);

  fclose(src);

  return result;

}
