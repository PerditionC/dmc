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

PROJ		= MIXAPP32
APPTYPE		= WIN32 EXE
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

HEADERS		= ..\..\..\..\include\win32\pshpack4.h ..\include\verinfo.h ..\..\..\..\include\win32\WINVER.H  \
		..\..\..\..\include\winver.h ..\..\..\..\include\win32\DLGS.H ..\..\..\..\include\dlgs.h ..\..\..\..\include\win32\WINRESRC.H  \
		..\..\..\..\include\winresrc.h ..\..\..\..\include\win32\WINDOWS.H ..\..\..\..\include\win32\scdefs.h ..\..\..\..\include\windows.h  \
		muldiv32.h debug.h tlb.h mixapp.h  \
		..\..\..\..\include\win32\objidl.h ..\..\..\..\include\win32\unknwn.h ..\..\..\..\include\win32\wtypes.h ..\..\..\..\include\win32\ole2.h  \
		..\..\..\..\include\win32\rpcndr.h ..\..\..\..\include\win32\rpc.h ..\..\..\..\include\win32\poppack.h ..\..\..\..\include\win32\pshpack2.h 

DEFFILE		= mixapp32.def

!IF $(DEBUG)
OUTPUTDIR	= .
CREATEOUTPUTDIR	=
TARGETDIR	= .
CREATETARGETDIR	=

SYMROOT		= 
SYMS		= 
LIBS		= advapi32.lib comdlg32.lib winmm.lib KERNEL32.LIB GDI32.LIB USER32.LIB 

CFLAGS		=  -mn -C -WA -S -3 -a8 -c -g 
LFLAGS		=  /CO /DE /NOPACKF /XN /NT /ENTRY:WinMainCRTStartup /VERS:1.0 /BAS:4194304 /A:512 /RC   :mixapp.RES
DEFINES		= -DWIN32 -D_WIN32 -D_WIN32_LEAN_AND_MEAN=1 -DNULL=0 -DDEBUG=1
!ELSE
OUTPUTDIR	= .
CREATEOUTPUTDIR	=
TARGETDIR	= .
CREATETARGETDIR	=

SYMROOT		= 
SYMS		= 
LIBS		= advapi32.lib comdlg32.lib winmm.lib KERNEL32.LIB GDI32.LIB USER32.LIB 

CFLAGS		=  -Ae -mn -C -o+time -WA -3 -a8 -c -w 
LFLAGS		=  /CO /DE /NOPACKF /XN /NT /ENTRY:WinMainCRTStartup /VERS:1.0 /BAS:4194304 /A:512 /RC   :mixapp.RES
DEFINES		= -DWIN32 -D_WIN32 -D_WIN32_LEAN_AND_MEAN=1 -DNULL=0
!ENDIF

HFLAGS		= $(CFLAGS) 
MFLAGS		= MASTERPROJ=$(PROJ) 
LIBFLAGS	=  /C 
RESFLAGS	=  -32 
DEBUGGERFLAGS	=  
AFLAGS		= $(CFLAGS) 
HELPFLAGS	= 

MODEL		= N

PAR		= PROJS BATS OBJS

RCDEFINES	= -DWIN32_LEAN_AND_MEAN=1

INCLUDES	= -I..\include

INCLUDEDOBJS	= 

OBJS		= debug.OBJ mactrls.OBJ mafader.OBJ  \
		mainit.OBJ malines.OBJ malist.OBJ mameter.OBJ  \
		maswitch.OBJ mixapp.OBJ tlb.OBJ 

RCFILES		=  mixapp.RES 

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
debug.OBJ+
mactrls.OBJ+
mafader.OBJ+
mainit.OBJ+
malines.OBJ+
malist.OBJ+
mameter.OBJ+
maswitch.OBJ+
mixapp.OBJ+
tlb.OBJ
$$SCW$$.EXE
NUL
advapi32.lib comdlg32.lib winmm.lib KERNEL32.LIB GDI32.LIB USER32.LIB 
mixapp32.def;
<<
!ELSE
.OBJ.EXE:
		$(LNK) $(LFLAGS) @$(PROJ).LNK<<
debug.OBJ+
mactrls.OBJ+
mafader.OBJ+
mainit.OBJ+
malines.OBJ+
malist.OBJ+
mameter.OBJ+
maswitch.OBJ+
mixapp.OBJ+
tlb.OBJ
$$SCW$$.EXE
NUL
advapi32.lib comdlg32.lib winmm.lib KERNEL32.LIB GDI32.LIB USER32.LIB 
mixapp32.def;
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
debug.OBJ+
mactrls.OBJ+
mafader.OBJ+
mainit.OBJ+
malines.OBJ+
malist.OBJ+
mameter.OBJ+
maswitch.OBJ+
mixapp.OBJ+
tlb.OBJ
$$SCW$$.EXE
NUL
advapi32.lib comdlg32.lib winmm.lib KERNEL32.LIB GDI32.LIB USER32.LIB 
mixapp32.def;
<<
!ELSE
		$(LNK) $(LFLAGS) @<<$(PROJ).LNK
debug.OBJ+
mactrls.OBJ+
mafader.OBJ+
mainit.OBJ+
malines.OBJ+
malist.OBJ+
mameter.OBJ+
maswitch.OBJ+
mixapp.OBJ+
tlb.OBJ
$$SCW$$.EXE
NUL
advapi32.lib comdlg32.lib winmm.lib KERNEL32.LIB GDI32.LIB USER32.LIB 
mixapp32.def;
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
		-del MIXAPP32.dpd
		-del $(OBJS)
		-del mixapp.RES

cleanres:
		-del mixapp.RES

res:		cleanres $(RCFILES) all


link:
!IF $(DEBUG)
		$(LNK) $(LFLAGS) @<<$(PROJ).LNK
debug.OBJ+
mactrls.OBJ+
mafader.OBJ+
mainit.OBJ+
malines.OBJ+
malist.OBJ+
mameter.OBJ+
maswitch.OBJ+
mixapp.OBJ+
tlb.OBJ
$$SCW$$.EXE
NUL
advapi32.lib comdlg32.lib winmm.lib KERNEL32.LIB GDI32.LIB USER32.LIB 
mixapp32.def;
<<
!ELSE
		$(LNK) $(LFLAGS) @<<$(PROJ).LNK
debug.OBJ+
mactrls.OBJ+
mafader.OBJ+
mainit.OBJ+
malines.OBJ+
malist.OBJ+
mameter.OBJ+
maswitch.OBJ+
mixapp.OBJ+
tlb.OBJ
$$SCW$$.EXE
NUL
advapi32.lib comdlg32.lib winmm.lib KERNEL32.LIB GDI32.LIB USER32.LIB 
mixapp32.def;
<<
!ENDIF

		-del $(TARGETDIR)\$(PROJ).$(PROJTYPE)
		-ren $(TARGETDIR)\$$SCW$$.$(PROJTYPE) $(PROJ).$(PROJTYPE)




!IF EXIST (MIXAPP32.dpd)
!INCLUDE MIXAPP32.dpd
!ENDIF


