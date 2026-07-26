# CNC AI-Assisted Drawing Machine

**Team:** Engineering Innovation Club, Al-Nahrain University (team of 4) | 2026

An X-Y CNC-style drawing machine paired with an AI-assisted image pipeline:
a camera captures a target image, which is processed and converted into a
pen-plotted line drawing.

## My role
Mechanical assembly, soldering, and hardware integration. The control
firmware and AI image-processing pipeline were developed by other team
members and are not reproduced in this repository.

## Hardware
- 2x stepper motors (X and Y axes)
- Belt-driven gantry system
- Arduino Uno
- V-slot linear rail
- Servo motor for pen lift/drop (Z-axis equivalent)
- Camera module (image capture for the AI drawing pipeline)

## Sourcing note
Most components were sourced internationally, as they were not available
locally in Iraq at the time.

## reference/ folder
Contains an illustrative, non-original example sketch showing the general
control approach for a 2-stepper-motor X-Y pen plotter (open-loop
step/direction control + servo pen lift). This is a generic reference
implementation added for documentation purposes only — it does not
represent the actual firmware used in the competition build, which was
authored by other team members and was not preserved.
