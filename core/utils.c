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
#include <time.h>
#include "code.h"
#include "core.h"


char *substring(char *src, int position, int length)
{
   char *ret;
   strncat(ret, src+position, length);
   return ret;
}

long get_time()
{
  return (long)(time(NULL));
}

long elapsed(long start, long end)
{
  //double elapsed = (second.tv_sec - first.tv_sec) * 1000.0;
  //elapsed += (second.tv_usec - first.tv_usec) / 1000.0;

  return (end - start) / 1000;
}

void read_char(const char *file, char chs[])
{
  FILE *fp;
  fp = fopen(file, "r");

  if(NULL == fp){
    return;
  }

  fread(chs, sizeof(chs), 1, fp);
  fclose(fp);

}

void write_header(FILE *stream)
{
  fprintf(stream, "%s", "Clean C");
}

void write_end(FILE *stream)
{
  fprintf(stream, "%d", END);
}

void write_simple_call(FILE *stream, CODE code)
{
  fprintf(stream, "%d", code);
}

void write_one_operand_call(FILE *stream, CODE code, char *litteral)
{
  fprintf(stream, "%d", code);

}

void write_litteral(FILE *stream, char *litteral)
{
  fprintf(stream, "%s", "S");
  fprintf(stream, "%d", (int)(strlen(litteral) - 2));

  char *temp = substring(litteral, 1, (int)(strlen(litteral) - 2));
  fprintf(stream, "%s", temp);
}

CODE read_code(FILE *file)
{
  int code;
  if(fscanf(file, "%d", &code) == 1){
    return (CODE) code;
  }
  return -1;
}

BOOL is_not_open(FILE *file)
{
  return (file == NULL);
}

BOOL has_next(FILE *file)
{
  return feof(file);
}

BOOL read_header(FILE *file)
{
  int magic = 'C' + 'l' + 'e' + 'a' + 'n' + ' ' + 'C';
  int ret;
  int i;
  for(i = 0; i < 7; i++){
    ret += fgetc(file);
  }

  return magic == ret;
}

char read_constant_type(FILE *file)
{
  char type = fgetc(file);
  return type;
}

char *read_litteral(FILE *file)
{
  char *ret;
  fgets(ret, 4096, file);
  return ret;
}

void close(FILE *file){
  fclose(file);
}