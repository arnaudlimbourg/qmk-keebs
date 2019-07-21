#!/usr/bin/env bash

echo "updating .git/config with hook folder"
git config core.hooksPath hooks

echo "setting up qmk git submodule"
git submodule init
git submodule update
git submodule sync --recursive

echo "Running QMK installer"
qmk_firmware/util/qmk_install.sh
