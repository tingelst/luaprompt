#ifndef LUAPROMPT__VISIBILITY_CONTROL_H_
#define LUAPROMPT__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define LUAPROMPT_EXPORT __attribute__ ((dllexport))
    #define LUAPROMPT_IMPORT __attribute__ ((dllimport))
  #else
    #define LUAPROMPT_EXPORT __declspec(dllexport)
    #define LUAPROMPT_IMPORT __declspec(dllimport)
  #endif
  #ifdef LUAPROMPT_BUILDING_LIBRARY
    #define LUAPROMPT_PUBLIC LUAPROMPT_EXPORT
  #else
    #define LUAPROMPT_PUBLIC LUAPROMPT_IMPORT
  #endif
  #define LUAPROMPT_PUBLIC_TYPE LUAPROMPT_PUBLIC
  #define LUAPROMPT_LOCAL
#else
  #define LUAPROMPT_EXPORT __attribute__ ((visibility("default")))
  #define LUAPROMPT_IMPORT
  #if __GNUC__ >= 4
    #define LUAPROMPT_PUBLIC __attribute__ ((visibility("default")))
    #define LUAPROMPT_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define LUAPROMPT_PUBLIC
    #define LUAPROMPT_LOCAL
  #endif
  #define LUAPROMPT_PUBLIC_TYPE
#endif

#endif  // LUAPROMPT__VISIBILITY_CONTROL_H_
