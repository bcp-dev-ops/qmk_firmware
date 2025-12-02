# Quantum Mechanical Keyboard Firmware

[![Current Version](https://img.shields.io/github/tag/qmk/qmk_firmware.svg)](https://github.com/qmk/qmk_firmware/tags)
[![Discord](https://img.shields.io/discord/440868230475677696.svg)](https://discord.gg/qmk)
[![Docs Status](https://img.shields.io/badge/docs-ready-orange.svg)](https://docs.qmk.fm)
[![GitHub contributors](https://img.shields.io/github/contributors/qmk/qmk_firmware.svg)](https://github.com/qmk/qmk_firmware/pulse/monthly)
[![GitHub forks](https://img.shields.io/github/forks/qmk/qmk_firmware.svg?style=social&label=Fork)](https://github.com/qmk/qmk_firmware/)

This is a keyboard firmware based on the [tmk_keyboard firmware](https://github.com/tmk/tmk_keyboard) with some useful features for Atmel AVR and ARM controllers, and more specifically, the [OLKB product line](https://olkb.com), the [ErgoDox EZ](https://ergodox-ez.com) keyboard, and the Clueboard product line.

## Documentation

- [See the official documentation on docs.qmk.fm](https://docs.qmk.fm)

The docs are powered by [VitePress](https://vitepress.dev/). They are also viewable offline; see [Previewing the Documentation](https://docs.qmk.fm/#/contributing?id=previewing-the-documentation) for more details.

You can request changes by making a fork and opening a [pull request](https://github.com/qmk/qmk_firmware/pulls).

## Supported Keyboards

- [Planck](/keyboards/planck/)
- [Preonic](/keyboards/preonic/)
- [ErgoDox EZ](/keyboards/ergodox_ez/)
- [Clueboard](/keyboards/clueboard/)
- [Cluepad](/keyboards/clueboard/17/)
- [Atreus](/keyboards/atreus/)

The project also includes community support for [lots of other keyboards](/keyboards/).

## Maintainers

QMK is developed and maintained by Jack Humbert of OLKB with contributions from the community, and of course, [Hasu](https://github.com/tmk). The OLKB product firmwares are maintained by [Jack Humbert](https://github.com/jackhumbert), the Ergodox EZ by [ZSA Technology Labs](https://github.com/zsa), the Clueboard by [Zach White](https://github.com/skullydazed), and the Atreus by [Phil Hagelberg](https://github.com/technomancy).

## Official Website

[qmk.fm](https://qmk.fm) is the official website of QMK, where you can find links to this page, the documentation, and the keyboards supported by QMK.

## Notes to Self (BrianPugh)

```
qmk git-submodule
qmk compile -kb yunzii/al68 -km bpugh
qmk flash -kb yunzii/al68 -km bpugh

# if already running my keymap: press capslocks+r or capslock+b to enter bootloader
# if running factory: hold space+b while plugging in keyboard.
```

## Notes to Self (bcp-dev-ops)

### Flashing Corne v4.1 with 6 columns (plus two extra)

```
qmk git-submodule
qmk compile -kb crkbd/rev4_1/standard -km bcp_supreme_6col_extra2
qmk flash -kb crkbd/rev4_1/standard -km bcp_supreme_6col_extra2
(or copy the .uf2 file in the build folder).
# flash one side at a time
# DO NOT disconnect TRRS headphone jack while usb is plugged in ("hot")
# if already running my keymap:
# if running factory: hold the first two keys (r1c1 + r1c2) during boot (left half) or the right two keys (r1c7 + r1c7) (right half)

```

### Flashing Yunzii AL68 v2

```
qmk git-submodule
qmk compile -kb yunzii/al68 -km bcp_supreme_68_percent
qmk flash -kb yunzii/al68 -km bcp_supreme_68_percent

# if already running my keymap: press right function + b
# if running factory: hold space+b while plugging in keyboard.


```

### Flashing Ploopy Adept

```
qmk git-submodule
qmk compile -kb ploopyco/madromys -km bcp_supreme_adept
qmk flash -kb ploopyco/madromys -km bcp_supreme_adept
(or copy the .uf2 file in the build folder).

# if already running my keymap:
# if running factory: hold bottom left key while plugging in


```
