/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:51:15 by redrouic          #+#    #+#             */
/*   Updated: 2024/02/21 19:07:46 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int check = 0;

int	main(int ac, char **av)
{
	if (ac != 3)
	return (0);
}

static void act_start(void) {
    struct sigaction act;
    int min = 24;
    int sec = 59;

    act.sa_flags = SA_SIGINFO|SA_RESTART;
    act.sa_sigaction = get_client_pid;
    sigaction(SIGUSR1, &act, NULL);
    while (1) {
        if (min == 0 && sec == 0)
            break;
        if (sec == 0) {
            sec = 59;
            min--;
        }
        usleep(1000000);
        sec--;
        if (check > 0) {
            send_seq(str2seq(time2str(min, sec)));
            check = 0;
        }
    }    
}

char **str2seq(char *str) {
    char **seq = NULL;
    int y = 0;
    int x = 0;

    seq = malloc(sizeof(char *) * 5);
    while (*str) {
        seq[y] = malloc(sizeof(char) * 9);
        for (int i = 7; i >= 0; --i) {
            seq[y][x] = ( (*str & (1 << i)) ? '1' : '0' );
            x++;
        }
        seq[y][9] = '\0';
        y++;
        x = 0;
        str++; 
    }
    return seq;
}

void send_seq(char **seq) {
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 8; x++) {
            if (seq[y][x] == '1') {
                kill(pclient, SIGUSR1);
                usleep(100);
            } else if (seq[y][x] == '0') {
                kill(pclient, SIGUSR2);
                usleep(100);
            }
            usleep(100);
        }
    } 
}

char *time2str(int min, int sec) {
    char *str = NULL;
    char smin[2];
    char ssec[2];

    my_itoa(min, smin, 10);
    str = my_strconc(smin, ":");
    my_itoa(sec, ssec, 10);
    str = my_strconc(str, ssec);
    return str;    
}

static void act_clock(void) {
    struct sigaction act;
    char *buf = get_server_pid();
    char *res = NULL;

    kill(atoi(buf), 10);
    free(buf);
    pclient = getpid();
    act.sa_flags = SA_RESTART|SA_SIGINFO;
    act.sa_sigaction = handler_clock;
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    while (1) {
        if (cnt == 40) {
            data[40] = '\0';
            break;
        }
    }
    res = bin2str(data);
    printf("%s\n", res);
    free(res);
    return;
}
