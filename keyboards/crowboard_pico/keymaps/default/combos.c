#ifdef COMBO_ENABLE
enum combo_events {
    COMBO_1,
    COMBO_2,
    COMBO_3,
    COMBO_4,
    COMBO_5,
    COMBO_6,
};
#endif

#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo1[] = {LT(3, KC_TAB), LT(2, KC_BSPC), COMBO_END};
const uint16_t PROGMEM combo2[] = {LT(1, KC_SPC), OSM(MOD_LSFT), COMBO_END};
const uint16_t PROGMEM combo3[] = {LT(3, KC_TAB), LT(1, KC_SPC), KC_P, COMBO_END};
const uint16_t PROGMEM combo4[] = {LT(3, KC_TAB), LT(1, KC_SPC), KC_PGUP, COMBO_END};
const uint16_t PROGMEM combo5[] = {OSM(MOD_LSFT), LT(2, KC_BSPC), KC_Q, COMBO_END};
const uint16_t PROGMEM combo6[] = {OSM(MOD_LSFT), LT(2, KC_BSPC), KC_ESC, COMBO_END};

combo_t key_combos[] = {
    [COMBO_1] = COMBO(combo1, MO(4)), [COMBO_2] = COMBO(combo2, MO(5)), [COMBO_3] = COMBO(combo3, TG(6)), [COMBO_4] = COMBO(combo4, TG(6)), [COMBO_5] = COMBO(combo5, TG(7)), [COMBO_6] = COMBO(combo6, TG(7)),
};
#endif
