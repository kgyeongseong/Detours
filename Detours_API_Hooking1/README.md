
BUILDING:
=========
Open a Developer Command Prompt for VS.  Note there are several different
flavors of the command prompt for different target architectures.  The
default Visual Studio Command prompt targets x86.  To target x64, choose
the "X64 Native Tools Command Prompt for VS"

Change directory to the samples directory for your git repo.  To build the
samples, type "nmake".

Note that you must build setdll and syslog in order to use many of the
other sample programs.

기본적으로 Developer Command Prompt for VS 2019 를 이용해서 nmake 빌드하면 x86 버전으로 빌드됨 <br>
x64 Native Tools Command Prompt for VS 2019를 이용해서 nmake 빌드하면 x64 버전으로 빌드됨
