/** Metres. Measured class envelopes; interior details are photo-based estimates.
 * Sources and the distinction from a certified cutting plan: docs/optimist-study. */
export const OPTIMIST = {
 length: 2.36, beam: 1.12, mastLength: 2.26,
 mastZ: -.72, mastStep: .04, tackHeight: .55,
 sail: {tack: [0, 0], throat: [0, 1.73], peak: [.87, 2.60], clew: [2.04, .16]},
} as const;
export interface OptimistPose {
 trim: number; heel: number; luff: number; time: number; penalty: boolean; crew: boolean;
}
export const DEFAULT_OPTIMIST_POSE: OptimistPose = {trim: 12, heel: 0, luff: 0, time: 0, penalty: false, crew: true};

/** z, sheer half-width/height, chine half-width/height; metres.
 * Shared with the water exclusion so the open cockpit stays dry. */
export const OPTIMIST_HULL_STATIONS = [
 [-1.18,.38,.37,.32,.13],[-.65,.515,.335,.445,.025],[0,.56,.32,.48,0],
 [.65,.535,.325,.455,.025],[1.18,.47,.34,.4,.09],
] as const;
