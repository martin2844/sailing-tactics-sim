# Bounded 2026 scene design

The audience is sailors learning tactics. The water, sails and relative positions
must carry the page; the controls help steer and inspect that scene.

Tokens: deep water #123F58, open water #177F9C, sail/panel #F4F7F8,
ink #12303D, course amber #D99A20, warning #B32635. Local IBM Plex Sans,
14px secondary, 16px controls, 22px instruments, 28px page title.

Layout: left-aligned, quiet top bar for venue/fleet; dominant scene; compact
instruments over the left edge; camera switch on the right; helm controls along
the bottom. White triangular sails are the visual signature.

```
Tact 2026     Round Lake / fleet                         Restart
┌────────────────────────────────────────────────────────────┐
│ countdown / heading                          camera        │
│                                                            │
│                   faceted water + fleet                    │
│                                                            │
└────────────────────────────────────────────────────────────┘
Pause                 Port / Tack / Starboard           pace
```

Before-build critique: a grid of dashboard cards would obscure the fleet and
look generic. Removed those cards; the scene is the sole dominant element.
No marketing hero, decorative gradients, extra typefaces or all-caps labels.
The bounded spike must expose backend evidence separately from sailing controls.
Production model scale, shoreline accuracy, map and complete HUD remain later
tracker tasks. Desktop Chrome is the current target; Pixel validation is deferred.
