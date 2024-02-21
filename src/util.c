/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:11:55 by redrouic          #+#    #+#             */
/*   Updated: 2024/02/21 19:12:14 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int my_strlen(char *str) {
    int len = 0;

    while (*str) {
        str++;
        len++;
    }
    return len;
}

bool my_strcmp(char *s1, char *s2) {
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s2[i] != s1[i]) {
            return false;   
        }
    }
    return true;
}

void my_swap(char *c1, char *c2) {
    char tmp;

    tmp = *c1;
    *c1 = *c2;
    *c2 = tmp;
}

void my_strrev(char *str) {
    int size = my_strlen(str);
    int half = size / 2;
    int y = size - 1;
    
    for (int i = 0; i < half; i++) {
        my_swap(&str[i], &str[y]);
        y--;
    }
}

int my_itoa(int n, char *str, int base) {
    int rem = 0;
    int i = 0;
    bool neg = false;

    if (n == 0) {
        str[0] = '0';
        str[1] = '\0';
        return 0;
    }
    if (n < 0) {
        n = -n;
        neg = true;
    }
    while (n != 0) { 
        rem = n % base;
        str[i++] = rem + '0';
        n = n / base;
    }
    if (neg == true)
       str[i++] = '-'; 
    str[i] = '\0';
    my_strrev(str);
    return 0; 
}

char *my_strconc(char *s1, char *s2) {
    int tsize = my_strlen(s1) + my_strlen(s2);
    char *str = malloc(sizeof(char) * tsize + 1);
    int w = 0;
    int i = 0;

    for ( ; i < tsize; i++) {
        if (i < my_strlen(s1))
            str[i] = s1[i];
        else {
            str[i] = s2[w];
            w++;
        }
    }
    str[++i] = '\0';
    return str;
}
