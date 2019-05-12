# Enable RGB underglow
# https://beta.docs.qmk.fm/features/feature_rgblight
RGBLIGHT_ENABLE = yes

# Disable backlight, since I use RGB underglow.
# https://beta.docs.qmk.fm/features/feature_backlight
BACKLIGHT_ENABLE = no


# Disable unused features to save on space
# https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/
MOUSEKEY_ENABLE = no # 2000 bytes
CONSOLE_ENABLE = no
AUDIO_ENABLE = yes # 4000 bytes
BOOTMAGIC_ENABLE = no
