# https://github.com/qmk/qmk_firmware/blob/master/docs/getting_started_make_guide.md
#
# https://www.reddit.com/r/olkb/comments/bmpgjm/programming_help/
# Should shave 2000 bytes
LINK_TIME_OPTIMIZATION_ENABLE = yes

# Enable debugging only when needed.
CONSOLE_ENABLE = no # +400 bytes (hid_listen support)

# Enable combo keys for vim usage.
# https://github.com/qmk/qmk_firmware/blob/master/docs/feature_combo.md
# COMBO_ENABLE = yes

# This allows the keyboard to tell the host OS that up to 248 keys are held down at once
# NKRO_ENABLE = yes # note: also needs FORCE_NKRO in config.h

# Disable unused features to save on space
# https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/
MOUSEKEY_ENABLE = no # 2000 bytes
BOOTMAGIC_ENABLE = no
COMMAND_ENABLE = no # https://beta.docs.qmk.fm/features/feature_command
