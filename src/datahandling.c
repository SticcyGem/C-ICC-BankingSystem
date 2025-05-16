/**
 * @file datahandling.c
 * @brief Provides low-level file handling and database manipulation utilities.
 * 
 * Contains helper functions for reading, writing, searching, and modifying
 * text-based databases (Account.txt, StatementOfAccount.txt). Supports 
 * algorithms like line-by-line scanning, appending, and overwriting.
 * 
 * @author 
 * BALANTAC, Neil Justine R.
 * 
 * @date 
 * May 2025
 */

#include <stdio.h>
#include "lib/bankinglib.h"

// Define data handling function
void readStatement(const char* accNum) {
    printf("Reading statement for account %s...\n", accNum);
}
