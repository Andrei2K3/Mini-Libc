// SPDX-License-Identifier: BSD-3-Clause

#include <internal/io.h>//Pentru write
#include <errno.h>//Pentru errno
#include <stdio.h>//Pentru puts
#include <string.h>//Pentru strlen

int puts(const char *str)
{
size_t lg_str = strlen(str);

if (write(1, str, lg_str) == -1)
	return errno;

if (write(1, "\n", 1) == -1)
	return errno;

return 0;
}

//
//#include <stdio.h>
//#include <string.h>
//#include <unistd.h>
//#include <errno.h>

//Din moment ce toate flag urile din errno sunt numere naturale > 0
//functia va returna 0 daca afisarea s-a realizat cu succes
//altfel errno
//int puts(const char *str)
//{
//    size_t lg_str = strlen(str);
//    ssize_t nr_bytes = write(1, str, lg_str);
//
//    if(nr_bytes != (ssize_t)lg_str)
//    {
//        errno = EIO;
//        return errno;
//    }

//    nr_bytes = write(1, "\n", 1);
//    if(nr_bytes != 1) {
//        errno = EIO;
//        return errno;
//    }

//    return 0;
//}
