#pragma once

// Modify the following defines if you have to target a platform prior to the ones specified below.
// Refer to MSDN for the latest info on corresponding values for different platforms.
#ifndef WINVER				// Allow use of features specific to Windows XP or later.
#define WINVER 0x0501		// Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef _WIN32_WINNT		// Allow use of features specific to Windows XP or later.                   
#define _WIN32_WINNT 0x0501	// Change this to the appropriate value to target other versions of Windows.
#endif						

#ifndef _WIN32_WINDOWS		// Allow use of features specific to Windows 98 or later.
#define _WIN32_WINDOWS 0x0410 // Change this to the appropriate value to target Windows Me or later.
#endif

#ifndef _WIN32_IE			// Allow use of features specific to IE 6.0 or later.
#define _WIN32_IE 0x0600	// Change this to the appropriate value to target other versions of IE.
#endif

// The stacktrace function only works on > NTDDI_WINXP, so for debug we limit it
#ifdef _DEBUG
#define NTDDI_VERSION NTDDI_WINXPSP2
#endif

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#define NOMINMAX
// Windows Header Files:
#include <windows.h>
#include <WindowsX.h>
#include <ShellApi.h>
#include <Commdlg.h>
#include <shlwapi.h>
#include <CommCtrl.h>
#include <HtmlHelp.h>
#include <basetsd.h>

#include <tchar.h>

#include <queue>
#include <string>
#include <map>
#include <set>
#include <list>
#include <fstream>
#include <memory>
#include <exception>
#include <stdlib.h>
#include <iterator>
#include <algorithm>
#include <iomanip>

#include <boost/regex.hpp>
#include <boost/shared_ptr.hpp>

#ifdef _DEBUG
	#undef _DEBUG
	#include <python.h>
	#define _DEBUG
#else
	#include <python.h>
#endif

/*   Warnings disabled because of boost::python
*   4127: Loop/conditional expression is constant
*/
#pragma warning( disable : 4127)
#pragma warning( push )

/*   Warnings disabled for boost::python
*   4244: Conversion from long double to double
*   4512: Assignment operator could not be generated
*   4100: Unreferenced local parameter
*   4459: declaration of 'self' hides global declaration
*   4121: 'boost::python::detail::aligned_storage<28>': alignment of a member was sensitive to packing
*/
#pragma warning( disable : 4244 4512 4100 4459 4121)
#include <boost/python.hpp>
#include <boost/python/raw_function.hpp>
#pragma warning( pop )

#include <NppPluginAPI/include/PluginInterface.h>
#include <NppPluginAPI/include/Notepad_plus_msgs.h>

#ifdef _DEBUG

#define NO_DEFAULT_CASE default: {\
	TCHAR tmpBuf[MAX_PATH + 80];\
	_stprintf_s(tmpBuf, MAX_PATH + 80, TEXT("%s(%d): %s"), TEXT(__FILE__), __LINE__, TEXT("Unhandled default case.\n"));\
    OutputDebugString(tmpBuf);\
    DebugBreak(); \
    }\
    break
#else
#define NO_DEFAULT_CASE 
#endif

// Index type
typedef size_t idx_t;

// Offset type
typedef int    offset_t;

#define IDX_MAX SIZE_MAX

#define OFF_MIN INT_MIN
#define OFF_MAX INT_MAX

// Workaround to fix boost::python::len return type, ssize_t, which is a signed integer.
#define _len(x) ((size_t)len(x))

#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

#include <string>
#include <exception>
#include <atlbase.h>
#include <atlstr.h>
#include <atltypes.h>