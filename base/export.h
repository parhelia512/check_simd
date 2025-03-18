#ifndef LOGGER_EXPORT_H_
#define LOGGER_EXPORT_H_

#if !defined(STATIC_LOGGER)

#if defined(WIN32)
 #define EXPORT __declspec(dllexport)
 #define EXPORT_PRIVATE __declspec(dllexport)
#else
 #define EXPORT __attribute__((visibility("default")))
 #define EXPORT_PRIVATE __attribute__((visibility("default")))
#endif  // defined(WIN32)

#else

#if defined(WIN32)
 #define EXPORT __declspec(dllimport)
 #define EXPORT_PRIVATE __declspec(dllimport)
#else
 #define EXPORT
 #define EXPORT_PRIVATE
#endif  // defined(WIN32)

#endif  // !defined(STATIC_LOGGER)

#endif // LOGGER_EXPORT_H_
