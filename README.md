# TB Fooger Ring Mod (2026 Mac)

TB Fooger Ring Mod for current Macs: **CLAP, VST3 and AU**, universal (Apple Silicon and Intel),
**macOS 11 and later**. Use it in Reaper, FL Studio, Logic, GarageBand, Tape16 and other hosts.

![panel](https://raw.githubusercontent.com/tonybuzzcock/TB-Fooger-Mountain-Lion-2026-MAC/gui-preview/panel_showcase.png)

The sound and panel are the same as the Mac OS X 10.8.5 VST build
([TB-Fooger-Mountain-Lion](https://github.com/tonybuzzcock/TB-Fooger-Mountain-Lion)). The DSP code is
the same, and the test suite checks that the plugin's output matches it sample for sample. It's a
model of the Moog moogerfooger MF-102 Ring Modulator, built from its schematic (in `Docs/`) and
checked against the user's own unit (the LFO matches the hardware). Personal, non-commercial use.

## Install

GitHub → Actions → latest run → Artifacts → `TB-Fooger-mac`, unzip, then follow `INSTALL.txt`.
In short:

- `TB Fooger Ring Mod.vst3` → `VST3/`
- `TB Fooger Ring Mod.component` → `Components/`
- `TB Fooger Ring Mod.clap` → `CLAP/`

These folders are in `/Library/Audio/Plug-Ins/` (the main Library) or `~/Library/Audio/Plug-Ins/`
(your user Library). Use whichever one your other plugins are in. Apple hasn't notarised the
plugins, so run the short Terminal lines in `INSTALL.txt` for the folder you used. Then rescan
plugins in your DAW.

## Controls

| Name | Control | Range |
|------|---------|-------|
| LFO Amount | how far the LFO sweeps the carrier | 0 – 10 (nothing below about 2; ±1 octave at 10) |
| LFO Wave | slide switch: square / sine | |
| LFO Rate | LFO speed | 0.1 – 25 Hz |
| Drive | input gain (also active in bypass, as on the unit) | x1 – x34 |
| Mix | dry to ring modulator | 0 – 10 (half and half at 5) |
| Lo/Hi | slide switch: carrier range | |
| Frequency | carrier frequency | HI 30 Hz – 4 kHz, LO 0.6 – 80 Hz |
| Effect On/Bypass | the footswitch (an 18 ms fade, through Drive) | On / Bypass |
| Input, Output | *plugin only*: level into the unit (1.0 = 1 V), output trim | ±12 dB, ±24 dB |

LEDs as on the unit: LEVEL (green, amber, red), LFO (red, pulsing), BYPASS (red on, green bypassed).
In stereo, each side runs through its own copy of the circuit with the same settings; a mono source
is processed once.

## The panel

480 × 780, laid out like the unit: walnut sides, black face, RING MODULATOR across the top, the LFO
and MODULATOR sections, the slide switches (the selected side lights up, and its legend glows), the
three LEDs, the chrome footswitch with the TB electronic logo beside it, and the strip with Input,
Output, presets and the readout.

Drag a knob up or down to turn it (hold Shift for fine control). Double-click to reset it, or use
the scroll wheel. Click a side of a slide switch to move it there. Click the footswitch to bypass.

**Presets:** click SAVE, then a slot 1–8. Click a saved slot to recall it. The presets are kept in
`~/Library/Application Support/TB/TB Fooger Ring Mod/Presets.txt` and shared by all three formats.

## Build

GitHub Actions (`.github/workflows/build.yml`) builds universal binaries on macOS, checks that all
three are arm64 + x86_64 with a macOS 11.0 minimum, ad-hoc signs them, and runs the CLAP host test,
the panel test, auval, clap-validator and pluginval (VST3 and AU). It runs on the Intel runner by
default; run it on Apple Silicon with
`gh workflow run build.yml -f runner=macos-15`.

Locally (macOS or Linux): `cmake -B build && cmake --build build`, then `build/preset_test`,
`build/ringmod_test renders` and `build/clap_host_test "build/plugins/TB Fooger Ring Mod.clap"`.
clap-wrapper v0.17.0 (MIT) and the SDKs it uses are downloaded at configure time.
