# Arnaud's QMK Keyboard Layouts

Forked from https://github.com/issmirnov/qmk - thank you to @issmirnov & @thenyeguy for the structure and template setup.

Supported Keyboards:

- Ergodox EZ
- Planck

## Commands

- `init.sh` for initial setup of repo after cloning. Will run [qmk_install.sh](https://github.com/qmk/qmk_firmware/blob/master/util/qmk_install.sh)
- `update.sh` will pull upstream changes to QMK. Note: Currently there is no sanity checking for breakages, so run a build to test.
- `qmk` is a util script that is used to interact with this repo. Available subcommands:
  - `build` - compiles layout into hex file
  - `push` - flashes firmware to keyboard
  - `show` - displays layout in visualizer

## TODO

### ergodox

- [ ] light underside rgb lights when changing layer
- [ ] review positioning of the alt and control keys
