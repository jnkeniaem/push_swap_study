void if_white_space(int argc, char **argv)
{
    int i;
    int j;

    i = 0;
    while (i < argc - 1)
    {
        j = 0;
        while (argv[i + 1][j])
        {
            if (ft_available(argv[i + 1][j], "\t\n\v\f\r "))
                j++;
            else
                break;
        }
        if (argv[i + 1][j] == 0)
            ft_error("Error\nWhite-spaced argument.");
        i++;
    }
    
}