#ifndef __Airflow_API_HPP__
#define __Airflow_API_HPP__

#if _WIN32 || _MSC_VER

#ifdef openstudio_airflow_EXPORTS
#define AIRFLOW_API __declspec(dllexport)
#else
#define AIRFLOW_API __declspec(dllimport)
#endif
#else
#define AIRFLOW_API
#endif

#endif
