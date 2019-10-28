#pragma once
#include <unistd.h>
extern void copy(int fdin, int fdout);
extern void set_fl(int fd, int flag);
extern void clr_fl(int fd, int flag);