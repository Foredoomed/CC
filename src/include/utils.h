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


#ifndef UTILS_H
#define UTILS_H


#include <stdio.h>
#include "code.h"
#include "core.h"


long get_time();

double elapsed(long start, long end);

void read_char(const char *file, char chs[]);

CODE read_code(FILE *file);

char read_type(FILE *file);

int read_header(FILE *file);

void close(FILE *file);

BOOL is_not_open(FILE *file);

int get_digits(int number);

#endif