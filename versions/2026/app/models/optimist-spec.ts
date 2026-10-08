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
