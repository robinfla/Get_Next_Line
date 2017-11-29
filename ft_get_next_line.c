#include "get_next_line.h"

int         get_next_line(int const fd, char **line)
{
    static char *save;
    char *buf;
    char *tmp;
    char *tmp2;
    int ret;

    buf = ft_strnew(BUFF_SIZE);
    tmp2 = ft_strnew(1);
    ret = 0;
    while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
    {
        if ((ft_strchr(buf, '\n')))
            break;
        buf[ret] = '\0';
        save = strcat(save, tmp2);
        save = ft_strjoin(save, buf);
    }
    ft_putnbr(ft_strlen(save));
    ft_putnbr(ret);
    puts("ok here1");
    puts("ok here2");
    free (buf);
    if ((tmp = ft_strchr(save, '\n')) != 0 || ret > 0)
    {
        puts("ok here3");
        *tmp = '\0';
        *line = ft_strdup(save);
        save = tmp + 1;
        return (1);
    }
    else
        return (0);
}
int         main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc == 0)
        return (0);
    if ((fd = open(argv[1], O_RDONLY)) == -1)
        return (0);
    get_next_line(fd, &line);
    /* ft_putnbr(get_next_line(fd, &line)); */
    /* puts(line); */
    /* ft_putchar('\n'); */
    /* ft_putnbr(get_next_line(fd, &line)); */
    /* puts(line); */
    /* ft_putchar('\n'); */
    /* ft_putnbr(get_next_line(fd, &line)); */
    /* puts(line); */
    /* ft_putchar('\n'); */
    close (fd);
    free (line);
    return (0);
}
