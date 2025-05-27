/**
 * @file common.c
 * @brief Contains utility functions for the Banking System.
 * 
 * This file contains common helper functions that can be used across
 * the banking system application. These functions perform tasks such
 * as handling user input or managing common banking operations.
 * 
 * @author
 * GARGANTA, Arexzus B.
 * 
 * @date 
 * May 2025
 */

#include "lib/bankinglib.h"
#include <direct.h>
#include <errno.h>

void pauseConsole() {
    LOGGER();
    printf("\n                                                > Press \033[1;33mENTER\033[0m to continue <                                   \n");
    while (_kbhit()) getch();
    char ch = getch();
    LOG_KEY_INPUT(ch);
}

char menuInput() {
    LOGGER();
    while (_kbhit()) getch();
    char ch = getch();
    LOG_KEY_INPUT(ch);
    return ch;
}

int userInput(const char *fmt, void *var) {
    LOGGER();
    char buffer[256];
    char sanitizedBuffer[256];
    size_t index = 0;

    while (1) {
        int ch = _getch();  // Changed from char to int

        // Ignore special keys like arrow keys, function keys
        if (ch == 0 || ch == 224) {
            int special = _getch(); // consume the next code
            LOG("Special key ignored: %d", special);
            continue;
        }

        // Esc key
        if (ch == 27) {
            LOG("Esc key detected.");
            return -1;
        }

        // Enter
        if (ch == '\r') {
            buffer[index] = '\0';
            break;
        }

        // Backspace
        if (ch == '\b') {
            if (index > 0) {
                printf("\b \b");
                index--;
            }
            continue;
        }

        // Accept only printable characters
        if (isprint(ch) && index < sizeof(buffer) - 1) {
            buffer[index++] = ch;
            putchar(ch);
        }
    }

    if (index == 0) {
        LOG("No input provided.");
        return 0;
    }

    // Remove commas
    int j = 0;
    for (size_t i = 0; buffer[i]; i++) {
        if (buffer[i] != ',') {
            sanitizedBuffer[j++] = buffer[i];
        }
    }
    sanitizedBuffer[j] = '\0';

    // Format handling
    if (strcmp(fmt, "%d") == 0) {
        *(int *)var = atoi(sanitizedBuffer);
    } else if (strcmp(fmt, "%f") == 0) {
        *(float *)var = atof(sanitizedBuffer);
    } else if (strcmp(fmt, "%s") == 0) {
        strncpy((char *)var, sanitizedBuffer, 49);
        ((char *)var)[49] = '\0';
    } else {
        LOG("Unsupported format: '%s'", fmt);
        return 0;
    }

    LOG("Scanned input: format='%s', sanitized='%s'", fmt, sanitizedBuffer);
    return 1;
}

const char* getCurrentTimestamp() {
    static char time_buf[20];
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(time_buf, sizeof(time_buf), "%Y-%m-%d %H:%M:%S", tm_info);
    return time_buf;
}

const char* getCurrentDate() {
    static char date_buf[11];
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(date_buf, sizeof(date_buf), "%Y-%m-%d", tm_info);
    return date_buf;
}

void setCurrentDate(char *buffer, size_t size) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(buffer, size, "%Y-%m-%d", tm_info);
}

int createFolderIfNeeded(const char *path) {
    int result = _mkdir(path);
    if (result == 0) {
        LOG("Created folder: %s", path);
        return 1;
    } else if (errno == EEXIST) {
        return 1;
    } else {
        LOG_ERROR("Failed to create folder: %s (errno %d)", path, errno);
        return 0;
    }
}


int fileExists(const char *filename) {
    FILE *file = fopen(filename, "rb");

    if (!file) {
        char path[256];
        strcpy(path, filename);

        char *lastSlash = strrchr(path, '\\');
        if (!lastSlash) lastSlash = strrchr(path, '/');

        if (lastSlash) {
            *lastSlash = 0;
            createFolderIfNeeded(path);
        }

        file = fopen(filename, "wb");
        if (!file) {
            LOG_ERROR("Failed to create missing file: %s", filename);
            return 0;
        }
        LOG("Created missing file: %s", filename);
        fclose(file);
        return 1;
    }

    fclose(file);
    return 1;
}
