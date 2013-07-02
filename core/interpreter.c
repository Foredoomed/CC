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
#include <stdlib.h>
#include "utils.h"
#include "code.h"
#include "type.h"
#include "stack.h"
#include "hash.h"



int parse(FILE *file)
{
  int head = read_header(file);

  if(head == false){
    printf("Invalid Clean C compiled file");
    return 1;
  }

  hash_t *var_map = malloc(sizeof(hash_t));
  hash_init(var_map, 1024);

  int ch = fgetc(file);
  while(ch != EOF){
    CODE code = ch - '0';
    switch(code){
      case PUSHS : {
        char type = read_type(file);
        if(type == 'S'){
          int length;
          fscanf(file, "%d", &length);
          char word[length+1];
          fgets(word, length+1, file);
          word[length+1]='\0';
          push(word);
        }
        break;
      }
      case PUSHV : {
        int length;
        fscanf(file, "%d", &length);
        char var[length+1];
        fgets(var, length+1, file);
        char *value = hash_lookup(var_map, var);
        push(value);
        break;
      }
      case ASSIGN : {
        int length;
        fscanf(file, "%d", &length);
        char var[length+1];
        fgets(var, length+1, file);

        char *value = pop();
        hash_insert(var_map, var, value);

        break;
      }
      case PRINT : {
        char *output = pop();
        printf("%s\n", output);
        break;
      }
      case END :
        return 0;
    }
    ch = fgetc(file);
  }

  free(var_map);
  return 0;
}

int execute(char *file)
{
  printf("Executing : %s\n", file);

  long start = get_time();

  FILE *src = fopen(file, "r");

  if(NULL == src){
    printf("Error opening %s\n", file);
    return 1;
  }

  int result = parse(src);

  long end = get_time();

  double t = elapsed(start, end);

  printf("Finished in %.3f seconds\n", t);

  fclose(src);

  return result;

}
