# Fleet identities (EXT-02)

Names are read from the original semantic CString cells (`4fec30 + boatId*4`),
initialized by `initializeBoats`, without replacing the fleet or writing game
memory. The initial default fleet is Fire, Bear, Betty, Fuzzy and Hoot.
All boats have 3D name labels. A custom player display name is optional, limited
to 32 characters and saved locally; empty text restores the native name.

[Chrome evaluation](fleet-names1/verification.json) verifies five/15 native
identities and labels, custom Unicode/markup-looking text safely rendered as
canvas text, persistence across reload, and whole native boundary equality
before/after editing. These are display identities, independent of sailing AI.
The championship/results UI will consume the same `boatName` function.
