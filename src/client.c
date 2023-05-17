/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 14:52:08 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/05/17 13:07:26 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void send_bits(int pid, char i)
{    
    int bit;
    
    bit = 0;
    while (bit < 8)
    {
        if (i & (1 << bit))
            kill(pid, SIGUSR1);
        else 
            kill(pid, SIGUSR2);
        usleep(150);
        bit++;
    }
}

int main(int argc, char **argv)
{
    int	pid;
    int i;
    
    i = 0;
    if (argc == 3)
    {
        pid = ft_atoi(argv[1]);
        while (1)
        {
            send_bits(pid, argv[2][i]);
            i++;
        }
    }
    else
    {
        ft_printf(RED "Error: Wrong format\n" RESET);
        ft_printf(RED "Try: ./client <PID> <MESSAGE>\n" RESET);
    }
    return (EXIT_FAILURE);
}