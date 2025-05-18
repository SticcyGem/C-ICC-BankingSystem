#include "debug.h"
#include <stdarg.h>
#include <direct.h>

static char sessionLogFilename[256] = "";
static int logFileInitialized = 0;

static void initSessionLogFilename() {
    if (!logFileInitialized) {
        _mkdir("logs");
        time_t now = time(NULL);
        struct tm *t = localtime(&now);
        snprintf(sessionLogFilename, sizeof(sessionLogFilename),
                 "logs/%04d%02d%02d_%02d%02d%02d_log.txt",
                 t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
                 t->tm_hour, t->tm_min, t->tm_sec);
        logFileInitialized = 1;
    }
}

// === Implementation of write_log ===
void write_log(const char *ansi_color, const char *fmt, ...) {
    static char history_filename[64] = "";
    static int is_history_initialized = 0;

    _mkdir("log");  // Create "log" folder if it doesn't exist

    // === Initialize history file name only once
    if (!is_history_initialized) {
        time_t t = time(NULL);
        struct tm *tm_info = localtime(&t);
        strftime(history_filename, sizeof(history_filename), "log/%Y-%m-%d_%H-%M-%S_log.txt", tm_info);
        is_history_initialized = 1;
    }

    // Open main log file (with color)
    FILE *f = fopen(DEBUG_LOG_FILE, "a");
    if (!f) return;

    // Open history log file (no color)
    FILE *h = fopen(history_filename, "a");
    if (!h) {
        fclose(f);
        return;
    }

    // Get current timestamp
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    char time_buf[20];
    strftime(time_buf, sizeof(time_buf), "%Y-%m-%d %H:%M:%S", tm_info);

    // Write timestamp to both files
    fprintf(f, "[%s] ", time_buf);
    fprintf(h, "[%s] ", time_buf);

    // Color goes to main log only
    fprintf(f, "%s", ansi_color);

    // Handle variable arguments
    va_list args1, args2;
    va_start(args1, fmt);
    va_copy(args2, args1);

    vfprintf(f, fmt, args1);
    vfprintf(h, fmt, args2);

    va_end(args1);
    va_end(args2);

    // Finish lines
    fprintf(f, "%s\n", ANSI_COLOR_RESET);
    fprintf(h, "\n");

    fclose(f);
    fclose(h);
}

// === LOG_COLOR that only logs to file ===
void LOG_COLOR(const char *ansi_color, const char *fmt, ...) {
    FILE *f = fopen(DEBUG_LOG_FILE, "a");
    if (!f) return;

    // Write timestamp
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    char time_buf[20];
    strftime(time_buf, sizeof(time_buf), "%Y-%m-%d %H:%M:%S", tm_info);
    fprintf(f, "[%s] ", time_buf);

    // Write color code to log file
    fprintf(f, "%s", ansi_color);

    va_list args;
    va_start(args, fmt);
    vfprintf(f, fmt, args);
    va_end(args);

    fprintf(f, "%s\n", ANSI_COLOR_RESET);

    fclose(f);
}
