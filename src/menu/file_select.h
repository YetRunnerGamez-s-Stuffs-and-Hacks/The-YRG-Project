#ifndef FILE_SELECT_H
#define FILE_SELECT_H

#include "types.h"

void file_select_init(void);
s32 file_select_update(void);
void file_select_draw(void);

extern s32 gSelectedFile;

#endif