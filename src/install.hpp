#include <windows.h>
#ifdef __cplusplus
#define USEC extern "C"
#endif
#ifdef __dllexport
#define ENDPOINT USEC __declspec(dllexport)
#else
#define ENDPOINT USEC __declspec(dllimport)
#endif

ENDPOINT void install(char* packagename);
