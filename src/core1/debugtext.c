#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"

#include "version.h"

#if VERSION == VERSION_USA_1_0

/* .data */
u8 RGB_VALUES[8][3] = {
    {0xFF, 0x00, 0x00}, // Red
    {0x00, 0xFF, 0x00}, // Green
    {0x00, 0x00, 0xFF}, // Blue
    {0xFF, 0xFF, 0x00}, // Yellow
    {0xFF, 0x00, 0xFF}, // Pink
    {0xFF, 0xFF, 0xFF}, // White
    {0xFF, 0x80, 0x00}, // Orange
    {0x00, 0xFF, 0xFF}  // Cyan 
};

s32 red = 0xFF;
s32 green = 0xFF;
s32 blue = 0xFF;

// Orders the above RGB values: Green, Cyan, Yellow, Pink, Red, Orange, White, Red.
// Curiously, blue is missing. No idea why there's an intermediary to the RGB values!
u8 COLOR_SELECTOR[] = { 1, 7, 3, 4, 0, 6, 5, 0 };

// Each pair of 2 values here corresponds to the width of a character and the "encoding" of a character so it can draw
u32 CHARACTER_ENCODING[] = {
    3, 0x0F6DE000, // 0
    1, 0x0F800000, // 1
    3, 0x0C4AE000, // 2
    3, 0x0E59E000, // 3
    4, 0x088AF200, // 4
    3, 0x0F39E000, // 5
    3, 0x0F3DE000, // 6
    3, 0x0E4A4000, // 7
    3, 0x0F7DE000, // 8
    3, 0x0F79E000, // 9
    3, 0x0F6FA000, // A
    3, 0x0D75C000, // B
    3, 0x0F24E000, // C
    3, 0x0D6DC000, // D
    3, 0x0F34E000, // E
    3, 0x0F348000, // F
    3, 0x0F25E000, // G
    3, 0x0B7DA000, // H
    3, 0x0E92E000, // I
    3, 0x0E928000, // J
    3, 0x0B75A000, // K
    3, 0x0924E000, // L
    5, 0x08EEB188, // M
    4, 0x09DFB900, // N
    4, 0x06999600, // O
    3, 0x0F7C8000, // P
    4, 0x069DB700, // Q
    3, 0x0F7EA000, // R
    3, 0x0F39E000, // S
    3, 0x0E924000, // T
    4, 0x09999600, // U
    5, 0x08C62A20, // V
    5, 0x08C63550, // W
    3, 0x0B55A000, // X
    3, 0x0B79E000, // Y
    4, 0x0F124F00, // Z
    1, 0x00800000, // .
    1, 0x05000000, // :
    3, 0x00380000, // -
    2, 0x00000000  //  
};

s16 startingXCoordinate = 0;
s16 largeYCoordinate = 0;
s16 cursorPosition = 0;
s16 startingYCoordinate = 0;
s16 currentColor = 0;
s16 isThreadLocked = FALSE;
s16 currentFontSize = 0; // "Font size", but really it's closer to pixel size
s16 largeValueCursorPosition = 0;
s16 longestLineLengthPosition = 0;
 u8 shouldClearText = FALSE;
s32 clearTime = 0;

char CHARACTER_RANGE[] = { 'a','z','A','Z','0','9','.',':', '-', ' ' };

/* .h */
void gcdebugText_wrapToTop(void);
void gcdebugText_printSpace(void);
void gcdebugText_endLine(void);

/* code */
void setRGB(s32 r, s32 g, s32 b) {
    red = r;
    green = g;
    blue = b;
}

void setPixelInFrameBuffer(s32 x, s32 y) {
    if (((x >= 0) && (x < gFramebufferWidth)) 
        && ((y >= 0) && (y < gFramebufferHeight))) {

        gFramebuffers[0][x + y * gFramebufferWidth] = _SHIFTL(red >> 3, 11, 5) | _SHIFTL(green >> 3, 6, 5) | _SHIFTL(blue >> 3, 1, 5) | _SHIFTL(1, 0, 1);
        gFramebuffers[1][x + y * gFramebufferWidth] = _SHIFTL(red >> 3, 11, 5) | _SHIFTL(green >> 3, 6, 5) | _SHIFTL(blue >> 3, 1, 5) | _SHIFTL(1, 0, 1);
    }
}

// Starts the drawing of the pixel at the x and y coordinates, and continues drawing until the w and h coordinates
void drawPixel(s32 x, s32 y, s32 w, s32 h) {
    s32 iy;
    s32 ix;

    for (ix = 0; ix < w; ix++) {
        for (iy = 0; iy < h; iy++) {
            setPixelInFrameBuffer(x + ix, y + iy);
        }
    }

    osWriteBackDCacheAll();
}

// Sets the color and draws a square
void drawSquare(s32 r, s32 g, s32 b) {
    setRGB(r, g, b);
    drawPixel((gFramebufferWidth - 128) / 2, (gFramebufferHeight - 100) / 2, 128, 100);
}

void gcdebugText_empty(void) { }

// Wastes time, and doesn't trigger isThreadLocked
void gcdebugText_stallOnThread(void) {
    s32 i;
    for (i = 0; i < 2000000; i++) {
        gcdebugText_empty();
    }
}

// Flashes a colored square in the middle of the screen permanently
void gcdebugText_flashSquare(s32 color) {
    do {
        drawSquare(RGB_VALUES[color][0], RGB_VALUES[color][1], RGB_VALUES[color][2]);
        gcdebugText_stallOnThread();
        drawSquare(0, 0, 0);
        gcdebugText_stallOnThread();
    } while (TRUE);
}

// Draws a colored square in the middle of the screen and replaces it with black
void gcdebugText_drawSquare(s32 color) {
    drawSquare(RGB_VALUES[color][0], RGB_VALUES[color][1], RGB_VALUES[color][2]);
    gcdebugText_stallOnThread();
    drawSquare(0, 0, 0);
    gcdebugText_stallOnThread();
}

// Draws a square, but doesn't replace with black and doesn't hold it on screen
void gcdebugText_drawSquareOnly(s32 color) {
    drawSquare(RGB_VALUES[color][0], RGB_VALUES[color][1], RGB_VALUES[color][2]);
}

// Draws the character and the background. 
// keepCursor: When true, does not advance to the next character and keeps an imaginary "cursor" in place before drawing the next
// setBackgroundColorBlack: When true, sets the color to black for the background. Kind of just draws boxes otherwise
void drawCharacter(s32 colorSelect, s32 displayCharacter, s32 fontSize, s32 keepCursor, bool setBackgroundColorBlack, s32 r, s32 g, s32 b) {
    s32 j;
    s32 i;
    u32 char_width;
    u32 encoding;
    s32 y_position;
    u32 encoding_mask;
    u32 *encoding_ptr = CHARACTER_ENCODING + (displayCharacter * 2);
    
    encoding_mask = 0x10000000;
    char_width = encoding_ptr[0];
    encoding = encoding_ptr[1];

    for (i = 0; i < 5; i++) { // For each column; the height of these characters is 5 "pixels"
        y_position = i * fontSize;
        for (j = 0; j != char_width; j++) {
            encoding_mask >>= 1; // Bitwise right shift 1
            if (encoding & encoding_mask) {
                setRGB(r, g, b);
                drawPixel((cursorPosition + fontSize * j) - keepCursor, 
                    (startingYCoordinate + y_position) - keepCursor, 
                    (fontSize + keepCursor) + keepCursor, 
                    (fontSize + keepCursor) + keepCursor);
            } else {
                if (setBackgroundColorBlack != 0) { // Set color to black for the background
                    setRGB(0, 0, 0);
                }

                drawPixel((cursorPosition + fontSize * j) - keepCursor, 
                    (startingYCoordinate + y_position) - keepCursor, 
                    (fontSize + keepCursor) + keepCursor, 
                    (fontSize + keepCursor) + keepCursor);
            }
        }
    }

    // Advance to the next character
    if (keepCursor == 0) { 
        cursorPosition += (char_width * fontSize) + 2;
    }
}

// Seems unneeded, since text is cleared anyway
void gcdebugText_clearText(void) {
    s32 i;

    if (clearTime == 0) {
        clearTime = globalTimer_getTime();
        return;
    }

    if (globalTimer_getTime() != clearTime) {
        shouldClearText = FALSE;
        clearTime = globalTimer_getTime();
    }

    if (shouldClearText) {
        for (i = 0; i < gFramebufferWidth * gFramebufferHeight; i++) {
            gFramebuffers[0][i] = 0;
            gFramebuffers[1][i] = 0;
        }
        osWriteBackDCacheAll();
    }
}

// Draw both the character and the background
void printCharacter(s32 colorSelect, s32 displayCharacter, s32 fontSize) {
    drawCharacter(colorSelect, displayCharacter, fontSize, TRUE, TRUE, 0, 0, 0);
    drawCharacter(colorSelect, displayCharacter, fontSize, FALSE, TRUE, 
        RGB_VALUES[COLOR_SELECTOR[colorSelect]][0], 
        RGB_VALUES[COLOR_SELECTOR[colorSelect]][1], 
        RGB_VALUES[COLOR_SELECTOR[colorSelect]][2]);
}

void printValue(s32 colorSelect, s32 displayValue, s32 fontSize) {
    s32 j, i;

    cursorPosition = startingXCoordinate;
    currentFontSize = fontSize;

    if (displayValue < 0) {
        printCharacter(colorSelect, 0x26, fontSize); // Print - character
        displayValue *= -1; // Convert to positive for the next calculation
    }
    
    // Sets i to a power of 10 with length equal to the given.
    // IE: 150 sets i to 100, 3500 sets i to 1000 
    for (i = 1000000000; i >= 10 && displayValue < i; i /= 10) {
        continue;
    }

    // Print each individual digit in the given value
    for (i = i; i >= 10; i /= 10) {
        for (j = 0; displayValue >= i; j++) {
            displayValue -= i;
        }

        printCharacter(colorSelect, j, fontSize);
    }

    printCharacter(colorSelect, displayValue, fontSize);
    gcdebugText_printSpace();

    if (fontSize == 7) { // Corresponds to largeValue
        largeValueCursorPosition = cursorPosition;
        longestLineLengthPosition = 0;
    } else if (cursorPosition >= longestLineLengthPosition) {
        longestLineLengthPosition = cursorPosition;
    }
}

// Prints a value to the screen, but always in the same place in the upper left. 
// Subsequent calls in the same frame will overwrite what's there
void gcdebugText_showLargeValue(s32 colorSelect, s32 displayValue) {
    isThreadLocked = FALSE;
    currentColor = colorSelect;
    startingXCoordinate = 0xE;
    startingYCoordinate = 0xA;
    printValue(colorSelect, displayValue, 7);
    gcdebugText_wrapToTop();
    largeYCoordinate = startingYCoordinate;
    longestLineLengthPosition = startingXCoordinate;
    shouldClearText = TRUE;
}

void gcdebugText_showValue(s32 displayValue) {
        printValue(currentColor, displayValue, 2);
        gcdebugText_wrapToTop();
}

// Given a value such as 0x0F64 will print on screen ":0F64"
void gcdebugText_showHexValue(u32 displayValue) {
    s32 display_character;

    cursorPosition = startingXCoordinate;
    currentFontSize = 2;
    printCharacter(currentColor, 0x25, 2); // Print :
    display_character = 
        (displayValue >= 0x01000000U) ? 0x1C
            : (displayValue >= 0x10000U) ? 0x14
                : 0xC;

    if (display_character >= 0) {
        do {
            printCharacter(currentColor, ((s32) displayValue >> display_character) & 0xF, 2);
            display_character -= 4;
        } while (display_character >= 0);
    }

    gcdebugText_endLine();
}

// Possibly bugged
void gcdebugText_showFloat(f32 displayValue) {
    f32 display_position;
    s32 display_character;

    cursorPosition = startingXCoordinate;
    currentFontSize = 2;
    
    // If a negative number, print the - symbol and convert the number to positive
    if (displayValue < 0.0f) {
        printCharacter(currentColor, 0x26, 2);
        displayValue *= -1.0f;
    }

    display_position = 1e+09;

    while ((display_position >= 10.0f) && (displayValue < display_position)) {
        display_position /= 10.0f;
    }

    while (1e-09 <= display_position) {
        if ((0.09 < display_position) && (display_position < 0.11)) {
            printCharacter(currentColor, 0x24, 2); // . character
        }
        
        display_character = 0;
        while (display_position <= displayValue) {
            displayValue -= display_position;
            display_character += 1;
        }
        printCharacter(currentColor, display_character, 2);
        display_position /= 10.0f;
    }

    gcdebugText_endLine();
}

// Turns characters into the corresponding number for CHARACTER_ENCODING
s32 encodeCharacter(s32 character) {

    // Lowercase letters
    if ((character >= (s32) CHARACTER_RANGE[0]) && ((s32) CHARACTER_RANGE[1] >= character)) {
        return (character - CHARACTER_RANGE[0]) + 0xA;
    }

    // Uppercase letters
    if ((character >= (s32) CHARACTER_RANGE[2]) && ((s32) CHARACTER_RANGE[3] >= character)) {
        return (character - CHARACTER_RANGE[2]) + 0xA;
    }

    // Numbers
    if ((character >= (s32) CHARACTER_RANGE[4]) && ((s32) CHARACTER_RANGE[5] >= character)) {
        return (character - CHARACTER_RANGE[4]);
    }

    // .
    if (character == CHARACTER_RANGE[6]) {
        return 0x24;
    }

    // :
    if (character == CHARACTER_RANGE[7]) {
        return 0x25;
    }

    // -
    if (character == CHARACTER_RANGE[8]) {
        return 0x26;
    }

    // (space)
    if (character == CHARACTER_RANGE[9]) {
        return 0x27;
    }

    return 0x27;
}

// Prints text to the screen. Note that it uses the current color value and isn't set here. Example usage:
// u8 str[] = " Banjo Kazooie";
// gcdebugText_showText(str);
void gcdebugText_showText(u8 *text) {
    s32 i;
    s32 character;

    cursorPosition = startingXCoordinate;
    currentFontSize = 2;

    for (i = 0; text[i] != 0; i++) {
        character = text[i];
        printCharacter(currentColor, encodeCharacter(character), 2);
    }

    gcdebugText_endLine();
}

// Lock up the thread and show what's on the screen permanently.
// Likely used for showing a value and keeping it there.
void gcdebugText_lockScreen(void) {
    isThreadLocked = TRUE;
    do { } while (1);
}

// Temporarily stop the thread, presumably to show the value
void gcdebugText_pauseThread(void) {
    s32 i;

    isThreadLocked = TRUE;

    for (i = 30000000; i != 0; i--) { }

    isThreadLocked = FALSE;
}

void gcdebugText_pauseThreadForTime(s32 time) {
    s32 i;

    isThreadLocked = TRUE;

    while (time != 0) {
        for (i = 30000000; i != 0; i--) { }
        time--;
    }

    isThreadLocked = FALSE;
}

void checkYAndgcdebugText_wrapToTop(s32 lineHeight) {
    startingYCoordinate += lineHeight;

    // Only continue if the y coordinate is about to go off screen
    if (startingYCoordinate < 0xCD) {
        return;
    }

    // Back the cursor to the top of the screen, and move it to the end of the existing line
    startingXCoordinate = longestLineLengthPosition + 4;
    cursorPosition = startingXCoordinate;
    startingYCoordinate = (largeValueCursorPosition < cursorPosition) ? 0xA : largeYCoordinate;
    longestLineLengthPosition = 0;
}

// Calculate line height and wrap
void gcdebugText_wrapToTop(void) {
    checkYAndgcdebugText_wrapToTop(currentFontSize * 5 + 2);
}

// Unused, but possibly used for very tiny debugs
void gcdebugText_wrapToTopSmall(void) {
    checkYAndgcdebugText_wrapToTop(2);
}

void gcdebugText_endLine(void) {
    gcdebugText_printSpace();

    if (cursorPosition >= longestLineLengthPosition) {
        longestLineLengthPosition = cursorPosition;
    }

    gcdebugText_wrapToTop();
}

void gcdebugText_printSpace(void) {
    s16 tempCursorPosition;

    tempCursorPosition = cursorPosition--;
    printCharacter(currentColor, 0x27, currentFontSize);
    cursorPosition = tempCursorPosition;
}

s32 gcdebugText_isThreadLocked(void) {
    return isThreadLocked;
}

void gcdebugText_unused(s32 arg0) { }

#endif
