#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>

// === Toggle Flags ===
#define DEBUG 1         // Set 0 to disable debug logs
#define INPUT_DEBUG 1   // Set 0 to disable key input logs

// === ANSI Escape Codes for Colors ===
#define ANSI_COLOR_INFO     "\033[1;32m" // Bright Green
#define ANSI_COLOR_WARN     "\033[1;33m" // Bright Yellow
#define ANSI_COLOR_ERROR    "\033[1;31m" // Bright Red
#define ANSI_COLOR_TRACE    "\033[1;36m" // Bright Cyan
#define ANSI_COLOR_FILE     "\033[1;35m" // Bright Magenta
#define ANSI_COLOR_RESET    "\033[0m"    // Reset color

// === Log File Path ===
#define DEBUG_LOG_FILE "log.txt" // Main log file

// === Function declarations ===
void write_log(const char *ansi_color, const char *fmt, ...);
void LOG_COLOR(const char *ansi_color, const char *fmt, ...);

// === General Debug Logger ===
#if DEBUG
    #define LOG(fmt, ...) write_log(ANSI_COLOR_INFO, fmt, ##__VA_ARGS__)
    #define LOG_ERROR(fmt, ...) write_log(ANSI_COLOR_ERROR, fmt, ##__VA_ARGS__)
    #define LOG_WARN(fmt, ...) write_log(ANSI_COLOR_WARN, fmt, ##__VA_ARGS__)
    #define LOGGER() write_log(ANSI_COLOR_TRACE, "Running: %s", __func__)
    #define TRACE(msg) write_log(ANSI_COLOR_TRACE, "TRACE: %s", msg)

    #define LOG_STRUCT_CHANGE_STR(fieldName, oldVal, newVal) do { \
        if (strcmp(oldVal, newVal) != 0) { \
            LOG_COLOR(ANSI_COLOR_WARN, "Struct Change - %s: \"%s\" -> \"%s\"", fieldName, oldVal, newVal); \
        } \
    } while (0)

    #define LOG_STRUCT_CHANGE_VAL(fieldName, oldVal, newVal) do { \
        if ((oldVal) != (newVal)) { \
            LOG_COLOR(ANSI_COLOR_WARN, "Struct Change - %s: %g -> %g", fieldName, (double)(oldVal), (double)(newVal)); \
        } \
    } while (0)

    #define LOG_FILE_CHANGE_STR(field, old_val, new_val) do { \
        if (strlen(new_val) > 0 && strcmp(old_val, new_val) != 0) { \
            LOG_COLOR(ANSI_COLOR_FILE, "File Save - %s changed: \"%s\" -> \"%s\"", field, old_val, new_val); \
        } else if (strcmp(old_val, new_val) == 0) { \
            LOG_COLOR(ANSI_COLOR_FILE, "File Save - %s unchanged: \"%s\"", field, old_val); \
        } \
    } while (0)

    #define LOG_FILE_CHANGE_VAL(field, old_val, new_val) do { \
        if ((old_val) != (new_val)) { \
            LOG_COLOR(ANSI_COLOR_FILE, "File Save - %s changed: \"%g\" -> \"%g\"", field, (double)(old_val), (double)(new_val)); \
        } else { \
            LOG_COLOR(ANSI_COLOR_FILE, "File Save - %s unchanged: \"%g\"", field, (double)(old_val)); \
        } \
    } while (0)
       
    #define LOG_FILE_RETRIEVED_STR(fieldName, oldVal, newVal) do { \
        if (strcmp(oldVal, newVal) != 0) { \
            LOG_COLOR(ANSI_COLOR_FILE, "File Retrieved - %s changed: \"%s\" -> \"%s\"", fieldName, oldVal, newVal); \
        } \
    } while (0)

    #define LOG_FILE_RETRIEVED_VAL(fieldName, oldVal, newVal) do { \
        if ((oldVal) != (newVal)) { \
            LOG_COLOR(ANSI_COLOR_FILE, "File Retrieved - %s changed: %g -> %g", fieldName, (double)(oldVal), (double)(newVal)); \
        } \
    } while (0)
#else
    #define LOG(fmt, ...)
    #define LOG_ERROR(fmt, ...)
    #define LOG_WARN(fmt, ...)
    #define LOGGER()
    #define TRACE(msg)
    #define LOG_STRUCT_CHANGE_STR(fieldName, oldVal, newVal)
    #define LOG_STRUCT_CHANGE_VAL(fieldName, oldVal, newVal)
    #define LOG_FILE_CHANGE_STR(fieldName, oldVal, newVal)
    #define LOG_FILE_CHANGE_VAL(fieldName, oldVal, newVal)
    #define LOG_FILE_RETRIEVED_STR(fieldName, oldVal, newVal)
    #define LOG_FILE_RETRIEVED_VAL(fieldName, oldVal, newVal)
#endif

// === Keyboard Input Debug Logger ===
#if DEBUG && INPUT_DEBUG
    #define LOG_KEY_INPUT(ch) do { \
        if ((ch) == '\r') { \
            LOG_COLOR(ANSI_COLOR_INFO, "Key Input: Enter"); \
        } else if ((ch) == '\b') { \
            LOG_COLOR(ANSI_COLOR_INFO, "Key Input: Backspace"); \
        } else { \
            LOG_COLOR(ANSI_COLOR_INFO, "Key Input: %c", (ch)); \
        } \
    } while (0)
#else
    #define LOG_KEY_INPUT(ch)
#endif

// Optional functions you might implement later
void openLogViewer();
void logReset();
void initSessionLogFilename();
void write_log(const char *ansi_color, const char *fmt, ...);
void LOG_COLOR(const char *ansi_color, const char *fmt, ...);

#endif // DEBUG_H
