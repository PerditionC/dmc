ORIGIN		= Symantec C++
ORIGIN_VER	= Version 7.22
VERSION		= DEBUG

!IFDEF SUB_DEBUG
DEBUG		= $(SUB_DEBUG)
NDEBUG		= !$(SUB_DEBUG)
!ELSE
DEBUG		= 1
NDEBUG		= 0
!ENDIF

PROJ		= ATSPEXE
APPTYPE		= WINDOWS EXE
PROJTYPE	= EXE

CC		= SC
CPP		= SPP
JAVAC		= sj
MAKE		= SMAKE
RC		= RCC
HC		= HC31
ASM		= SC
DISASM		= OBJ2ASM
LNK		= LINK
DLLS		= 

HEADERS		= ..\..\..\..\include\windows.h ..\..\..\..\include\win16\WINDOWS.H ..\..\..\..\include\memory.h  \
		..\..\..\..\include\string.h atsp.h ..\..\..\..\include\TSPI.H ..\..\..\..\include\win16\TSPI.H  \
		..\..\..\..\include\tapi.h ..\..\..\..\include\win16\TAPI.H atsprc.h ..\..\..\..\include\malloc.h  \
		..\..\..\..\include\stdlib.h ..\..\..\..\include\heapstat.h ..\..\..\..\include\assert.h ..\..\..\..\include\win16\VER.H  \
		..\..\..\..\include\ver.h 

DEFFILE		= atspexe.def

!IF $(DEBUG)
OUTPUTDIR	= .
CREATEOUTPUTDIR	=
TARGETDIR	= .
CREATETARGETDIR	=

SYMROOT		= 
SYMS		= 
LIBS		= LIBW.LIB COMMDLG.LIB SHELL.LIB 

CFLAGS		=  -ml -C -WA -S -2 -a2 -c -w- -w7 -g 
LFLAGS		=  /CO /DE /PACKF /XU /A:16 /RC  -31 :atspexe.RES
DEFINES		= 
!ELSE
OUTPUTDIR	= .
CREATEOUTPUTDIR	=
TARGETDIR	= .
CREATETARGETDIR	=

SYMROOT		= 
SYMS		= 
LIBS		= LIBW.LIB COMMDLG.LIB SHELL.LIB 

CFLAGS		=  -ml -o+time -WA -2 -a2 -c -w- -w7 
LFLAGS		=  /DE /E /PACKF /WI /XU /A:16 /RC  -31 :atspexe.RES
DEFINES		= 
!ENDIF

HFLAGS		= $(CFLAGS) 
MFLAGS		= MASTERPROJ=$(PROJ) 
LIBFLAGS	=  /C 
RESFLAGS	=  
DEBUGGERFLAGS	=  
AFLAGS		= $(CFLAGS) 
HELPFLAGS	= 

MODEL		= L

PAR		= PROJS BATS OBJS

RCDEFINES	= 

INCLUDES	= 

INCLUDEDOBJS	= 

OBJS		= atspexe.OBJ serial.OBJ 

RCFILES		=  atspexe.RES 

RESFILES	= 

HELPFILES	= 

BATS		= 

.SUFFIXES: .C .CP .CPP .CXX .CC .H .HPP .HXX .COM .EXE .DLL .LIB .RTF .DLG .ASM .RES .RC .OBJ 

.C.OBJ:
	$(CC) $(CFLAGS) $(DEFINES) $(INCLUDES) -o$*.obj $*.c

.CPP.OBJ:
	$(CC) $(CFLAGS) $(DEFINES) $(INCLUDES) -o$*.obj $*.cpp

.CXX.OBJ:
	$(CC) $(CFLAGS) $(DEFINES) $(INCLUDES) -o$*.obj $*.cxx

.CC.OBJ:
	$(CC) $(CFLAGS) $(DEFINES) $(INCLUDES) -o$*.obj $*.cc

.CP.OBJ:
	$(CC) $(CFLAGS) $(DEFINES) $(INCLUDES) -o$*.obj $*.cp

.H.SYM:
	$(CC) $(HFLAGS) $(DEFINES) $(INCLUDES) -HF -o$(*B).sym $*.h

.HPP.SYM:
	$(CC) $(HFLAGS) $(DEFINES) $(INCLUDES) -HF -o$(*B).sym $*.hpp

.HXX.SYM:
	$(CC) $(HFLAGS) $(DEFINES) $(INCLUDES) -HF -o$(*B).sym $*.hxx

.C.EXP:
	$(CPP) $(CFLAGS) $(DEFINES) $(INCLUDES)   $*.c   -o$*.lst

.CPP.EXP:
	$(CPP) $(CFLAGS) $(DEFINES) $(INCLUDES) $*.cpp -o$*.lst

.CXX.EXP:
	$(CPP) $(CFLAGS) $(DEFINES) $(INCLUDES) $*.cxx -o$*.lst

.CP.EXP:
	$(CPP) $(CFLAGS) $(DEFINES) $(INCLUDES)  $*.cp  -o$*.lst

.CC.EXP:
	$(CPP) $(CFLAGS) $(DEFINES) $(INCLUDES)  $*.cc  -o$*.lst

.ASM.EXP:
	$(CPP) $(CFLAGS) $(DEFINES) $(INCLUDES) $*.asm -o$*.lst

.OBJ.COD:
	$(DISASM) $*.OBJ -c

!IF $(DEBUG)
.OBJ.EXE:
		$(LNK) $(LFLAGS) @<<$(PROJ).LNK
atspexe.OBJ+
serial.OBJ
$$SCW$$.EXE
NUL
LIBW.LIB COMMDLG.LIB SHELL.LIB 
atspexe.def;
<<
!ELSE
.OBJ.EXE:
		$(LNK) $(LFLAGS) @$(PROJ).LNK<<
atspexe.OBJ+
serial.OBJ
$$SCW$$.EXE
NUL
LIBW.LIB COMMDLG.LIB SHELL.LIB 
atspexe.def;
<<
!ENDIF

.RTF.HLP:
	$(HC) $(HELPFLAGS) $*.HPJ

.ASM.OBJ:
	$(ASM) $(AFLAGS) $(DEFINES) $(INCLUDES) -o$*.obj $*.asm

.RC.RES: 
	$(RC) $(RCDEFINES) $(RESFLAGS) $(INCLUDES) $*.rc -o$*.res

.DLG.RES:
	echo ^#include "windows.h" >$$$*.rc
	echo ^IF EXIST "$*.h" >>$$$*.rc
	echo ^#include "$*.h" >>$$$*.rc
	echo ^#include "$*.dlg" >>$$$*.rc
	$(RC) $(RCDEFINES) $(RESFLAGS) $(INCLUDES) $$$*.rc
	-del $*.res
	-ren $$$*.res $*.res



all:	noteout createdir $(PRECOMPILE) $(SYMS) $(OBJS) $(INCLUDEDOBJS) $(POSTCOMPILE) $(TARGETDIR)\$(PROJ).$(PROJTYPE) $(POSTLINK) _done


all2:	createdir $(PRECOMPILE) $(SYMS) $(OBJS) $(INCLUDEDOBJS) $(POSTCOMPILE) $(TARGETDIR)\$(PROJ).$(PROJTYPE) $(POSTLINK) _done

noteout:
	REM Output to $(OUTPUTDIR)

createdir:
	$(CREATEOUTPUTDIR)
	$(CREATETARGETDIR)
	
$(TARGETDIR)\$(PROJ).$(PROJTYPE): $(OBJS) $(INCLUDEDOBJS) $(RCFILES) $(RESFILES) $(HELPFILES) $(DEFFILE)
			-del $(TARGETDIR)\$(PROJ).$(PROJTYPE)
!IF $(DEBUG)
		$(LNK) $(LFLAGS) @<<$(PROJ).LNK
atspexe.OBJ+
serial.OBJ
$$SCW$$.EXE
NUL
LIBW.LIB COMMDLG.LIB SHELL.LIB 
atspexe.def;
<<
!ELSE
		$(LNK) $(LFLAGS) @<<$(PROJ).LNK
atspexe.OBJ+
serial.OBJ
$$SCW$$.EXE
NUL
LIBW.LIB COMMDLG.LIB SHELL.LIB 
atspexe.def;
<<
!ENDIF

			-ren $(TARGETDIR)\$$SCW$$.$(PROJTYPE) $(PROJ).$(PROJTYPE)
			-echo $(TARGETDIR)\$(PROJ).$(PROJTYPE) built

_done:
		REM  Project is up to date

buildall:	clean	all


clean:
		-del $(TARGETDIR)\$$SCW$$.$(PROJTYPE)
		-del $(PROJ).CLE
		-del $(OUTPUTDIR)\SCPH.SYM
		-del ATSPEXE.dpd
		-del $(OBJS)
		-del atspexe.RES

cleanres:
		-del atspexe.RES

res:		cleanres $(RCFILES) all


link:
!IF $(DEBUG)
		$(LNK) $(LFLAGS) @<<$(PROJ).LNK
atspexe.OBJ+
serial.OBJ
$$SCW$$.EXE
NUL
LIBW.LIB COMMDLG.LIB SHELL.LIB 
atspexe.def;
<<
!ELSE
		$(LNK) $(LFLAGS) @<<$(PROJ).LNK
atspexe.OBJ+
serial.OBJ
$$SCW$$.EXE
NUL
LIBW.LIB COMMDLG.LIB SHELL.LIB 
atspexe.def;
<<
!ENDIF

		-del $(TARGETDIR)\$(PROJ).$(PROJTYPE)
		-ren $(TARGETDIR)\$$SCW$$.$(PROJTYPE) $(PROJ).$(PROJTYPE)




!IF EXIST (ATSPEXE.dpd)
!INCLUDE ATSPEXE.dpd
!ENDIF


