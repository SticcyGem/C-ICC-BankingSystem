/**
 * @file menu.c
 * @brief Handles the console GUI menu systems.
 * 
 * @authors
 * PEREZ, Emmanuel A.
 * 
 * @date 
 * May 2025
 */

#include "lib/bankinglib.h"

void guiCredit(){
    system("cls");
    LOGGER();
    printf(
        "\n"
        "                               ██████ ██████  ███████ ██████  ██ ████████ ███████                               \n"
        "                              ██      ██   ██ ██      ██   ██ ██    ██    ██                                    \n"
        "                              ██      ██████  █████   ██   ██ ██    ██    ███████                               \n"
        "                              ██      ██   ██ ██      ██   ██ ██    ██         ██                               \n"
        "                               ██████ ██   ██ ███████ ██████  ██    ██    ███████                               \n"
        "\n"
        "                                        █▀▀   █▀▀ █▀▄ ▀█▀ ▀█▀ ▀█▀ █▀█ █▀█                                       \n"
        "                                        █     █▀▀ █ █  █   █   █  █ █ █ █                                       \n"
        "                                        ▀▀▀   ▀▀▀ ▀▀  ▀▀▀  ▀  ▀▀▀ ▀▀▀ ▀ ▀                                       \n"
        "\n"
        "\n"
    );
    Sleep(1000);
    printf(
        "█▀█ █▀▄ █▀█ ▀▀█ █▀▀ █▀▀ ▀█▀   █   █▀▀ █▀█ █▀▄\n"
        "█▀▀ █▀▄ █ █   █ █▀▀ █    █    █   █▀▀ █▀█ █ █\n"
        "▀   ▀ ▀ ▀▀▀ ▀▀  ▀▀▀ ▀▀▀  ▀    ▀▀▀ ▀▀▀ ▀ ▀ ▀▀ \n"
        "\n"
        "-> PEREZ, Emmanuel A.           | Banking System: Program Flow           | Github: SticcyGem           \n"
        "                                | Banking System: Header Library         |                             \n"
        "                                | Banking System: Graphic User Interface |                             \n"
        "\n"
    );
    Sleep(2000);
    printf(
        "█▀▀   █▀█ █▀▄ █▀█ █▀▀ █▀▄ █▀█ █▄█ █▄█ █▀▀ █▀▄\n"
        "█     █▀▀ █▀▄ █ █ █ █ █▀▄ █▀█ █ █ █ █ █▀▀ █▀▄\n"
        "▀▀▀   ▀   ▀ ▀ ▀▀▀ ▀▀▀ ▀ ▀ ▀ ▀ ▀ ▀ ▀ ▀ ▀▀▀ ▀ ▀\n"
        "\n"
        "Project Link: https://github.com/SticcyGem/C-ICC-BankingSystem.git \n"
        "\n"
        "-> ANUTA, Vhien H.              | Account: Creation System               | Github: algo-boy           \n"
        "-> ESPEJO, John Gabriel R.      | Account: Inquiry, Deposit, Withdraw    | Github: ishiigami          \n"
        "-> LUMAKIN, Luke Gabriel C.     | Account: Update, Delete                | Github: lukegabriel520     \n"
        "-> BALANTAC, Neil Justine R.    | Database: Manipulation                 | Github: Sirpandaboi        \n"
        "-> GARGANTA, Arexzus B.         | Doccumentation                         | Github: rekzus             \n"
        "\n"
    );
    Sleep(3000);
    printf(
        "█▀▀          █▀█ █▀▄ █▀█ █▀▀ █▀▄ █▀█ █▄█ █▄█ █▀▀ █▀▄\n"
        "█   ▄█▄ ▄█▄  █▀▀ █▀▄ █ █ █ █ █▀▄ █▀█ █ █ █ █ █▀▀ █▀▄\n"
        "▀▀▀  ▀   ▀   ▀   ▀ ▀ ▀▀▀ ▀▀▀ ▀ ▀ ▀ ▀ ▀ ▀ ▀ ▀ ▀▀▀ ▀ ▀\n"
        "\n"
        "Project Link: \n"
        "\n"
        "-> PACULAN, Mikhaela Abbygail C.| Account: Creation System               | Github: MikhaelaPaculan    \n"
        "-> BONIFACIO, James Craven C.   | Account: Inquiry, Deposit, Withdraw    | Github: Azure-Light-Studios\n"
        "                                | Account: Update, Delete                |                            \n"
        "-> CHEN, Kenneth M.             | Database: Manipulation                 | Github: kennethchen-cs     \n"
        "-> SULIT, Ruzzel Mae P.         | Doccumentation                         | Github: ryuzzel            \n"
        "\n"
    );
    Sleep(3000);
    printf(
        "▀▀█ █▀█ █ █ █▀█   █▀█ █▀▄ █▀█ █▀▀ █▀▄ █▀█ █▄█ █▄█ █▀▀ █▀▄\n"
        "  █ █▀█ ▀▄▀ █▀█   █▀▀ █▀▄ █ █ █ █ █▀▄ █▀█ █ █ █ █ █▀▀ █▀▄\n"
        "▀▀  ▀ ▀  ▀  ▀ ▀   ▀   ▀ ▀ ▀▀▀ ▀▀▀ ▀ ▀ ▀ ▀ ▀ ▀ ▀ ▀ ▀▀▀ ▀ ▀\n"
        "Project Link: \n"
        "\n"
        "-> PELAYO, Wilhelm Gabrielle    | Account: Creation System               | Github: wgpelayo          \n"
        "-> CANARIA, Raine Dominique P.  | Account: Inquiry, Deposit, Withdraw    | Github: rdc-hdg           \n"
        "-> DATU, Trixia Kyle M.         | Account: Update, Delete                | Github: kyxia-dt          \n"
        "-> UNDAG, Matthew James C.      | Database: Manipulation                 | Github: Mattjamesss       \n"
        "-> DICKINSON, Jedrick C.        | Doccumentation                         | Github: Jediyx            \n"
        "\n"
    );
    Sleep(3000);
    pauseConsole();
}

void guiAuthMenu(){
    system("cls");
    LOGGER();
    printf(
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "   ██████   █████  ███    ██ ██   ██ ██ ███    ██  ██████      ███████ ██    ██ ███████ ████████ ███████ ███    ███  \n"
        "   ██   ██ ██   ██ ████   ██ ██  ██  ██ ████   ██ ██           ██       ██  ██  ██         ██    ██      ████  ████  \n"
        "   ██████  ███████ ██ ██  ██ █████   ██ ██ ██  ██ ██   ███     ███████   ████   ███████    ██    █████   ██ ████ ██  \n"
        "   ██   ██ ██   ██ ██  ██ ██ ██  ██  ██ ██  ██ ██ ██    ██          ██    ██         ██    ██    ██      ██  ██  ██  \n"
        "   ██████  ██   ██ ██   ████ ██   ██ ██ ██   ████  ██████      ███████    ██    ███████    ██    ███████ ██      ██  \n"
        "\n"
        "                                           █▀▀   █▀▀ █▀▄ ▀█▀ ▀█▀ ▀█▀ █▀█ █▀█                                         \n"
        "                                           █     █▀▀ █ █  █   █   █  █ █ █ █                                         \n"
        "                                           ▀▀▀   ▀▀▀ ▀▀  ▀▀▀  ▀  ▀▀▀ ▀▀▀ ▀ ▀                                         \n"
        "\n"
        "\n"
        "\n"
        "\n"
        "       ░█▀░░▀█░░▀█░░░░█░░░█▀█░█▀▀░░░▀█▀░█▀█░░░░░░░                  ░█▀░░▀▀█░▀█░░░░█▀▀░█▀▄░█▀▀░█▀▄░▀█▀░▀█▀░█▀▀░      \n"
        "       ░█░░░░█░░░█░░░░█░░░█░█░█░█░░░░█░░█░█░░░░░░░                  ░█░░░░▀▄░░█░░░░█░░░█▀▄░█▀▀░█░█░░█░░░█░░▀▀█░      \n"
        "       ░▀▀░░▀▀▀░▀▀░░░░▀▀▀░▀▀▀░▀▀▀░░░▀▀▀░▀░▀░░░░░░░                  ░▀▀░░▀▀░░▀▀░░░░▀▀▀░▀░▀░▀▀▀░▀▀░░▀▀▀░░▀░░▀▀▀░      \n"
        "\n"
        "       ░█▀░░▀▀▄░▀█░░░░█▀▀░▀█▀░█▀▀░█▀█░░░█░█░█▀█░░░                  ░█▀░░█░█░▀█░░░░█▀▀░█░█░▀█▀░▀█▀░░░░░░░░░░░░░      \n"
        "       ░█░░░▄▀░░░█░░░░▀▀█░░█░░█░█░█░█░░░█░█░█▀▀░░░                  ░█░░░▀▀█░░█░░░░█▀▀░▄▀▄░░█░░░█░░░░░░░░░░░░░░      \n"
        "       ░▀▀░░▀▀▀░▀▀░░░░▀▀▀░▀▀▀░▀▀▀░▀░▀░░░▀▀▀░▀░░░░░                  ░▀▀░░░░▀░▀▀░░░░▀▀▀░▀░▀░▀▀▀░░▀░░░░░░░░░░░░░░      \n"
        "\n"
    );
}

void guiMainMenu(const Account *acc){
    system("cls");
    LOGGER();
    printf(
        "\n"
        "                        ███    ███  █████  ██ ███    ██     ███    ███ ███████ ███    ██ ██    ██                    \n"
        "                        ████  ████ ██   ██ ██ ████   ██     ████  ████ ██      ████   ██ ██    ██                    \n"
        "                        ██ ████ ██ ███████ ██ ██ ██  ██     ██ ████ ██ █████   ██ ██  ██ ██    ██                    \n"
        "                        ██  ██  ██ ██   ██ ██ ██  ██ ██     ██  ██  ██ ██      ██  ██ ██ ██    ██                    \n"
        "                        ██      ██ ██   ██ ██ ██   ████     ██      ██ ███████ ██   ████  ██████                     \n"
        "\n"
        "                                █▀▄ █▀█ █▀█ █ █ ▀█▀ █▀█ █▀▀   █▀▀ █ █ █▀▀ ▀█▀ █▀▀ █▄█                                \n"
        "                                █▀▄ █▀█ █ █ █▀▄  █  █ █ █ █   ▀▀█  █  ▀▀█  █  █▀▀ █ █                                \n"
        "                                ▀▀  ▀ ▀ ▀ ▀ ▀ ▀ ▀▀▀ ▀ ▀ ▀▀▀   ▀▀▀  ▀  ▀▀▀  ▀  ▀▀▀ ▀ ▀                                \n"
        "\n"
        "                                              ░ Account Number: %d ░                                             \n"
        "\n"
        "\n"
        "\n"
        "       ░█▀░░▀█░░▀█░░░░▀█▀░█▀█░█▀█░░█░█░▀█▀░█▀▄░█░█░░░░      ░█▀░░█░█░▀█░░░░█▀▀░█▀▀░▀█▀░▀█▀░▀█▀░█▀█░█▀▀░░░░░░░░░      \n"
        "       ░█░░░░█░░░█░░░░░█░░█░█░█ █░░█░█░░█░░█▀▄░░█░░░░░      ░█░░░▀▀█░░█░░░░▀▀█░█▀▀░░█░░░█░░░█░░█░█░█░█░░░░░░░░░      \n"
        "       ░▀▀░░▀▀▀░▀▀░░░░▀▀▀░▀░▀░░▀▀▀░▀▀▀░▀▀▀░▀░▀░░▀░░░░░      ░▀▀░░░░▀░▀▀░░░░▀▀▀░▀▀▀░░▀░░░▀░░▀▀▀░▀░▀░▀▀▀░░░░░░░░░      \n"
        "\n"
        "       ░█▀░░▀▀▄░▀█░░░░█▀▄░█▀▀░█▀█░█▀█░█▀▀░▀█▀░▀█▀░░░░░      ░█▀░░█▀▀░▀█░░░░█░░░█▀█░█▀▀░░░█▀█░█░█░▀█▀░░░░░░░░░░░      \n"
        "       ░█░░░▄▀░░░█░░░░█░█░█▀▀░█▀▀░█░█░▀▀█░░█░░░█░░░░░░      ░█░░░▀▀▄░░█░░░░█░░░█░█░█░█░░░█░█░█░█░░█░░░░░░░░░░░░      \n"
        "       ░▀▀░░▀▀▀░▀▀░░░░▀▀░░▀▀▀░▀░░░▀▀▀░▀▀▀░▀▀▀░░▀░░░░░░      ░▀▀░░▀▀░░▀▀░░░░▀▀▀░▀▀▀░▀▀▀░░░▀▀▀░▀▀▀░░▀░░░░░░░░░░░░      \n"
        "\n"
        "       ░█▀░░▀▀█░▀█░░░░█░█░▀█▀░▀█▀░█░█░█▀▄░█▀▄░█▀█░█░█░                                                               \n"
        "       ░█░░░░▀▄░░█░░░░█▄█░░█░░░█░░█▀█░█░█░█▀▄░█▀█░█▄█░                                                               \n"
        "       ░▀▀░░▀▀░░▀▀░░░░▀░▀░▀▀▀░░▀░░▀░▀░▀▀░░▀░▀░▀░▀░▀░▀░                                                               \n"
        "\n", acc->accountNumber
    );
}

void guiAccSettingMenu(){
    system("cls");
    LOGGER();
    printf(
        "\n"
        "                 █████   ██████  ██████        ███████ ███████ ████████ ████████ ██ ███    ██  ██████                \n"
        "                ██   ██ ██      ██             ██      ██         ██       ██    ██ ████   ██ ██                     \n"
        "                ███████ ██      ██             ███████ █████      ██       ██    ██ ██ ██  ██ ██   ███               \n"
        "                ██   ██ ██      ██                  ██ ██         ██       ██    ██ ██  ██ ██ ██    ██               \n"
        "                ██   ██  ██████  ██████ ██     ███████ ███████    ██       ██    ██ ██   ████  ██████                \n"
        "\n"
        "                                █▀▄ █▀█ █▀█ █ █ ▀█▀ █▀█ █▀▀   █▀▀ █ █ █▀▀ ▀█▀ █▀▀ █▄█                                \n"
        "                                █▀▄ █▀█ █ █ █▀▄  █  █ █ █ █   ▀▀█  █  ▀▀█  █  █▀▀ █ █                                \n"
        "                                ▀▀  ▀ ▀ ▀ ▀ ▀ ▀ ▀▀▀ ▀ ▀ ▀▀▀   ▀▀▀  ▀  ▀▀▀  ▀  ▀▀▀ ▀ ▀                                \n"
        "\n"
        "\n"
        "                       ░█▀░░▀█░░▀█░░░░█▀▄░▀█▀░█▀▀░█▀█░█░░░█▀█░█░█░░░█▀▄░█▀▀░▀█▀░█▀█░▀█▀░█░░░█▀▀░                     \n"
        "                       ░█░░░░█░░░█░░░░█░█░░█░░▀▀█░█▀▀░█░░░█▀█░░█░░░░█░█░█▀▀░░█░░█▀█░░█░░█░░░▀▀█░                     \n"
        "                       ░▀▀░░▀▀▀░▀▀░░░░▀▀░░▀▀▀░▀▀▀░▀░░░▀▀▀░▀░▀░░▀░░░░▀▀░░▀▀▀░░▀░░▀░▀░▀▀▀░▀▀▀░▀▀▀░                     \n"
        "\n"
        "                       ░█▀░░▀▀▄░▀█░░░░█▀▀░█▀▄░▀█▀░▀█▀░░░█▀▄░█▀▀░▀█▀░█▀█░▀█▀░█░░░█▀▀░░░░░░░░░░░░░                     \n"
        "                       ░█░░░▄▀░░░█░░░░█▀▀░█░█░░█░░░█░░░░█░█░█▀▀░░█░░█▀█░░█░░█░░░▀▀█░░░░░░░░░░░░░                     \n"
        "                       ░▀▀░░▀▀▀░▀▀░░░░▀▀▀░▀▀░░▀▀▀░░▀░░░░▀▀░░▀▀▀░░▀░░▀░▀░▀▀▀░▀▀▀░▀▀▀░░░░░░░░░░░░░                     \n"
        "\n"
        "                       ░█▀░░▀▀█░▀█░░░░█▀▄░█▀▀░█░░░█▀▀░▀█▀░█▀▀░░░█▀█░█▀▀░█▀▀░█▀█░█░█░█▀█░▀█▀░░░░░                     \n"
        "                       ░█░░░░▀▄░░█░░░░█░█░█▀▀░█░░░█▀▀░░█░░█▀▀░░░█▀█░█░░░█░░░█░█░█░█░█░█░░█░░░░░░                     \n"
        "                       ░▀▀░░▀▀░░▀▀░░░░▀▀░░▀▀▀░▀▀▀░▀▀▀░░▀░░▀▀▀░░░▀░▀░▀▀▀░▀▀▀░▀▀▀░▀▀▀░▀░▀░░▀░░░░░░                     \n"
        "\n"
        "                       ░█▀░░█░█░▀█░░░░█▀▄░█▀█░█▀▀░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░                     \n"
        "                       ░█░░░▀▀█░░█░░░░█▀▄░█▀█░█░░░█▀▄░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░                     \n"
        "                       ░▀▀░░░░▀░▀▀░░░░▀▀░░▀░▀░▀▀▀░▀░▀░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░                     \n"
        "\n"
    );
}

void guiAccEditingMenu(){
    system("cls");
    LOGGER();
    printf(
        "\n"
        "                    █████   ██████  ██████        ███████ ██████  ██ ████████ ██ ███    ██  ██████                   \n"
        "                   ██   ██ ██      ██             ██      ██   ██ ██    ██    ██ ████   ██ ██                        \n"
        "                   ███████ ██      ██             █████   ██   ██ ██    ██    ██ ██ ██  ██ ██   ███                  \n"
        "                   ██   ██ ██      ██             ██      ██   ██ ██    ██    ██ ██  ██ ██ ██    ██                  \n"
        "                   ██   ██  ██████  ██████ ██     ███████ ██████  ██    ██    ██ ██   ████  ██████                   \n"
        "\n"
        "                                █▀▄ █▀█ █▀█ █ █ ▀█▀ █▀█ █▀▀   █▀▀ █ █ █▀▀ ▀█▀ █▀▀ █▄█                                \n"
        "                                █▀▄ █▀█ █ █ █▀▄  █  █ █ █ █   ▀▀█  █  ▀▀█  █  █▀▀ █ █                                \n"
        "                                ▀▀  ▀ ▀ ▀ ▀ ▀ ▀ ▀▀▀ ▀ ▀ ▀▀▀   ▀▀▀  ▀  ▀▀▀  ▀  ▀▀▀ ▀ ▀                                \n"
        "\n"
        "\n"
        "                          ░█▀░░▀█░░▀█░░░░█▀▀░█▀▄░▀█▀░▀█▀░░░█▀█░█▀█░█▄█░█▀▀░░░░░░░░░░░░░░░░░                          \n"
        "                          ░█░░░░█░░░█░░░░█▀▀░█░█░░█░░░█░░░░█░█░█▀█░█░█░█▀▀░░░░░░░░░░░░░░░░░                          \n"
        "                          ░▀▀░░▀▀▀░▀▀░░░░▀▀▀░▀▀░░▀▀▀░░▀░░░░▀░▀░▀░▀░▀░▀░▀▀▀░░░░░░░░░░░░░░░░░                          \n"
        "\n"
        "                          ░█▀░░▀▀▄░▀█░░░░█▀▀░█▀▄░▀█▀░▀█▀░░░█▀█░█▀▄░█▀▄░█▀▄░█▀▀░█▀▀░█▀▀░░░░░                          \n"
        "                          ░█░░░▄▀░░░█░░░░█▀▀░█░█░░█░░░█░░░░█▀█░█░█░█░█░█▀▄░█▀▀░▀▀█░▀▀█░░░░░                          \n"
        "                          ░▀▀░░▀▀▀░▀▀░░░░▀▀▀░▀▀░░▀▀▀░░▀░░░░▀░▀░▀▀░░▀▀░░▀░▀░▀▀▀░▀▀▀░▀▀▀░░░░░                          \n"
        "\n"
        "                          ░█▀░░▀▀█░▀█░░░░█▀▀░█▀▄░▀█▀░▀█▀░░░█▀█░█▀█░█▀▀░█▀▀░█░█░█▀█░█▀▄░█▀▄░                          \n"
        "                          ░█░░░░▀▄░░█░░░░█▀▀░█░█░░█░░░█░░░░█▀▀░█▀█░▀▀█░▀▀█░█▄█░█░█░█▀▄░█░█░                          \n"
        "                          ░▀▀░░▀▀░░▀▀░░░░▀▀▀░▀▀░░▀▀▀░░▀░░░░▀░░░▀░▀░▀▀▀░▀▀▀░▀░▀░▀▀▀░▀░▀░▀▀░░                          \n"
        "\n"
        "                          ░█▀░░█░█░▀█░░░░█▀▄░█▀█░█▀▀░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░                          \n"
        "                          ░█░░░▀▀█░░█░░░░█▀▄░█▀█░█░░░█▀▄░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░                          \n"
        "                          ░▀▀░░░░▀░▀▀░░░░▀▀░░▀░▀░▀▀▀░▀░▀░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░                          \n"
        "\n"
    );
}

void guiAccDeleteMenu(){
    system("cls");
    LOGGER();
    printf(
        "\033[31m\n"
        "             █████   ██████  ██████        ██████  ███████ ██      ███████ ████████ ██  ██████  ███    ██            \n"
        "            ██   ██ ██      ██             ██   ██ ██      ██      ██         ██    ██ ██    ██ ████   ██            \n"
        "            ███████ ██      ██             ██   ██ █████   ██      █████      ██    ██ ██    ██ ██ ██  ██            \n"
        "            ██   ██ ██      ██             ██   ██ ██      ██      ██         ██    ██ ██    ██ ██  ██ ██            \n"
        "            ██   ██  ██████  ██████ ██     ██████  ███████ ███████ ███████    ██    ██  ██████  ██   ████            \n"
        "\033[0m\n"
        "\n"
        "                 █▀█ █▀▄ █▀▀   █ █ █▀█ █ █   █▀▀ █ █ █▀▄ █▀▀   █ █ █▀█ █ █   █ █ █▀█ █▀█ ▀█▀   ▀█▀ █▀█               \n"
        "                 █▀█ █▀▄ █▀▀    █  █ █ █ █   ▀▀█ █ █ █▀▄ █▀▀    █  █ █ █ █   █▄█ █▀█ █ █  █     █  █ █               \n"
        "                 ▀ ▀ ▀ ▀ ▀▀▀    ▀  ▀▀▀ ▀▀▀   ▀▀▀ ▀▀▀ ▀ ▀ ▀▀▀    ▀  ▀▀▀ ▀▀▀   ▀ ▀ ▀ ▀ ▀ ▀  ▀     ▀  ▀▀▀               \n"
        "                      \033[31m█▀▄ █▀▀ █   █▀▀ ▀█▀ █▀▀\033[0m   █ █ █▀█ █ █ █▀▄   █▀█ █▀▀ █▀▀ █▀█ █ █ █▀█ ▀█▀ ▀▀█     \n"
        "                      \033[31m█ █ █▀▀ █   █▀▀  █  █▀▀\033[0m    █  █ █ █ █ █▀▄   █▀█ █   █   █ █ █ █ █ █  █   ▀      \n"
        "                      \033[31m▀▀  ▀▀▀ ▀▀▀ ▀▀▀  ▀  ▀▀▀\033[0m    ▀  ▀▀▀ ▀▀▀ ▀ ▀   ▀ ▀ ▀▀▀ ▀▀▀ ▀▀▀ ▀▀▀ ▀ ▀  ▀   ▀      \n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "                                             ░█▀░░▀█░░▀█░░░░█▀█░█▀█░░░░░                                             \n"
        "                                             ░█░░░░█░░░█░░░░█░█░█░█░░░░░                                             \n"
        "                                             ░▀▀░░▀▀▀░▀▀░░░░▀░▀░▀▀▀░░░░░                                             \n"
        "\n"
        "                                             ░█▀░░▀▀▄░▀█░░░░█░█░█▀▀░█▀▀░                                             \n"
        "                                             ░█░░░▄▀░░░█░░░░░█░░█▀▀░▀▀█░                                             \n"
        "                                             ░▀▀░░▀▀▀░▀▀░░░░░▀░░▀▀▀░▀▀▀░                                             \n"
        "\n"
        "\n"
    );
}

void guiAccInquiryMenu(){
    system("cls");
    LOGGER();
    printf(
        "\n"
        "                    █████   ██████  ██████        ██ ███    ██  ██████  ██    ██ ██ ██████  ██    ██                 \n"
        "                   ██   ██ ██      ██             ██ ████   ██ ██    ██ ██    ██ ██ ██   ██  ██  ██                  \n"
        "                   ███████ ██      ██             ██ ██ ██  ██ ██    ██ ██    ██ ██ ██████    ████                   \n"
        "                   ██   ██ ██      ██             ██ ██  ██ ██ ██ ▄▄ ██ ██    ██ ██ ██   ██    ██                    \n"
        "                   ██   ██  ██████  ██████ ██     ██ ██   ████  ██████   ██████  ██ ██   ██    ██                    \n"
        "                                                                   ▀▀                                                \n"
        "                                █▀▄ █▀█ █▀█ █ █ ▀█▀ █▀█ █▀▀   █▀▀ █ █ █▀▀ ▀█▀ █▀▀ █▄█                                \n"
        "                                █▀▄ █▀█ █ █ █▀▄  █  █ █ █ █   ▀▀█  █  ▀▀█  █  █▀▀ █ █                                \n"
        "                                ▀▀  ▀ ▀ ▀ ▀ ▀ ▀ ▀▀▀ ▀ ▀ ▀▀▀   ▀▀▀  ▀  ▀▀▀  ▀  ▀▀▀ ▀ ▀                                \n"
        "\n"
        "\n"
        "                   ░█▀░░▀█░░▀█░░░░█▀▀░█░█░█▀▀░█▀▀░█░█░░░█▀▄░█▀█░█░░░█▀█░█▀█░█▀▀░█▀▀░░░░░░░░░░░░░░░░░                 \n"
        "                   ░█░░░░█░░░█░░░░█░░░█▀█░█▀▀░█░░░█▀▄░░░█▀▄░█▀█░█░░░█▀█░█░█░█░░░█▀▀░░░░░░░░░░░░░░░░░                 \n"
        "                   ░▀▀░░▀▀▀░▀▀░░░░▀▀▀░▀░▀░▀▀▀░▀▀▀░▀░▀░░░▀▀░░▀░▀░▀▀▀░▀░▀░▀░▀░▀▀▀░▀▀▀░░░░░░░░░░░░░░░░░                 \n"
        "\n"
        "                   ░█▀░░▀▀▄░▀█░░░░█▀█░█▀▀░█▀▀░█▀█░█░█░█▀█░▀█▀░░░█▀▀░▀█▀░█▀█░▀█▀░█▀▀░█▄█░█▀▀░█▀█░▀█▀░                 \n"
        "                   ░█░░░▄▀░░░█░░░░█▀█░█░░░█░░░█░█░█░█░█░█░░█░░░░▀▀█░░█░░█▀█░░█░░█▀▀░█░█░█▀▀░█░█░░█░░                 \n"
        "                   ░▀▀░░▀▀▀░▀▀░░░░▀░▀░▀▀▀░▀▀▀░▀▀▀░▀▀▀░▀░▀░░▀░░░░▀▀▀░░▀░░▀░▀░░▀░░▀▀▀░▀░▀░▀▀▀░▀░▀░░▀░░                 \n"
        "\n"
        "                   ░█▀░░▀▀█░▀█░░░░█▀▄░█▀█░█▀▀░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░                 \n"
        "                   ░█░░░░▀▄░░█░░░░█▀▄░█▀█░█░░░█▀▄░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░                 \n"
        "                   ░▀▀░░▀▀░░▀▀░░░░▀▀░░▀░▀░▀▀▀░▀░▀░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░                 \n"
    );
}
void guiAccDisplay(const Account *acc) {
    system("cls");
    LOGGER();
    printf("=== Account Details ===\n");
    printf("Account Number : %d\n", acc->accountNumber);
    printf("Name           : %s, %s %s\n", acc->lastname, acc->firstname, acc->midname);
    printf("Address        : %s, %s, %s, %s\n",
           acc->street, acc->barangay, acc->city, acc->region);
    printf("Postal Code    : %s\n", acc->postalCode);
    pauseConsole();
}

void guiAccBalance(const Account *acc) {
    system("cls");
    LOGGER();
    printf("=== Account Inquiry ===\n");
    printf("Account Number : %d\n", acc->accountNumber);
    printf("Balance        : %.2f\n", acc->balance);
    pauseConsole();
}

void guiAccSignup() {
    system("cls");
    LOGGER();
    printf(
        "\n"
        "                                  ███████ ██  ██████  ███    ██     ██    ██ ██████                                  \n"
        "                                  ██      ██ ██       ████   ██     ██    ██ ██   ██                                 \n"
        "                                  ███████ ██ ██   ███ ██ ██  ██     ██    ██ ██████                                  \n"
        "                                       ██ ██ ██    ██ ██  ██ ██     ██    ██ ██                                      \n"
        "                                  ███████ ██  ██████  ██   ████      ██████  ██                                      \n"
        "\n\n\n"
    );
}

void guiAccLogin() {
    system("cls");
    LOGGER();
    printf(
        "\n"
        "                                     ██       ██████   ██████      ██ ███    ██                                     \n"
        "                                     ██      ██    ██ ██           ██ ████   ██                                     \n"
        "                                     ██      ██    ██ ██   ███     ██ ██ ██  ██                                     \n"
        "                                     ██      ██    ██ ██    ██     ██ ██  ██ ██                                     \n"
        "                                     ███████  ██████   ██████      ██ ██   ████                                     \n"
        "\n\n\n"
    );
}

void guiAccDeposit() {
    system("cls");
    LOGGER();
    printf(
        "\n"
        "                                 ██████  ███████ ██████   ██████  ███████ ██ ████████                                \n"
        "                                 ██   ██ ██      ██   ██ ██    ██ ██      ██    ██                                   \n"
        "                                 ██   ██ █████   ██████  ██    ██ ███████ ██    ██                                   \n"
        "                                 ██   ██ ██      ██      ██    ██      ██ ██    ██                                   \n"
        "                                 ██████  ███████ ██       ██████  ███████ ██    ██                                   \n"
        "\n\n\n"
    );
}

void guiAccWithdraw() {
    system("cls");
    LOGGER();
    printf(
        "\n"
        "                           ██     ██ ██ ████████ ██   ██ ██████  ██████   █████  ██     ██                           \n"
        "                           ██     ██ ██    ██    ██   ██ ██   ██ ██   ██ ██   ██ ██     ██                           \n"
        "                           ██  █  ██ ██    ██    ███████ ██   ██ ██████  ███████ ██  █  ██                           \n"
        "                           ██ ███ ██ ██    ██    ██   ██ ██   ██ ██   ██ ██   ██ ██ ███ ██                           \n"
        "                            ███ ███  ██    ██    ██   ██ ██████  ██   ██ ██   ██  ███ ███                            \n"
        "\n\n\n"
    );
}

void guiAccEditName() {
    system("cls");
    LOGGER();
    printf(
        "\n"
        "                         ███████ ██████  ██ ████████     ███    ██  █████  ███    ███ ███████                        \n"
        "                         ██      ██   ██ ██    ██        ████   ██ ██   ██ ████  ████ ██                             \n"
        "                         █████   ██   ██ ██    ██        ██ ██  ██ ███████ ██ ████ ██ █████                          \n"
        "                         ██      ██   ██ ██    ██        ██  ██ ██ ██   ██ ██  ██  ██ ██                             \n"
        "                         ███████ ██████  ██    ██        ██   ████ ██   ██ ██      ██ ███████                        \n"
        "\n\n\n"
    );
}

void guiAccEditAddress() {
    system("cls");
    LOGGER();
    printf(
        "\n"
        "               ███████ ██████  ██ ████████      █████  ██████  ██████  ██████  ███████ ███████ ███████               \n"
        "               ██      ██   ██ ██    ██        ██   ██ ██   ██ ██   ██ ██   ██ ██      ██      ██                    \n"
        "               █████   ██   ██ ██    ██        ███████ ██   ██ ██   ██ ██████  █████   ███████ ███████               \n"
        "               ██      ██   ██ ██    ██        ██   ██ ██   ██ ██   ██ ██   ██ ██           ██      ██               \n"
        "               ███████ ██████  ██    ██        ██   ██ ██████  ██████  ██   ██ ███████ ███████ ███████               \n"
        "\n\n\n"
    );
}

void guiAccEditPassword() {
    system("cls");
    LOGGER();
    printf(
        "\n"
        "         ███████ ██████  ██ ████████     ██████   █████  ███████ ███████ ██     ██  ██████  ██████  ██████           \n"
        "         ██      ██   ██ ██    ██        ██   ██ ██   ██ ██      ██      ██     ██ ██    ██ ██   ██ ██   ██          \n"
        "         █████   ██   ██ ██    ██        ██████  ███████ ███████ ███████ ██  █  ██ ██    ██ ██████  ██   ██          \n"
        "         ██      ██   ██ ██    ██        ██      ██   ██      ██      ██ ██ ███ ██ ██    ██ ██   ██ ██   ██          \n"
        "         ███████ ██████  ██    ██        ██      ██   ██ ███████ ███████  ███ ███   ██████  ██   ██ ██████           \n"
        "\n\n\n"
    );
}

int guiStringInput(Account *acc, Account *accb, int choice){
    LOGGER();
    int loop = 1;
    switch (choice){
        case GUI_INPUT_ACCOUNTNUMBER_LOGIN:
            LOG("Using Account Number Input GUI");

            int genAccNum = getNextAccountNumber("data/Accounts.txt");
            int accNum;

            printf(
                "                                              Your Account ID Is: \033[1;33m%d\033[0m\n"
                "                                Remember it! You will need it to access your account.                                \n"
                "\n"
                "                                         Enter your Account ID to continue...                                        \n"
                "\n"
                "\033[1;33m\n"
                "                                         █▀█ █▀▀ █▀▀ █▀█ █ █ █▀█ ▀█▀   ▀█▀ █▀▄                                       \n"
                "                                         █▀█ █   █   █ █ █ █ █ █  █     █  █ █                                       \n"
                "                                         ▀ ▀ ▀▀▀ ▀▀▀ ▀▀▀ ▀▀▀ ▀ ▀  ▀    ▀▀▀ ▀▀                                        \n"
                "\033[0m\n", genAccNum
            );
            printf("                               >   \033[1;33m ");
            while (loop) {
                int result = userInput("%d", &accNum);
                if (result == -1) {
                    LOG("Esc key pressed. Exiting Account Number Input.");
                    printf("\033[0m");
                    return 0;
                }
                if (!result) {
                    printf("\n\n                               \033[31m Invalid input. Please try again.                                \033[0m");
                    printf(
                        "\033[1A\r\033[1A\r                                                                                                                     "
                        "\033[1G\033[0m                               >   \033[1;33m "
                    );
                    fflush(stdout);
                    continue;
                }
        
                if (accNum != genAccNum) {
                    printf("\n\n                               \033[31m Account ID does not match. Please try again.                    \033[0m");
                    printf(
                        "\033[1A\r\033[1A\r                                                                                                                     "
                        "\033[1G\033[0m                               >   \033[1;33m "
                    );
                    fflush(stdout);
                    continue;
                }

                acc->accountNumber = genAccNum;
                LOG_STRUCT_CHANGE_VAL("Account Number", accb->accountNumber, acc->accountNumber);
                
                break;
            }
            break;
        case GUI_INPUT_PASSWORD_SIGNUP:
            LOG("Using Password Input GUI");
            char pass[50];
            char confirmPass[50];
            printf(
                "                                                                                                                     \033[1;33m\n"
                "                                           █▀█ █▀█ █▀▀ █▀▀ █ █ █▀█ █▀▄ █▀▄                                           \n"
                "                                           █▀▀ █▀█ ▀▀█ ▀▀█ █▄█ █ █ █▀▄ █ █                                           \n"
                "                                           ▀   ▀ ▀ ▀▀▀ ▀▀▀ ▀ ▀ ▀▀▀ ▀ ▀ ▀▀                                            \n"
                "\033[0m\n"
            );
            printf("                               >   \033[1;33m ");
            while (loop) {
                int result = userInput("%s", pass);
                if (result == -1) {
                    LOG("Esc key pressed. Exiting Account Number Input.");
                    printf("\033[0m");
                    return 0;
                }
                
                if (!result) {
                    printf("\n\n                               \033[31m Invalid input. Please try again.                                \033[0m");
                    printf(
                        "\033[1A\r\033[1A\r                                                                                                                     "
                        "\033[1G\033[0m                               >   \033[1;33m "
                    );
                    fflush(stdout);
                    continue;
                }
        
                if (strlen(pass) < 6) {
                    printf("\n\n                               \033[31m Password must be at least 6 characters long.                    \033[0m");
                    printf(
                        "\033[1A\r\033[1A\r                                                                                                                     "
                        "\033[1G\033[0m                               >   \033[1;33m "
                    );
                    fflush(stdout);
                    continue;
                } else {
                    break;
                }
                
            }
            printf(
                "\033[1A\r\033[1A\r\033[1A\r\033[1A\r\033[1A\r\033[1A\r"
                "\033[1;33m\n\n"
                "                            █▀▀ █▀█ █▀█ █▀▀ ▀█▀ █▀▄ █▄█   █▀█ █▀█ █▀▀ █▀▀ █ █ █▀█ █▀▄ █▀▄                            \n"
                "                            █   █ █ █ █ █▀▀  █  █▀▄ █ █   █▀▀ █▀█ ▀▀█ ▀▀█ █▄█ █ █ █▀▄ █ █                            \n"
                "                            ▀▀▀ ▀▀▀ ▀ ▀ ▀   ▀▀▀ ▀ ▀ ▀ ▀   ▀   ▀ ▀ ▀▀▀ ▀▀▀ ▀ ▀ ▀▀▀ ▀ ▀ ▀▀                             \n"
                "                                                                                                                     \n"
                "                                                                                                                     \n"
                "                                                                                                                     \n"
                "                                                                                                                     \n"
                "\033[0m"
            );
            printf(
                "                                                                                                                     \n"
                "\033[1A\r\033[1A\r\033[1A\r\033[1A\r\033[1A\r                               >   \033[1;33m "
            );
            while (loop){
                int result = userInput("%s", confirmPass);
                if (result == -1) {
                    LOG("Esc key pressed. Exiting Account Number Input.");
                    printf("\033[0m");
                    return 0;
                }
                if (!result) {
                    printf("\n\n                               \033[31m Invalid input. Please try again.                                \033[0m");
                    printf(
                        "\033[1A\r\033[1A\r                                                                                                                     "
                        "\033[1G\033[0m                               >   \033[1;33m "
                    );
                    fflush(stdout);
                    continue;
                } 
                
                if (strcmp(pass, confirmPass) != 0) {
                    printf("\n\n                               \033[31m Password does not match. Please try again.                      \033[0m");
                    printf(
                        "\033[1A\r\033[1A\r                                                                                                                     "
                        "\033[1G\033[0m                               >   \033[1;33m "
                    );
                    fflush(stdout);
                    continue;
                }
                
                else {
                    strcpy(acc->password, pass);
                    LOG_STRUCT_CHANGE_STR("Password", accb->password, acc->password);
                    break;
                }
            }
            break;
        case GUI_INPUT_FIRSTNAME:
            LOG("Using First Name Input GUI");
            printf(
                "\033[1;33m\n"
                "                                        █▀▀ ▀█▀ █▀▄ █▀▀ ▀█▀   █▀█ █▀█ █▄█ █▀▀                                        \n"
                "                                        █▀▀  █  █▀▄ ▀▀█  █    █ █ █▀█ █ █ █▀▀                                        \n"
                "                                        ▀   ▀▀▀ ▀ ▀ ▀▀▀  ▀    ▀ ▀ ▀ ▀ ▀ ▀ ▀▀▀                                        \n"
                "\033[0m\n"
            );
            printf("      %49s   ->   \033[1;33m", accb->firstname);
            if (!userInput("%s", acc->firstname)) {
                printf("\033[1A\r\033[0m      %49s   ->   \033[1;33m%s", accb->firstname, accb->firstname);
                fflush(stdout);
            }
            LOG_STRUCT_CHANGE_STR("First Name", accb->firstname, acc->firstname);
            break;
        case GUI_INPUT_LASTNAME:
            LOG("Using Last Name Input GUI");
            printf(
                "\033[1;33m\n"
                "                                          █   █▀█ █▀▀ ▀█▀   █▀█ █▀█ █▄█ █▀▀                                          \n"
                "                                          █   █▀█ ▀▀█  █    █ █ █▀█ █ █ █▀▀                                          \n"
                "                                          ▀▀▀ ▀ ▀ ▀▀▀  ▀    ▀ ▀ ▀ ▀ ▀ ▀ ▀▀▀                                          \n"
                "\033[0m\n"
            );
            printf("      %49s   ->   \033[1;33m", accb->lastname);
            if (!userInput("%s", acc->lastname)) {
                printf("\033[1A\r\033[0m      %49s   ->   \033[1;33m%s", accb->lastname, accb->lastname);
                fflush(stdout);
            }
            LOG_STRUCT_CHANGE_STR("Last Name", accb->lastname, acc->lastname);
            break;
        case GUI_INPUT_MIDNAME:
            LOG("Using Middle Name Input GUI");
            printf(
                "\033[1;33m\n"
                "                                      █▄█ ▀█▀ █▀▄ █▀▄ █   █▀▀   █▀█ █▀█ █▄█ █▀▀                                      \n"
                "                                      █ █  █  █ █ █ █ █   █▀▀   █ █ █▀█ █ █ █▀▀                                      \n"
                "                                      ▀ ▀ ▀▀▀ ▀▀  ▀▀  ▀▀▀ ▀▀▀   ▀ ▀ ▀ ▀ ▀ ▀ ▀▀▀                                      \n"
                "\033[0m\n"
            );
            printf("      %49s   ->   \033[1;33m", accb->midname);
            if (!userInput("%s", acc->midname)) {
                printf("\033[1A\r\033[0m      %49s   ->   \033[1;33m%s", accb->midname, accb->midname);
                fflush(stdout);
            }
            LOG_STRUCT_CHANGE_STR("Middle Name", accb->midname, acc->midname);
            break;
        case GUI_INPUT_STREET:
            LOG("Using Street Input GUI");
            printf(
                "\033[1;33m\n"
                "                                               █▀▀ ▀█▀ █▀▄ █▀▀ █▀▀ ▀█▀                                               \n"
                "                                               ▀▀█  █  █▀▄ █▀▀ █▀▀  █                                                \n"
                "                                               ▀▀▀  ▀  ▀ ▀ ▀▀▀ ▀▀▀  ▀                                                \n"
                "\033[0m\n"
            );
            printf("      %49s   ->   \033[1;33m", accb->street);
            if (!userInput("%s", acc->street)) {
                printf("\033[1A\r\033[0m      %49s   ->   \033[1;33m%s", accb->street, accb->street);
                fflush(stdout);
            }
            LOG_STRUCT_CHANGE_STR("First Name", accb->street, acc->street);
            break;
        case GUI_INPUT_BARANGAY:
            LOG("Using Barangay Input GUI");
            printf(
                "\033[1;33m\n"
                "                                           █▀▄ █▀█ █▀▄ █▀█ █▀█ █▀▀ █▀█ █ █                                           \n"
                "                                           █▀▄ █▀█ █▀▄ █▀█ █ █ █ █ █▀█  █                                            \n"
                "                                           ▀▀  ▀ ▀ ▀ ▀ ▀ ▀ ▀ ▀ ▀▀▀ ▀ ▀  ▀                                            \n"
                "\033[0m\n"
            );
            printf("      %49s   ->   \033[1;33m", accb->barangay);
            if (!userInput("%s", acc->barangay)) {
                printf("\033[1A\r\033[0m      %49s   ->   \033[1;33m%s", accb->barangay, accb->barangay);
                fflush(stdout);
            }
            LOG_STRUCT_CHANGE_STR("First Name", accb->barangay, acc->barangay);
            break;
        case GUI_INPUT_CITY:
            LOG("Using City Input GUI");
            printf(
                "\033[1;33m\n"
                "                                                   █▀▀ ▀█▀ ▀█▀ █ █                                                   \n"
                "                                                   █    █   █   █                                                    \n"
                "                                                   ▀▀▀ ▀▀▀  ▀   ▀                                                    \n"
                "\033[0m\n"
            );
            printf("      %49s   ->   \033[1;33m", accb->city);
            if (!userInput("%s", acc->city)) {
                printf("\033[1A\r\033[0m      %49s   ->   \033[1;33m%s", accb->city, accb->city);
                fflush(stdout);
            }
            LOG_STRUCT_CHANGE_STR("First Name", accb->city, acc->city);
            break;
        case GUI_INPUT_REGION:
            LOG("Using Region Input GUI");
            printf(
                "\033[1;33m\n"
                "                                               █▀▄ █▀▀ █▀▀ ▀█▀ █▀█ █▀█                                               \n"
                "                                               █▀▄ █▀▀ █ █  █  █ █ █ █                                               \n"
                "                                               ▀ ▀ ▀▀▀ ▀▀▀ ▀▀▀ ▀▀▀ ▀ ▀                                               \n"
                "\033[0m\n"
            );
            printf("      %49s   ->   \033[1;33m", accb->region);
            if (!userInput("%s", acc->region)) {
                printf("\033[1A\r\033[0m      %49s   ->   \033[1;33m%s", accb->region, accb->region);
                fflush(stdout);
            }
            LOG_STRUCT_CHANGE_STR("First Name", accb->region, acc->region);
            break;
        case GUI_INPUT_POSTALCODE:
            LOG("Using Postal Code Input GUI");
            printf(
                "\033[1;33m\n"
                "                                      █▀█ █▀█ █▀▀ ▀█▀ █▀█ █     █▀▀ █▀█ █▀▄ █▀▀                                     \n"
                "                                      █▀▀ █ █ ▀▀█  █  █▀█ █     █   █ █ █ █ █▀▀                                     \n"
                "                                      ▀   ▀▀▀ ▀▀▀  ▀  ▀ ▀ ▀▀▀   ▀▀▀ ▀▀▀ ▀▀  ▀▀▀                                     \n"
                "\033[0m\n"
            );
            printf("      %49s   ->   \033[1;33m", accb->postalCode);
            if (!userInput("%s", acc->postalCode)) {
                printf("\033[1A\r\033[0m      %49s   ->   \033[1;33m%s", accb->postalCode, accb->postalCode);
                fflush(stdout);
            }
            LOG_STRUCT_CHANGE_STR("First Name", accb->postalCode, acc->postalCode);
            break;
        case GUI_INPUT_WITHDRAWBALANCE:
            LOG("Using Withdraw Input GUI");
            printf(
                "\033[1;33m\n"
                "                            █ █ ▀█▀ ▀█▀ █ █ █▀▄ █▀▄ █▀█ █ █   █▀▄ █▀█ █   █▀█ █▀█ █▀▀ █▀▀                           \n"
                "                            █▄█  █   █  █▀█ █ █ █▀▄ █▀█ █▄█   █▀▄ █▀█ █   █▀█ █ █ █   █▀▀                           \n"
                "                            ▀ ▀ ▀▀▀  ▀  ▀ ▀ ▀▀  ▀ ▀ ▀ ▀ ▀ ▀   ▀▀  ▀ ▀ ▀▀▀ ▀ ▀ ▀ ▀ ▀▀▀ ▀▀▀                           \n"
                "\033[0m\n"
            );
            break;
        case GUI_INPUT_DEPOSITBALANCE:
            LOG("Using Deposit Input GUI");
            float deposit = 0.0f;
            printf(
                "\033[1;33m\n"
                "                              █▀▄ █▀▀ █▀█ █▀█ █▀▀ ▀█▀ ▀█▀   █▀▄ █▀█ █   █▀█ █▀█ █▀▀ █▀▀                             \n"
                "                              █ █ █▀▀ █▀▀ █ █ ▀▀█  █   █    █▀▄ █▀█ █   █▀█ █ █ █   █▀▀                             \n"
                "                              ▀▀  ▀▀▀ ▀   ▀▀▀ ▀▀▀ ▀▀▀  ▀    ▀▀  ▀ ▀ ▀▀▀ ▀ ▀ ▀ ▀ ▀▀▀ ▀▀▀                             \n"
                "\033[0m\n"
            );
            printf("                               >   \033[1;33mPHP: ");
            while (loop){
                if (!userInput("%f", &deposit)) {
                    printf("                               >   \033[1;33m%s", "Skipped! No deposit made.");
                    fflush(stdout);
                    break;
                } else if (deposit < 0) {
                    printf("\n                               \033[31m Invalid deposit amount. Please enter a positive value. \033[0m");
                    printf(
                        "\033[1A\r\033[1A\r                                                                                                                     "
                        "\033[1G\033[0m                               >   \033[1;33mPHP: "
                    );
                    fflush(stdout);
                    deposit = 0.0f;
                    continue;
                } else {
                    acc->balance += deposit;
                    LOG_STRUCT_CHANGE_VAL("Balance", accb->balance, acc->balance);
                    LOG("Deposited: %.2f", deposit);
                    break;
                }
            }
            break;
        default :
            LOG("Input GUI not Declared Properly, Skipping...");
            break;
    }
    printf("\033[0m\n");
    return 1;
}

void guiAccStatement(const Account *acc, const Transaction *trans) {
    printf("=== Account Statement ===\n");

    if (trans != NULL) {
        printf("Recent Transaction:\n");
        printf("Date: %s\n", trans->date);
        
        const char *typeStr = (trans->transactionType == 0) ? "Deposit" :
                              (trans->transactionType == 1) ? "Withdraw" : "Unknown";

        printf("Type: %s\n", typeStr);
        printf("Amount: %.2f\n", trans->amount);
    } else {
        printf("No recent transaction available.\n");
    }

    printf("=========================\n");

    // Placeholder for future GUI display logic
}

void guiDEBUG(){
    system("cls");
    LOGGER();
    printf(
        "                                                                                                                     \n"
        "                          ██████  ███████ ██████  ██    ██  ██████          ██████  ███    ██                        \n"
        "                          ██   ██ ██      ██   ██ ██    ██ ██       ██     ██    ██ ████   ██                        \n"
        "                          ██   ██ █████   ██████  ██    ██ ██   ███        ██    ██ ██ ██  ██                        \n"
        "                          ██   ██ ██      ██   ██ ██    ██ ██    ██ ██     ██    ██ ██  ██ ██                        \n"
        "                          ██████  ███████ ██████   ██████   ██████          ██████  ██   ████                        \n"
        "                                                                                                                     \n"
        "                                         █▀▀ █ █ █▀▀ █▀▀ █ █   █   █▀█ █▀▀ █▀▀                                       \n"
        "                                         █   █▀█ █▀▀ █   █▀▄   █   █ █ █ █ ▀▀█                                       \n"
        "                                         ▀▀▀ ▀ ▀ ▀▀▀ ▀▀▀ ▀ ▀   ▀▀▀ ▀▀▀ ▀▀▀ ▀▀▀                                       \n"
        "                                                                                                                     \n"
        "                                                                                                                     \n"
        "                                                                                                                     \n"
        "                               ░█▀░░▀█░░▀█░░░░█▀█░█▀█░█▀▄░█▄█░█▀█░█░░░░░█▄█░█▀█░█▀▄░█▀▀░                             \n"
        "                               ░█░░░░█░░░█░░░░█░█░█░█░█▀▄░█░█░█▀█░█░░░░░█░█░█░█░█░█░█▀▀░                             \n"
        "                               ░▀▀░░▀▀▀░▀▀░░░░▀░▀░▀▀▀░▀░▀░▀░▀░▀░▀░▀▀▀░░░▀░▀░▀▀▀░▀▀░░▀▀▀░                             \n"
        "                                                                                                                     \n"
        "                               ░█▀░░▀▀▄░▀█░░░░█▀▄░█▀▀░█▀▄░█░█░█▀▀░░░█▄█░█▀█░█▀▄░█▀▀░░░░░                             \n"
        "                               ░█░░░▄▀░░░█░░░░█░█░█▀▀░█▀▄░█░█░█░█░░░█░█░█░█░█░█░█▀▀░░░░░                             \n"
        "                               ░▀▀░░▀▀▀░▀▀░░░░▀▀░░▀▀▀░▀▀░░▀▀▀░▀▀▀░░░▀░▀░▀▀▀░▀▀░░▀▀▀░░░░░                             \n"
        "                                                                                                                     \n"
    );
}