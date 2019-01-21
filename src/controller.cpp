#include "controller.hpp"
#include "pros/misc.hpp"
#include "pros/rtos.hpp"

namespace controller {
    bool rumble(pros::Controller &ctr) {
        return rumble(ctr, RUMBLE_SHORT_1);
    }

    bool rumble(pros::Controller &ctr, const char* rumblePattern) {
        return ctr.rumble(rumblePattern) == 1;
    }

    bool rumble(pros::Controller &ctr1, pros::Controller &ctr2) {
        return rumble(ctr1, ctr2, RUMBLE_SHORT_1);
    }

    bool rumble(pros::Controller &ctr1, pros::Controller &ctr2, const char* rumblePattern) {
        return rumble(ctr1, rumblePattern) && rumble(ctr2, rumblePattern);
    }

    bool clearScreen(pros::Controller &ctr) {
        return ctr.clear() == 1;
    }

    bool clearScreen(pros::Controller &ctr1, pros::Controller &ctr2) {
        return clearScreen(ctr1) && clearScreen(ctr2);
    }

    bool clearScreen(pros::Controller &ctr, const char *rumblePattern) {
        clearScreen(ctr);
        rumble(ctr, rumblePattern);
    }

    bool clearScreen(pros::Controller &ctr1, pros::Controller &ctr2, const char *rumblePattern) {
        clearScreen(ctr1, ctr2);
        rumble(ctr1, ctr2, rumblePattern);
    }

    bool clearLine(pros::Controller &ctr) {
        return clearLine(ctr, (std::uint_fast8_t)0);
    }

    bool clearLine(pros::Controller ctr, const std::uint_fast8_t row) {
        return ctr.clear_line(row) == 1;
    }

    bool clearLine(pros::Controller &ctr1, pros::Controller &ctr2) {
        return clearLine(ctr1) && clearLine(ctr2);
    }

    bool clearLine(pros::Controller &ctr1, pros::Controller &ctr2, const std::uint_fast8_t row) {
        return clearLine(ctr1, row) && clearLine(ctr2, row);
    }

    bool clearLine(pros::Controller &ctr, const char *rumblePattern) {
        return clearLine(ctr) && rumble(ctr, rumblePattern);
    }

    bool clearLine(pros::Controller &ctr, const std::uint_fast8_t row, const char *rumblePattern) {
        return clearLine(ctr, row) && rumble(ctr, rumblePattern);
    }

    bool clearLine(pros::Controller &ctr1, pros::Controller &ctr2, const char *rumblePattern) {
        return clearLine(ctr1, ctr2) && rumble(ctr1, ctr2, rumblePattern);
    }

    bool clearLine(pros::Controller &ctr1, pros::Controller &ctr2, const std::uint_fast8_t row, const char *rumblePattern) {
        return clearLine(ctr1, ctr2, row) && rumble(ctr1, ctr2, rumblePattern);
    }

    bool sendChar(pros::Controller &ctr, const char character) {
        return sendChar(ctr, 0, 0, character);
    }

    bool sendChar(pros::Controller &ctr, const std::uint_fast8_t row, const char character) {
        return sendChar(ctr, row, 0, character);
    }

    bool sendChar(pros::Controller &ctr, const std::uint_fast8_t row, const std::uint_fast8_t col, const char character) {
        return ctr.print(row, col, "%c", character) == 1;
    }

    bool sendChar(pros::Controller &ctr1, pros::Controller &ctr2, const char character) {
        return sendChar(ctr1, character) && sendChar(ctr2, character);
    }

    bool sendChar(pros::Controller &ctr1, pros::Controller &ctr2, const std::uint_fast8_t row, const char character) {
        return sendChar(ctr1, row, character) && sendChar(ctr2, row, character);
    }

    bool sendChar(pros::Controller &ctr1, pros::Controller &ctr2, const std::uint_fast8_t row, const std::uint_fast8_t col, const char character) {
        return sendChar(ctr1, row, col, character) && sendChar(ctr2, row, col, character);
    }

    bool sendChar(pros::Controller &ctr, const char character, const char *rumblePattern) {
        return sendChar(ctr, character) && rumble(ctr, rumblePattern);
    }

    bool sendChar(pros::Controller &ctr, const std::uint_fast8_t row, const char character, const char *rumblePattern) {
        return sendChar(ctr, row, character) && rumble(ctr, rumblePattern);
    }

    bool sendChar(pros::Controller &ctr, const std::uint_fast8_t row, const std::uint_fast8_t col, const char character, const char *rumblePattern) {
        return sendChar(ctr, row, col, character) && rumble(ctr, rumblePattern);
    }

    bool sendChar(pros::Controller &ctr1, pros::Controller &ctr2, const char character, const char *rumblePattern) {
        return sendChar(ctr1, ctr2, character) && rumble(ctr1, ctr2, rumblePattern);
    }

    bool sendChar(pros::Controller &ctr1, pros::Controller &ctr2, const std::uint_fast8_t row, const char character, const char *rumblePattern) {
        return sendChar(ctr1, ctr2, row, character) && rumble(ctr1, ctr2, rumblePattern);
    }

    bool sendChar(pros::Controller &ctr1, pros::Controller &ctr2, const std::uint_fast8_t row, const std::uint_fast8_t col, const char character, const char *rumblePattern) {
        return sendChar(ctr1, ctr2, row, col, character) && rumble(ctr1, ctr2, rumblePattern);
    }

    bool fillScreen(pros::Controller &ctr) {
        return fillScreen(ctr, '\xdb');
    }

    bool fillScreen(pros::Controller &ctr1, pros::Controller &ctr2) {
        return fillScreen(ctr1) && fillScreen(ctr2);
    }

    bool fillScreen(pros::Controller &ctr, const char character) {
        for (std::uint_fast8_t r = 0; r <= 2; r++)
            for (std::uint_fast8_t c = 0; c <= 14; c++) {
                if(!sendChar(ctr, r, c, character))
                    return false;
            }
        return true;
    }

    bool fillScreen(pros::Controller &ctr1, pros::Controller &ctr2, const char character) {
        return fillScreen(ctr1, character) && fillScreen(ctr2, character);
    }

    bool fillScreen(pros::Controller &ctr, const char* rumblePattern) {
        return fillScreen(ctr) && rumble(ctr, rumblePattern);
    }

    bool fillScreen(pros::Controller &ctr1, pros::Controller &ctr2, const char* rumblePattern) {
        return fillScreen(ctr1, ctr2) && rumble(ctr1, ctr2, rumblePattern);
    }

    bool fillScreen(pros::Controller &ctr, const char character, const char *rumblePattern) {
        return fillScreen(ctr, character) && rumble(ctr, rumblePattern);
    }

    bool fillScreen(pros::Controller &ctr1, pros::Controller &ctr2, const char character, const char *rumblePattern) {
        return fillScreen(ctr1, ctr2, character) && rumble(ctr1, ctr2, rumblePattern);
    }

    bool sendBitmap(pros::Controller &ctr, bool bmp[3 * 15]) {
        for (std::uint_fast8_t r = 1; r <= 3; r++)
            for (std::uint_fast8_t c = 1; c <= 15; r++) {
                if(bmp[r*c - 1])
                    if(!sendChar(ctr, r, c, '\xdb')) return false;
                else
                    if(!sendChar(ctr, r, c, ' ')) return false;
            }
        return true;
    }

    bool sendBitmap(pros::Controller &ctr, const char bmp[3 * 15]) {
        for (std::uint_fast8_t r = 1; r <= 3; r++)
            for (std::uint_fast8_t c = 1; c <= 15; r++)
                if(!sendChar(ctr, r, c, bmp[r*c - 1])) return false;
        return true;
    }

    bool sendBitmap(pros::Controller &ctr1, pros::Controller &ctr2, bool bmp[3 * 15]) {
        return sendBitmap(ctr1, bmp) && sendBitmap(ctr2, bmp);
    }

    bool sendBitmap(pros::Controller &ctr1, pros::Controller &ctr2, const char bmp[3 * 15]) {
        return sendBitmap(ctr1, bmp) && sendBitmap(ctr2, bmp);
    }

    bool sendBitmap(pros::Controller &ctr, bool bmp[3 * 15], const char *rumblePattern) {
        return sendBitmap(ctr, bmp) && rumble(ctr, rumblePattern);
    }

    bool sendBitmap(pros::Controller &ctr, const char bmp[3 * 15], const char *rumblePattern) {
        return sendBitmap(ctr, bmp, rumblePattern);
    }

    bool sendBitmap(pros::Controller &ctr1, pros::Controller &ctr2, bool bmp[3 * 15], const char *rumblePattern) {
        return sendBitmap(ctr1, ctr2, bmp) && rumble(ctr1, ctr2, rumblePattern);
    }

    bool sendBitmap(pros::Controller &ctr1, pros::Controller &ctr2, const char bmp[3 * 15], const char *rumblePattern) {
        return sendBitmap(ctr1, ctr2, bmp) && rumble(ctr1, ctr2, rumblePattern);
    }

    bool sendText(pros::Controller &ctr, const char *text) {
        return sendText(ctr, text, (const std::uint_fast8_t)0, (const std::uint_fast8_t)0);
    }

    bool sendText(pros::Controller &ctr, const char *text, const std::uint8_t row) {
        return sendText(ctr, text, (const std::uint_fast8_t)row, (const std::uint_fast8_t)0);
    }

    bool sendText(pros::Controller &ctr, const char *text, const std::uint8_t row, const std::uint8_t col) {
        return ctr.print(row, col, text) == 1;
    }

    bool sendText(pros::Controller &ctr1, pros::Controller &ctr2, const char *text) {
        return sendText(ctr1, text) && sendText(ctr2, text);
    }

    bool sendText(pros::Controller &ctr1, pros::Controller &ctr2, const char *text, const std::uint8_t row) {
        return sendText(ctr1, text, row) && sendText(ctr2, text, row);
    }

    bool sendText(pros::Controller &ctr1, pros::Controller &ctr2, const char *text, const std::uint8_t row, const std::uint8_t col) {
        return sendText(ctr1, text, row, col) && sendText(ctr2, text, row, col);
    }

    bool sendText(pros::Controller &ctr, const char *text, const char *rumblePattern) {
        return sendText(ctr, text) && rumble(ctr, rumblePattern);
    }

    bool sendText(pros::Controller &ctr, const char *text, const std::uint_fast8_t row, const char *rumblePattern) {
        return sendText(ctr, text, row) && rumble(ctr, rumblePattern);
    }

    bool sendText(pros::Controller &ctr, const char *text, const std::uint_fast8_t row, const std::uint_fast8_t col, const char *rumblePattern) {
        return sendText(ctr, text, row, col) && rumble(ctr, rumblePattern);
    }

    bool sendText(pros::Controller &ctr1, pros::Controller &ctr2, const char *text, const char *rumblePattern) {
        return sendText(ctr1, ctr2, text) && rumble(ctr1, ctr2, rumblePattern);
    }

    bool sendText(pros::Controller &ctr1, pros::Controller &ctr2, const char *text, const std::uint_fast8_t row, const char *rumblePattern) {
        return sendText(ctr1, ctr2, text, row) && rumble(ctr1, ctr2, rumblePattern);
    }

    bool sendText(pros::Controller &ctr1, pros::Controller &ctr2, const char *text, const std::uint_fast8_t row, const std::uint_fast8_t col, const char *rumblePattern) {
        return sendText(ctr1, ctr2, text, row, col) && rumble(ctr1, ctr2, rumblePattern);
    }

    void awaitControllerResponse(pros::Controller &ctr, pros::controller_digital_e_t btn) {
        while (!ctr.get_digital(btn)) pros::delay(CONTROLLER_DELAY_TIME);
    }

    void awaitControllerResponse(pros::Controller &ctr1, pros::Controller &ctr2, pros::controller_digital_e_t btn) {
        bool ctr1Pressed = false, ctr2Pressed = false;
        while(!(ctr1Pressed && ctr2Pressed)) {
            if(ctr1.get_digital(btn)) ctr1Pressed = true;
            if (ctr2.get_digital(btn)) ctr2Pressed = true;
            pros::delay(CONTROLLER_DELAY_TIME);
        }
    }

    void awaitControllerResponse(pros::Controller &ctr, const char *rumblePattern, pros::controller_digital_e_t btn) {
        while(!ctr.get_digital(btn)){
            rumble(ctr, rumblePattern);
            pros::delay(CONTROLLER_DELAY_TIME);
        }
    }

    void awaitControllerResponse(pros::Controller &ctr1, pros::Controller &ctr2, const char *rumblePattern, pros::controller_digital_e_t btn) {
        bool ctr1Pressed = false, ctr2Pressed = false;
        while (!(ctr1Pressed && ctr2Pressed)) {
            if (ctr1.get_digital(btn)) ctr1Pressed = true;
            if (ctr2.get_digital(btn)) ctr2Pressed = true;
            rumble(ctr1, ctr2, rumblePattern);
            pros::delay(CONTROLLER_DELAY_TIME);
        }
    }
}