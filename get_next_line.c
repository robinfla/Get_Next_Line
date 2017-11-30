#include "includes/get_next_line.h"

int         get_next_line(int const fd, char **line)
{
    static t_list *save;
    char *buf;
    char *pos;
    int ret;

    if (!save)
        save = ft_lstnew("\0", 1);
    buf = ft_strnew(BUFF_SIZE + 1);
    if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
        return (-1);
    while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
    {
        buf[ret] = '\0';
        if (!(save->content = ft_strjoin(save->content, buf)))
                return (-1);
        if ((ft_strchr(buf, '\n')))
            break;
    }
    free (buf);
    if ((pos = ft_strchr(save->content, '\n')))
    {
        *pos = '\0';
        *line = ft_strdup(save ->content);
        if (!(pos + 1))
            ft_strclr(save->content);
        else
            save->content = pos + 1;
        return (1);
    }
    else
    {
        *line = ft_strdup(save->content);
        return (0);
    }
}
