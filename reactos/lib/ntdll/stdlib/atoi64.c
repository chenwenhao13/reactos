/* $Id$
 *
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         ReactOS kernel
 * FILE:            lib/ntdll/stdlib/atoi64.c
 * PURPOSE:         converts an ascii string to 64 bit integer
 */

#include <stdlib.h>
#define __NO_CTYPE_INLINES
#include <ctype.h>

/*
 * @implemented
 */
__int64
_atoi64 (const char *nptr)
{
   int c;
   __int64 value;
   int sign;

   while (isspace((int)*nptr))
        ++nptr;

   c = (int)*nptr++;
   sign = c;
   if (c == '-' || c == '+')
        c = (int)*nptr++;

   value = 0;

   while (isdigit(c))
     {
        value = 10 * value + (c - '0');
        c = (int)*nptr++;
     }

   if (sign == '-')
       return -value;
   else
       return value;
}

/* EOF */
