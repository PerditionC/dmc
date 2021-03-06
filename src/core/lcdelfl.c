/*_ lcdelfl.c						*/
/* Copyright (C) 1995 by Digital Mars		*/
/* All Rights Reserved					*/

#ifdef __NT__

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <setlocal.h>
#include <lcapi32.h>

typedef WINBASEAPI BOOL WINAPI fnDeleteFileW(LPCWSTR lpFileName);

static fnDeleteFileW* pDeleteFileW;
static int initDeleteFileW;

BOOL __cdecl __wDeleteFile (UINT cPage, LPCWSTR pF) {
 BOOL		ret;
 size_t		sz;
 char *		cp = NULL;

  if (!initDeleteFileW) {
   pDeleteFileW = (fnDeleteFileW*)GetProcAddress(GetModuleHandle("kernel32"), "DeleteFileW");
   initDeleteFileW = 1;
  }
  if (pDeleteFileW)
    return (*pDeleteFileW)(pF);

  if (cPage == 0) {
    cPage = __locale_codepage;
  }
  sz = WtoMcsSZ (pF, -1);
  if (sz == 0) {
    goto error;
  }
  sz++;
  cp = GETCMAIN (sz);
  if (cp == NULL) {
    goto error;
  }
  if (wcstombs (cp, pF, sz) == CPYERR) {
    goto error;
  }
  ret = DeleteFileA (cp);
done:
  free (cp);
  return ret;
error:
  ret = FALSE;
  goto done;
}

#endif

/**/
