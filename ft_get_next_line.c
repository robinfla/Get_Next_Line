#include "get_next_line.h"

int         ft_nb_lines(int fd)
{
    int count;
    char c;

    c = '\0';
    count = 0;
    while (read(fd, &c, 1))
        count++;
    return (count);
}

int         ft_size_file(int fd)
{
    int count;
    char c;

    count = 0;
    c = '\0';
    lseek(fd, 0, SEEK_SET);
    while (read(fd, &c, 1))
        count++;
    return (count);
}


int         ft_get_next_line(int const fd, char * line)
{
    int i;
    char *buf;
    static int ret;

    i = 0;
    if ((buf = malloc(sizeof(char) * BUFF_SIZE)) == NULL)
        return (-1);
    lseek (fd, ret, SEEK_SET);
    while ((read(fd, &buf[i], 50)))
    {
        if (buf[i] == '\n')
            break;
        i++;
    }
    ret = ret + i + 1;
    buf[i] = '\0';
    ft_strcpy(line, buf);
    free (buf);
    if (ret == ft_size_file(fd))
    return (0);
    else
    return (1);
}

int         get_next_line(int const fd, char **line)
{
    static char *save;
    char *buf;
    char *tmp;
    int ret;

    if ((buf = malloc(sizeof(char) * BUFF_SIZE)) == NULL)
        return (-1);
    ret = 0;
    while ((ret = read(fd, &buf, BUFF_SIZE)) > 0)
    {
        if ((ft_strchr(buf, '\n')))
            break;
        ft_strncat(save, buf, BUFF_SIZE);
    }
    free (buf);
    if ((tmp = ft_strchr(save, '\n')) || ret > 0)
    {
        *tmp = '\0';
        *line = ft_strdup(save);
        save = tmp + 1;
        return (1);
    }
    else
        return (0)

}
int         main(int argc, char **argv)
{
    int fd;
    char *line;
    /* int nb_lines; */

    if (argc == 0)
        return (0);
    if ((fd = open(argv[1], O_RDONLY)) == -1)
        return (0);
    /* nb_lines = ft_nb_lines(fd); */
    /* if ((line = malloc(sizeof(char *) * nb_lines)) == NULL) */
    /*     return (0); */
    if ((line = malloc(sizeof(char) * BUFF_SIZE)) == NULL)
        return (0);
    ft_putnbr(ft_get_next_line(fd, line));
    puts(line);
    ft_putchar('\n');
    ft_putnbr(ft_get_next_line(fd, line));
    puts(line);
    ft_putchar('\n');
    ft_putnbr(ft_get_next_line(fd, line));
    puts(line);
    ft_putchar('\n');
    close (fd);
    free (line);
    return (0);
}
