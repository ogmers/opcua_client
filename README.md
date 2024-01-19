# OPEN SOURCE OPC UA CLIENT FOR CAB PRINTER USECASES

These are examples of an OPC UA client written in C++ and Python. Basic functionalities in 
dealing with a CAB printer and OPC UA are shown. This includes reading and writing configurations, 
handling and printing labels and replacing data fields in the label using Replace. These examples 
are intended to give you an idea of how the functionalities of the printer and with the printer 
can be set up.

## Dependencies and installation on Linux systems

### Use the cpp-opcua-client

An environment supporting C++17 is necessary. Project dependencies:
 * CMake >= 3.16.3
 * GNU Make >= 4.2.1
 * open62541 >= v1.3.8
 * Python3 >= 3.8.10 

The open62541 library version 1.3.8 is required for the c++ and python client. 
Download the open62541 sources (using git or as a zipfile from github) or use the included in the project. 
Newer versions and documentation on:
 * https://www.open62541.org/
 * https://www.open62541.org/doc/0.3/toc.html
 * https://github.com/open62541/open62541

Install the open62541 library:

    $ cd home/shadow/opcua_client/open62541-1.3.8/
    $ mkdir build
    $ cd build/
    $ cmake ..
    $ make

Build and configure the client project:

    $ cd home/shadow/opcua_client/
    $ mkdir build 
    $ cd build/
    $ cmake ..
    $ make

To test or use the client make sure OPC UA is activated in printer settings. 
(/Menu/Setup/Interfaces/Network services/ ...OPC UA)

    $ cd home/shadow/opcua_client/build
    $ chmod +x client
    $ ./client -h

Visit home/shadow/opcua_client/res/usage.txt for usecases and examples or call ./client --help.

### Use the python-opcua-client

The python client works with the python-opcua library witch is build 
on FreeOpcUa. For more information visit:
 * https://github.com/FreeOpcUa/python-opcua
 * https://python-opcua.readthedocs.io/en/latest/

To use the same functionality in a client based on python the python-opcua library is required.
For istalling the library use following syntax:

    $ sudo apt install python-opcua 
    $ sudo apt install python-opcua-tools
    # pip install opcua

Make sure OPC UA is activated in printer settings. 
(/Menu/Setup/Interfaces/Network services/ ...OPC UA)

    $ cd home/shadow/opcua_cab/
    $ chmod +x client.py
    $ python3 client.py 
        or
    $ ./client.py --help

The python script automatically generates a build directory with output files, depending on jobs entered.

## Dependencies and installation on Windows systems

### Use the cpp-opcua-client

Use Microsoft Visual Studio 17 2022 working with cpp-client.

Project dependencies:
 * CMake >= 3.28.1: http://www.cmake.org/cmake/resources/software.html
 * Microsoft Visual Studio: https://www.visualstudio.com/products/visual-studio-community-vs
 * Python >= 3.12.1: https://python.org/downloads

The open62541 library version 1.3.8 is required for the c++ and python client. 
Download the open62541 sources using git or as a zipfile from github.
    
    $ cd C:\Users\shadow\source\repos\opcua_client
    $ git clone https://github.com/open62541/open62541.git
    $ cd open62541
    $ git checkout tags/v1.3.8

Newer versions and documentation on:
 * https://www.open62541.org/
 * https://www.open62541.org/doc/0.3/toc.html
 * https://github.com/open62541/open62541

Open a Windows Power Shell (cmd) with admin rights and run;

    $ cd C:\Users\shadow\source\repos\opcua_client\open62541
    $ mkdir build   
    $ mkdir lib
    $ cd build
    $ call "C:\Programm Files\Microsoft Visual Studio\2022\Professional\VC\Auxiliary\Build\vcvarsall.bat" x64 # Configure environment
    $ call "C:\Users\shadow\source\tools\cmake-3.28.1-windows-x86_64\bin\cmake-gui.exe" 
    
Configure built with the cmake gui. 
 * Where is the source code: C:\Users\shadow\source\repos\opcua_client\open62541
 * Where to build the binaries: C:\Users\shadow\source\repos\opcua_client\open62541\build
Press >Configure< and select your Visual Studio version. Continue with >Finish<.
Change only the following parameters;
 * BUILD_SHARED_LIBS=ON
 * CMAKE_BUILD_TYPE=Release
 * CMAKE_INSTALL_PREFIX=C:\User\shadow\source\repos\opcua_client\lib
Press >Configure< and continue with pressing >Generate<.
Switch to your cmd window and enter the following commands;

    $ msbuild /m /p:Configuration=Release /p:Platform=x64 open62541.sln
    $ call "C:\Users\shadow\source\tools\cmake-3.28.1-windows-x86_64\bin\cmake.exe" --install .

Under C:\User\shadow\source\repos\opcua_client\lib the files fall out.



    





### Use the python-opcua-client

Project dependencies:
 * Python >= 3.12.1: https://python.org/downloads

The python client works with the python-opcua library witch is build 
on FreeOpcUa. For more information visit:
 * https://github.com/FreeOpcUa/python-opcua
 * https://python-opcua.readthedocs.io/en/latest/

To use the same functionality in a client based on python the python-opcua library is required.
For istalling the library use following syntax:

    $ pip install opcua

Make sure OPC UA is activated in printer settings. 
(/Menu/Setup/Interfaces/Network services/ ...OPC UA)

    $ cd C:\Users\shadow\source\repos\opcua_client\
    $ python .\client.py --help

The python script automatically generates a build directory with output files, depending on jobs entered.

<!-- Eof -->