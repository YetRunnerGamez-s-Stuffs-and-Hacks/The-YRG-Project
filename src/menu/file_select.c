#include "types.h"

#include "game/main.h"
#include "game/print.h"
#include "game/save_file.h"
#include "game/game_init.h"
#include "game/area.h"

#include "file_select.h"

s32 gSelectedFile = 0;

void file_select_init(void) {
    save_file_load_all();

    if (gDebugLevelSelect) {
        gCurrSaveFileNum = 1;
        save_file_create_temporary_file();
        return;
    }

    gSelectedFile = 0;
}

static s32 get_file_star_count(s32 file) {
    if (!save_file_exists(file)) {
        return -1;
    }

    return save_file_get_total_star_count(file, COURSE_MIN - 1, COURSE_MAX - 1);
}

void file_select_draw(void) {
    char buffer[32];

    s32 i;
    s32 stars;

    print_text_centered(160, 180, "SELECT FILE");

    for (i = 0; i < 4; i++) {
        stars = get_file_star_count(i);

        if (gSelectedFile == i) {
            print_text(80, 140 - (i * 20), "-");
        } else {
            print_text(80, 140 - (i * 20), " ");
        }

        if (stars < 0) {
            sprintf(buffer, "FILE %c Empty", 'A' + i);
        } else {
            sprintf(buffer, "FILE %c %d STARS", 'A' + i, stars);
        }

        print_text(95, 140 - (i * 20), buffer);
    }

    print_text(80, 40, "A: SELECT");
    print_text(80, 25, "B: BACK");
    print_text(80, 10, "Z: DELETE");
}

s32 file_select_update(void) {
    if (gPlayer1Controller->buttonPressed & U_JPAD) {
        gSelectedFile--;

        if (gSelectedFile < 0)
            gSelectedFile = 3;
    }

    if (gPlayer1Controller->buttonPressed & D_JPAD) {
        gSelectedFile++;

        if (gSelectedFile > 3)
            gSelectedFile = 0;
    }

    // Select file
    if (gPlayer1Controller->buttonPressed & A_BUTTON) {
        gCurrSaveFileNum = gSelectedFile + 1;

        if (!save_file_exists(gCurrSaveFileNum - 1)) {
            save_file_erase(gCurrSaveFileNum - 1);
            save_file_set_flags(SAVE_FLAG_FILE_EXISTS);
        }

        save_file_create_temporary_file();

        return 1;
    }

    // Delete file
    if (gPlayer1Controller->buttonPressed & Z_TRIG) {
        save_file_erase(gSelectedFile);
    }

    // Back
    if (gPlayer1Controller->buttonPressed & B_BUTTON) {
        return -1;
    }

    return 0;
}