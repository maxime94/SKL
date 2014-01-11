/*
** string.c for string in /home/debas_e/Project/piscine_cpp/Rush/piscine_cpp_rush1/bonus/string_bonus
** 
** Made by Etienne
** Login   <debas_e@epitech.net>
** 
** Started on  Sat Jan 11 19:08:38 2014 Etienne
** Last update Sat Jan 11 19:57:58 2014 jonathan.collinet
*/


#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "string.h"
#include "new.h"

typedef struct
{
  Class		base;
  const char	*s;
  char		*str;
}		StringClass;

static void String_ctor(Object* self, va_list *ap)
{
  StringClass *a;

  a = (StringClass *) self;
  a->s = va_arg(*ap, char *);
  a->str = NULL;
}

static void String_dtor(Object* self)
{
  StringClass *a;

  a = (StringClass *) self;
  if (a != NULL)
    free(a->str);
}

static char const *String_str(Object* self)
{
  StringClass *a;

  a = (StringClass *) self;
  if (a != NULL && !strcmp(a->base.__name__, "String"))
    {
      if (a->str != NULL)
        free(a->str);
      a->str = malloc(strlen(a->s) + 12);
      snprintf(a->str, 199, "<%s (%s)>", (a->base).__name__, a->s);
      return(a->str);
    }
  return NULL;
}

static const char *String_c_str(Object *self)
{
  return (((StringClass*)self)->s);
}

/* static Object *String_append(const Object* self, const Objet *other) */
/* { */
/*   StringClass *a; */
/*   StringClass *b; */

/*   a = (StringClass *)self; */
/*   b = (StringClass *)other; */
/*   if ((a != NULL && !strcmp(a->base.__name__, "String")) && (b != NULL && !strcmp(b->base.__name__, "String"))) */
/*     return(new(Point, )); */
/*   return NULL; */
/* } */

/* static Object *String_append_s(const Object* self, const Object* other) */
/* { */
/*   StringClass *a; */
/*   StringClass *b; */

/*   a = (StringClass *)self; */
/*   b = (StringClass *)other; */
/*   if ((a != NULL && !strcmp(a->base.__name__, "Point")) && (b != NULL && !strcmp(b->base.__name__, "Point"))) */
/*     return(new(Point, a->x + b->x, a->y + b->y)); */
/*   return NULL; */
/* } */

static StringClass _description = {
  { sizeof(StringClass), "String", &String_ctor, &String_dtor, &String_str, &String_c_str},
  NULL, NULL
};

Class* String = (Class*) &_description;