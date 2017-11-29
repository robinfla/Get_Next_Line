#include "get_next_line.h"

/* t_list          *ft_add_zero(t_list **save) */
/* { */
/*     t_list *tmp; */

/*     tmp = *save; */
/*     while (tmp) */
/*     { */
/*         if ((int)tmp->content_size == 1) */
/*             return (tmp); */
/*         tmp = tmp->next; */
/*     } */
/*     tmp = ft_lstnew("\0", 1); */
/*     ft_lstadd(save, tmp); */
/*     tmp = *save; */
/*     return (tmp); */
/* } */

int         get_next_line(int const fd, char **line)
{
    static t_list *save;
    /* t_list *tmp; */
    char *buf;
    char *pos;
    int ret;

    if (!save)
        save = ft_lstnew("\0", 1);
    buf = ft_strnew(BUFF_SIZE + 1);
    if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
        return (-1);
    /* tmp = ft_add_zero(&save); */
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
        ft_strclr(save->content);
        save->content = pos + 1;
        return (1);
    }
    else
    {
        *line = ft_strdup(save->content);
        free(save);
        return (0);
    }

}
int         main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc == 0)
        return (0);
    if ((fd = open(argv[1], O_RDONLY)) == -1)
        return (0);
    while (get_next_line(fd, &line))
    {
        puts(line);
        ft_putchar('\n');
    }
    close (fd);
    free (line);
    return (0);
}
