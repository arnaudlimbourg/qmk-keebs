# https://github.com/qmk/qmk_firmware/blob/master/docs/getting_started_make_guide.md
ifndef QUANTUM_DIR
    include ../../../../Makefile
endif

# enable hid_listen support (400kb)
CONSOLE_ENABLE = yes
