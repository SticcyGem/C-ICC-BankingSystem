#include "debug.h"
#include <stdarg.h>
#include <time.h>

void write_log(const char *ansi_color, const char *fmt, ...) {
    static char history_filename[64] = "";
    static int is_history_initialized = 0;

    if (!is_history_initialized) {
        time_t t = time(NULL);
        struct tm *tm_info = localtime(&t);
        strftime(history_filename, sizeof(history_filename), "log/%Y-%m-%d_%H-%M-%S_log.txt", tm_info);
        is_history_initialized = 1;
    }

    FILE *f = fopen(DEBUG_LOG_FILE, "a");
    if (!f) return;

    FILE *h = fopen(history_filename, "a");
    if (!h) {
        fclose(f);
        return;
    }

    const char *time_buf = getCurrentTimestamp();

    fprintf(f, "[%s] ", time_buf);
    fprintf(h, "[%s] ", time_buf);

    fprintf(f, "%s", ansi_color);

    va_list args1, args2;
    va_start(args1, fmt);
    va_copy(args2, args1);

    vfprintf(f, fmt, args1);
    vfprintf(h, fmt, args2);

    va_end(args1);
    va_end(args2);

    fprintf(f, "%s\n", ANSI_COLOR_RESET);
    fprintf(h, "\n");

    fclose(f);
    fclose(h);
}

void LOG_COLOR(const char *ansi_color, const char *fmt, ...) {
    FILE *f = fopen(DEBUG_LOG_FILE, "a");
    if (!f) return;

    const char *time_buf = getCurrentTimestamp();
    fprintf(f, "[%s] ", time_buf);
    fprintf(f, "%s", ansi_color);

    va_list args;
    va_start(args, fmt);
    vfprintf(f, fmt, args);
    va_end(args);

    fprintf(f, "%s\n", ANSI_COLOR_RESET);

    fclose(f);
}

void logReset() {
    LOGGER();
    FILE *logFile = fopen(DEBUG_LOG_FILE, "w");
    if (logFile) {
        fclose(logFile);
    } else {
        LOG("Error resetting log file");
    }
}

void openLogViewer() {
    LOGGER();
    #if DEBUG
        system("start \"LogViewerWindow\" powershell -NoExit -Command \"$host.UI.RawUI.WindowTitle = 'LogViewerWindow'; Get-Content log\\log.txt -Wait\"");
    #endif
}
