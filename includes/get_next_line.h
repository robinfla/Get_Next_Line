#ifndef __GET_NEXT_LINE_H__
# define __GET_NEXT_LINE_H__
# define BUFF_SIZE 23
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/includes/libft.h"

int         get_next_line(const int fd, char ** line);
#endif
