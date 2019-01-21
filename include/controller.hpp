#ifndef _CONTROLLER_HEADER
#define _CONTROLLER_HEADER

#include "pros/misc.hpp"

#define CONTROLLER_DELAY_TIME 2

#define RUMBLE_SHORT_1 "."
#define RUMBLE_SHORT_2 ".."
#define RUMBLE_SHORT_3 ".."
#define RUMBLE_SHORT_4 ".."
#define RUMBLE_SHORT_5 ".."
#define RUMBLE_SHORT_6 ".."
#define RUMBLE_SHORT_7 ".."
#define RUMBLE_SHORT_8 ".."

#define RUMBLE_LONG_1 "-"
#define RUMBLE_LONG_2 "--"
#define RUMBLE_LONG_3 "---"
#define RUMBLE_LONG_4 "----"
#define RUMBLE_LONG_5 "-----"
#define RUMBLE_LONG_6 "------"
#define RUMBLE_LONG_7 "-------"
#define RUMBLE_LONG_8 "--------"

#define RUMBLE_SHORT_PAUSE_SHORT_7 ". . . ."
#define RUMBLE_LONG_PAUSE_LONG_7 "- - - -"
#define RUMBLE_SHORT_PAUSE_LONG_7 ". - . -"
#define RUMBLE_LONG_PAUSE_SHORT_7 "- . - ."

#define RUMBLE_SHORT_PAUSE_SHORT_5 ". . ."
#define RUMBLE_LONG_PAUSE_LONG_5 "- - -"
#define RUMBLE_SHORT_PAUSE_LONG_5 ". - ."
#define RUMBLE_LONG_PAUSE_SHORT_5 "- . -"

#define RUMBLE_SHORT_PAUSE_SHORT_3 ". ."
#define RUMBLE_LONG_PAUSE_LONG_3 "- -"
#define RUMBLE_SHORT_PAUSE_LONG_3 ". -"
#define RUMBLE_LONG_PAUSE_SHORT_3 "- ."

namespace controller {
    bool rumble(pros::Controller &ctr);
    bool rumble(pros::Controller &ctr, const char* rumblePattern);
    template <typename C, typename R, typename... Args> bool rumble(C ctr, R rumblePattern, Args... rumblePatterns);
    bool rumble(pros::Controller &ctr1, pros::Controller &ctr2);
    bool rumble(pros::Controller &ctr1, pros::Controller &ctr2, const char *rumblePattern);
    template <typename C, typename D, typename R, typename... Args> bool rumble(C ctr1, D ctr2, R rumblePattern, Args... rumblePatterns);

    bool clearScreen(pros::Controller &ctr);
    bool clearScreen(pros::Controller &ctr1, pros::Controller &ctr2);

    bool clearScreen(pros::Controller &ctr, const char *rumblePattern);
    bool clearScreen(pros::Controller &ctr1, pros::Controller &ctr2, const char *rumblePattern);

    bool clearLine(pros::Controller &ctr);
    bool clearLine(pros::Controller ctr, const std::uint_fast8_t row);
    bool clearLine(pros::Controller &ctr1, pros::Controller &ctr2);
    bool clearLine(pros::Controller &ctr1, pros::Controller &ctr2, const std::uint_fast8_t row);

    bool clearLine(pros::Controller &ctr, const char *rumblePattern);
    bool clearLine(pros::Controller &ctr, const std::uint_fast8_t row, const char *rumblePattern);
    bool clearLine(pros::Controller &ctr1, pros::Controller &ctr2, const char *rumblePattern);
    bool clearLine(pros::Controller &ctr1, pros::Controller &ctr2, const std::uint_fast8_t row, const char *rumblePattern);

    bool sendChar(pros::Controller &ctr, const char character);
    bool sendChar(pros::Controller &ctr, const std::uint_fast8_t row, const char character);
    bool sendChar(pros::Controller &ctr, const std::uint_fast8_t row, const std::uint_fast8_t col, const char character);
    bool sendChar(pros::Controller &ctr1, pros::Controller &ctr2, const char character);
    bool sendChar(pros::Controller &ctr1, pros::Controller &ctr2, const std::uint_fast8_t row, const char character);
    bool sendChar(pros::Controller &ctr1, pros::Controller &ctr2, const std::uint_fast8_t row, const std::uint_fast8_t col, const char character);

    bool sendChar(pros::Controller &ctr, const char character, const char *rumblePattern);
    bool sendChar(pros::Controller &ctr, const std::uint_fast8_t row, const char character, const char *rumblePattern);
    bool sendChar(pros::Controller &ctr, const std::uint_fast8_t row, const std::uint_fast8_t col, const char character, const char *rumblePattern);
    bool sendChar(pros::Controller &ctr1, pros::Controller &ctr2, const char character, const char *rumblePattern);
    bool sendChar(pros::Controller &ctr1, pros::Controller &ctr2, const std::uint_fast8_t row, const char character, const char *rumblePattern);
    bool sendChar(pros::Controller &ctr1, pros::Controller &ctr2, const std::uint_fast8_t row, const std::uint_fast8_t col, const char character, const char *rumblePattern);

    bool fillScreen(pros::Controller &ctr);
    bool fillScreen(pros::Controller &ctr1, pros::Controller &ctr2);
    bool fillScreen(pros::Controller &ctr, const char character);
    bool fillScreen(pros::Controller &ctr1, pros::Controller &ctr2, const char character);

    bool fillScreen(pros::Controller &ctr, const char *rumblePattern);
    bool fillScreen(pros::Controller &ctr1, pros::Controller &ctr2, const char *rumblePattern);
    bool fillScreen(pros::Controller &ctr, const char character, const char *rumblePattern);
    bool fillScreen(pros::Controller &ctr1, pros::Controller &ctr2, const char character, const char *rumblePattern);

    bool sendBitmap(pros::Controller &ctr, bool bmp[3 * 15]);
    bool sendBitmap(pros::Controller &ctr, const char bmp[3 * 15]);
    bool sendBitmap(pros::Controller &ctr1, pros::Controller &ctr2, bool bmp[3 * 15]);
    bool sendBitmap(pros::Controller &ctr1, pros::Controller &ctr2, const char bmp[3 * 15]);

    bool sendBitmap(pros::Controller &ctr, bool bmp[3 * 15], const char *rumblePattern);
    bool sendBitmap(pros::Controller &ctr, const char bmp[3 * 15], const char *rumblePattern);
    bool sendBitmap(pros::Controller &ctr1, pros::Controller &ctr2, bool bmp[3 * 15], const char *rumblePattern);
    bool sendBitmap(pros::Controller &ctr1, pros::Controller &ctr2, const char bmp[3 * 15], const char *rumblePattern);

    bool sendText(pros::Controller &ctr, const char *text);
    bool sendText(pros::Controller &ctr, const char *text, const std::uint8_t row);
    bool sendText(pros::Controller &ctr, const char *text, const std::uint8_t row, const std::uint8_t col);
    bool sendText(pros::Controller &ctr1, pros::Controller &ctr2, const char *text);
    bool sendText(pros::Controller &ctr1, pros::Controller &ctr2, const char *text, const std::uint8_t row);
    bool sendText(pros::Controller &ctr1, pros::Controller &ctr2, const char *text, const std::uint8_t row, const std::uint8_t col);

    bool sendText(pros::Controller &ctr, const char *text, const char *rumblePattern);
    bool sendText(pros::Controller &ctr, const char *text, const std::uint_fast8_t row, const char *rumblePattern);
    bool sendText(pros::Controller &ctr, const char *text, const std::uint_fast8_t row, const std::uint_fast8_t col, const char *rumblePattern);
    bool sendText(pros::Controller &ctr1, pros::Controller &ctr2, const char *text, const char *rumblePattern);
    bool sendText(pros::Controller &ctr1, pros::Controller &ctr2, const char *text, const std::uint_fast8_t row, const char *rumblePattern);
    bool sendText(pros::Controller &ctr1, pros::Controller &ctr2, const char *text, const std::uint_fast8_t row, const std::uint_fast8_t col, const char *rumblePattern);

    void awaitControllerResponse(pros::Controller &ctr, pros::controller_digital_e_t btn);
    template <typename C, typename B, typename... Args> void awaitControllerResponse(C ctr, B btn, Args... btns);
    void awaitControllerResponse(pros::Controller &ctr1, pros::Controller &ctr2, pros::controller_digital_e_t btn);
    template <typename C, typename D, typename B, typename... Args> void awaitControllerResponse(C ctr1, D ctr2, B btn, Args... btns);

    void awaitControllerResponse(pros::Controller &ctr, const char *rumblePattern, pros::controller_digital_e_t btn);
    template <typename C, const char *R, pros::controller_digital_e_t B, typename... Args> void awaitControllerResponse(C ctr, const char *rumblePattern, pros::controller_digital_e_t btn, Args... btns);
    void awaitControllerResponse(pros::Controller &ctr1, pros::Controller &ctr2, const char *rumblePattern, pros::controller_digital_e_t btn);
    template <typename C, typename D, const char *R, pros::controller_digital_e_t B, typename... Args> void awaitControllerResponse(C ctr1, D ctr2, const char *rumblePattern, pros::controller_digital_e_t btn, Args... btns);
}

// Implement the templates
#include "../src/controller.tpp"

#endif