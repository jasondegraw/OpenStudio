#ifndef __AFN_API_HPP__
#define __AFN_API_HPP__

#if _WIN32 || _MSC_VER

#ifdef openstudio_afn_EXPORTS
#define AFN_API __declspec(dllexport)
#else
#define AFN_API __declspec(dllimport)
#endif
#else
#define AFN_API
#endif

#endif
