unix { 
	QTDIR = $$system(printenv QTDIR)
	OPEN2000E_HOME = $$system(printenv OPEN2000E_HOME)
	CURRENT_PROJECT_PATH = $$system(pwd)
}
win32 { 
	QTDIR = $$system("echo %QTDIR%")
	OPEN2000E_HOME = $$system("echo %OPEN2000E_HOME%")
	CURRENT_PROJECT_PATH = .
}
!include ($$QTDIR/lib/qmake.conf):error(the file $$QTDIR/lib/qmake.conf is not exist!!)

TARGET = isca_ctrlfile
TEMPLATE = app
CONFIG += cp_target
DEFINES += 

unix:INCLUDEPATH += . \
	$$D5000_HOME/db_def/ \
	$$D5000_HOME/src/include/ \
	$$D5000_HOME/src/include/msg_api \
	$$D5000_HOME/src/include/db_com

unix:LIBS += -L$D5000_HOME/lib \
	-L$$D5000_HOME/src/lib \
	-L$$D5000_HOME/lib \
	-L$$D5000_HOME/src/lib_linux \
	-lrte \
	-lmsgproxy \
	-lsqlspclient \
	-lalarmclient \
	-ldbclient \
	-ldms_sca_ctrl \
	-lpriv_access \
	-llogin_dlg  \
	-llogclient
	
win32:OBJECTS_DIR = tmp
unix:OBJECTS_DIR = tmp
unix:VERSION = 1.0

FORMS+=

SOURCES += main.cpp \
           CCtrlFile.cpp \
	   isca_ctrl_trans_m.cpp

HEADERS += CCtrlFile.h \
           ctrl_file_include.h \
	   isca_ctrl_trans_m.h \
    ctrl_file_define.h \
    ctrl_file_struct.h
           

RESOURCES +=

unix::QMAKE_POST_LINK += echo \
"Copy..." \
; \
rm  $$D5000_HOME/bin/$$TARGET; \
cp  ./$$TARGET $$D5000_HOME/bin/.; \
rm ./$$TARGET; \

